<?php

/**
 * @file
 */

/**
 * Provides HTML markup for a WSNtimetracking list.
 */
//function theme_WSNsensors_list($variables) {
//  $header = $variables['header'];
//  $sensors = $variables['sensors'];
//
//  drupal_add_css(drupal_get_path('module', 'WSN') . '/WSN.css', 'module');
//
//  $rows = array();
//  foreach ($sensors as $key => $sensors) {
//    $rows[] = array(
//      WSN_icon('sensorCategory_' . $sensors->sensorCategory, WSN_attribute_value('Sensor Category', $sensors->sensorCategory)),
//      l($sensors->Nodes_title, 'node/' . $sensors->Nodes_nid),
//      l($sensors->title, 'node/' . $sensors->nid) . theme('mark', array('type' => node_mark($sensors->nid, $sensors->changed))),
//      WSN_icon('status_' . $sensors->sensorStatus, WSN_attribute_value('Sensor Status', $sensors->sensorStatus)),
//      WSN_icon('error_' . $sensors->sensorserror, WSN_attribute_value('Sensor Error', $sensors->sensorserror)),
//      //WSN_icon('priority_' . $sensors->sensorspriority, WSN_attribute_value('sensors priority', $sensors->sensorspriority)),
//      array(
//        'data' => WSN_icon_edit_node($sensors, $_GET) . '&nbsp;' . WSN_icon_delete_node($sensors, $_GET),
//        'class' => 'WSN_list_operations',
//      ),
//    );
//  }
//  return theme('table', array('header' => $header, 'rows' => $rows));
//}

/**
 * Provides HTML markup for a WSNsensors node view.
 */
function theme_WSNsensors_view($variables) {
  $node = $variables['node'];

  drupal_add_css(drupal_get_path('module', 'WSN') . '/WSN-node.css');

  $l_pos = 1; // Used to increase the link position number (see issue 814820)

  $node->content['links'] = array(
    '#prefix' => '<div class="WSNlinks"><dl>',
    '#suffix' => '</dl></div>',
    '#weight' => -25,
  );

//  $node->content['links']['expenses'] = theme('WSN_link', 'WSNsensors', 'WSNexpense', $node->nid, $l_pos++);
//  $node->content['links']['invoices'] = theme('WSN_link', 'WSNsensors', 'WSNinvoice', $node->nid, $l_pos++);
//  $node->content['links']['notes'] = theme('WSN_link', 'WSNsensors', 'WSNnote', $node->nid, $l_pos++);
//  $node->content['links']['tasks'] = theme('WSN_link', 'WSNsensors', 'WSNtask', $node->nid, $l_pos++);
//  $node->content['links']['tickets'] = theme('WSN_link', 'WSNsensors', 'WSNticket', $node->nid, $l_pos++);
//  $node->content['links']['timetrackings'] = theme('WSN_link', 'WSNsensors', 'WSNtimetracking', $node->nid, $l_pos++);

  // Code to create invoice auto_add link
//  if (module_exists('WSNinvoice')) {
//
//    $node->content['links']['auto_invoice'] = array(
//      '#prefix' => variable_get('WSN_icons_display', TRUE) ? '<dt id="WSNinvoices" class="WSNcomponent">' : '<dt class="WSNcomponent">',
//      '#suffix' => '</dt>',
//      '#value' => theme('WSNinvoice_autoadd_links', array('nid' => $node->nid, 'billable' => $node->billable, 'billed' => $node->billed)),
//      '#weight' => $l_pos++,
//    );
//  }


  $node->content['group1'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );
    
  $node->content['group1']['sites'] = array(
    '#prefix' => '<div class="sites">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sites'), 'value' => l($node->sites_title, 'node/' . $node->sites_nid))),
    '#weight' => 1,
  );
  
  $node->content['group1']['nodes'] = array(
    '#prefix' => '<div class="nodes">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Nodes'), 'value' => l($node->nodes_title, 'node/' . $node->nodes_nid))),
    '#weight' => 1,
  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

  $node->content['group2']['sensorCategory'] = array(
    '#prefix' => '<div class="sensorCategory">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sensor Category'), 'value' => check_plain(WSN_attribute_value('Sensor Category', $node->sensorCategory)))),
    '#weight' => 1,
  );

  $node->content['group2']['sensorStatus'] = array(
    '#prefix' => '<div class="sensorStatus">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sensor Status'), 'value' => check_plain(WSN_attribute_value('Sensor Status', $node->sensorStatus)))),
    '#weight' => 2,
  );

  $node->content['group2']['sensorError'] = array(
    '#prefix' => '<div class="sensorError">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sensor Error'), 'value' => check_plain(WSN_attribute_value('Sensor Error', $node->sensorError)))),
    '#weight' => 3,
  );
  $node->content['group2']['forecastE'] = array(
    '#prefix' => '<div class="forecastE">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Forecast Enable'), 'value' => check_plain($node->forecastE))),
    '#weight' => 3,
  );  
  $node->content['group3'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -18,
  );
  
  $node->content['group4']['sensorModel'] = array(
    '#prefix' => '<div class="sensorModel">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sensor Model'), 'value' => check_plain($node->sensorModel))),
    '#weight' => 1,
  );
  
  $node->content['group3']['unit'] = array(
    '#prefix' => '<div class="unit">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sensor Unit'), 'value' => check_plain(WSN_attribute_value('Unit', $node->unit)))),
    '#weight' => 1,
  );

  $node->content['group3']['medium'] = array(
    '#prefix' => '<div class="medium">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sense Medium'), 'value' => check_plain(WSN_attribute_value('Medium', $node->medium)))),
    '#weight' => 2,
  );

  $node->content['group4'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -17,
  );

  $node->content['group4']['minOpRa'] = array(
    '#prefix' => '<div class="minOpRa">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Minimum Operating Range'), 'value' => check_plain($node->minOpRa))),
    '#weight' => 1,
  );
  $node->content['group4']['maxOpRa'] = array(
    '#prefix' => '<div class="maxOpRa">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Maximum Operating Range'), 'value' => check_plain($node->maxOpRa))),
    '#weight' => 2,
  );
  $node->content['group4']['polya0'] = array(
    '#prefix' => '<div class="polya0">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Polynomial a0'), 'value' => check_plain($node->polya0))),
    '#weight' => 3,
  );
  $node->content['group4']['polya1'] = array(
    '#prefix' => '<div class="polya1">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Polynomial a1x'), 'value' => check_plain($node->polya1))),
    '#weight' => 4,
  );
  $node->content['group4']['polya2'] = array(
    '#prefix' => '<div class="polya2">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Polynomial a2x^2'), 'value' => check_plain($node->polya2))),
    '#weight' => 5,
  );
  $node->content['group5'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
  );
  $node->content['group5']['orderBy'] = array(
    '#prefix' => '<div class="oderBy">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('orderBy'), 'value' => check_plain($node->orderBy))),
    '#weight' => 1,
  );
  $node->content['group5']['iCode'] = array(
    '#prefix' => '<div class="iCode">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Identifier Code'), 'value' => check_plain($node->iCode))),
    '#weight' => 2,
  );
  
  $node->content['group6'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group6') : -15,
  );

  $node->content['group6']['notificationE'] = array(
    '#prefix' => '<div class="notificationE">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Notification Enable'), 'value' => check_plain($node->notificationE))),
    '#weight' => 1,
  );
  $node->content['group6']['opCondition'] = array(
    '#prefix' => '<div class="opCondition">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Operation Condition'), 'value' => check_plain(WSN_attribute_value('Operation Condition', $node->opCondition)))),
    '#weight' => 2,
  );
  $node->content['group6']['criteria'] = array(
    '#prefix' => '<div class="criteria">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Criteria'), 'value' => check_plain($node->criteria))),
    '#weight' => 3,
  );
  $node->content['group6']['message'] = array(
    '#prefix' => '<div class="message">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Message'), 'value' => check_plain($node->message))),
    '#weight' => 4,
  );
  $node->content['group6']['receiverNum'] = array(
    '#prefix' => '<div class="receiverNum">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('ReceiverNum'), 'value' => check_plain($node->receiverNum))),
    '#weight' => 5,
  );

  
  $body = field_get_items('node', $node, 'body');
  if ($body) {
    $node->content['body'] = array(
      '#prefix' => '<div class="WSNbody">',
      '#suffix' => '</div>',
      '#markup' => theme('WSN_view_item', array('label' => t('Description'), 'value' => $body[0]['safe_value'])),
      '#weight' => 4,
    );
  }

  return $node;
}
