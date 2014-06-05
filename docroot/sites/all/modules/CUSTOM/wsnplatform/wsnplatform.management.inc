<?php

/**
 * View WSN Platform Group
 */
 function wsnplatform_group_view(){
  $results = db_select('wsnplatform_group', 'wsngroup')
    ->fields('wsngroup', array(
                    'group_nid', 
                    'group_title',
                    'contact_name',
                    'contact_email_address',
                    'contact_number',
                    'contact_address',
                    'contact_language',
                    'contact_details'
                    ))
    //->condition('wsngroup.input_id', $from)
    ->orderBy('wsngroup.group_nid')
    ->execute();
  $header = array(
    t('Group ID'),
    t('Group Title'),
    t('Contact Name'),
    t('Contact Email'),
    t('Contact Number'),
    t('Contact Address'),
    t('Contact Language'),
    t('Other Details'),
    t('Operation')
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->group_nid), 
      check_plain($result->group_title),
      check_plain($result->contact_name),
      check_plain($result->contact_email_address),
      check_plain($result->contact_number),
      check_plain($result->contact_address),
      check_plain($result->contact_language),
      check_plain($result->contact_details),
      "<a href='wsnplatform/group/edit/".$result->group_nid."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/group/delete/".$result->group_nid."'>" . t('Delete') . "</a>",
      
    );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}
/**
 * Implements hook_form().
 */
 function wsnplatform_group_form($form, &$form_state){
   
  $form['group_title'] = array(
    '#type' => 'textfield',
    '#title' => t('WSN Platform Group Name'),
    '#required' => TRUE,
    '#size' => 20,
  );
  $form['contact_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact Name'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['contact_email_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact Email Address'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['contact_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact Number'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['contact_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact Address'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['contact_language'] = array(
    '#type' => 'textfield',
    '#title' => t('Contact Language'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['other_details'] = array(
    '#type' => 'textfield',
    '#title' => t('Other Details'),
    '#size' => 10,
  );
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  
  return $form;
}

/**
 * Submit  ahndler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_group_form_submit($form, &$form_state){
    //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_group')
    ->fields(array(
        'group_title' => $form_state['values']['group_title'],
        'contact_name' => $form_state['values']['contact_name'],
        'contact_email_address' => $form_state['values']['contact_email_address'],
        'contact_number' => $form_state['values']['contact_number'],
        'contact_address' => $form_state['values']['contact_address'],
        'contact_language' => $form_state['values']['contact_language'],
        'contact_details' => $form_state['values']['other_details'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Grooup has been added'));
  $form_state['redirect'] =  'wsnplatform/group';
}

/**
 * View WSN Platform NodeEntity
 */
 function wsnplatform_nodeentity_view(){
  $results = db_select('wsnplatform_nodeentity', 'ne')
    ->fields('ne')
    //->condition('wsngroup.input_id', $from)
    ->orderBy('ne.nodeentity_nid')
    ->execute();
  $header = array(
    t('Node Entity ID'),
    t('Node Entity Title'),
    t('Node Group ID'),
    t('Input ID'),
    t('Reading Occurence'),
    t('Sensor Number'),
    t('Data Compression ID'),
    t('Frequency Read'),
    t('Frequency Transmission'),
    t('Site Location'),
    t('Node Elevation'),
    t('Node Activity'),
    t('Notification ID'),
    t('Last Measured'),
    t('Last Sent Text'),    
    t('Plant ID'),
    t('Input Method'),
    t('Operation'),
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->nodeentity_nid), 
      check_plain($result->nodeentity_title),
      check_plain($result->group_nid),
      check_plain($result->input_id),
      check_plain($result->reading_occurence),
      check_plain($result->sensor_number),
      check_plain($result->datacompression_id),
      check_plain($result->freq_read),
      check_plain($result->freq_trans),
      check_plain($result->site_location),
      check_plain($result->node_elevation),
      check_plain($result->node_activity),
      check_plain($result->notification_id),
      check_plain($result->last_measured),
      check_plain($result->last_text),
      check_plain($result->plant_id),
      check_plain($result->input_method),
      "<a href='wsnplatform/nodeentity/edit/".$result->nodeentity_nid."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/nodeentity/delete/".$result->nodeentity_nid."'>" . t('Delete') . "</a>",
    );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Implements hook_form().
 */
 function wsnplatform_nodeentity_form($form, &$form_state){
   
  $form['nodeentity_title'] = array(
    '#type' => 'textfield',
    '#title' => t('WSN Platform Node Entity Name'),
    '#required' => TRUE,
    '#size' => 20,
  );
  //to be related to WSN Group
  $form['group_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Node Entity Group ID'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['input_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Input Identifier'),
    '#description' => 'unique receiver id',
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['input_method'] = array(
    '#type' => 'textfield',
    '#title' => t('Input Method'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['reading_occurence'] = array(
    '#type' => 'textfield',
    '#title' => t('Reading Occurence'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['sensor_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Sensor in a Node Entity'),
    '#size' => 50,
    '#required' => TRUE,
  );
  //to be linked to data compression id
  $form['datacompression_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Data Compression Technique ID'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['freq_read'] = array(
    '#type' => 'textfield',
    '#title' => t('Frequency of Reading'),
    '#size' => 10,
    '#required' => TRUE,
  );
  $form['freq_trans'] = array(
    '#type' => 'textfield',
    '#title' => t('Frequency of Transmission'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['site_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Latitude / Longitude'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['node_elevation'] = array(
    '#type' => 'textfield',
    '#title' => t('Elevation of field (in meter)'),
    '#size' => 10,
    '#required' => TRUE,
  );
  $form['notification_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Notification ID'),
    '#size' => 50,
  );
  $form['plant_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Plant ID'),
    '#size' => 10,
    '#required' => TRUE,
  );
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  
  return $form;
}

/**
 * Submit handler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_nodeentity_form_submit($form, &$form_state){
    //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_nodeentity')
    ->fields(array(
        'nodeentity_title' => $form_state['values']['nodeentity_title'],
        'group_nid' => $form_state['values']['group_nid'],
        'input_id' => $form_state['values']['input_id'],
        'reading_occurence' => $form_state['values']['reading_occurence'],
        'sensor_number' => $form_state['values']['sensor_number'],
        'datacompression_id' => $form_state['values']['datacompression_id'],
        'freq_read' => $form_state['values']['freq_read'],
        'freq_trans' => $form_state['values']['freq_trans'],
        'site_location' => $form_state['values']['site_location'],
        'node_elevation' => $form_state['values']['node_elevation'],
        'notification_id' => $form_state['values']['notification_id'],
        'plant_id' => $form_state['values']['plant_id'],
        'input_method' => $form_state['values']['input_method'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Node Model has been added'));
}

/**
 * View WSN Platform Sensor Model
 */
 function wsnplatform_sensormodel_view(){
  $results = db_select('wsnplatform_sensor_model', 'sm')
    ->fields('sm')
    //->condition('wsngroup.input_id', $from)
    ->orderBy('sm.model_nid')
    ->execute();
  $header = array(
    t('Model NID'),
    t('Model Title'),
    t('Scale Factor'),
    t('Unit of Measurement'),
    t('Callibration Polynomial 0'),
    t('Callibration Polynomial 1'),
    t('Callibration Polynomial 2'),
    t('Sensor Observation Max Value'),
    t('Sensor Observation Min Value'),
    t('Datasheet'),
    t('Operation'),
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->model_nid), 
      check_plain($result->model_title),
      check_plain($result->scalefactor),
      check_plain($result->unit),
      check_plain($result->callibration_a0),
      check_plain($result->callibration_a1),
      check_plain($result->callibration_a2),
      check_plain($result->operating_max),
      check_plain($result->operating_min),
      check_plain($result->datasheet),
      "<a href='wsnplatform/sensormodel/edit/".$result->model_nid."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/sensormodel/delete/".$result->model_nid."'>" . t('Delete') . "</a>",
    );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Implements hook_form().
 */
 function wsnplatform_sensormodel_form($form, &$form_state){
   
  $form['model_title'] = array(
    '#type' => 'textfield',
    '#title' => t('WSN Platform Sensor Model Name'),
    '#required' => TRUE,
    '#size' => 20,
  );
  $form['scalefactor'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Factor'),
    '#size' => 20,
    '#default_value' => 1,
    '#required' => TRUE,
  );
  $form['unit'] = array(
    '#type' => 'textfield',
    '#title' => t('Unit of Measurement'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['callibration_a0'] = array(
    '#type' => 'textfield',
    '#title' => t('Callibration Polynomial 0'),
    '#size' => 20,
    '#default_value' => 0,
    '#required' => TRUE,
  );
  $form['callibration_a1'] = array(
    '#type' => 'textfield',
    '#title' => t('Callibration Polynomial 1'),
    '#size' => 50,
    '#default_value' => 1,
    '#required' => TRUE,
  );
  $form['callibration_a2'] = array(
    '#type' => 'textfield',
    '#title' => t('Callibration Polynomial 2'),
    '#size' => 50,
    '#default_value' => 0,
    '#required' => TRUE,
  );
  $form['operating_max'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum Value'),
    '#size' => 10,
  );
  $form['operating_min'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum Value'),
    '#size' => 10,
  );
  $form['datasheet'] = array(
    '#type' => 'textfield',
    '#title' => t('Datasheet'),
    '#size' => 10,
  );
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  
  return $form;
}

/**
 * Submit  ahndler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_sensormodel_form_submit($form, &$form_state){
    //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_sensor_model')
    ->fields(array(
        'model_title' => $form_state['values']['model_title'],
        'scalefactor' => $form_state['values']['scalefactor'],
        'unit' => $form_state['values']['unit'],
        'callibration_a0' => $form_state['values']['callibration_a0'],
        'callibration_a1' => $form_state['values']['callibration_a1'],
        'callibration_a2' => $form_state['values']['callibration_a2'],
        'operating_max' => $form_state['values']['operating_max'],
        'operating_min' => $form_state['values']['operating_min'],
        'datasheet' => $form_state['values']['datasheet'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Sensor Model has been added'));
}

/**
 * View WSN Platform Sensor
 */
 function wsnplatform_sensor_view(){
  $results = db_select('wsnplatform_sensor', 'se')
    ->fields('se')
    //->condition('wsngroup.input_id', $from)
    ->orderBy('se.sensor_nid')
    ->execute();
  $header = array(
    t('Sensor ID'),
    t('Sensor Title'),
    t('Mote Unit'),
    t('Low Threshold'),
    t('High Threshold'),
    t('Sensor Model'),
    t('Order of Sensor'),
    t('Notification ID'),
    t('Operation'),
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->sensor_nid), 
      check_plain($result->sensor_title),
      check_plain($result->nodeentity_nid),
      check_plain($result->low_threshold),
      check_plain($result->high_threshold),
      check_plain($result->model_nid),
      check_plain($result->order_number),
      check_plain($result->notification_id),
      "<a href='wsnplatform/sensor/edit/".$result->sensor_nid."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/sensor/delete/".$result->sensor_nid."'>" . t('Delete') . "</a>",
    );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Implements hook_form().
 */
 function wsnplatform_sensor_form($form, &$form_state){
   
  $form['sensor_title'] = array(
    '#type' => 'textfield',
    '#title' => t('WSN Platform Sensor Name'),
    '#required' => TRUE,
    '#size' => 20,
  );
  $form['nodeentity_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Node Entity ID'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['model_nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Model ID'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['low_threshold'] = array(
    '#type' => 'textfield',
    '#title' => t('Low Threshold'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['high_threshold'] = array(
    '#type' => 'textfield',
    '#title' => t('High Threshold'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['order_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Order in Node'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['notification_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Notification ID'),
    '#size' => 50,
  );
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  return $form;
}

/**
 * Submit  ahndler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_sensor_form_submit($form, &$form_state){
    //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_sensor')
    ->fields(array(
        'sensor_title' => $form_state['values']['sensor_title'],
        'nodeentity_nid' => $form_state['values']['nodeentity_nid'],
        'model_nid' => $form_state['values']['model_nid'],
        'low_threshold' => $form_state['values']['low_threshold'],
        'high_threshold' => $form_state['values']['high_threshold'],
        'order_number' => $form_state['values']['order_number'],
        'notification_id' => $form_state['values']['notification_id'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Sensor has been added'));
}

/**
 * View WSN Platform Attribute
 */
 function wsnplatform_attribute_view(){
  $results = db_select('wsnplatform_attribute', 'at')
    ->fields('at')
    //->condition('wsngroup.input_id', $from)
    ->orderBy('at.attribute_nid')
    ->execute();
  $header = array(
    t('Attribute NID'),
    t('List Domain'),
    t('List Key'),
    t('List Value'),
    t('Active Set'),
    t('Operation'),
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->attribute_nid), 
      check_plain($result->domain),
      check_plain($result->akey),
      check_plain($result->avalue),
      check_plain($result->isactive),
      "<a href='wsnplatform/attribute/edit/".$result->attribute_nid."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/attribute/delete/".$result->attribute_nid."'>" . t('Delete') . "</a>",
    );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}
/**
 * Implements hook_form().
 */
 function wsnplatform_attribute_form($form, &$form_state){
   
  $form['domain'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain'),
    '#required' => TRUE,
    '#size' => 20,
  );
  $form['akey'] = array(
    '#type' => 'textfield',
    '#title' => t('Key'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['avalue'] = array(
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#size' => 50,
    '#required' => TRUE,
  );
  $form['isactive'] = array(
    '#type' => 'textfield',
    '#title' => t('is Active'),
    '#size' => 20,
    '#required' => TRUE,
  );
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  
  return $form;
}

/**
 * Submit  ahndler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_attribute_form_submit($form, &$form_state){
    //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_attribute')
    ->fields(array(
        'domain' => $form_state['values']['domain'],
        'akey' => $form_state['values']['akey'],
        'avalue' => $form_state['values']['avalue'],
        'isactive' => $form_state['values']['isactive'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Attribute has been added'));
}

/**
 * View WSN Platform Data Compression
 */
 function wsnplatform_datacompression_view(){
  $results = db_select('wsnplatform_datacompression', 'dc')
    ->fields('dc')
    //->condition('wsngroup.input_id', $from)
    ->orderBy('dc.datacompression_id')
    ->execute();
  $header = array(
    t('Data Compression ID'),
    t('Data Compression Title'),
    t('Sensor Sensor Delimiter'),
    t('Measurand Set Delimiter'),
    t('Details'),
    t('Operation'),
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->datacompression_id), 
      check_plain($result->datacompression_title),
      check_plain($result->sensor_sensor_delimiter),
      check_plain($result->measurand_set_delimiter),
      check_plain($result->details),
      "<a href='wsnplatform/datacompression/edit/".$result->datacompression_id."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/datacompression/delete/".$result->datacompression_id."'>" . t('Delete') . "</a>",
    );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Implements hook_form().
 */
 function wsnplatform_datacompression_form($form, &$form_state){
   
  $form['datacompression_title'] = array(
    '#type' => 'textfield',
    '#title' => t('WSN Platform Data Compression Name'),
    '#required' => TRUE,
    '#size' => 20,
  );
  $form['sensor_sensor_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('Sensor to Sensor Delimiter'),
    '#size' => 20,
    '#required' => FALSE,
  );
  $form['measurand_set_delimiter'] = array(
    '#type' => 'textfield',
    '#title' => t('Measurant Set Delimiter'),
    '#size' => 50,
    '#required' => FALSE,
  );
  $form['details'] = array(
    '#type' => 'textfield',
    '#title' => t('Details'),
    '#size' => 20,
    '#required' => FALSE,
  );
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  
  return $form;
}

/**
 * Submit  ahndler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_datacompression_form_submit($form, &$form_state){
    //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_datacompression')
    ->fields(array(
        'datacompression_title' => $form_state['values']['datacompression_title'],
        'sensor_sensor_delimiter' => $form_state['values']['sensor_sensor_delimiter'],
        'measurand_set_delimiter' => $form_state['values']['measurand_set_delimiter'],
        'details' => $form_state['values']['details'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Grooup has been added'));
}

/**
 * View WSN Platform NodeEntity
 */
 function wsnplatform_notification_view(){
  $results = db_select('wsnplatform_notification', 'nt')
    ->fields('nt')
    //->condition('wsngroup.input_id', $from)
    ->orderBy('nt.notification_id')
    ->execute();
  $header = array(
    t('Notification ID'),
    t('Notification Message'),
    t('Notification Receiver No.'),
    t('Notification Condition'),
    t('Operation'),
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->notification_id), 
      check_plain($result->notification_message),
      check_plain($result->notification_receiver),
      check_plain($result->notification_condition),
      "<a href='wsnplatform/notification/edit/".$result->notification_id."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/notification/delete/".$result->notification_id."'>" . t('Delete') . "</a>",
    );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}


/**
 * Implements hook_form().
 */
 function wsnplatform_notification_form($form, &$form_state){
   
  $form['notification_message'] = array(
    '#type' => 'textfield',
    '#title' => t('WSN Notifcation Group Name'),
    '#required' => TRUE,
    '#size' => 20,
  );
  $form['notification_receiver'] = array(
    '#type' => 'textfield',
    '#title' => t('Receiver Number'),
    '#size' => 20,
    '#required' => TRUE,
  );
  $form['notification_condition'] = array(
    '#type' => 'textfield',
    '#title' => t('Notification Condition'),
    '#description' =>t('EXAMPLE a:3:{s:12:&quot;order_number&quot;;i:7;s:9:&quot;condition&quot;;s:2:&quot;&lt;=&quot;;s:9:&quot;parameter&quot;;s:1:&quot;5&quot;;}'),
    '#size' => 50,
    '#required' => TRUE,
  );
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  
  return $form;
}

/**
 * Submit  ahndler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_notification_form_submit($form, &$form_state){
    //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_notification')
    ->fields(array(
        'notification_message' => $form_state['values']['notification_message'],
        'notification_receiver' => $form_state['values']['notification_receiver'],
        'notification_condition' => $form_state['values']['notification_condition'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Notification has been added'));
}
/**
 * View WSN Platform Plant
 */
 function wsnplatform_plant_view(){
  $results = db_select('wsnplatform_plant', 'pl')
    ->fields('pl')
    //->condition('wsngroup.input_id', $from)
    ->orderBy('pl.plant_id')
    ->execute();
  $header = array(
    t('Plant ID'),
    t('Plant Type'),
    t('Plant Start Cycle'),
    t('Plant Growth Stage'),
    t('Operation'),
   );
  $rows = array(); 
  foreach($results AS $result){
    $rows[] = array(
      check_plain($result->plant_id), 
      check_plain($result->plant_type),
      check_plain($result->plant_startcycle),
      check_plain($result->plant_growthstage),
      "<a href='wsnplatform/plant/edit/".$result->plant_id."'>" . t('Edit') . "</a> |
       <a href='wsnplatform/plant/delete/".$result->plant_id."'>" . t('Delete') . "</a>",
      );
  } 
  return theme('table', array('header' => $header, 'rows' => $rows));
}
/**
 * Implements hook_form().
 */
 function wsnplatform_plant_form($form, &$form_state){
   
  $form['plant_type'] = array(
    '#type' => 'textfield',
    '#title' => t('WSN Platform Plant Type'),
    '#required' => TRUE,
    '#size' => 20,
  );
  $form['plant_startcycle'] = array(
    '#type' => 'textfield',
    '#title' => t('Start Cycle Date'),
    '#size' => 20,
  );
  $form['plant_growthstage'] = array(
    '#type' => 'textfield',
    '#title' => t('Growth Cycle'),
    '#size' => 50,
  );
  
  $form['submit'] = array(
  '#type' => 'submit',
  '#value' => t('Add Item'),
  );
  
  return $form;
}

/**
 * Submit  ahndler for the wsnplatform_group_form. Insert entry to database
 */
function wsnplatform_plant_form_submit($form, &$form_state){
    $startcycle = $form_state['values']['plant_startcycle'];
    if(!is_numeric($form_state['values']['plant_startcycle']))
          $startcycle = 0;
        //need to validate sensor first  
    $result = $id = db_insert('wsnplatform_plant')
    ->fields(array(
        'plant_type' => $form_state['values']['plant_type'],
        'plant_startcycle' => $startcycle,
        'plant_growthstage' => $form_state['values']['plant_growthstage'],
    ))
    ->execute();
  drupal_set_message(t('Your New WSN Platform Plant has been added'));
}

