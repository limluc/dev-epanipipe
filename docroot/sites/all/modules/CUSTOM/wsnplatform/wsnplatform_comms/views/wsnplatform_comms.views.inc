<?php
/**
 * @file
 * WSN Platform Communication Log: views
 *
 * @package wsnplatform
 * @subpackage wsnplatform_comms
 */
 
/**
 * Implement hook_views_data().
 */
function wsnplatform_comms_views_data() {
  $data = array();
  $data['wsnplatform_comms_log'] = array(
    'table' => array(
      'base' => array(
        'field' => 'id',
        'title' => 'WSN Platform Comms Log',
        'help' => 'WSN Platform Management Log for Data Streaming.',
      ),
      'group' => 'WSN Platform Comms Log',
      'join' => array(
          'wsnplatform_nodeentity' => array(
            'left_field' => 'input_id',
            'field' => 'id',
           ),
      ),
    ),
    'id' => array(
      'title' => 'Id',
      'help' => 'The primary identifier.',
       'relationship' => array(
          'label' => t('Node Identifier'),
          'base' => 'wsnplatform_nodeentity',
          'base field' => 'input_id',
        ),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric)',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),  
    ),
    'reference' => array(
      'title' => 'Reference',
      'help' => 'Reference Code of Message.',
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
    'message_status' => array(
      'title' => 'Message Status',
      'help' => '0 = Okay, 1 = Error.',
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
    'data_type' => array(
      'title' => 'Data Type',
      'help' => 'Data type based on identifier.',
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
    'number' => array(
      'title' => 'Number',
      'help' => 'Node Sender Number.',
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
    'message' => array(
      'title' => 'Message',
      'help' => 'Message text.',
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
    'created_datetime' => array(
      'title' => 'Created Datetime',
      'help' => 'The creation timestamp.',
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),    
    ),
    'post_message' => array(
      'title' => 'Post Message',
      'help' => 'Post processed data.',
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
  );
  return $data;
}
