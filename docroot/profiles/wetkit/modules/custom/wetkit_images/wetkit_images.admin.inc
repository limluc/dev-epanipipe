<?php

/**
 * @file
 * Picture - map breakpoints and image styles
 */


/**
 * Picture settings.
 */
function wetkit_images_admin_settings($form, &$form_state) {
  $form['picture_implementation'] = array(
    '#type' => 'select',
    '#title' => t('Choose the javascript library to use'),
    '#options' => array(
      PICTURE_IMPLEMENTATION_PICTUREFILL => 'picturefill',
      PICTURE_IMPLEMENTATION_WEBLINC => 'weblinc',
      PICTURE_IMPLEMENTATION_WXT => 'wet-boew',
    ),
    '#default_value' => variable_get('picture_implementation', PICTURE_IMPLEMENTATION_WXT),
  );

  return system_settings_form($form);
}
