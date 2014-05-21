<?php

/**
 * @file
 * Theme functions for the WSN Observations module.
 */

/**
 * Provides HTML for the Observations node view.
 */
function theme_WSNobservations_view($variables) {
  $node = $variables['node'];

  drupal_add_css(drupal_get_path('module', 'WSN') . '/WSN-node.css', 'module');

  $l_pos = 1; // Used to increase the link position number (see issue 814820)

  $node->content['links'] = array(
    '#prefix' => '<div class="WSNlinks">',
    '#suffix' => '</div>',
    '#weight' => -25,
  );

//  $node->content['links']['expenses'] = theme('WSN_link', 'WSNobservations', 'WSNexpense', $node->nid, $l_pos++);
//  $node->content['links']['notes'] = theme('WSN_link', 'WSNobservations', 'WSNnote', $node->nid, $l_pos++);
//  $node->content['links']['tickets'] = theme('WSN_link', 'WSNobservations', 'WSNticket', $node->nid, $l_pos++);
//  $node->content['links']['timetrackings'] = theme('WSN_link', 'WSNobservations', 'WSNtimetracking', $node->nid, $l_pos++);


  $node->content['group1'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group1') : -20,
  );

  $node->content['group1']['sites'] = array(
    '#prefix' => '<div class="sites">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Site'), 'value' => l($node->sites_title, 'node/' . $node->sites_nid))),
    '#weight' => 1,
  );

  $node->content['group1']['nodes'] = array(
    '#prefix' => '<div class="nodes">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Node'), 'value' => l($node->nodes_title, 'node/' . $node->nodes_nid))),
    '#weight' => 2,
  );
  
  $node->content['group1']['sensors'] = array(
    '#prefix' => '<div class="sensors">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Sensor'), 'value' => l($node->sensors_title, 'node/' . $node->sensors_nid))),
    '#weight' => 2,
  );

//  $node->content['group1']['stepno'] = array(
//    '#prefix' => '<div class="stepno">',
//    '#suffix' => '</div>',
//    '#markup' => theme('WSN_view_item', array('label' => t('Step no.'), 'value' => check_plain($node->stepno))),
//    '#weight' => 3,
//  );

  $node->content['group2'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group2') : -19,
  );

//  $node->content['group2']['category'] = array(
//    '#prefix' => '<div class="category">',
//    '#suffix' => '</div>',
//    '#markup' => theme('WSN_view_item', array('label' => t('Category'), 'value' => check_plain(WSN_attribute_value('Observations category', $node->Observationscategory)))),
//    '#weight' => 1,
//  );

  $node->content['group2']['value'] = array(
    '#prefix' => '<div class="WSN_value">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Value'), 'value' => check_plain($node->value))),
    '#weight' => 2,
  );
  
  $node->content['group3'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group3') : -11,
  );
  
  $node->content['group3']['datetime'] = array(
    '#prefix' => '<div class="datetime">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Date Time'), 'value' => check_plain($node->datetime))),
    '#weight' => 6,
  );  
    $node->content['group4'] = array(
    '#prefix' => '<div class="WSNfields">',
    '#suffix' => '</div>',
    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group4') : -10,
  );
  
  $node->content['group4']['observationCategory'] = array(
    '#prefix' => '<div class="WSN_category">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Observation Category'), 'value' => check_plain(WSN_attribute_value('Observation Category', $node->observationCategory)))),
    '#weight' => 7,
  );

  $node->content['group4']['observationError'] = array(
    '#prefix' => '<div class="WSN_error">',
    '#suffix' => '</div>',
    '#markup' => theme('WSN_view_item', array('label' => t('Observation Error'), 'value' => check_plain(WSN_attribute_value('Observation Error', $node->observationError)))),
    '#weight' => 9,
  );

//  $node->content['group5'] = array(
//    '#prefix' => '<div class="WSNfields">',
//    '#suffix' => '</div>',
//    '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'group5') : -16,
//  );
//
//  $node->content['group5']['assigned'] = array(
//    '#prefix' => '<div class="assigned">',
//    '#suffix' => '</div>',
//    '#markup' => theme('WSN_view_item', array('label' => t('Assigned to'), 'value' => l($node->assigned_title, 'node/' . $node->assigned_nid))),
//    '#weight' => 2,
//  );

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
