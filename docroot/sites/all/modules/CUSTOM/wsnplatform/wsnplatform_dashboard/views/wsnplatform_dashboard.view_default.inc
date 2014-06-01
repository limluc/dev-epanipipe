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

    $view = new view();
    $view->name = 'wsn_platform_dashboard';
    $view->description = 'WSN Observation Dashboard';
    $view->tag = 'WSN Platform';
    $view->base_table = 'wsnplatform_observation';
    $view->human_name = 'WSN Platform Dashboard';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
    
    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'WSN Platform Chart';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '100';
    $handler->display->display_options['pager']['options']['offset'] = '0';
    $handler->display->display_options['pager']['options']['id'] = '0';
    $handler->display->display_options['pager']['options']['quantity'] = '9';
    $handler->display->display_options['style_plugin'] = 'visualization';
    $handler->display->display_options['style_options']['fields'] = array(
      'moteunit_nid' => array(
        'enabled' => 0,
      ),
      'observation_type' => array(
        'enabled' => 0,
      ),
      'timestamp' => array(
        'enabled' => 0,
        'sort' => '0',
      ),
      'sensor_one' => array(
        'enabled' => 1,
      ),
      'sensor_two' => array(
        'enabled' => 1,
      ),
      'sensor_three' => array(
        'enabled' => 1,
      ),
      'sensor_four' => array(
        'enabled' => 1,
      ),
      'sensor_five' => array(
        'enabled' => 1,
      ),
      'sensor_six' => array(
        'enabled' => 1,
      ),
      'sensor_seven' => array(
        'enabled' => 1,
      ),
      'sensor_eight' => array(
        'enabled' => 1,
      ),
    );
    $handler->display->display_options['style_options']['yAxis'] = array(
      'title' => '',
    );
    $handler->display->display_options['style_options']['xAxis'] = array(
      'labelField' => 'timestamp',
      'invert' => 0,
    );
    $handler->display->display_options['row_plugin'] = 'fields';
    /* Field: Wsnplatform Observation: Observation Nid */
    $handler->display->display_options['fields']['observation_nid']['id'] = 'observation_nid';
    $handler->display->display_options['fields']['observation_nid']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['observation_nid']['field'] = 'observation_nid';
    /* Field: Wsnplatform Observation: Moteunit Nid */
    $handler->display->display_options['fields']['moteunit_nid']['id'] = 'moteunit_nid';
    $handler->display->display_options['fields']['moteunit_nid']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['moteunit_nid']['field'] = 'moteunit_nid';
    /* Field: Wsnplatform Observation: Observation Type */
    $handler->display->display_options['fields']['observation_type']['id'] = 'observation_type';
    $handler->display->display_options['fields']['observation_type']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['observation_type']['field'] = 'observation_type';
    /* Field: Wsnplatform Observation: Sensor Eight */
    $handler->display->display_options['fields']['sensor_eight']['id'] = 'sensor_eight';
    $handler->display->display_options['fields']['sensor_eight']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_eight']['field'] = 'sensor_eight';
    /* Field: Wsnplatform Observation: Sensor Five */
    $handler->display->display_options['fields']['sensor_five']['id'] = 'sensor_five';
    $handler->display->display_options['fields']['sensor_five']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_five']['field'] = 'sensor_five';
    /* Field: Wsnplatform Observation: Sensor Four */
    $handler->display->display_options['fields']['sensor_four']['id'] = 'sensor_four';
    $handler->display->display_options['fields']['sensor_four']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_four']['field'] = 'sensor_four';
    /* Field: Wsnplatform Observation: Sensor One */
    $handler->display->display_options['fields']['sensor_one']['id'] = 'sensor_one';
    $handler->display->display_options['fields']['sensor_one']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_one']['field'] = 'sensor_one';
    /* Field: Wsnplatform Observation: Sensor Seven */
    $handler->display->display_options['fields']['sensor_seven']['id'] = 'sensor_seven';
    $handler->display->display_options['fields']['sensor_seven']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_seven']['field'] = 'sensor_seven';
    /* Field: Wsnplatform Observation: Sensor Six */
    $handler->display->display_options['fields']['sensor_six']['id'] = 'sensor_six';
    $handler->display->display_options['fields']['sensor_six']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_six']['field'] = 'sensor_six';
    /* Field: Wsnplatform Observation: Sensor Three */
    $handler->display->display_options['fields']['sensor_three']['id'] = 'sensor_three';
    $handler->display->display_options['fields']['sensor_three']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_three']['field'] = 'sensor_three';
    /* Field: Wsnplatform Observation: Sensor Two */
    $handler->display->display_options['fields']['sensor_two']['id'] = 'sensor_two';
    $handler->display->display_options['fields']['sensor_two']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_two']['field'] = 'sensor_two';
    /* Field: Wsnplatform Observation: Timestamp */
    $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
    $handler->display->display_options['fields']['timestamp']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
    $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
    $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
    /* Sort criterion: Wsnplatform Observation: Timestamp */
    $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
    $handler->display->display_options['sorts']['timestamp']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
    /* Filter criterion: Wsnplatform Observation: Timestamp */
    $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
    $handler->display->display_options['filters']['timestamp']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
    $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
    $handler->display->display_options['filters']['timestamp']['group'] = 1;
    $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
    $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
    $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Timestamp';
    $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
    $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
    $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
      2 => '2',
      1 => 0,
      3 => 0,
    );
    
    /* Display: Main Chart */
    $handler = $view->new_display('page', 'Main Chart', 'page');
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Wsnplatform Observation: Moteunit Nid */
    $handler->display->display_options['fields']['moteunit_nid']['id'] = 'moteunit_nid';
    $handler->display->display_options['fields']['moteunit_nid']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['moteunit_nid']['field'] = 'moteunit_nid';
    $handler->display->display_options['fields']['moteunit_nid']['exclude'] = TRUE;
    /* Field: Wsnplatform Observation: Observation Type */
    $handler->display->display_options['fields']['observation_type']['id'] = 'observation_type';
    $handler->display->display_options['fields']['observation_type']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['observation_type']['field'] = 'observation_type';
    $handler->display->display_options['fields']['observation_type']['exclude'] = TRUE;
    /* Field: Wsnplatform Observation: Timestamp */
    $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
    $handler->display->display_options['fields']['timestamp']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
    $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
    $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
    /* Field: Wsnplatform Observation: Sensor One */
    $handler->display->display_options['fields']['sensor_one']['id'] = 'sensor_one';
    $handler->display->display_options['fields']['sensor_one']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_one']['field'] = 'sensor_one';
    /* Field: Wsnplatform Observation: Sensor Two */
    $handler->display->display_options['fields']['sensor_two']['id'] = 'sensor_two';
    $handler->display->display_options['fields']['sensor_two']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_two']['field'] = 'sensor_two';
    /* Field: Wsnplatform Observation: Sensor Three */
    $handler->display->display_options['fields']['sensor_three']['id'] = 'sensor_three';
    $handler->display->display_options['fields']['sensor_three']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_three']['field'] = 'sensor_three';
    /* Field: Wsnplatform Observation: Sensor Four */
    $handler->display->display_options['fields']['sensor_four']['id'] = 'sensor_four';
    $handler->display->display_options['fields']['sensor_four']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_four']['field'] = 'sensor_four';
    /* Field: Wsnplatform Observation: Sensor Five */
    $handler->display->display_options['fields']['sensor_five']['id'] = 'sensor_five';
    $handler->display->display_options['fields']['sensor_five']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_five']['field'] = 'sensor_five';
    /* Field: Wsnplatform Observation: Sensor Six */
    $handler->display->display_options['fields']['sensor_six']['id'] = 'sensor_six';
    $handler->display->display_options['fields']['sensor_six']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_six']['field'] = 'sensor_six';
    /* Field: Wsnplatform Observation: Sensor Seven */
    $handler->display->display_options['fields']['sensor_seven']['id'] = 'sensor_seven';
    $handler->display->display_options['fields']['sensor_seven']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_seven']['field'] = 'sensor_seven';
    /* Field: Wsnplatform Observation: Sensor Eight */
    $handler->display->display_options['fields']['sensor_eight']['id'] = 'sensor_eight';
    $handler->display->display_options['fields']['sensor_eight']['table'] = 'wsnplatform_observation';
    $handler->display->display_options['fields']['sensor_eight']['field'] = 'sensor_eight';
    $handler->display->display_options['path'] = 'wsnplatform/dashboard';
    
    /* Display: WSN Platform Table */
    $handler = $view->new_display('attachment', 'WSN Platform Table', 'attachment_1');
    $handler->display->display_options['defaults']['title'] = FALSE;
    $handler->display->display_options['title'] = 'WSN Platform Table';
    $handler->display->display_options['display_description'] = 'WSN Platform Table View';
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['defaults']['style_plugin'] = FALSE;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'observation_nid' => 'observation_nid',
      'moteunit_nid' => 'moteunit_nid',
      'observation_type' => 'observation_type',
      'sensor_eight' => 'sensor_eight',
      'sensor_five' => 'sensor_five',
      'sensor_four' => 'sensor_four',
      'sensor_one' => 'sensor_one',
      'sensor_seven' => 'sensor_seven',
      'sensor_six' => 'sensor_six',
      'sensor_three' => 'sensor_three',
      'sensor_two' => 'sensor_two',
      'timestamp' => 'timestamp',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'observation_nid' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'moteunit_nid' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'observation_type' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_eight' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_five' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_four' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_one' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_seven' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_six' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_three' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'sensor_two' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'timestamp' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    $handler->display->display_options['defaults']['style_options'] = FALSE;
    $handler->display->display_options['defaults']['row_plugin'] = FALSE;
    $handler->display->display_options['defaults']['row_options'] = FALSE;
    $handler->display->display_options['displays'] = array(
      'page' => 'page',
      'default' => 0,
      'page_1' => 0,
    );
  
  
    $views[$view->name] = $view;
    return $views;
}