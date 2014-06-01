<?php
/**
 * @file
 * WSN Platform Communication module: views
 *
 * @package wsnplatform
 * @subpackage wsnplatform_comms
 */

/**
 * Implement hook_views_default_views().
 */
function wsnplatform_comms_views_default_views() {
    $view = new view();
    $view->name = 'wsnplatform_comms_log';
    $view->description = 'WSN Platform Data Stream I/O';
    $view->tag = 'wsnplatform';
    $view->base_table = 'wsnplatform_comms_log';
    $view->human_name = 'WSN Platform Log';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
    
    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'WSN Platform Log';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'created_datetime' => 'created_datetime',
      'number' => 'number',
      'data_type' => 'data_type',
      'message' => 'message',
      'post_message' => 'post_message',
      'message_status' => 'message_status',
    );
    $handler->display->display_options['style_options']['default'] = 'created_datetime';
    $handler->display->display_options['style_options']['info'] = array(
      'created_datetime' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'number' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'data_type' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'message' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'post_message' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'message_status' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    /* Field: [wsnplatform_comms] Table wsnplatform_comms_log: Created Datetime */
    $handler->display->display_options['fields']['created_datetime']['id'] = 'created_datetime';
    $handler->display->display_options['fields']['created_datetime']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['fields']['created_datetime']['field'] = 'created_datetime';
   
    /* Field: [wsnplatform_comms] Table wsnplatform_comms_log: Number */
    $handler->display->display_options['fields']['number']['id'] = 'number';
    $handler->display->display_options['fields']['number']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['fields']['number']['field'] = 'number';
   
    /* Field: [wsnplatform_comms] Table wsnplatform_comms_log: Data Type */
    $handler->display->display_options['fields']['data_type']['id'] = 'data_type';
    $handler->display->display_options['fields']['data_type']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['fields']['data_type']['field'] = 'data_type';
   
    /* Field: [wsnplatform_comms] Table wsnplatform_comms_log: Message */
    $handler->display->display_options['fields']['message']['id'] = 'message';
    $handler->display->display_options['fields']['message']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['fields']['message']['field'] = 'message';
   
    /* Field: [wsnplatform_comms] Table wsnplatform_comms_log: Post Message */
    $handler->display->display_options['fields']['post_message']['id'] = 'post_message';
    $handler->display->display_options['fields']['post_message']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['fields']['post_message']['field'] = 'post_message';
   
    /* Field: [wsnplatform_comms] Table wsnplatform_comms_log: Message Status */
    $handler->display->display_options['fields']['message_status']['id'] = 'message_status';
    $handler->display->display_options['fields']['message_status']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['fields']['message_status']['field'] = 'message_status';
   
    /* Sort criterion: [wsnplatform_comms] Table wsnplatform_comms_log: Created Datetime */
    $handler->display->display_options['sorts']['created_datetime']['id'] = 'created_datetime';
    $handler->display->display_options['sorts']['created_datetime']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['sorts']['created_datetime']['field'] = 'created_datetime';
    $handler->display->display_options['sorts']['created_datetime']['exposed'] = FALSE;
    $handler->display->display_options['sorts']['created_datetime']['expose']['label'] = 'Created Datetime';
   
    /* Filter criterion: [wsnplatform_comms] Table wsnplatform_comms_log: Number */
    $handler->display->display_options['filters']['number']['id'] = 'number';
    $handler->display->display_options['filters']['number']['table'] = 'wsnplatform_comms_log';
    $handler->display->display_options['filters']['number']['field'] = 'number';
    $handler->display->display_options['filters']['number']['operator'] = 'contains';
    $handler->display->display_options['filters']['number']['exposed'] = TRUE;
    $handler->display->display_options['filters']['number']['expose']['operator_id'] = 'number_op';
    $handler->display->display_options['filters']['number']['expose']['label'] = 'Number';
    $handler->display->display_options['filters']['number']['expose']['operator'] = 'number_op';
    $handler->display->display_options['filters']['number']['expose']['identifier'] = 'number';
    $handler->display->display_options['filters']['number']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
    );
    
    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'wsnplatform/comms/log';

    $views[$view->name] = $view;
    return $views;
}
