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
function wsnplatform_views_data() {
  $data = array();
  $data['wsnplatform_group'] = array(
    'table' => array(
      'base' => array(
        'field' => 'group_nid',
        'title' => 'WSN Platform Group',
        'help' => 'WSN Platform - Mote Group',
      ),
      'group' => 'WSN Platform Group',
    ),
    'group_nid' => array(
    'title' => 'Group Nid',
    'help' => 'Mote Group ID',
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_numeric',
      ),
    ),
    'group_title' => array(
      'title' => 'Group Title',
      'help' => 'Mote Group Title',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
        ),
          'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
          'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'contact_name' => array(
        'title' => 'Contact Name',
        'help' => 'Mote Group Contact Name',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'contact_email_address' => array(
        'title' => 'Contact Email Address',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'contact_number' => array(
        'title' => 'Contact Number',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
           'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'contact_address' => array(
        'title' => 'Contact Address',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
         'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'contact_language' => array(
        'title' => 'Contact Language',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'contact_details' => array(
        'title' => 'Contact Details',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
          'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
          'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
    );
    
    $data['wsnplatform_nodeentity'] = array(
      'table' => array(
        'base' => array(
          'field' => 'nodeentity_nid',
          'title' => 'WSN Platform Nodeentity',
          'help' => 'WSN Platform Schema for Nodeentity',
        ),
        'group' => 'WSN Platform Nodeentity',
        'join' => array(
          'wsnplatform_group' => array(
            'left_field' => 'group_nid',
            'field' => 'group_nid',
           ),
          'wsnplatform_datacompression' => array(
            'left_field' => 'datacompression_id',
            'field' => 'datacompression_id',
           ),
           'wsnplatform_notification' => array(
            'left_field' => 'notification_id',
            'field' => 'notification_id',
           ),
           'wsnplatform_plant' => array(
            'left_field' => 'plant_id',
            'field' => 'plant_id',
           ),  
        ),
      ),
      'nodeentity_nid' => array(
        'title' => 'Nodeentity Nid',
        'help' => 'Nodeentity ID ',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
          'filter' => array(
            'handler' => 'views_handler_filter_numeric',
          ),
          'sort' => array(
            'handler' => 'views_handler_numeric',
            ),
      ),
      'nodeentity_title' => array(
        'title' => 'Nodeentity Title',
        'help' => 'Nodeentity Title',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
          'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
          'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'group_nid' => array(
        'title' => 'Group NID',
        'help' => 'Group NID',
        'relationship' => array(
          'label' => t('Group NID'),
          'base' => 'wsnplatform_group',
          'base field' => 'group_nid',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
          'handler' => 'views_handler_sort_numeric',
         ),
       ),
      'input_id' => array(
        'title' => 'Input Id',
        'help' => 'Input ID',
        'field' => array(
          'handler' => 'views_handler_field_string',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'reading_occurence' => array(
        'title' => 'Reading Occurence',
        'help' => 'How Many Set of Reading Per Message',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'sensor_number' => array(
        'title' => 'Sensor Number',
        'help' => 'Number of Sensor in a Mode',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'datacompression_id' => array(
        'title' => 'Datacompression Id',
        'help' => 'Data Compression Technique Used',
        'relationship' => array(
          'label' => t('Data Compression ID'),
          'base' => 'wsnplatform_datacompression',
          'base field' => 'datacompression_id',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         
          'filter' => array(
            'handler' => 'views_handler_filter_numeric',
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_numeric',
            ),
      ),
      'freq_read' => array(
        'title' => 'Freq Read',
        'help' => 'Frequency of Reading',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
          'filter' => array(
            'handler' => 'views_handler_filter_numeric',
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_numeric',
            ),
      ),
      'freq_trans' => array(
        'title' => 'Freq Trans',
        'help' => 'Frequency of Transmission',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
          'filter' => array(
            'handler' => 'views_handler_filter_numeric',
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_numeric',
            ),
      ),
      'site_location' => array(
        'title' => 'Site Location',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'node_elevation' => array(
        'title' => 'Node Elevation',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'node_activity' => array(
        'title' => 'Node Activity',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      ),
      'notification_id' => array(
        'title' => 'Notification Id',
        'help' => 'TODO: please describe this field!',
        'relationship' => array(
          'label' => t('Notification ID'),
          'base' => 'wsnplatform_notification',
          'base field' => 'notification_id',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'last_measured' => array(
        'title' => 'Last Measured',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_date',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_date',
         ),
      ),
      'last_text' => array(
        'title' => 'Last Text',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_date',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_date',
         ),
      ),
      'plant_id' => array(
        'title' => 'Plant Id',
        'help' => 'TODO: please describe this field!',
        'relationship' => array(
          'label' => t('Plant ID'),
          'base' => 'wsnplatform_plant',
          'base field' => 'plant_id',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'input_method' => array(
        'title' => 'Input Method',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
    );
     $data['wsnplatform_observation'] = array(
      'table' => array(
        'base' => array(
          'field' => 'observation_nid',
          'title' => 'WSN Platform Observation',
          'help' => 'Table schema to store measured value',
        ),
        'group' => 'WSN Platform Observation',
        'join' => array(
          'wsnplatform_nodeentity' => array(
            'left_field' => 'nodeentity_nid',
            'field' => 'nodeentity_nid',
           ),
        ),
      ),
      'observation_nid' => array(
        'title' => 'Observation Nid',
        'help' => 'Observation ID',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'nodeentity_nid' => array(
        'title' => 'Nodeentity Nid',
        'help' => 'Mote ID sensor',
        'relationship' => array(
          'label' => t('Nodeentity'),
          'base' => 'wsnplatform_nodeentity',
          'base field' => 'nodeentity_nid',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'observation_type' => array(
        'title' => 'Observation Type',
        'help' => 'Observation Type Measurement.',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
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
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'sensor_one' => array(
        'title' => 'Sensor One',
        'help' => 'Measured value for Sensor 1',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_two' => array(
        'title' => 'Sensor Two',
        'help' => 'Measured value for Sensor 2',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_three' => array(
        'title' => 'Sensor Three',
        'help' => 'Measured value for Sensor 3',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_four' => array(
        'title' => 'Sensor Four',
        'help' => 'Measured value for Sensor 4',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_five' => array(
        'title' => 'Sensor Five',
        'help' => 'Measured value for Sensor 5',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_six' => array(
        'title' => 'Sensor Six',
        'help' => 'Measured value for Sensor 6',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_seven' => array(
        'title' => 'Sensor Seven',
        'help' => 'Measured value for Sensor 7',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_eight' => array(
        'title' => 'Sensor Eight',
        'help' => 'Measured value for Sensor 8',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_nine' => array(
        'title' => 'Sensor Nine',
        'help' => 'Measured value for Sensor 9',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
      'sensor_ten' => array(
        'title' => 'Sensor Ten',
        'help' => 'Measured value for Sensor 10',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
      ),
    );
    $data['wsnplatform_sensor'] = array(
      'table' => array(
        'base' => array(
          'field' => 'sensor_nid',
          'title' => 'WSN Platform Sensor',
          'help' => 'Sensor Schema for WSN Platform',
        ),
        'group' => 'WSN Platform Sensor',
        'join' => array(
          'wsnplatform_nodeentity' => array(
            'left_field' => 'nodeentity_nid',
            'field' => 'nodeentity_nid',
           ),
          'wsnplatform_sensor_model' => array(
            'left_field' => 'model_nid',
            'field' => 'model_nid',
           ),
           'wsnplatform_notification' => array(
            'left_field' => 'notification_id',
            'field' => 'notification_id',
           ),
        ),
        
      ),
      'sensor_nid' => array(
        'title' => 'Sensor Nid',
        'help' => 'Sensor ID',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
           'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'sensor_title' => array(
        'title' => 'Sensor Title',
        'help' => 'Sensor Title',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
           'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'nodeentity_nid' => array(
        'title' => 'Nodeentity Nid',
        'help' => 'Mote Unit This Sensor Belong To',
        'relationship' => array(
          'label' => t('Nodeentity'),
          'base' => 'wsnplatform_nodeentity',
          'base field' => 'nodeentity_nid',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'model_nid' => array(
        'title' => 'Model Nid',
        'help' => 'This Sensor Model',
        'relationship' => array(
          'label' => t('Model NID'),
          'base' => 'wsnplatform_sensor_model',
          'base field' => 'model_nid',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'order_number' => array(
        'title' => 'Order Number',
        'help' => 'Order of Sensor in the Mote Unit',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'low_threshold' => array(
        'title' => 'Low Threshold Level',
        'help' => 'Low Threshold Level',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'high_threshold' => array(
        'title' => 'High Threshold Level',
        'help' => 'High Threshold Level',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'notification_id' => array(
        'title' => 'Notification Id',
        'help' => 'TODO: please describe this field!',
        'relationship' => array(
          'label' => t('Notification ID'),
          'base' => 'wsnplatform_notification',
          'base field' => 'notification_id',
        ),
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
    );
    $data['wsnplatform_sensor_model'] = array(
      'table' => array(
        'base' => array(
          'field' => 'model_nid',
          'title' => 'WSN Platform Sensor Model',
          'help' => 'Sensor Model Schema for WSN Platform',
        ),
        'group' => 'WSN Platform Sensor Model',
      ),
      'model_nid' => array(
        'title' => 'Model Nid',
        'help' => 'Model NID',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'model_title' => array(
        'title' => 'Model Title',
        'help' => 'Model Title',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
          'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'scalefactor' => array(
        'title' => 'Scalefactor',
        'help' => 'Scale Factor',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
          'filter' => array(
            'handler' => 'views_handler_filter_numeric',
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_numeric',
            ),
      ),
      'unit' => array(
        'title' => 'Unit',
        'help' => 'Unit of Measurement',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'callibration_a0' => array(
        'title' => 'Callibration A0',
        'help' => 'Callibration Polynomial 0',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
          'filter' => array(
            'handler' => 'views_handler_filter_numeric',
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_numeric',
            ),
      ),
      'callibration_a1' => array(
        'title' => 'Callibration A1',
        'help' => 'Callibration Polynomial 1',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
           'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
          'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'callibration_a2' => array(
        'title' => 'Callibration A2',
        'help' => 'Callibration Polynomial 2',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'operating_max' => array(
        'title' => 'Operating Max',
        'help' => 'Sensor Observation Max Value',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
           'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort_numeric',
          ),
      ),
      'operating_min' => array(
        'title' => 'Operating Min',
        'help' => 'Sensor Observation Min Value',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
           'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
           'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'datasheet' => array(
        'title' => 'Datasheet',
        'help' => 'Datasheet Link for further details',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
           'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
    );
    $data['wsnplatform_notification'] = array(
      'table' => array(
        'base' => array(
          'field' => 'notification_id',
          'title' => 'WSN Platform Notification',
          'help' => 'TODO: please describe this table!',
        ),
        'group' => 'WSN Platform Notification',
      ),
      'notification_id' => array(
        'title' => 'Notification Id',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
          'filter' => array(
            'handler' => 'views_handler_filter_numeric',
          ),
          'sort' => array(
            'handler' => 'views_handler_sort_numeric',
            ),
      ),
      'notification_message' => array(
        'title' => 'Notification Message',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'notification_receiver' => array(
        'title' => 'Notification Receiver',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
          'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'notification_condition' => array(
        'title' => 'Notification Condition',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
    );
    $data['wsnplatform_attribute'] = array(
      'table' => array(
        'base' => array(
          'field' => 'attribute_nid',
          'title' => 'WSN Platform Attribute',
          'help' => 'Attribute List for Dropdown List - METHOD',
        ),
        'group' => 'WSN Platform Attribute',
      ),
      'attribute_nid' => array(
        'title' => 'Attribute Nid',
        'help' => 'Attribute NID',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort_numeric',
        ), 
      ),
      'domain' => array(
        'title' => 'Domain',
        'help' => 'List Domain',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'akey' => array(
        'title' => 'Akey',
        'help' => 'List Key',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'avalue' => array(
        'title' => 'Avalue',
        'help' => 'List Value',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'isactive' => array(
        'title' => 'Isactive',
        'help' => 'Active Set',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort_numeric',
        ),
      ),
    );
  
    $data['wsnplatform_datacompression'] = array(
      'table' => array(
        'base' => array(
          'field' => 'datacompression_id',
          'title' => 'WSN Platform Datacompression',
          'help' => 'TODO: please describe this table!',
        ),
        'group' => 'WSN Platform Datacompression',
      ),
      'datacompression_id' => array(
        'title' => 'Datacompression Id',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_numeric',
        ),
      ),
      'datacompression_title' => array(
        'title' => 'Datacompression Title',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'sensor_sensor_delimiter' => array(
        'title' => 'Sensor Sensor Delimiter',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'measurand_set_delimiter' => array(
        'title' => 'Measurand Set Delimiter',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'details' => array(
        'title' => 'Details',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
          ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
    );
    $data['wsnplatform_plant'] = array(
      'table' => array(
        'base' => array(
          'field' => 'plant_id',
          'title' => 'WSN Platform Plant',
          'help' => 'TODO: please describe this table!',
        ),
        'group' => 'WSN Platform Plant',
      ),
      'plant_id' => array(
        'title' => 'Plant ID',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field_numeric',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_numeric',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_numeric',
         ),
      ),
      'plant_type' => array(
        'title' => 'Plant Type',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
      'plant_startcycle' => array(
        'title' => 'Plant Startcycle',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field_date',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_date',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort_date',
         ),
      ),
      'plant_growthstage' => array(
        'title' => 'Plant Growthstage',
        'help' => 'TODO: please describe this field!',
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => TRUE,
         ),
         'filter' => array(
            'handler' => 'views_handler_filter_string',
         ),
         'sort' => array(
            'handler' => 'views_handler_sort',
         ),
        'argument' => array(
          'handler' => 'views_handler_argument_string',
        ),
      ),
    );


  return $data;
}
