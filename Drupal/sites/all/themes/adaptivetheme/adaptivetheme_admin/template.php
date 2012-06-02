<?php
/**
 * Override or insert variables into html templates.
 */
function adaptivetheme_admin_preprocess_html(&$vars) {
  $vars['classes_array'][] = theme_get_setting('font_family');
  $vars['classes_array'][] = theme_get_setting('font_size'); 
}

/**
 * Override or insert variables into page templates.
 */
function adaptivetheme_admin_preprocess_page(&$vars) {
  $vars['datetime_rfc'] = '';
  $vars['datetime_iso'] = '';
  $vars['datetime_rfc'] = date("r" , time()); // RFC2822 date format
  $vars['datetime_iso'] = gmdate('Y-m-d\TH:i:s\Z'); // ISO 8601 date format   
}

/**
* Theme button. Override AT Core because it screws with Views.
*/
function adaptivetheme_admin_button($vars) {
  $element = $vars['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Alter the search block form.
 */
function adaptivetheme_admin_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#title'] = t('Search');
    $form['search_block_form']['#title_display'] = 'invisible';
    $form['search_block_form']['#size'] = 20;
    $form['search_block_form']['#attributes']['placeholder'] = t('Search');
    $form['actions']['submit']['#value'] = t('Go');
  }
}
