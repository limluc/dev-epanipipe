<?php
/**
 * @file
 * wsn_platform.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function wsn_platform_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_characteristics|node|wsn_platform_sensor_model|form';
  $field_group->group_name = 'group_characteristics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_sensor_model';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Characteristics',
    'weight' => '5',
    'children' => array(
      0 => 'field_callibration_polynomial_a0',
      1 => 'field_callibration_polynomial_a1',
      2 => 'field_callibration_polynomial_a2',
      3 => 'field_min_operating_range',
      4 => 'field_max_operating_range',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-characteristics field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_characteristics|node|wsn_platform_sensor_model|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|wsn_platform_group|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_contact_name',
      1 => 'field_contact_number',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|node|wsn_platform_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_input|node|wsn_platform_node|form';
  $field_group->group_name = 'group_data_input';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_node';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Node Data Input Details',
    'weight' => '5',
    'children' => array(
      0 => 'field_data_input_method',
      1 => 'field_data_compression_technique',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-data-input field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_data_input|node|wsn_platform_node|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_parsing_field|node|wsn_monitor_sensor|form';
  $field_group->group_name = 'group_data_parsing_field';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_monitor_sensor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Parsing Data Parsing Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_order_in_node',
      1 => 'field_sensor_node_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-data-parsing-field field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_data_parsing_field|node|wsn_monitor_sensor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data_parsing|node|wsn_platform_node|form';
  $field_group->group_name = 'group_data_parsing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_node';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Node Data Parsing Information',
    'weight' => '6',
    'children' => array(
      0 => 'field_sensor_sensor_delimiter',
      1 => 'field_measurand_set_delimiter',
      2 => 'field_measurand_set_time_interva',
      3 => 'field_measurand_set_occurence',
      4 => 'field_sensor_set_number',
      5 => 'field_measurand_set_order',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-data-parsing field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_data_parsing|node|wsn_platform_node|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_extra_functionality|node|wsn_monitor_sensor|form';
  $field_group->group_name = 'group_extra_functionality';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_monitor_sensor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sensor Extra Functionality',
    'weight' => '6',
    'children' => array(
      0 => 'field_forecast_enable',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-extra-functionality field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_extra_functionality|node|wsn_monitor_sensor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_field_information|node|wsn_platform_node|form';
  $field_group->group_name = 'group_field_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_node';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Field Information',
    'weight' => '11',
    'children' => array(
      0 => 'field_plant_type',
      1 => 'field_plant_start_cycle',
      2 => 'field_plant_age_da_',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-field-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_field_information|node|wsn_platform_node|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_model_detail|node|wsn_platform_sensor_model|form';
  $field_group->group_name = 'group_model_detail';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_sensor_model';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Model Detail',
    'weight' => '1',
    'children' => array(
      0 => 'field_unit_of_measurement',
      1 => 'field_sense_medium',
      2 => 'field_datasheet',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-model-detail field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_model_detail|node|wsn_platform_sensor_model|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_details|node|wsn_platform_node|form';
  $field_group->group_name = 'group_node_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_node';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Node Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_site_location',
      1 => 'field_site_elevation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-node-details field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_node_details|node|wsn_platform_node|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_node_information|node|wsn_platform_node|form';
  $field_group->group_name = 'group_node_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_node';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Node Information',
    'weight' => '4',
    'children' => array(
      0 => 'field_node_actitity_status',
      1 => 'field_node_deployment_category',
      2 => 'field_node_error_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-node-information field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_node_information|node|wsn_platform_node|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notififcation_centre|node|wsn_platform_node|form';
  $field_group->group_name = 'group_notififcation_centre';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_platform_node';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Centre',
    'weight' => '9',
    'children' => array(
      0 => 'field_notification_on_off',
      1 => 'field_message',
      2 => 'field_notification_receiver_numb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-notififcation-centre field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_notififcation_centre|node|wsn_platform_node|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_obs_details|node|wsn_monitor_sensor|form';
  $field_group->group_name = 'group_obs_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_monitor_sensor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Observation Details',
    'weight' => '7',
    'children' => array(
      0 => 'field_last_date_data_received',
      1 => 'field_last_reading_received',
      2 => 'field_next_forecast',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-obs-details field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_obs_details|node|wsn_monitor_sensor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sensor_details|node|wsn_monitor_sensor|form';
  $field_group->group_name = 'group_sensor_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_monitor_sensor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sensor Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_node_error_category',
      1 => 'field_node_actitity_status',
      2 => 'field_node_deployment_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sensor-details field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sensor_details|node|wsn_monitor_sensor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sensor_not_centre|node|wsn_monitor_sensor|form';
  $field_group->group_name = 'group_sensor_not_centre';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_monitor_sensor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Centre',
    'weight' => '4',
    'children' => array(
      0 => 'field_notification_on_off',
      1 => 'field_operating_criteria',
      2 => 'field_notification_receiver_numb',
      3 => 'field_message',
      4 => 'field_operating_condition',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sensor-not-centre field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_sensor_not_centre|node|wsn_monitor_sensor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wsn_tree_3|node|wsn_monitor_observation|form';
  $field_group->group_name = 'group_wsn_tree_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_monitor_observation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'WSN Tree',
    'weight' => '1',
    'children' => array(
      0 => 'field_wsn_parent_node',
      1 => 'field_wsn_parent_site',
      2 => 'field_wsn_parent_sensor',
      3 => 'field_wsn_hierarchy',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-wsn-tree-3 field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_wsn_tree_3|node|wsn_monitor_observation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wsn_tree|node|wsn_monitor_sensor|form';
  $field_group->group_name = 'group_wsn_tree';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'wsn_monitor_sensor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'WSN Tree',
    'weight' => '1',
    'children' => array(
      0 => 'field_wsn_parent_site',
      1 => 'field_wsn_hierarchy',
      2 => 'field_wsn_parent_node',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-wsn-tree field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_wsn_tree|node|wsn_monitor_sensor|form'] = $field_group;

  return $export;
}
