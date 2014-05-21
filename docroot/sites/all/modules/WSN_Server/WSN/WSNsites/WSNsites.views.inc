<?php
/**
 * @file
 * Functions to expose WSN sites data to views
 */
function WSNsites_views_data() {
  $data['WSNsites']['table']['group']  = 'WSN Sites';
  $data['WSNsites']['table']['join'] = array(
    'node' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
  );
  
  $data['WSNsites']['iscustomer'] = array(
    'title' => t('Is customer'),
    'help' => t('WSN Sites Is Customer'),
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

//  $data['WSNsites']['isprovider'] = array(
//    'title' => t('Is provider'),
//    'help' => t('WSN Sites Is Provider'),
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

  $data['WSNsites']['isactive'] = array(
    'title' => t('Is active'),
    'help' => t('WSN Sites Is Active'),
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

  $data['WSNsites']['country'] = array(
    'title' => t('Country'),
    'help' => t('WSN Sites Country'),
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

  $data['WSNsites']['provstate'] = array(
    'title' => t('County'),
    'help' => t('County'),
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

  $data['WSNsites']['city'] = array(
    'title' => t('City'),
    'help' => t('WSN Sites City'),
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

  $data['WSNsites']['zip'] = array(
    'title' => t('Post Code'),
    'help' => t('WSN Post Code'),
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

  $data['WSNsites']['address'] = array(
    'title' => t('Address'),
    'help' => t('WSN Sites Address'),
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
  
  $data['WSNsites']['longitude'] = array(
    'title' => t('Longitude'),
    'help' => t('WSN Sites Longitude'),
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
  
    $data['WSNsites']['latitude'] = array(
    'title' => t('Latitude'),
    'help' => t('WSN Sites Latitude'),
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

    $data['WSNsites']['elevation_m'] = array(
    'title' => t('Elevation (m)'),
    'help' => t('WSN Sites Elevation'),
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
//  $data['WSNsites']['taxid'] = array(
//    'title' => t('Tax ID'),
//    'help' => t('WSN Sites Tax ID'),
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

//  $data['WSNsites']['www'] = array(
//    'title' => t('WWW'),
//    'help' => t('WSN Sites WWW'),
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

  $data['WSNsites']['contactid'] = array(
    'title' => t('Contact ID'),
    'help' => t('WSN Sites Contact'),
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

  $data['WSNsites']['phone'] = array(
    'title' => t('Phone'),
    'help' => t('WSN Sites Phone'),
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
  
  $data['WSNsites']['email'] = array(
    'title' => t('Email'),
    'help' => t('WSN Sites Email'),
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
  
  $data['WSNsites']['language'] = array(
    'title' => t('Language'),
    'help' => t('WSN Sites Language'),
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

//  $data['WSNsites']['currency'] = array(
//    'title' => t('Currency'),
//    'help' => t('WSN Sites Currency'),
//    'field' => array(
//      'handler' => 'WSN_handler_field_attributes_domain',
//      'domain' => 'Currency',
//      'click sortable' => TRUE,
//    ),
//    'filter' => array(
//      'handler' => 'WSN_handler_filter_attributes_domain',
//      'domain' => 'Currency',
//    ),
//    'sort' => array(
//      'handler' => 'views_handler_sort',
//    ),
//    'argument' => array(
//      'handler' => 'views_handler_argument_string',
//    ),
//  );

  $data['WSNsites']['operation'] = array(
    'field' => array(
      'title' => t('Edit/Delete link'),
      'help' => t('Provide a simple link to edit and delete the node.'),
      'handler' => 'WSN_handler_field_operation',
      'type' => 'WSNsites',
    ),
  );

  return $data;
}

/**
 * Implements WSNsites_views_handlers().
 */
function WSNsites_views_handlers() {
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
