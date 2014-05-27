<?php
/**
 * @file
 * wsn_platform.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wsn_platform_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function wsn_platform_node_info() {
  $items = array(
    'wsn_monitor_observation' => array(
      'name' => t('WSN Monitor Observation'),
      'base' => 'node_content',
      'description' => t('Wireless Sensor Network (WSN) Platform - Observation Layer'),
      'has_title' => '1',
      'title_label' => t('WSN Observation'),
      'help' => '',
    ),
    'wsn_monitor_sensor' => array(
      'name' => t('WSN Monitor Sensor'),
      'base' => 'node_content',
      'description' => t('Wireless Sensor Network (WSN) Platform Sensor Level'),
      'has_title' => '1',
      'title_label' => t('WSN Sensor'),
      'help' => '',
    ),
    'wsn_platform_group' => array(
      'name' => t('WSN Platform Group'),
      'base' => 'node_content',
      'description' => t('Placeholder for Wireless Sensor Network (WSN) Platform - Group containing information such as Contact / Site Details'),
      'has_title' => '1',
      'title_label' => t('WSN Group'),
      'help' => '',
    ),
    'wsn_platform_node' => array(
      'name' => t('WSN Platform Node'),
      'base' => 'node_content',
      'description' => t('Wireless Sensor Network (WSN) In-Field Node Level'),
      'has_title' => '1',
      'title_label' => t('WSN Node'),
      'help' => '',
    ),
    'wsn_platform_sensor_model' => array(
      'name' => t('WSN Platform Sensor Model'),
      'base' => 'node_content',
      'description' => t('WSN Platform Sensor Model Classification'),
      'has_title' => '1',
      'title_label' => t('WSN Sensor Model'),
      'help' => '',
    ),
  );
  return $items;
}
