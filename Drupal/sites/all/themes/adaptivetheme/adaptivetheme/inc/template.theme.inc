<?php

/**
 * IMPORTANT WARNING: DO NOT MODIFY THIS FILE.
 *
 * If you need to add or modify theme functions do it in your sub-theme.
 */

/**
 * Returns HTML for a breadcrumb trail.
 */
function adaptivetheme_breadcrumb($vars) {
  $breadcrumb = $vars['breadcrumb'];
  $show_breadcrumb = theme_get_setting('breadcrumb_display');
  if ($show_breadcrumb == 'yes') {
    $show_breadcrumb_home = theme_get_setting('breadcrumb_home');
    if (!$show_breadcrumb_home) {
      array_shift($breadcrumb);
    }
    if (!empty($breadcrumb)) {
      $heading = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
      $separator = filter_xss(theme_get_setting('breadcrumb_separator'));
      $output = '';
      foreach ($breadcrumb as $key => $val) {
        if ($key == 0) {
          $output .= '<li class="crumb">' . $val . '</li>';
        }
        else {
          $output .= '<li class="crumb"><span>' . $separator . '</span>' . $val . '</li>';
        }
      }
      return $heading . '<ol id="crumbs">' . $output . '</ol>';
    }
  }
  return '';
}

/**
 * Returns HTML for a list or nested list of items.
 */
function adaptivetheme_item_list($vars) {
  $items = $vars['items'];
  $title = $vars['title'];
  $type = $vars['type'];
  $attributes = $vars['attributes'];

  $output = '<div class="item-list">';
  if (isset($title)) {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if (theme_get_setting('extra_item_list_classes')) {
        if ($i & 1) {
          $attributes['class'][] = 'odd';
        }
        else {
          $attributes['class'][] = 'even';
        }
        if ($i == 0) {
          $attributes['class'][] = 'first';
        }
        if ($i == $num_items - 1) {
          $attributes['class'][] = 'last';
        }
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>"; // no new line!
    }
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}

if (!function_exists('dhtml_menu_init')) {

  // theme_menu_tree
  function adaptivetheme_menu_tree($vars) {
    return '<ul class="menu clearfix">' . $vars['tree'] . '</ul>';
  }

  // theme_menu_link
  function adaptivetheme_menu_link(array $vars) {
    $element = $vars['element'];
    $sub_menu = '';
    if ($element['#below']) {
      $sub_menu = drupal_render($element['#below']);
    }
    if (theme_get_setting('extra_menu_classes')) {
      $element['#attributes']['class'][] = 'menu-item-' . $element['#original_link']['mlid'];
    }
    if (theme_get_setting('menu_item_span_elements')) {
      $element['#title'] = '<span>' . $element['#title'] . '</span>';
      $element['#localized_options']['html'] = TRUE;
    }
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>";
  }

}

// theme links
function adaptivetheme_links($vars) {
  $links = $vars['links'];
  $attributes = $vars['attributes'];
  $heading = $vars['heading'];
  global $language_url;
  $output = '';
  if (count($links) > 0) {
    $output = '';
    if (!empty($heading)) {
      if (is_string($heading)) {
        $heading = array(
          'text' => $heading,
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }
    $output .= '<ul' . drupal_attributes($attributes) . '>';
    $num_links = count($links);
    $i = 1;
    foreach ($links as $key => $link) {
      if (theme_get_setting('extra_menu_classes')) {
        $class = array($key);
      }
      if (theme_get_setting('extra_menu_classes')) {
        if ($i == 1) {
          $class[] = 'first';
        }
        if ($i == $num_links) {
          $class[] = 'last';
        }
      }
      if (theme_get_setting('extra_menu_classes')) {
        if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
            && (empty($link['language']) || $link['language']->language == $language_url->language)) {
          $class[] = 'active';
        }
      }
      if (theme_get_setting('extra_menu_classes')) {
        $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';
      }
      else {
        $output .= '<li>';
      }
      if (isset($link['href'])) {
        if (theme_get_setting('menu_item_span_elements')) {
          $link['title'] = '<span>' . $link['title'] . '</span>';
          $link['html'] = TRUE;
        }
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }
      $i++;
      $output .= "</li>";
    }
    $output .= '</ul>';
  }
  return $output;
}

/**
 * Modify the output of theme_field to use H2 for field lables.
 * There is a mirror image of this code as a template file in the
 * templates directory, see field.tpl.php.txt (example file to use
 * for template suggestions).
 */
function adaptivetheme_field($vars) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$vars['label_hidden']) {
    $output .= '<h2 class="field-label"' . $vars['title_attributes'] . '>' . $vars['label'] . ':&nbsp;</h2>';
  }

  // Render the items.
  $output .= '<div class="field-items"' . $vars['content_attributes'] . '>';
  foreach ($vars['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $vars['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
  }
  $output .= '</div>';

  // Render the top-level wrapper element.
  $tag = $vars['label_hidden'] ? 'div' : 'section';
  $output = "<$tag class=\"" . $vars['classes'] . '"' . $vars['attributes'] . '>' . $output . "</$tag>";

  return $output;
}
