<?php
/**
 * @file
 * Functions to expose WSN sensors data to the views module
 */

/**
 * Implements hook_views_data().
 */
function WSNsensors_views_data() {
  $data['WSNsensors']['table']['group']  = 'WSN Sensors';
  $data['WSNsensors']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  $data['WSNsensors']['sites_nid'] = array(
    'title' => t('Sites'),
    'help' => t('Sensors -> Sites'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Sensors -> Sites'),
    ),
  );

  $data['WSNsensors']['sites_title'] = array(
    'title' => t('Sites'),
    'help' => t('WSN Sensor Sites (title only)'),
    'field' => array(
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
  );
  
  $data['WSNsensors']['nodes_nid'] = array(
    'title' => t('Nodes'),
    'help' => t('Sensors -> Nodes'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Sensors -> Nodes'),
    ),
  );

  $data['WSNsensors']['nodes_title'] = array(
    'title' => t('Nodes'),
    'help' => t('WSN Sensor Nodes (title only)'),
    'field' => array(
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
  );

  $data['WSNsensors']['sensorStatus'] = array(
    'title' => t('Sensor Status'),
    'help' => t('WSN Sensor Status'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Sensor Status',
      'icon' => 'sensorStatus',
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Sensor Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['WSNsensors']['sensorCategory'] = array(
    'title' => t('Sensor Category'),
    'help' => t('WSN Sensor Category'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Sensor Category',
      'icon' => 'sensorCategory',
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Sensor Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

$data['WSNsensors']['sensorError'] = array(
    'title' => t('Sensor Error'),
    'help' => t('WSN Sensor Error'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Sensor Error',
      'icon' => 'sensorError'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Sensor Error',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['WSNsensors']['sensorModel'] = array(
    'title' => t('Sensor Model'),
    'help' => t('Sensor Model'),
    'field' => array(
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
  );
  
  $data['WSNsensors']['forecastE'] = array(
    'title' => t('Forecast Enable'),
    'help' => t('Forecast Enable'),
    'field' => array(
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
  );
  
$data['WSNsensors']['unit'] = array(
    'title' => t('Measurand Unit'),
    'help' => t('Unit'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Unit',
      'icon' => 'unit'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Unit',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

$data['WSNsensors']['medium'] = array(
    'title' => t('medium'),
    'help' => t('medium'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Medium',
      'icon' => 'medium'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Medium',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

//
  $data['WSNsensors']['minOpRa'] = array(
    'title' => t('Minimum Operating Range'),
    'help' => t('Minimum Operating Range of the Sensor'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['WSNsensors']['maxOpRa'] = array(
    'title' => t('Maximum Operating Range'),
    'help' => t('Maximum Operating Range of the Sensor'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
    $data['WSNsensors']['polya0'] = array(
    'title' => t('Polynomial a0'),
    'help' => t('Polynomrial a0 or Offset'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
    $data['WSNsensors']['polya1'] = array(
    'title' => t('Polynomial a1'),
    'help' => t('Polynomrial a1 or Gradietn'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
    
    $data['WSNsensors']['polya2'] = array(
    'title' => t('Polynomial a2'),
    'help' => t('Polynomrial a2 x^2'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
    
   $data['WSNsensors']['notificationE'] = array(
    'title' => t('Notification Enable'),
    'help' => t('Enable Notification'),
    'field' => array(
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
  );
//
  $data['WSNsensors']['opCondition'] = array(
    'title' => t('Operation Condition'),
    'help' => t('Operation Condition'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Operation Condition',
      'icon' => 'opCondition'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Operation Condition',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['WSNsensors']['criteria'] = array(
    'title' => t('Criteria Value'),
    'help' => t('Criteria Value'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  
  $data['WSNsensors']['message'] = array(
    'title' => t('Message'),
    'help' => t('Message to be sent'),
    'field' => array(
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
  );
  
    $data['WSNsensors']['receiverNum'] = array(
    'title' => t('Receiver Number'),
    'help' => t('Receiver Number'),
    'field' => array(
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
  );
    $data['WSNsensors']['orderBy'] = array(
    'title' => t('Order of Sensors'),
    'help' => t('Order of sensor in node'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
    
    $data['WSNsensors']['iCode'] = array(
    'title' => t('Identifier Code'),
    'help' => t('Identifier Code'),
    'field' => array(
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
  );
    
  $data['WSNsensors']['operation'] = array(
    'field' => array(
      'title' => t('Edit/Delete link'),
      'help' => t('Provide a simple link to edit and delete the node.'),
      'handler' => 'WSN_handler_field_operation',
      'type' => 'WSNsensors',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function WSNsensors_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'WSN'),
    ),
    'handlers' => array(
      'WSN_handler_field_attributes_domain' => array(
        'parent' => 'views_handler_field',
      ),
      'WSN_handler_filter_attributes_domain' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'WSN_handler_field_operation' => array(
        'parent' => 'views_handler_field_node_link',
        'path' => drupal_get_path('module', 'WSN'),
      ),
    ),
  );
}