<?php
/**
 * @file
 * Functions to expose WSN Node data to the views module
 */

/**
 * Implements hook_views_data().
 */
function WSNnodes_views_data() {
  $data['WSNnodes']['table']['group']  = 'WSN Nodes';
  $data['WSNnodes']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

  $data['WSNnodes']['sites_nid'] = array(
    'title' => t('sites'),
    'help' => t('Node -> sites'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node -> Sites'),
    ),
  );

  $data['WSNnodes']['sites_title'] = array(
    'title' => t('sites'),
    'help' => t('WSN Node Sites (title only)'),
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
  $data['WSNnodes']['latitude'] = array(
    'title' => t('Latidude'),
    'help' => t('Latitude'),
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
    $data['WSNnodes']['longitude'] = array(
    'title' => t('Longitude'),
    'help' => t('Longitude)'),
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
  $data['WSNnodes']['nodeStatus'] = array(
    'title' => t('Node Status'),
    'help' => t('WSN Node Status'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Node Status',
      'icon' => 'nodeStatus',
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Node Status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['WSNnodes']['nodeCategory'] = array(
    'title' => t('Node Category'),
    'help' => t('WSN Node Category'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Node Category',
      'icon' => 'nodeCategory',
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Node Category',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['WSNnodes']['nodeError'] = array(
    'title' => t('nodeError'),
    'help' => t('WSN Node Error'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Node Error',
      'icon' => 'nodeError'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Node Error',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['WSNnodes']['wsnTopic'] = array(
    'title' => t('WSN Topic'),
    'help' => t('WSN Node Topic'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'WSN Topic',
      'icon' => 'wsnTopic'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'WSN Topic',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['WSNnodes']['dataInputMethod'] = array(
    'title' => t('Data Input Method'),
    'help' => t('Data Input Method'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Data Input Method',
      'icon' => 'dataInputMethod'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'dataInputMethod',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['WSNnodes']['dataCompressionTech'] = array(
    'title' => t('Data Compression Technique'),
    'help' => t('Data Compression Technique'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Data Compression Technique',
      'icon' => 'dataCompressionTech'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'dataCompressionTech',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['WSNnodes']['inputIdentifier'] = array(
    'title' => t('Input Identifier'),
    'help' => t('Input Identifier'),
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

  $data['WSNnodes']['readNumOccurence'] = array(
    'title' => t('No. of Reading Occurence'),
    'help' => t('No. of Reading Occurence'),
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

  $data['WSNnodes']['numSensorUnit'] = array(
    'title' => t('No. of Sensor Unit'),
    'help' => t('No. of Sensor Unit'),
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
  
  $data['WSNnodes']['timeInterval'] = array(
    'title' => t('Time Interval'),
    'help' => t('Time Interval'),
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
  $data['WSNnodes']['occOrder'] = array(
    'title' => t('Order Occurence'),
    'help' => t('Order Occurence'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Order Occurence',
      'icon' => 'occOrder'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Order Occurence',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['WSNnodes']['sensorDelimiter'] = array(
    'title' => t('Sensor Delimiter'),
    'help' => t('Sensor Delimiter'),
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
  $data['WSNnodes']['dataDelimiter'] = array(
    'title' => t('Data Delimiter'),
    'help' => t('Data Delimiter'),
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
  
  $data['WSNnodes']['notificationE'] = array(
    'title' => t('Notification Enable'),
    'help' => t('Notification Enable'),
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
  
  $data['WSNnodes']['notiRecurrence'] = array(
    'title' => t('Notification Recurrence'),
    'help' => t('Notification Recurrence'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Recurrence',
      'icon' => 'notiRecurrence'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Recurrence',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['WSNnodes']['notiValue'] = array(
    'title' => t('Notification Value'),
    'help' => t('Notification Value'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Recurrence Day',
      'icon' => 'notiValue'
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Recurrence Day',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  $data['WSNnodes']['message'] = array(
    'title' => t('Message'),
    'help' => t('Message'),
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

  $data['WSNnodes']['receiverNum'] = array(
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
  
  $data['WSNnodes']['operation'] = array(
    'field' => array(
      'title' => t('Edit/Delete link'),
      'help' => t('Provide a simple link to edit and delete the node.'),
      'handler' => 'WSN_handler_field_operation',
      'type' => 'WSNnodes',
    ),
  );
  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function WSNnodes_views_handlers() {
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

/**
 * Implement hook_date_api_tables().
 */
function WSNnodes_date_api_tables() {
  return array('WSNnodes');
}
