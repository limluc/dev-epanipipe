<?php
/**
 * @file
 * Bean Slide plugin for Tabbed Interface.
 */

class WetKitBeanSlideTabbedInterfacePlugin implements WetKitBeanSlidePluginInterface {

  /**
   * Implements WetKitBeanSlidePluginInterface::attachments().
   */
  public function attachments() {}

  /**
   * Implements WetKitBeanSlidePluginInterface::form().
   */
  public function form($settings) {
    $form = array();

    $form['autoplay'] = array(
      '#type' => 'checkbox',
      '#title' => t('Auto Play'),
      '#default_value' => $settings['autoplay'],
    );

    $form['animate_effect'] = array(
      '#type' => 'select',
      '#title' => t('Animation effect'),
      '#options' => array(
        '' => 'none',
        'animate' => 'animate',
        'animate-fast' => 'animate-fast',
        'animate-slow' => 'animate-slow',
      ),
      '#default_value' => $settings['animate_effect'],
    );

    $form['rotate_effect'] = array(
      '#type' => 'select',
      '#title' => t('Cycle Effect'),
      '#options' => array(
        '' => 'none',
        'cycle' => 'cycle',
        'cycle-fast' => 'cycle-fast',
        'cycle-slow' => 'cycle-slow',
      ),
      '#default_value' => $settings['rotate_effect'],
    );

    $form['tabs_style_effect'] = array(
      '#type' => 'select',
      '#title' => t('Default Appearance'),
      '#options' => drupal_map_assoc(array(
        'tabs-style-1',
        'tabs-style-2',
        'tabs-style-3',
        'tabs-style-4',
        'tabs-style-5',
      )),
      '#default_value' => $settings['tabs_style_effect'],
    );

    return $form;
  }

  /**
   * Implements WetKitBeanSlidePluginInterface::values().
   */
  public function values() {
    return array(
      'animate_effect' => 'animate',
      'autoplay' => TRUE,
      'rotate_effect' => 'cycle',
      'tabs_style_effect' => 'tabs-style-3',
    );
  }

  /**
   * Implements WetKitBeanSlidePluginInterface::submit().
   */
  public function submit(&$settings) {

  }
}
