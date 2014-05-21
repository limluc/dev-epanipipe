<?php

/**
 * @file
 * Provides theme functions for WSN modules
 */

/**
 * Provides HTML for a WSN form group.
 */
function theme_WSN_form_group($variables) {
  $element = $variables['element'];

  drupal_add_css(drupal_get_path('module', 'WSN') . '/WSN.css');

  $row = array();
  foreach (element_children($element) as $key) {
    array_push($row, drupal_render($element[$key]));
  }
    
  
  $rows = array(
    array(
      'data' => $row,
      'class' => array('formgroup'),
      'no_striping' => TRUE,
    )
  );

  return theme('table', array(
    'header' => array(),
    'rows' => $rows,
    'attributes' => array('class' => array('formgroup'))
  ));
}

/**
 * Provides theming for the datetime element.
 */
function theme_datetime($element) {
  return theme('form_element', $element, '<div class="container-inline">' . $element['#children'] . '</div>');
}

/**
 * Provides theming for the dateext element.
 */
function theme_dateext($element) {
  return theme('form_element', $element, '<div class="container-inline">' . $element['#children'] . '</div>');
}

/**
 * Provides HTML to theme WSN fields.
 */
function theme_WSN_view_item($variables) {
  $o = '<div class="label"><span class="label">' . $variables['label'] . ':&nbsp;</span></div><div class="value">' . $variables['value'] . '&nbsp;</div>';
  return $o;
}

/**
 * Provides HTML for a WSN dashboard.
 */
function theme_WSN_dashboard($link_blocks) {
  $content = '<div id="WSNdashboard">';
  if (!empty($link_blocks)) {
    $content .= '<dl class="WSNdashboard clear-block">';
    foreach ($link_blocks as $block_id => $link_block_array) {
      $content .= '<div class="WSNdashboard">';
      if (!empty($link_block_array)) {
        foreach ($link_block_array as $key => $link_array) {
          if (!empty($link_array['theme'])) {
            $content .= theme($link_array['theme'], $link_array);
          }
          else {
            $content .= theme('WSN_dashboard_link', $link_array);
          }
        }
      }
      $content .= '</div>';
    }
    $content .= '</dl>';
  }
  else {
    $content .= t('No dashboard links available');
  }
  $content .= '</div>';

  return $content;
}

/**
 * Provides HTML for the WSN dashboard blocks.
 */
function theme_WSN_dashboard_block($link_blocks) {
  $content = '<div id="WSNdashboard-block">';
  if (!empty($link_blocks)) {
    foreach ($link_blocks as $block_id => $link_block_array) {
      if (!empty($link_block_array)) {
        foreach ($link_block_array as $key => $link_array) {
          $content .= '<div class="WSNdashboard-icon">';
          if (!empty($link_array['theme'])) {
            $content .= theme($link_array['theme'], $link_array);
          }
          else {
            $content .= theme('WSN_dashboard_link', $link_array);
          }
          $content .= '</div>';
        }
      }
    }
  }
  else {
    // no links, hide block
    return '';
  }
  $content .= '</div>';
  return $content;
}

/**
 * Provides HTML for WSN links.
 */
function theme_WSN_dashboard_link($link_array) {
  $content = '';

  // DEFAULT ICON
  if (empty($link_array['icon'])) {
//    $dt_id = 'WSNexpenses';
  }
  else {
    $dt_id = $link_array['icon'];
  }

  $params = array();
  if (!empty($link_array['nid'])) {
    $params_key = $link_array['node_type'] . '_nid';
    $params['query'] = array($params_key => $link_array['nid']);
  }

  $link = l($link_array['title'], $link_array['path'], $params);

  // ADD PLUS SIGN (node/add)
  if (!empty($link_array['add_type'])) {
    $item = new stdClass();
    $item->type = $link_array['add_type'];
    if (empty($link_array['params'])) {
      $link_array['params'] = array();
    }
    $link .= WSN_icon_add('node/add/' . str_replace('_', '-', $link_array['add_type']), $item, $link_array['params']);
  }


  if (empty($link_array['nid']) || 0 == $link_array['nid']) {
    if (variable_get('WSN_icons_display', TRUE)) {
      $content .= '<dt id="' . $dt_id . '" class="WSNcomponent">';
    }
    else {
      $content .= '<dt class="WSNcomponent">';
    }
    $content .= $link;
    $content .= '</dt>';
  }
  else {
    $content = array(
      '#prefix' => variable_get('WSN_icons_display', TRUE) ? '<dt id="' . $dt_id . '" class="WSNcomponent">' : '<dt class="WSNcomponent">',
      '#suffix' => '</dt>',
      '#value' => $link,
      '#weight' => $link_array['weight'],
    );
  }
  return $content;
}

/**
 * Provides HTML for the WSN dashboard weight table.
 */
function theme_WSN_dashboard_links_weight_table($form = array()) {
  $type = $form['#infix'];
  $rows = array();
  foreach ($form as $id => &$value) {
    if ($id[0] == '#') {
      continue;
    }
    $value[$type . '_WSN_dashboard_link_weight_' . $id]['#attributes']['class'] = $type . 'dashboard-link-table-weight';

    $row = array();
    $row[] = $value['#value'];
    $row[] = drupal_render($value[$type . '_WSN_dashboard_link_active_' . $id]);
    $row[] = drupal_render($value[$type . '_WSN_dashboard_link_weight_' . $id]);
    unset($value['#value']);
    if (!empty($row)) {
      $rows[] = array(
        'data' => $row,
        'class' => 'draggable',
      );
    }
  }
  $headers = array(t('Link'), t('Active'), t('Weight'));

  $output = theme('table', array('headers' => $headers, 'rows' => $rows, 'attributes' => array('id' => $type . 'dashboard-link-table')));

  drupal_add_tabledrag($type . 'dashboard-link-table', 'order', 'sibling', $type . 'dashboard-link-table-weight');

  $output .= drupal_render($form);

  return $output;
}

/**
 * Provides HTML for a WSN link.
 */
function theme_WSN_link($source_module='', $destination_module='', $node_nid=0, $weight=0) {
  switch ($source_module) {

    case "WSNsites":
      $params_key = 'sites_nid';
      break;

    case "WSNnodes":
      $params_key = 'nodes_nid';
      break;

    case "WSNsensors":
      $params_key = 'sensors_nid';
      break;

    case "WSNobservations":
      $params_key = 'observations_nid';
      break;
  }



  switch ($destination_module) {
    case "WSNattribute":
      $user_access_check = 'WSN: access administration pages';
      $list_text = t('Attributes');
      $list_path = 'WSN/attributes';
      $add_icon_type = 'WSNattribute';
      $add_path = 'WSN/attributes/add';
      $dt_id = 'WSNattributes';
      break;

    case "WSNconfiguration":
      $user_access_check = 'WSN: access administration pages';
      $list_text = t('Configuration');
      $list_path = 'admin/settings/WSN';
      $add_icon_type = '';
      $add_path = '';
      $dt_id = 'WSNconfiguration';
      break;

    case "WSNsites":
      $user_access_check = 'WSN sites: access';
      $list_text = t('Sites');
      $list_path = 'WSN/sites';
      $add_icon_type = 'WSNsites';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'WSNsites';
      break;
    
    case "WSNnodes":
      $user_access_check = 'WSN nodes: access';
      $list_text = t('Nodes');
      $list_path = 'WSN/nodes';
      $add_icon_type = 'WSNnodes';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'WSNnodes';
      break;
    
    case "WSNsensors":
      $user_access_check = 'WSN sensors: access';
      $list_text = t('Sensors');
      $list_path = 'WSN/sensors';
      $add_icon_type = 'WSNsensors';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'WSNsensors';
      break;

    case "WSNobservations":
      $user_access_check = 'WSN observations: access';
      $list_text = t('Observations');
      $list_path = 'WSN/observations/';
      $add_icon_type = 'WSNobservations';
      $add_path = 'node/add/' . $destination_module;
      $dt_id = 'WSNobservations';
      break;
  }

  if (($destination_module=='WSNconfiguration' && user_access($user_access_check)) || (module_exists($destination_module) && user_access($user_access_check))) {
    if ($node_nid == 0) {
      $params = array();
    }
    else {
      $params = array('query' => array($params_key => $node_nid));
    }
    $v = l($list_text, $list_path, $params);

    if (!$add_icon_type=='') {
      $i = new stdClass();
      $i->type = $add_icon_type;
      if ($node_nid == 0) {
        $params = $_GET;
      }
      else {
        $params = $_GET;
        $params[$params_key] = $node_nid;
      }
      $nmb_itms = _WSN_number_of_items($source_module, $destination_module, $node_nid);
      $nmb_itms = theme('WSN_number_items', $nmb_itms);
      $v .= $nmb_itms . WSN_icon_add($add_path, $i, $params);
    }

    if ($node_nid == 0) {
      $r = variable_get('WSN_icons_display', TRUE) ? '<dt id="' . $dt_id . '" class="WSNcomponent">' : '<dt class="WSNcomponent">';
      $r .= $v;
      $r .= '</dt>';
    }
    else {
      $r = array(
        '#prefix' => variable_get('WSN_icons_display', TRUE) ? '<dt id="' . $dt_id . '" class="WSNcomponent">' : '<dt class="WSNcomponent">',
        '#suffix' => '</dt>',
        '#value' => $v,
        '#weight' => $weight,
      );
    }
    return $r;
  }
}

/**
 * Provides HTML for the Project Managment number of items text.
 */
function theme_WSN_number_items($number) {
  $content = '';
  if ($number !== '') {
    $content .= '<span class="WSNlinks-count">(' . $number . ')</span>';
  }
  return $content;
}

/**
 * Provides HTML for the WSN attributes list.
 */
function theme_WSN_attribute_list($form) {
  drupal_add_tabledrag('attributes', 'order', 'sibling', 'attribute-weight');

  $header = array();
  $row = array();
  $rows = array();

  $header = $form['form']['header']['#value'];
  unset($form['form']['header']);

  if (isset($form['form']['attributes'])) {
    foreach (element_children($form['form']['attributes']) as $key) {
      $form['form']['attributes'][$key]['attribute_weight_' . $key]['#attributes']['class'] = array('attribute-weight');
      $domain = check_markup($form['form']['attributes'][$key]['attribute_domain_' . $key]['#value']);
      $isdefault = $form['form']['attributes'][$key]['attribute_default_' . $key]['#default_value'];
      if ($isdefault) {
        $ischecked = 'checked="checked"';
      }
      else {
        $ischecked = '';
      }
      $domain_name = 'attribute_default_' . str_replace(' ', '|', $domain);
      $default_ctl = '<input type="radio" name="' . $domain_name . '" value="' . $key . '" ' . $ischecked . '"/>';
      $data = array(
        $domain,
        check_markup($form['form']['attributes'][$key]['attribute_akey_' . $key]['#value']),
        check_markup($form['form']['attributes'][$key]['attribute_avalue_' . $key]['#value']),
        drupal_render($form['form']['attributes'][$key]['attribute_isactive_' . $key]),
        $default_ctl,
        drupal_render($form['form']['attributes'][$key]['attribute_weight_' . $key]),
        array(
          'data' => $form['form']['attributes'][$key]['attribute_operations_' . $key]['#value'],
          'class' => 'WSN_list_operations',
        ),
      );
      $row['data'] = $data;
//      $row['class'] = empty($row['class']) ? array('draggable') : $row['class'][] = ' draggable';
      $rows[] = $row;
    }
  }
  $o = theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'attributes')));
  return $o;
}
