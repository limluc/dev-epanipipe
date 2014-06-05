<?php



/**
 * Custom Page Callback
 * 
 */
 
function wsnplatform_dashboard_group(){
  $rowsdata = array();
  $mapdata = array();
  $tabdata = array(); 
  $tableheader = array(
    t('Node ID'),
    t('Time'),
    t('AVG Temp (C)'),
    t('AVG Humidity (%)'),
    t('MAX Temp (C)'),
    t('MIN Temp (C)'),
    t('MIN Humidity (%)'),
    t('MIN Humidity (%)'),
    t('Water Level (cm)'),
    t('Water Salinity (uS/cm)'),
    t('Battery Level (%)'),
    t('Light Level (%)')
   );
  // BUILD THE FIRST QUERY FOR MAP
  $querydata = db_select('wsnplatform_observation', 'wo');
  $querydata -> join ('wsnplatform_nodeentity', 'ne', 'wo.nodeentity_nid = ne.nodeentity_nid');
  $querydata  
    -> fields('wo', array('nodeentity_nid', 'timestamp', 'observation_type', 'sensor_one','sensor_two','sensor_three','sensor_four','sensor_five','sensor_six','sensor_seven','sensor_eight','sensor_nine','sensor_ten'))
    -> fields('ne', array('nodeentity_nid', 'nodeentity_title', 'input_id', 'site_location'))
    -> condition('observation_type', 0)
    -> orderBy('wo.timestamp', 'DESC')
    -> range(0,50);
  $resultdata = $querydata ->execute();  
  foreach($resultdata AS $result){
    if(!empty($result)){
      $rowsdata[] = array(
        check_plain($result->nodeentity_title . ' (' . $result->input_id . ')'),
        check_plain(date( 'Y-m-d H:i:s', $result->timestamp)), 
        check_plain($result->sensor_one),
        check_plain($result->sensor_two),
        check_plain($result->sensor_three),
        check_plain($result->sensor_four),
        check_plain($result->sensor_five),
        check_plain($result->sensor_six),
        check_plain($result->sensor_seven),
        check_plain($result->sensor_eight),
        check_plain($result->sensor_nine),
        check_plain($result->sensor_ten)
      ); 
    } 
  };
  $sensorheader = array(
    //t('Node ID'),
    t('Node Title'),
    t('Input Identifier'),
    t('Latitude'),
    t('Longitude'),
   );
   
  $queryactive = db_select('wsnplatform_nodeentity', 'ne')
      -> fields('ne')
      -> condition('node_activity', 0)
      -> orderBy('nodeentity_nid')
      -> range(0,10);
  $resultnodes = $queryactive ->execute();  
  foreach($resultnodes AS $result){
      $mapdata[] = array(
        "nodeentity_nid" => check_plain($result->nodeentity_nid),
        "nodeentity_title" => check_plain($result->nodeentity_title),
        "input_id" => check_plain($result->input_id),
        "location" => unserialize($result->site_location),
      );
  };
  foreach($mapdata AS $result){
      $tabdata[] = array(
        //"nodeentity_nid" => $result["nodeentity_nid"],
        "<a href='wsnplatformdashboard/node/". $result["input_id"]."'>" . $result["nodeentity_title"] . "</a>",
        $result["input_id"],
        $result["location"]["lat"],
        $result["location"]["lon"],
      );
  };
  $content['raw_markup'] = array(
    '#type' => 'markup',
    '#markup' => '
    <div class="header-in"><p class ="lead-in">WSN Platform Nodes Data View</p></div>
    <div class="row">
      <div class="col-lg-6">
        <div class="panel panel-primary">
          <div class="panel-heading">
            <h3 class="panel-title">Location of Nodes</h3></div>
            <div class="panel-body">'.gmap_simple_map($mapdata[0]["location"]["lat"], $mapdata[0]["location"]["lon"], '', 'default', 'default').'</div>
          </div>
        </div>
        <div class="col-lg-6">
          <div class="panel panel-primary">
            <div class="panel-heading">
            <h3 class="panel-title">Active Nodes</h3></div>
            <div class="panel-body">'.theme('table', array('header' => $sensorheader, 'rows' => $tabdata)).'
          </div>
        </div>
      </div>
    </div><!-- /.row -->           
    <div class="row">
      <div class="col-lg-12">
        <div class="panel panel-primary">
          <div class="panel-heading">
            <h3 class="panel-title"><i class="fa fa-bar-chart-o"></i>Historical Observation</h3>
          </div>
          <div class="panel-body">'.
            theme('table', array('header' => $tableheader, 'rows' => $rowsdata))
          .'</div>
        </div>
      </div>
    </div><!-- /.row -->',
  );
  return $content;
}

/**
 * Custom
 * 
 */
function wsnplatform_dashboard_node_page(){

$from = arg(2); 
$query = db_select('wsnplatform_nodeentity', 'ne');
$query -> join('wsnplatform_datacompression', 'dc' , 'dc.datacompression_id = ne.datacompression_id');
$query
  -> fields('ne', array('nodeentity_nid','last_measured','last_text','datacompression_id','input_id', 'reading_occurence', 'sensor_number', 'freq_read', 'freq_trans'))
  -> fields('dc', array('datacompression_id','datacompression_title'))
  -> condition('ne.input_id', $from);     
$result = $query->execute();   
$data = $result->fetchAssoc();
//getting more static data from the node!! 
 $header2 = array(
  t('Node Information'),
  t('Value'),
 );
  $rows2 = array(
  array(t('Input ID'), $data['input_id']),
  array(t('Number of Sensor'), $data['sensor_number']),
  array(t('Reading Occurence'), $data['reading_occurence']),
  array(t('Frequency of Reading (s)'), $data['freq_read']),
  array(t('Frequency of Transmission (s)'), $data['freq_trans']),
  array(t('Data Compression Technique'), $data['datacompression_title']),
  array(t('Last Measured Time'), date( 'Y-m-d H:i:s', $data['last_measured'])),
  );
//getting the latest reading//
$query2 = db_select('wsnplatform_observation', 'wo')
  ->fields('wo')
  ->condition('wo.timestamp',$data['last_measured'])
  ->condition('wo.observation_type',0)
  ->condition('wo.nodeentity_nid', $data['nodeentity_nid']);
$result2 = $query2->execute();
$data2 = $result2->fetchAssoc();
//getting the latest reading//

$rowslog = array();
//getting the latest reading//
$querylog = db_select('wsnplatform_comms_log', 'cl')
  ->fields('cl')
  ->condition('data_type','Notification')
  ->condition('post_message', $from);
$resultlog = $querylog -> execute();
  foreach($resultlog AS $result){
    if(!empty($result)){
      $rowslog[] = array(
        check_plain(date( 'Y-m-d H:i:s', $result->created_datetime)),
        check_plain($result->message),
        check_plain($result->number),
      );
    }
  }
 $headerlog = array(
  t('Date Time'),
  t('Message'),
  t('Number Sent'),
 );

//getting the latest reading//
$query5 = db_select('wsnplatform_sensor', 'se');
$query5
  -> fields('se')
  -> condition('se.nodeentity_nid',$data['nodeentity_nid']);
$result5 = $query5->execute();
/////////////////////////////////
$unsvalue = unserialize($data2['value_array']);
$stat = '';
$rows =array();
foreach($result5 AS $res){
   $i = $res->order_number; 
   if($unsvalue[$i-1] < $res->low_threshold)
     $stat='LOW';
   elseif($unsvalue[$i-1] > $res->high_threshold)
     $stat='HIGH';
   else 
     $stat='NORMAL';
       
    $rows[] = array(
       $res->sensor_title,
       $unsvalue[$i-1],
       $stat,
       );
  }         
 $header = array(
  t('Sensor Class'),
t('Measured Value'),
t('Status')
 );

//getting the observation//
$results3 = db_select('wsnplatform_observation', 'wo')
  ->fields('wo')           
  ->condition('wo.nodeentity_nid', $data['nodeentity_nid'])
  ->orderBy('wo.timestamp', 'DESC')
  ->range(0,30)
  ->execute();
        $header3 = array(
          t('Time'),
          t('AVG Temp (C)'),
          t('AVG Humidity (%)'),
          t('MAX Temp (C)'),
          t('MIN Temp (C)'),
          t('MIN Humidity (%)'),
          t('MIN Humidity (%)'),
          t('Water Level (cm)'),
          t('Water Salinity (uS/cm)'),
          t('Battery Level (%)'),
          t('Light Level (%)')
         );
      $rows3 = array(); 
      foreach($results3 AS $result){
        $rows3[] = array(
          check_plain(date( 'Y-m-d H:i:s', $result->timestamp)), 
          check_plain($result->sensor_one),
          check_plain($result->sensor_two),
          check_plain($result->sensor_three),
          check_plain($result->sensor_four),
          check_plain($result->sensor_five),
          check_plain($result->sensor_six),
          check_plain($result->sensor_seven),
          check_plain($result->sensor_eight),
          check_plain($result->sensor_nine),
          check_plain($result->sensor_ten)
        );
      };
    $content['from']['content'] = drupal_get_form('wsnplatform_dashboard_node_form');
//getting the observation//
    $content['raw_markup'] = array(
      '#type' => 'markup',
      '#markup' => '
         </div><!-- /.row -->
          <div class="row">
            <div class="col-lg-6">
              <div align="center">
                <img src="'.drupal_get_path('theme', 'bootstrap_epanipipe').'/images/local/plant.jpg" alt="Prototype"/>
              </div>
            </div>
            <div class="col-lg-6">
              <div class="panel panel-primary">
                <div class="panel-heading">
                  <h3 class="panel-title"><i class="fa fa-long-arrow-right"></i>Node Information</h3>
                </div>
                <div class="panel-body">'.
                theme('table', array('header' => $header2, 'rows' => $rows2))
                .'</div>
              </div>
            </div>
            <div class="col-lg-6">
              <div class="panel panel-primary">
                <div class="panel-heading">
                  <h3 class="panel-title"><i class="fa fa-clock-o"></i>Most Recent Observation</h3>
                </div>
                <div class="panel-body">'.
                theme('table', array('header' => $header, 'rows' => $rows))
                .'</div>
                <div><a href='.'wsnplatformdashboard/multi/'.$from.'>View as Graph</a></div>              </div>
            </div>
            <div class="col-lg-6">
              <div class="panel panel-primary">
                <div class="panel-heading">
                  <h3 class="panel-title"><i class="fa fa-clock-o"></i>Communication to Stakeholder</h3>
                </div>
                <div class="panel-body">'.
                theme('table', array('header' => $headerlog, 'rows' => $rowslog))
                .'</div>              </div>
            </div>
            </div>
            <!-- /.row -->
          
          <div class="row">
            <div class="col-lg-12">
              <div class="panel panel-primary">
                <div class="panel-heading">
                  <h3 class="panel-title"><i class="fa fa-bar-chart-o"></i>Historical Observation</h3>
                </div>
                <div class="panel-body">'.
                  theme('table', array('header' => $header3, 'rows' => $rows3))
                .'</div>
              </div>
            </div>
          </div><!-- /.row -->',

    );
  return $content;
}

/**
 * Custom
 * 
 */
function wsnplatform_dashboard_multi_page(){
//  
// $from = arg(2);
// 
// $query = db_select('wsnplatform_nodeentity', 'ne');
// $query -> join('wsnplatform_datacompression', 'dc' , 'dc.datacompression_id = ne.datacompression_id');
// $query
  // -> fields('ne', array('nodeentity_nid','last_measured','last_text','datacompression_id','input_id', 'reading_occurence', 'sensor_number', 'freq_read', 'freq_trans'))
  // -> fields('dc', array('datacompression_id','datacompression_title'))
  // -> condition('ne.input_id', $from);     
// $result = $query->execute();   
// $data = $result->fetchAssoc();
// //getting more static data from the node!! 
 // $header2 = array(
  // t('Node Information'),
  // t('Value'),
 // );
  // $rows2 = array(
  // array(t('Input ID'), $data['input_id']),
  // array(t('Number of Sensor'), $data['sensor_number']),
  // array(t('Reading Occurence'), $data['reading_occurence']),
  // array(t('Frequency of Reading (s)'), $data['freq_read']),
  // array(t('Frequency of Transmission (s)'), $data['freq_trans']),
  // array(t('Data Compression Technique'), $data['datacompression_title']),
  // array(t('Last Measured Time'), date( 'Y-m-d H:i:s', $data['last_measured'])),
  // );
// //getting the latest reading//
// $query2 = db_select('wsnplatform_observation', 'wo')
  // ->fields('wo')
  // ->condition('wo.timestamp',$data['last_measured'])
  // ->condition('wo.observation_type',0)
  // ->condition('wo.nodeentity_nid', $data['nodeentity_nid']);
// $result2 = $query2->execute();
// $data2 = $result2->fetchAssoc();
// //getting the latest reading//
// //getting the observation//
// $results3 = db_select('wsnplatform_observation', 'wo')
  // ->fields('wo')           
  // ->condition('wo.nodeentity_nid', $data['nodeentity_nid'])
  // ->orderBy('wo.timestamp', 'DESC')
  // ->range(0,30)
  // ->execute();
      // $header3 = array(
    // t('Time'),
    // t('AVG Temp (C)'),
    // t('AVG Humidity (%)'),
    // t('MAX Temp (C)'),
    // t('MIN Temp (C)'),
    // t('MIN Humidity (%)'),
    // t('MIN Humidity (%)'),
    // t('Water Level (cm)'),
    // t('Water Salinity (uS/cm)'),
    // t('Battery Level (%)'),
    // t('Light Level (%)')
       // );
      // $rows3 = array(); 
      // foreach($results3 AS $result){
        // $rows3[] = array(
          // check_plain(date( 'Y-m-d H:i:s', $result->timestamp)), 
          // check_plain($result->sensor_one),
          // check_plain($result->sensor_two),
          // check_plain($result->sensor_three),
          // check_plain($result->sensor_four),
          // check_plain($result->sensor_five),
          // check_plain($result->sensor_six),
          // check_plain($result->sensor_seven),
          // check_plain($result->sensor_eight),
          // check_plain($result->sensor_nine),
          // check_plain($result->sensor_ten)
        // );
      // };
    // $content['from']['content'] = drupal_get_form('wsnplatform_dashboard_multi_form');
// //getting the observation//
    // $content['raw_markup'] = array(
      // '#type' => 'markup',
      // '#markup' => '
         // </div><div class="row">
            // <div class="col-lg-12">
              // <div class="panel panel-primary">
                // <div class="panel-heading">
                  // <h3 class="panel-title"><i class="fa fa-bar-chart-o"></i>Historical Observation</h3>
                // </div>
                // <div class="panel-body">'.
                  // theme('table', array('header' => $header3, 'rows' => $rows3))
                // .'</div>
              // </div>
            // </div>
          // </div><!-- /.row -->',
// 
    // );
    // return $content;
}

/**
 * Implements hook_form().
 */
 function wsnplatform_dashboard_node_form($form, &$form_state){
       
     //Query DB for Rows
    $query = db_select('wsnplatform_nodeentity', 'ne')
        ->fields('ne')
        ->orderBy('nodeentity_nid', 'ASC');
    $results = $query->execute();
    
    //define rows
    $options = array();
    $options[0] = '<SELECT WHICH NODE TO VIEW>';
    foreach ($results as $result) {
        $options[$result->input_id] = $result->nodeentity_title . ' - ' . $result->input_id;
    }
    
    $form['id'] = array(
      '#type' => 'select',
      '#title' => t('WSN Platform Node Entity ID'),
      '#options' => $options,
      '#prefix' => '<div class="row">
                        <div class="col-lg-8"><h1>Dashboard
                        <div><small> Wireless Sensor Network (WSN) Platform Node Overview</small></div></h1></div>
                        <div class="col-lg-4">
                          <div class="panel panel-primary">
                            <div class="panel-heading">',
      '#suffix' => '',
      );
    $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Select'),
      '#prefix' => '<div align="right">',
      '#suffix' => '</div></div></div>',
    );
    
    return $form;
}

/**
 * Submit  handler for the wsnplatform_dashboard_node_form. Insert entry to database
 */
function wsnplatform_dashboard_node_form_submit($form, &$form_state){
    //need to validate sensor first  
    $from = $form_state['values']['id'];
    $form_state['redirect'] =  'wsnplatformdashboard/node/'.$from;
    
}

// 
// 
// /**
 // * Implements hook_form().
 // */
 // function wsnplatform_dashboard_multi_form($form, &$form_state){
//        
     // //Query DB for Rows
    // $query = db_select('wsnplatform_nodeentity', 'ne')
        // ->fields('ne')
        // ->orderBy('nodeentity_nid', 'ASC');
    // $results = $query->execute();
//     
    // //define rows
    // $options = array();
    // $options[0] = '<SELECT WHICH NODE TO VIEW>';
    // foreach ($results as $result) {
        // $options[$result->input_id] = $result->nodeentity_title . ' - ' . $result->input_id;
    // }
//     
    // $form['id'] = array(
      // '#type' => 'select',
      // '#title' => t('WSN Platform Node Entity ID'),
      // '#options' => $options,
      // '#prefix' => '<div class="row">
                        // <div class="col-lg-8"><h1>Dashboard
                        // <div><small> Wireless Sensor Network (WSN) Platform Node Overview</small></div></h1></div>
                        // <div class="col-lg-4">
                          // <div class="panel panel-primary">
                            // <div class="panel-heading">',
      // '#suffix' => '',
      // );
    // $form['submit'] = array(
    // '#type' => 'submit',
    // '#value' => t('Select'),
      // '#prefix' => '<div align="right">',
      // '#suffix' => '</div></div></div>',
    // );
//     
    // return $form;
// }
// 
// /**
 // * Submit  handler for the wsnplatform_dashboard_node_form. Insert entry to database
 // */
// function wsnplatform_dashboard_multi_form_submit($form, &$form_state){
    // //need to validate sensor first  
    // $from = $form_state['values']['id'];
    // $form_state['redirect'] =  'wsnplatformdashboard/multi/'.$from;
//     
//}


