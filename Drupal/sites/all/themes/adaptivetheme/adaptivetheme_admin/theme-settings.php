<?php
function adaptivetheme_admin_form_system_theme_settings_alter(&$form, &$form_state)  {
  // some basic font settings for the admin theme
  $form['at']['font'] = array(
    '#type' => 'fieldset',
    '#title' => t('Font Settings'),
    '#description' => t('<h3>Font Settings</h3>'),
  );
  $form['at']['font']['font_family'] = array(
    '#type' => 'select',
    '#title' => t('Font'),
    '#default_value' => theme_get_setting('font_family'),
    '#options' => array(
      'ff-sss' => t('Candara, Trebuchet MS, Helvetica Neue, Arial, Helvetica, sans-serif'),
      'ff-ssl' => t('Verdana, Geneva, Arial, Helvetica, sans-serif'),
      'ff-a'   => t('Arial, Helvetica, sans-serif'),
      'ff-cc'  => t('Calibri, Candara, Arial, Helvetica, sans-serif'),
      'ff-m'   => t('Segoe UI, Myriad Pro, Myriad, Arial, Helvetica, sans-serif'),
      'ff-l'   => t('Lucida Sans Unicode, Lucida Sans, Lucida Grande, Verdana, Geneva, sans-serif'),
      'ff-ss'  => t('Garamond, Perpetua, Times New Roman, serif'),
      'ff-sl'  => t('Georgia, Baskerville, Palatino, Palatino Linotype, Book Antiqua, Times New Roman, serif'),
      'ff-ms'  => t('Consolas, Monaco, Courier New, Courier, monospace'),
    ),
  );
  $form['at']['font']['font_size'] = array(
    '#type' => 'select',
    '#title' => t('Size'),
    '#default_value' => theme_get_setting('font_size'),
    '#description' => t('This sets a base font-size on the body element - all text will scale relative to this value.'),
    '#options' => array(
      'fs-smallest' => t('Smallest'),
      'fs-small'    => t('Small'),
      'fs-medium'   => t('Medium'),
      'fs-large'    => t('Large'),
      'fs-largest'  => t('Largest'),
    ),
  );
  // Wrangle the theme settings form so it makes sense and avoids any problems with logo's
  $form['theme_settings']['#collapsible'] = TRUE;
  $form['theme_settings']['#collapsed'] = TRUE;
  $form['theme_settings']['toggle_logo']['#type'] = 'hidden';
  $form['theme_settings']['toggle_logo']['#default_value'] = 0;
  $form['logo']['#type'] = 'hidden';
  $form['logo']['#default_value'] = 1;
  $form['favicon']['#collapsible'] = TRUE;
  $form['favicon']['#collapsed'] = TRUE;
}
