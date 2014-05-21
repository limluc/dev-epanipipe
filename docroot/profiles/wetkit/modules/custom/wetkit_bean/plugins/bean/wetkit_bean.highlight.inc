<?php
/**
 * @file
 * Listing bean plugin.
 */

class WetKitHighlightBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'wetkit_bean_title_settings' => array(
        'classes' => '',
      ),
    );

    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form['wetkit_bean_title_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure Title Field'),
      '#tree' => TRUE,
      '#weight' => 1,
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );
    $form['wetkit_bean_title_settings']['classes'] = array(
      '#description' => t('CSS classes to be added to the title field.'),
      '#type' => 'textfield',
      '#title' => t('CSS'),
      '#default_value' => isset($bean->wetkit_bean_title_settings['classes']) ? $bean->wetkit_bean_title_settings['classes'] : '',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => FALSE,
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    // Link Field.
    $link_path = field_get_items('bean', $bean, 'field_bean_highlight_link');
    if (isset($link_path[0])) {
      $link_url = $link_path[0]['display_url'];
    }

    // Content Fields.
    foreach ($content['bean'] as &$child) {
      if (isset($link_url)) {
        $child['field_bean_highlight_image'][0]['file']['#prefix'] = '<a href="' . $link_url . '">';
        $child['field_bean_highlight_image'][0]['file']['#suffix'] = '</a>';
      }
    }
    return $content;
  }
}
