<?php
/**
 * @file
 * Listing bean plugin.
 */

class WetKitShareBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'share_settings' => array(
        'configure_share_widget' => 'span-5',
        'custom_css' => '',
      ),
    );

    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form['share_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure Share Widget'),
      '#tree' => TRUE,
      '#weight' => -8,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['share_settings']['configure_share_widget'] = array(
      '#type' => 'select',
      '#title' => t('Configure Share Span'),
      '#options' => array(
        'span-2' => t('Span 2'),
        'span-3' => t('Span 3'),
        'span-4' => t('Span 4'),
        'span-5' => t('Span 5'),
        'span-6' => t('Span 6'),
        'span-7' => t('Span 7'),
        'span-8' => t('Span 8'),
      ),
      '#default_value' => isset($bean->share_settings['configure_share_widget']) ? $bean->share_settings['configure_share_widget'] : '',
    );
    $form['share_settings']['email'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add sharing by email?'),
      '#default_value' => isset($bean->share_settings['email']) ? $bean->share_settings['email'] : '',
    );
    $form['share_settings']['source_tag'] = array(
      '#type' => 'textfield',
      '#title' => t('Add a source tag'),
      '#default_value' => isset($bean->share_settings['source_tag']) ? $bean->share_settings['source_tag'] : '',
    );
    $form['share_settings']['custom_css'] = array(
      '#type' => 'textfield',
      '#title' => t('Configure Shared Widget Custom CSS'),
      '#default_value' => isset($bean->share_settings['custom_css']) ? $bean->share_settings['custom_css'] : '',
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

    $span = isset($bean->share_settings['configure_share_widget']) ? $bean->share_settings['configure_share_widget'] : '';
    $custom_css = isset($bean->share_settings['custom_css']) ? $bean->share_settings['custom_css'] : '';
    $email = isset($bean->share_settings['email']) && $bean->share_settings['email'] ? ', addEmail:true' : '';
    $source_tag = isset($bean->share_settings['source_tag']) && !empty($bean->share_settings['source_tag'])?  ', sourceTag: \'' . $bean->share_settings['source_tag'] . '\'' : '';

    // Sites.
    $sites = '';
    foreach ($bean->field_share_widget[LANGUAGE_NONE] as $service) {
      $sites[] = '\'' . $service['value'] . '\'';
    }
    if (!empty($sites)) {
      $sites = '[' . implode(",", $sites) . ']';
    }
    else {
      $sites = '[]';
    }
    $content = array();
    $markup = '<div class="wet-boew-share ' . $span . ' ' . $custom_css . ' margin-bottom-none align-right" data-wet-boew="{sites: ' . $sites . $email . $source_tag . '}"></div>';
    $content['share_bean']['#markup'] = $markup;

    return $content;
  }
}