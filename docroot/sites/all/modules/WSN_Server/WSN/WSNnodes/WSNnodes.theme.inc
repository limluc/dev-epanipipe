<?php

/**
 * @file
 */

/**
 * Provides HTML markup for a WSNnodes node view.
 */
function theme_WSNnodes_view($variables) {
  $node = $variables['node'];

  drupal_add_css(drupal_get_path('module', 'WSN') . '/WSN-node.css');

  $l_pos = 1; // Used to increase the link position number (see issue 814820)

  $node->content['links'] = array(
    '#prefix' => '<div class="WSNlinks"><dl>',
    '#suffix' => '</dl></div>',
    '#weight' => -25,
  );

  $node->content['links']['sensors'] = theme('WSN_link', 'WSNnodes', 'WSNsensors', $node->nid, $l_pos++);
  $node->content['links']['observations'] = theme('WSN_link', 'WSNnodes', 'WSNobservations', 'WSNsensors', $node->nid, $l_pos++);

  $node->content['group2'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -20,
  );

  $node->content['group2']['sites'] = array(
    '#prefix' => '<div class="sites">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Site'), 'value' => l($node->sites_title, 'node/' . $node->sites_nid))),
    '#weight' => 1,
  );

  $node->content['group3'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -19,
  );

  $node->content['group3']['wsnTopic'] = array(
    '#prefix' => '<div class="wsnTopic">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('WSN Topic'), 'value' => check_plain(WSN_attribute_value('WSN Topic', $node->wsnTopic)))),
    '#weight' => 1,
  );
  $node->content['group3']['latitude'] = array(
    '#prefix' => '<div class="latitude">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Latitude'), 'value' => check_plain($node->latitude))),
    '#weight' => 5,
  );
  $node->content['group3']['longitude'] = array(
    '#prefix' => '<div class="longitude">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Longitude'), 'value' => check_plain($node->longitude))),
    '#weight' => 6,
  );
  
  $node->content['group4'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -18,
  );

  $node->content['group4']['nodeCategory'] = array(
    '#prefix' => '<div class="nodeCategory">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Node Category'), 'value' => check_plain(WSN_attribute_value('Node Category', $node->nodeCategory)))),
    '#weight' => 1,
  );

  $node->content['group4']['nodeStatus'] = array(
    '#prefix' => '<div class="nodeStatus">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Node Status'), 'value' => check_plain(WSN_attribute_value('Node Status', $node->nodeStatus)))),
    '#weight' => 2,
  );

  $node->content['group4']['nodeError'] = array(
    '#prefix' => '<div class="nodeError">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Node Error'), 'value' => check_plain(WSN_attribute_value('Node Error', $node->nodeError)))),
    '#weight' => 3,
  );
  $node->content['group5'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -17,
  );

  $node->content['group5']['dataInputMethod'] = array(
    '#prefix' => '<div class="dataInputMethod">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Data Input Method'), 'value' => check_plain(WSN_attribute_value('Data Input Method', $node->dataInputMethod)))),
    '#weight' => 1,
  );

  $node->content['group5']['dataCompressionTech'] = array(
    '#prefix' => '<div class="dataCompressionTech">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Data Compression Technique'), 'value' => check_plain(WSN_attribute_value('Data Compression Technique', $node->dataCompressionTech)))),
    '#weight' => 2,
  );

  $node->content['group5']['inputIdentifier'] = array(
    '#prefix' => '<div class="inputIdentifier">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Input Identifier'), 'value' => check_plain($node->inputIdentifier))),
    '#weight' => 3,
  );
  $node->content['group5']['readNumOccurence'] = array(
    '#prefix' => '<div class="readNumOccurence">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Reading Occurence'), 'value' => check_plain($node->readNumOccurence))),
    '#weight' => 4,
  );
  $node->content['group5']['numSensorUnit'] = array(
    '#prefix' => '<div class="numSensorUnit">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('No. of Sensor Unit'), 'value' => check_plain($node->numSensorUnit))),
    '#weight' => 5,
  );
  $node->content['group5']['timeInterval'] = array(
    '#prefix' => '<div class="timeInterval">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Time Interval'), 'value' => check_plain($node->timeInterval))),
    '#weight' => 6,
  );
  $node->content['group5']['occOrder'] = array(
    '#prefix' => '<div class="occOrder">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Occurence Order'), 'value' => check_plain(WSN_attribute_value('Order Occurence', $node->occOrder)))),
    '#weight' => 7,
  );
  $node->content['group6'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group6') : -16,
  );
  $node->content['group6']['sensorDelimiter'] = array(
    '#prefix' => '<div class="sensorDelimiter">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sensor Delimiter'), 'value' => check_plain($node->sensorDelimiter))),
    '#weight' => 1,
  );
  $node->content['group6']['dataDelimiter'] = array(
    '#prefix' => '<div class="dataDelimiter">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Data Delimiter'), 'value' => check_plain($node->dataDelimiter))),
    '#weight' => 2,
  );
  
  $node->content['group7'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group7') : -15,
  );
  $node->content['group7']['notificationE'] = array(
    '#prefix' => '<div class="notificationE">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Notification Enable'), 'value' => check_plain($node->notificationE))),
    '#weight' => 0,
  );
  $node->content['group7']['notiRecurrence'] = array(
    '#prefix' => '<div class="notiRecurrence">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Notification Recurrence'), 'value' => check_plain(WSN_attribute_value('Recurrence', $node->notiRecurrence)))),
    '#weight' => 1,
  );
  $node->content['group7']['notiValue'] = array(
    '#prefix' => '<div class="notiValue">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Recurrence Value'), 'value' => check_plain(WSN_attribute_value('Recurrence Day', $node->notiValue)))),
    '#weight' => 2,
  );
  
  $node->content['group7']['message'] = array(
    '#prefix' => '<div class="message">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Message'), 'value' => check_plain($node->message))),
    '#weight' => 3,
  );
  $node->content['group7']['receiverNum'] = array(
    '#prefix' => '<div class="receiverNum">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('receiverNum'), 'value' => check_plain($node->receiverNum))),
    '#weight' => 4,
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
