<?php
/**
 * @file
 * Functions to expose WSN Observations module data to the Views module.
 */

/**
 * Implements hook_views_data().
 */
function WSNobservations_views_data() {
  $data['WSNobservations']['table']['group']  = 'WSN Observations';
  $data['WSNobservations']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );

//  $data['WSNobservations']['stepno'] = array(
//    'title' => t('Step number'),
//    'help' => t('WSN Observations Step Number'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_string',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_string',
//    ),
//  );

  $data['WSNobservations']['sites_nid'] = array(
    'title' => t('sites'),
    'help' => t('Observations -> sites'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Observations -> Sites'),
    ),
  );

  $data['WSNobservations']['sites_title'] = array(
    'title' => t('sites'),
    'help' => t('WSN Observations Sites (title only)'),
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

  $data['WSNobservations']['nodes_nid'] = array(
    'title' => t('Nodes'),
    'help' => t('Observations -> Nodes'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Observations -> Nodes'),
    ),
  );

  $data['WSNobservations']['nodes_title'] = array(
    'title' => t('Nodes'),
    'help' => t('WSN Observations Nodes (title only)'),
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

  $data['WSNobservations']['sensors_nid'] = array(
    'title' => t('Sensors'),
    'help' => t('Observations -> Sensors'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Observations -> Sensors'),
    ),
  );

  $data['WSNobservations']['sensors_title'] = array(
    'title' => t('Sensors'),
    'help' => t('WSN Observations Sensors (title only)'),
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

//  $data['WSNobservations']['parent_nid'] = array(
//    'title' => t('Parent Observations'),
//    'help' => t('Observations -> Parent Observations'),
//    'relationship' => array(
//      'base' => 'node',
//      'base field' => 'nid',
//      'handler' => 'views_handler_relationship',
//      'label' => t('Observations -> Parent Observations'),
//    ),
//  );
//
//  $data['WSNobservations']['weight'] = array(
//    'title' => t('Weight'),
//    'help' => t('WSN Observations Weight'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );

  $data['WSNobservations']['observationCategory'] = array(
    'title' => t('Category'),
    'help' => t('WSN Observation Category'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Observation Category',
      'icon' => 'status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Observation Category',
    ),
  );

//  $data['WSNobservations']['Observationscategory'] = array(
//    'title' => t('Category'),
//    'help' => t('WSN Observations Category'),
//    'field' => array(
//      'click sortable' => TRUE,
//      'handler' => 'WSN_handler_field_attributes_domain',
//      'domain' => 'Observations Category',
//      'icon' => 'category',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'WSN_handler_filter_attributes_domain',
//      'domain' => 'Observations Category',
//    ),
//  );

  $data['WSNobservations']['observationError'] = array(
    'title' => t('Error'),
    'help' => t('WSN Observation Error'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'WSN_handler_field_attributes_domain',
      'domain' => 'Observation Error',
      'icon' => 'error',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'WSN_handler_filter_attributes_domain',
      'domain' => 'Observation Error',
    ),
  );

//  $data['WSNobservations']['pricemode'] = array(
//    'title' => t('Price mode'),
//    'help' => t('WSN Observations Price Mode'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_string',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_string',
//    ),
//  );
//
//  $data['WSNobservations']['price'] = array(
//    'title' => t('Price'),
//    'help' => t('WSN Observations Price'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );
//
//  $data['WSNobservations']['currency'] = array(
//    'title' => t('Currency'),
//    'help' => t('WSN Observations Currency'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_string',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_string',
//    ),
//  );

  $data['WSNobservations']['datetime'] = array(
    'title' => t('Date Time'),
    'help' => t('WSN Observations Date Time'),
    'field' => array(
      'click sortable' => TRUE,
      'handler' => 'views_handler_field_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['WSNobservations']['value'] = array(
    'title' => t('Value'),
    'help' => t('WSN Observations Value'),
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

//  $data['WSNobservations']['dateend'] = array(
//    'title' => t('Date end'),
//    'help' => t('WSN Observations Date End'),
//    'field' => array(
//      'click sortable' => TRUE,
//      'handler' => 'views_handler_field_date',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort_date',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_date',
//    ),
//  );
//
//  $data['WSNobservations']['durationunit'] = array(
//    'title' => t('Duration unit'),
//    'help' => t('WSN Observations Duration Unit'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_string',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_string',
//    ),
//  );
//
//  $data['WSNobservations']['duration'] = array(
//    'title' => t('Duration'),
//    'help' => t('WSN Observations Duration'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_numeric',
//    ),
//  );
//
//  $data['WSNobservations']['assigned_nid'] = array(
//    'title' => t('Assigned'),
//    'help' => t('Observations -> Assigned'),
//    'relationship' => array(
//      'base' => 'node',
//      'base field' => 'nid',
//      'handler' => 'views_handler_relationship',
//      'label' => t('Observations -> Assigned'),
//    ),
//  );
//
//  $data['WSNobservations']['assigned_title'] = array(
//    'title' => t('Assigned'),
//    'help' => t('WSN Observations Assigned (title only)'),
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_string',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_string',
//    ),
//  );
//
//  $data['WSNobservations']['billable'] = array(
//    'title' => t('Observations billable'),
//    'help' => 'WSN Observations Billable',
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//  );
//
//  $data['WSNobservations']['billed'] = array(
//    'title' => t('Observations billed'),
//    'help' => 'WSN Observations Billed',
//    'field' => array(
//      'click sortable' => TRUE,
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'filter' => array(
//      'handler' => 'views_handler_filter_numeric',
//    ),
//  );

  $data['WSNobservations']['operation'] = array(
    'field' => array(
      'title' => t('Edit/Delete link'),
      'help' => t('Provide a simple link to edit and delete the node.'),
      'handler' => 'WSN_handler_field_operation',
      'type' => 'WSNobservations',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function WSNobservations_views_handlers() {
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
 * Implements hook_date_api_fields().
 */
function WSNobservations_date_api_fields($field) {
  $values = array(
    'sql_type' => DATE_UNIX,
    'tz_handling' => 'site',
    'timezone_field' => '',
    'offset_field' => '',
    'related_fields' => array(),
    'granularity' => array('year', 'month', 'day', 'hour', 'minute', 'second'),
  );

  switch ($field) {
    case 'WSNobservations.datetime':
    //case 'WSNobservations.dateend':
      return $values;
  }

}

/**
 * Implement hook_date_api_tables().
 */
function WSNobservations_date_api_tables() {
  return array('WSNobservations');
}
