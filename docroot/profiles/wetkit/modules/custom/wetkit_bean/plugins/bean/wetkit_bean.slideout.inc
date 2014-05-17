<?php
/**
 * @file
 * A bean default plugin.
 */

class WetKitSlideOutBean extends BeanPlugin {

  /**
   * Implements BeanPlugin::values().
   */
  public function values() {
    $values = array();

    return array_merge(parent::values(), $values);
  }

  /**
   * Implements BeanPlugin::form().
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    return $form;
  }

  /**
   * Implements BeanPlugin::view().
   */
  public function view($bean, $content, $view_mode = 'full', $langcode = NULL) {
    $showtext = field_get_items('bean', $bean, 'title_field');
    $hidetext = field_get_items('bean', $bean, 'field_slideout_hide');

    if (is_array($showtext)) {
      $showtext = reset($showtext);
      $showtext = $showtext['safe_value'];
    } else {
      $showtext = '';
    }

    if (is_array($hidetext)) {
      $hidetext = reset($hidetext);
      $hidetext = $hidetext['safe_value'];
    } else {
      $hidetext = '';
    }

    $form = array(
      '#theme' => 'wetkit_slideout',
      '#show_title' => $showtext,
      '#hide_title' => $hidetext,
      '#contents' => $content['bean'],
    );

    return $form;
  }

  /**
   * Implements BeanPlugin::submit().
   */
  public function submit(Bean $bean) {
    return parent::submit($bean);
  }
}
