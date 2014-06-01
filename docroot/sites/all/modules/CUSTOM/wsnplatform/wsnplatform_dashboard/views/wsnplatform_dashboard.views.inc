<?php
/**
 * @file
 * WSN Platform Dashboard: views
 *
 * @package wsnplatform
 * @subpackage wsnplatform_dashboard
 */
 
/**
 * Implement hook_views_data().
 */
function wsnplatform_dashboard_views_data() {
  $data = array();
  $data['wsnplatform_attribute'] = array(
    'table' => array(
      'base' => array(
        'field' => 'attribute_nid',
        'title' => 'WSN Platfrom Attribute',
        'help' => 'Attribute List for Dropdown List - METHOD',
      ),
      'group' => 'WSN Platfrom Attribute',
    ),
    'attribute_nid' => array(
      'title' => 'Attribute Nid',
      'help' => 'Attribute NID',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ), 
    ),
    'domain' => array(
      'title' => 'Domain',
      'help' => 'List Domain',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ), 
    ),
    'akey' => array(
      'title' => 'Akey',
      'help' => 'List Key',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ), 
    ),
    'avalue' => array(
      'title' => 'Avalue',
      'help' => 'List Value',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ), 
    ),
    'isactive' => array(
      'title' => 'Isactive',
      'help' => 'Active Set',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ), 
    ),
  );
  
  $data['wsnplatform_group'] = array(
    'table' => array(
      'base' => array(
        'field' => 'group_nid',
        'title' => 'WSN Platfrom Group',
        'help' => 'WSN Platform - Mote Group',
      ),
      'group' => 'WSN Platfrom Group',
    ),
    'group_nid' => array(
      'title' => 'Group Nid',
      'help' => 'Mote Group ID',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ), 
    ),
    'group_title' => array(
      'title' => 'Group Title',
      'help' => 'Mote Group Title',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),       
    ),
    'contact_name' => array(
      'title' => 'Contact Name',
      'help' => 'Mote Group Contact Name',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
  );
  
  $data['wsnplatform_moteunit'] = array(
    'table' => array(
      'base' => array(
        'field' => 'moteunit_nid',
        'title' => 'WSN Platfrom Moteunit',
        'help' => 'WSN Platform Schema for MoteUnit',
      ),
      'group' => 'WSN Platfrom Moteunit',
    ),
    'moteunit_nid' => array(
      'title' => 'Moteunit Nid',
      'help' => 'MoteUnit ID ',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'moteunit_title' => array(
      'title' => 'Moteunit Title',
      'help' => 'MoteUnit Title',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'group_nid' => array(
      'title' => 'Group Nid',
      'help' => 'MoteGroup ID',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'input_id' => array(
      'title' => 'Input Id',
      'help' => 'Input ID',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'reading_occurence' => array(
      'title' => 'Reading Occurence',
      'help' => 'How Many Set of Reading Per Message',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_number' => array(
      'title' => 'Sensor Number',
      'help' => 'Number of Sensor in a Mode',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'datacompression' => array(
      'title' => 'Datacompression',
      'help' => 'Data Compression Technique Used',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'freq_read' => array(
      'title' => 'Freq Read',
      'help' => 'Frequency of Reading',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'freq_trans' => array(
      'title' => 'Freq Trans',
      'help' => 'Frequency of Transmission',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
  );
  
  $data['wsnplatform_observation'] = array(
    'table' => array(
      'base' => array(
        'field' => 'observation_nid',
        'title' => 'WSN Platfrom Observation',
        'help' => 'Table schema to store measured value',
      ),
      'group' => 'WSN Platfrom Observation',
    ),
    'observation_nid' => array(
      'title' => 'Observation Nid',
      'help' => 'Observation ID',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'moteunit_nid' => array(
      'title' => 'Moteunit Nid',
      'help' => 'Mote ID sensor',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'observation_type' => array(
      'title' => 'Observation Type',
      'help' => 'Observation Type Measurement.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'timestamp' => array(
      'title' => 'Timestamp',
      'help' => 'Time of Observation measured',
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
          'handler' => 'views_handler_filter_date',
        ),
    ),
    'value_array' => array(
      'title' => 'Value Array',
      'help' => 'Measured Value Array',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_one' => array(
      'title' => 'Sensor One',
      'help' => 'Measured value for Sensor 1',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_two' => array(
      'title' => 'Sensor Two',
      'help' => 'Measured value for Sensor 2',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_three' => array(
      'title' => 'Sensor Three',
      'help' => 'Measured value for Sensor 3',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_four' => array(
      'title' => 'Sensor Four',
      'help' => 'Measured value for Sensor 4',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_five' => array(
      'title' => 'Sensor Five',
      'help' => 'Measured value for Sensor 5',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_six' => array(
      'title' => 'Sensor Six',
      'help' => 'Measured value for Sensor 6',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_seven' => array(
      'title' => 'Sensor Seven',
      'help' => 'Measured value for Sensor 7',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_eight' => array(
      'title' => 'Sensor Eight',
      'help' => 'Measured value for Sensor 8',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
  );
  
  $data['wsnplatform_sensor'] = array(
    'table' => array(
      'base' => array(
        'field' => 'sensor_nid',
        'title' => 'WSN Platfrom Sensor',
        'help' => 'Sensor Schema for WSN Platform',
      ),
      'group' => 'WSN Platfrom Sensor',
    ),
    'sensor_nid' => array(
      'title' => 'Sensor Nid',
      'help' => 'Sensor ID',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'sensor_title' => array(
      'title' => 'Sensor Title',
      'help' => 'Sensor Title',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'moteunit_nid' => array(
      'title' => 'Moteunit Nid',
      'help' => 'Mote Unit This Sensor Belong To',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'model_nid' => array(
      'title' => 'Model Nid',
      'help' => 'This Sensor Model',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'order_number' => array(
      'title' => 'Order Number',
      'help' => 'Order of Sensor in the Mote Unit',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
  );
  
  $data['wsnplatform_sensor_model'] = array(
    'table' => array(
      'base' => array(
        'field' => 'model_nid',
        'title' => 'WSN Platfrom Sensor Model',
        'help' => 'Sensor Model Schema for WSN Platform',
      ),
      'group' => 'WSN Platfrom Sensor Model',
    ),
    'model_nid' => array(
      'title' => 'Model Nid',
      'help' => 'Model NID',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'model_title' => array(
      'title' => 'Model Title',
      'help' => 'Model Title',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'scalefactor' => array(
      'title' => 'Scalefactor',
      'help' => 'Scale Factor',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'unit' => array(
      'title' => 'Unit',
      'help' => 'Unit of Measurement',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'callibration_a0' => array(
      'title' => 'Callibration A0',
      'help' => 'Callibration Polynomial 0',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'callibration_a1' => array(
      'title' => 'Callibration A1',
      'help' => 'Callibration Polynomial 1',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'callibration_a2' => array(
      'title' => 'Callibration A2',
      'help' => 'Callibration Polynomial 2',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'operating_max' => array(
      'title' => 'Operating Max',
      'help' => 'Sensor Observation Max Value',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'operating_min' => array(
      'title' => 'Operating Min',
      'help' => 'Sensor Observation Min Value',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'datasheet' => array(
      'title' => 'Datasheet',
      'help' => 'Datasheet Link for further details',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
  );
  return $data;
}
