<?php
/**
 * @file
 * WSN Platform Comms Module for Drupal: Admin settings form functions
 *
 * @package wsnplatform
 * @subpackage wsnplatform_comms
 */


/**
 * Admin settings form
 *
 * @return
 *   Drupal form array
 */
function wsnplatform_comms_settings_form() {
  $form['data_sms_in'] = array(
    '#type'  => 'fieldset',
    '#title' => 'Communication SMS Gateway',
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );
  $form['data_sms_in']['smsgateway_path'] = array(
    '#type'  => 'textfield',
    '#title' => 'SMS Gateway Choice',
    '#size'          => 50,
    '#default_value' => variable_get('wsnplatform_comms_smsgateway'),
    '#description'   => 'SMS Gateway Choice -> '. 'http://'. $_SERVER['HTTP_HOST'],
  );
  // Archive section
  $form['data_log'] = array(
    '#type'  => 'fieldset',
    '#title' => 'Log Archiving',
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );
  $form['data_log']['archive'] = array(
    '#type'  => 'select',
    '#title' => 'Turn on Log Archive',
    '#default_value' => variable_get('wsnplatform_comms_archive_set', 0),
    '#options' => array(
      0 => 'No Archiving [default]',
      1 => 'Archiving Data Log',
    ),
    '#description' => t('Note that this will revert to the default option when the module is disabled.'),
  );
  $form['data_log']['archive_max_age_days'] = array(
    '#type'  => 'textfield',
    '#title' => 'Purge messages after n days',
    '#size'          => 10,
    '#default_value' => variable_get('wsnplatform_comms_archive_max_age_days'),
    '#description'   => 'Set to 0 (zero) to disable archive purge. This will only work if you have cron configured correctly.',
  );
  $form['data_in'] = array(
    '#type'  => 'fieldset',
    '#title' => 'Communication',
    '#collapsible' => TRUE,
    '#collapsed'   => FALSE,
  );
  $form['data_in']['data_prefix'] = array(
    '#type'  => 'textfield',
    '#title' => 'Incoming Data Prefix - Normal',
    '#size'          => 3,
    '#default_value' => variable_get('wsnplatform_comms_data_prefix',utf8_encode(chr(163))),
    '#description'   => 'Incoming Data Prefix - Normal',
  );
  $form['data_in']['warning_prefix'] = array(
    '#type'  => 'textfield',
    '#title' => 'Incoming Data Prefix - Warning',
    '#size'          => 3,
    '#default_value' => variable_get('wsnplatform_comms_warning_prefix',utf8_encode(chr(165))),
    '#description'   => 'Incoming Data Prefix - Warning',
  );
  $form['data_in']['config_prefix'] = array(
    '#type'  => 'textfield',
    '#title' => 'Incoming Data Prefix - Config',
    '#size'          => 3,
    '#default_value' => variable_get('wsnplatform_comms_config_prefix',utf8_encode(chr(167))),
    '#description'   => 'Incoming Data Prefix - Warning',
  );
  $form['data_in']['suffix'] = array(
    '#type'  => 'textfield',
    '#title' => 'Incoming Data Suffix',
    '#size'          => 3,
    '#default_value' => variable_get('wsnplatform_comms_suffix',utf8_encode(chr(164))),
    '#description'   => 'Incoming Data Suffix',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}


function wsnplatform_comms_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  //sms communication link
  $gateway = $values['smsgateway_path'];
  variable_set('wsnplatform_comms_smsgateway', $gateway);
  
  $archive_set_old = variable_get('wsnplatform_comms_archive_set', 0);
  $archive_set = $values['archive'];
  variable_set('wsnplatform_comms_archive_set', $archive_set);

  $archive_max_age_days = $values['archive_max_age_days'];
  variable_set('wsnplatform_comms_archive_max_age_days', $archive_max_age_days);
  
  //communication specific variable  
  $normal_prefix = $values['data_prefix'];
  variable_set('wsnplatform_comms_data_prefix',$normal_prefix);
  
  $warning_prefix = $values['warning_prefix'];
  variable_set('wsnplatform_comms_warning_prefix',$warning_prefix);
  
  $config_prefix = $values['config_prefix'];
  variable_set('wsnplatform_comms_config_prefix',$config_prefix);

  $suffix = $values['suffix'];
  variable_set('wsnplatform_comms_suffix',$suffix);
    

  // Trigger watchdog messages
  if ($archive_set_old && ! $archive_set) {
    watchdog('wsnplatform_comms', 'WSN Comms archive collector DISABLED');
  }
  if (! $archive_set_old && $archive_set) {
    watchdog('wsnplatform_comms', 'WSN Comms archive collector ENABLED');
  }
  drupal_set_message(t('Settings saved.'));
}


/**
 * Admin View page
 *
 * @return
 *   HTML content string
 */
function wsnplatform_comms_admin_view() {
  $content = views_embed_view('wsnplatform_comms', $display_id = 'default');
  return $content;
}
