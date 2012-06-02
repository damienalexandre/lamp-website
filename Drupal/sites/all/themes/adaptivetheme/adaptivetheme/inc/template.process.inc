<?php

/**
 * IMPORTANT WARNING: DO NOT MODIFY THIS FILE.
 *
 * If you need to add or modify preprocess or process functions do it in your sub-theme.
 */

// Process variables for html tag
function adaptivetheme_process_html_tag(&$vars) {
  $tag = &$vars['element'];
  if ($tag['#tag'] == 'style' || $tag['#tag'] == 'script') {
    // Remove redundant type attribute and CDATA comments.
    unset($tag['#attributes']['type'], $tag['#value_prefix'], $tag['#value_suffix']);

    // Remove media="all" but leave others unaffected.
    if (isset($tag['#attributes']['media']) && $tag['#attributes']['media'] === 'all') {
      unset($tag['#attributes']['media']);
    }
  }
}

// Preprocess variables for html.tpl.php
function adaptivetheme_preprocess_html(&$vars) {

  global $language;

  // AT no longer uses doctype switching or $rdf_profile, these maintain backwards
  // compatibility with pre 7.x-2.1 versions of html.tpl.php
  $vars['doctype'] = '<!DOCTYPE html>' . "\n";
  $vars['rdf_profile'] = '';

  // Clean up the lang attributes, great idea Zen
  $vars['html_attributes'] = 'lang="' . $language->language . '" dir="' . $language->dir . '"';

  // add extra classes if set
  if (theme_get_setting('extra_page_classes')) {
    if (function_exists('locale')) {
      $vars['classes_array'][] = 'lang-' . $vars['language']->language;
    }

    // Classes for body element. Allows advanced theming based on context
    // (home page, node of certain type, etc.), cheers Zen.
    if (!$vars['is_front']) {
      // Add unique class for each page.
      $path = drupal_get_path_alias($_GET['q']);
      // Add unique class for each website section.
      list($section, ) = explode('/', $path, 2);
      $arg = explode('/', $_GET['q']);
      $vars['classes_array'][] = drupal_html_class('section-' . $section);
    }

    // Set classes for views and panels pages, thanks again Zen, you're amazing!
    $vars['menu_item'] = menu_get_item();
    switch ($vars['menu_item']['page_callback']) {
      case 'views_page':
        // Is this a Views page?
        $vars['classes_array'][] = 'page-views';
        break;
      case 'page_manager_page_execute':
      case 'page_manager_node_view':
      case 'page_manager_contact_site':
        // Is this a Panels page?
        $vars['classes_array'][] = 'page-panels';
        break;
    }
  }
  // strip rubbish classes if extra classes not set
  if (theme_get_setting('extra_page_classes') == 0) {
    foreach ($vars['classes_array'] as $i => $class) {
      if (preg_match('/page*/', $class)) {
        unset($vars['classes_array'][$i]);
      }
    }
  }

  // Load the media queries layout CSS files
  global $theme;
  $filename = $theme . '_mediaqueries_css';
  $file = variable_get($filename);
  $path = "public://at_css";
  if (!empty($file)) {
    $filepath = $path . '/' . $file;
    drupal_add_css($filepath, array(
      'preprocess' => variable_get('preprocess_css', '') == 1 ? TRUE : FALSE,
      'group' => CSS_THEME,
      'media' => 'all',
      'every_page' => TRUE,
      )
    );
  }

  // Ad respond.js to the footer to avoid crashes in IE8
  drupal_add_js(drupal_get_path('theme', 'adaptivetheme') . '/js/respond.js',
    array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => JS_THEME,
      'preprocess' => TRUE,
      'cache' => TRUE,
    )
  );

  // add a body class is the site name is hidden
  if (theme_get_setting('toggle_name') == FALSE) {
    $vars['classes_array'][] = 'site-name-hidden';
  }
}

// Process variables for html.tpl.php
function adaptivetheme_process_html(&$vars) {
  $classes = explode(' ', $vars['classes']);
  if ($node = menu_get_object()) {
    $node_type_class = drupal_html_class('node-type-' . $node->type);
    if (in_array($node_type_class, $classes)) {
      if (theme_get_setting('extra_page_classes') == 0) {
        $classes = str_replace($node_type_class, '', $classes);
      }
      if (theme_get_setting('extra_page_classes') == 1) {
        $classes = str_replace('node-type-', 'page-type-', $classes);
      }
    }
  }
  $vars['classes'] = trim(implode(' ', $classes));
}

// Preprocess variables for page.tpl.php
function adaptivetheme_preprocess_page(&$vars) {
  $vars['logo_alt_text'] = check_plain(variable_get('site_name', '')) . ' ' . t('logo');
  $vars['logo_img'] = $vars['logo'] ? '<img src="' . check_url($vars['logo']) . '" alt="' . $vars['logo_alt_text'] . '"/>' : '';
  $vars['linked_site_logo'] = $vars['logo_img'] ? l($vars['logo_img'], '<front>', array(
    'attributes' => array(
      'title' => t('Home page')
    ),
    'html' => TRUE,
    )
  ) : '';
  if (theme_get_setting('toggle_name') == FALSE) {
    $vars['visibility'] = 'element-invisible';
    $vars['hide_site_name'] = TRUE;
  }
  else {
    $vars['visibility'] = '';
    $vars['hide_site_name'] = FALSE;
  }
  $sitename = filter_xss_admin(variable_get('site_name', 'Drupal'));
  $vars['site_name'] = $sitename ? l($sitename, '<front>', array(
    'attributes' => array(
      'title' => t('Home page')),
    )
  ) : '';

  if (isset($vars['main_menu'])) {

    $text = block_get_blocks_by_region('menu_bar') ? t('Navigation') : t('Main menu');

    $vars['primary_navigation'] = theme('links', array(
      'links' => $vars['main_menu'],
      'attributes' => array(
        'class' => array('menu', 'primary-menu', 'clearfix'),
       ),
      'heading' => array(
        'text' => $text,
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  if (!empty($vars['primary_navigation'])) {
    $vars['primary_navigation'] = _theme_menu_variables($vars['primary_navigation'], 'primary');
  }
  if (isset($vars['secondary_menu'])) {
    $vars['secondary_navigation'] = theme('links', array(
      'links' => $vars['secondary_menu'],
      'attributes' => array(
        'class' => array('menu', 'secondary-menu', 'clearfix'),
      ),
      'heading' => array(
        'text' => t('Secondary navigation'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  if (!empty($vars['secondary_navigation'])) {
    $vars['secondary_navigation'] = _theme_menu_variables($vars['secondary_navigation'], 'secondary');
  }

  $vars['primary_local_tasks'] = menu_primary_local_tasks();
  $vars['secondary_local_tasks'] = menu_secondary_local_tasks();
  $vars['attribution'] = "<small id=\"attribution\"><a href=\"http://adaptivethemes.com\">Premium Drupal Themes</a></small>";

  // Work-around a stupid bug in Drupal 7
  if (arg(0) == 'user' && arg(1) == 'login') {
    drupal_set_title(t('User login'));
  }
  if (arg(0) == 'user' && arg(1) == 'password') {
    drupal_set_title(t('Request new password'));
  }
  if (arg(0) == 'user' && arg(1) == 'register') {
    drupal_set_title(t('Create new account'));
  }
}

// Preprocess variables for node.tpl.php
function adaptivetheme_preprocess_node(&$vars) {
  global $theme, $user;

  if (theme_get_setting('extra_article_classes')) {
    if (module_exists('translation')) {
      if ($vars['node']->language) {
        global $language;
        $vars['classes_array'][] = 'article-lang-' . $vars['node']->language;
      }
    }
  }

  if (theme_get_setting('extra_article_classes')) {
    $vars['classes_array'][] = $vars['zebra'];
    if ($vars['display_submitted'] && !empty($vars['picture'])) {
      $vars['classes_array'][] = 'article-with-picture';
    }
  }
  if (!$vars['teaser'] && theme_get_setting('extra_article_classes')) {
    $vars['classes_array'][] = drupal_html_class('article-' . $vars['view_mode']);
  }

  $vars['attributes_array']['role'][] = 'article';
  $vars['title_attributes_array']['class'][] = 'article-title';
  $vars['content_attributes_array']['class'][] = 'article-content';
  $vars['datetime'] = format_date($vars['created'], 'custom', 'Y-m-d\TH:i:s\Z'); // PHP 'c' format is not proper ISO8601, we need to build it
  if (variable_get('node_submitted_' . $vars['node']->type, TRUE)) {
    $vars['submitted'] = t('Submitted by !username on !datetime',
      array(
        '!username' => $vars['name'],
        '!datetime' => '<time datetime="' . $vars['datetime'] . '" pubdate="pubdate">' . $vars['date'] . '</time>',
      )
    );
  }
  else {
    $vars['submitted'] = '';
  }

  $vars['unpublished'] = '';
  if (!$vars['status']) {
    $vars['unpublished'] = '<div class="unpublished">' . t('Unpublished') . '</div>';
  }

}

// Process variables for node.tpl.php
function adaptivetheme_process_node(&$vars) {
  $classes = explode(' ', $vars['classes']);
  $classes = str_replace('node', 'article', $classes);
  if (in_array('article-' . $vars['node']->type, $classes)) {
    $classes = str_replace('article-' . $vars['node']->type, 'article-type-' . $vars['node']->type, $classes);
  }
  if (in_array('article-sticky', $classes)) {
    theme_get_setting('extra_article_classes') ? '' : $classes = str_replace('article-sticky', '', $classes);
  }
  if (in_array('article-promoted', $classes)) {
    theme_get_setting('extra_article_classes') ? '' : $classes = str_replace('article-promoted', '', $classes);
  }
  if (in_array('article-teaser', $classes)) {
    theme_get_setting('extra_article_classes') ? '' : $classes = str_replace('article-teaser', '', $classes);
  }
  if (in_array('article-preview', $classes)) {
    theme_get_setting('extra_article_classes') ? '' : $classes = str_replace('article-preview', '', $classes);
  }
  $vars['classes'] = trim(implode(' ', $classes));
}

// Preprocess variables for comment.tpl.php
function adaptivetheme_preprocess_comment(&$vars) {

  if (theme_get_setting('extra_comment_classes')) {
    $vars['classes_array'][] = $vars['zebra'];
    if (theme_get_setting('comments_hide_title')) {
      $vars['classes_array'][] = 'comment-title-hidden';
    }
    if ($vars['picture']) {
      $vars['classes_array'][] = 'comment-with-picture';
    }
    if ($vars['signature']) {
      $vars['classes_array'][] = 'comment-with-signature';
    }
  }

  $vars['title_attributes_array']['class'][] = 'comment-title';
  if (theme_get_setting('comments_hide_title')) {
    $vars['title_attributes_array']['class'][] = 'element-invisible';
  }
  $vars['content_attributes_array']['class'][] = 'comment-content';

  $uri = entity_uri('comment', $vars['comment']);
  $uri['options'] += array('attributes' => array('rel' => 'bookmark'));
  $vars['title'] = l($vars['comment']->subject, $uri['path'], $uri['options']);
  $vars['permalink'] = l(t('Permalink'), $uri['path'], $uri['options']);
  $vars['created'] = '<span class="date-time permalink">' . l($vars['created'], $uri['path'], $uri['options']) . '</span>';
  $vars['datetime'] = format_date($vars['comment']->created, 'custom', 'Y-m-d\TH:i:s\Z');
  $vars['submitted'] = t('Submitted by !username on !datetime',
    array(
      '!username' => $vars['author'],
      '!datetime' => '<time datetime="' . $vars['datetime'] . '" pubdate="pubdate">' . $vars['created'] . '</time>',
    )
  );
  $vars['unpublished'] = '';
  if ($vars['status'] == 'comment-unpublished') {
    $vars['unpublished'] = '<div class="unpublished">' . t('Unpublished') . '</div>';
  }
}

// Process variables for comment.tpl.php
function adaptivetheme_process_comment(&$vars) {
  $classes = explode(' ', $vars['classes']);
  if (in_array('comment-by-anonymous', $classes)) {
    theme_get_setting('extra_comment_classes') ? '' : $classes = str_replace('comment-by-anonymous', '', $classes);
  }
  if (in_array('comment-by-node-author', $classes)) {
    $classes = str_replace('comment-by-node-author', 'comment-by-article-author', $classes);
    theme_get_setting('extra_comment_classes') ? '' : $classes = str_replace('comment-by-article-author', '', $classes);
  }
  if (in_array('comment-by-viewer', $classes)) {
    theme_get_setting('extra_comment_classes') ? '' : $classes = str_replace('comment-by-viewer', '', $classes);
  }
  if (in_array('comment-new', $classes)) {
    theme_get_setting('extra_comment_classes') ? '' : $classes = str_replace('comment-new', '', $classes);
  }
  $vars['classes'] = trim(implode(' ', $classes));
}

// Preprocess variables for block.tpl.php
function adaptivetheme_preprocess_block(&$vars) {

  if (theme_get_setting('extra_block_classes')) {
    $vars['classes_array'][] = 'block-' . $vars['block_zebra'];
    $vars['classes_array'][] = 'block-count-' . $vars['id'];
    $vars['classes_array'][] = drupal_html_class('block-region-' . $vars['block']->region);
  }
  if (theme_get_setting('horizontal_login_block') && $vars['block']->module == 'user' && $vars['block']->delta == 'login') {
    $vars['classes_array'][] = 'lb-h';
  }
  if (theme_get_setting('slider_login_block') && $vars['block']->module == 'user' && $vars['block']->delta == 'login') {
    $vars['classes_array'][] = 'lb-s';
  }

  $vars['title_attributes_array']['class'][] = 'block-title';
  $vars['content_attributes_array']['class'][] = 'block-content';
  $vars['content_attributes_array']['class'][] = 'content';
  $nav_blocks = array('navigation', 'main-menu', 'management', 'user-menu');

  if (in_array($vars['block']->delta, $nav_blocks)) {
    $vars['theme_hook_suggestions'][] = 'block__menu';
  }
  $nav_modules = array('superfish', 'nice_menus');
  if (in_array($vars['block']->module, $nav_modules)) {
    $vars['theme_hook_suggestions'][] = 'block__menu';
  }
  if ($vars['block']->region == 'menu_bar') {
    $vars['theme_hook_suggestions'][] = 'block__menu_bar';
    $vars['title_attributes_array']['class'][] = 'element-invisible';
  }

  // Provide template suggestions such as block--header--search, or block--menu-bar--menu
  $vars['theme_hook_suggestions'][] = 'block__' . $vars['block']->region . '__' . $vars['block']->module;

  // Add ARIA Roles to blocks, thank-you to Jacine http://drupal.org/user/88931 for cleaning up this code :)
  $roles = array(
    'complementary' => array(
      'aggregator',
      'help',
      'locale',
      'poll',
      'profile',
      'node' => array('syndicate'),
      'system' => array('powered-by', 'help'),
      'user' => array('new', 'online'),
    ),
    'navigation' => array(
      'blog',
      'book',
      'comment',
      'forum',
      'menu',
      'menu_block',
      'node' => array('recent'),
      'shortcut',
      'statistics',
      'system' => array_keys(menu_list_system_menus()),
      'superfish',
      'nice_menus',
    ),
    'search' => array(
      'search',
    ),
    'form' => array(
      'user' => array('login'),
    ),
  );
  foreach ($roles as $role => $module) {
    if (!is_array($role) && in_array($vars['block']->module, $module)) {
      $vars['attributes_array']['role'] = "$role";
    }
    elseif (is_array($role)) {
      foreach ($role as $module => $delta) {
        if ($vars['block']->module == $module && in_array($vars['block']->delta, $delta)) {
          $vars['attributes_array']['role'] = "$role";
        }
      }
    }
  }

}

// Changes the search form to use the "search" input element of HTML5 (from the Boron theme)
function adaptivetheme_preprocess_search_block_form(&$vars) {
  $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}

// Modify search results based on theme settings
function adaptivetheme_preprocess_search_result(&$vars) {
  $result = $vars['result'];
  $vars['url'] = check_url($result['link']);
  $vars['title'] = check_plain($result['title']);
  $vars['snippet'] = '';
  if (!empty($result['snippet']) && theme_get_setting('search_snippet')) {
    $vars['snippet'] = $result['snippet'];
  }
  $info = array();
  if (!empty($result['type']) && theme_get_setting('search_info_type')) {
    $info['type'] = check_plain($result['type']);
  }
  if (!empty($result['user']) && theme_get_setting('search_info_user')) {
    $info['user'] = $result['user'];
  }
  if (!empty($result['date']) && theme_get_setting('search_info_date')) {
    $info['date'] = format_date($result['date'], 'small');
  }
  if (isset($result['extra']) && is_array($result['extra'])) {
    if (!empty($result['extra'][0]) && theme_get_setting('search_info_comment')) {
      $info['comment'] = $result['extra'][0];
    }
    if (!empty($result['extra'][1]) && theme_get_setting('search_info_upload')) {
      $info['upload'] = $result['extra'][1];
    }
  }
  $vars['info_split'] = $info;
  $vars['info'] = implode(' - ', $info);
  $vars['info_separator'] = filter_xss(theme_get_setting('search_info_separator'));
}

// Preprocess variables for region.tpl.php
function adaptivetheme_preprocess_region(&$vars, $hook) {
  if (strpos($vars['region'], 'sidebar_') === 0) {
    $vars['classes_array'][] = 'sidebar';
  }
}

// Process variables for aggregator-item.tpl.php
function adaptivetheme_preprocess_aggregator_item(&$vars) {
  $item = $vars['item'];
  $vars['datetime'] = format_date($item->timestamp, 'custom', 'Y-m-d\TH:i:s\Z');
}

// Process variables for maintenance-page.tpl.php
function adaptivetheme_preprocess_maintenance_page(&$vars) {
  $vars['attribution'] = "<small id=\"attribution\"><a href=\"http://adaptivethemes.com\">Premium Drupal Themes</a></small>";
}
