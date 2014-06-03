<?php



/**
 * Custom
 * 
 */
function wsnplatform_dashboard_group(){
  
  $results3 = db_select('wsnplatform_observation', 'wo')
    ->fields('wo')           
    ->orderBy('wo.timestamp', 'DESC')
    ->execute();
  $header3 = array(
    t('Node ID'),
    t('Time Stamp'),
    t('Average Temperature'),
    t('Average Humidity'),
    t('Maximum Temperature'),
    t('Minimum Temperature'),
    t('Maximum Humidity'),
    t('Minimum Humidity'),
    t('Water Level'),
    t('Water Salinity'),
    t('Light Level'),
    t('Battery Level')
   );
  $rows3 = array(); 
  foreach($results3 AS $result){
    $rows3[] = array(
      check_plain($result->nodeentity_nid),
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
  
  $content['raw_markup'] = array(
    '#type' => 'markup',
    '#markup' => '
    <div class="header-in"><p class ="lead-in">WSN Platform All Nodes</p></div>
    </div></div>
    <div class="row">
      <div class="col-lg-12">
        <div class="panel panel-primary">
          <div class="panel-heading">
            <h3 class="panel-title"><i class="fa fa-bar-chart-o"></i>Map View</h3>
          </div>
          <div class="panel-body">
            <div id="morris-chart-area">PLACEHOLDER</div>
          </div>
        </div>
      </div>
    </div><!-- /.row -->
<div class="row">
      <div class="col-lg-12">
        <div class="panel panel-primary">
          <div class="panel-heading">
            <h3 class="panel-title"><i class="fa fa-bar-chart-o"></i>Data Stream Message</h3>
          </div>
          <div class="panel-body">
            <div id="morris-chart-area">PLACEHOLDER</div>
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
function wsnplatform_dashboard_node(){
      //need to validate sensor first  
    $from='447938797117'; //to create dropdown list
    $query = db_select('wsnplatform_nodeentity', 'ne');
    $query -> join('wsnplatform_datacompression', 'dc' , 'dc.datacompression_id = ne.datacompression_id');
    $query
      -> fields('ne', array('nodeentity_nid','last_measured','last_text','datacompression_id','input_id', 'reading_occurence', 'sensor_number', 'freq_read', 'freq_trans'))
      -> fields('dc', array('datacompression_id','datacompression_title'))
      -> condition('ne.input_id', $from);     
    $result = $query->execute();   
    $data = $result->fetchAssoc();
    //getting info on node
    
    $query2 = db_select('wsnplatform_observation', 'wo')
      ->fields('wo')
      ->condition('wo.timestamp',$data['last_measured'])
      ->condition('wo.observation_type',0);
    $result2 = $query2->execute();
    $data2 = $result2->fetchAssoc();
    
   $header = array(
    t('Sensor'),
    t('Measured Value'),
   );
    $rows = array(
    array(t('Average Temperature (C)'), $data2['sensor_one']),
    array(t('Average Humidity (%)'), $data2['sensor_two']),
    array(t('Maximum Temperature (C)'), $data2['sensor_three']),
    array(t('Minimum Temperature (C)'), $data2['sensor_four']),
    array(t('Maximum Humidity (%)'), $data2['sensor_five']),
    array(t('Minimum Humidity (%)'), $data2['sensor_six']),
    array(t('Water Level (cm)'), $data2['sensor_seven']),
    array(t('Water Salinity (uS/cm)'), $data2['sensor_eight']),
    array(t('Light Level (%)'), $data2['sensor_nine']),
    array(t('Battery Level (%)'), $data2['sensor_ten']),
    );
   $header2 = array(
    t('Node Information'),
    t('Value'),
   );
    $rows2 = array(
    array(t('Data Compression Technique'), $data['datacompression_title']),
    array(t('Number of Sensor'), $data['sensor_number']),
    array(t('Input ID'), $data['input_id']),
    array(t('Last Measured'), date( 'Y-m-d H:i:s', $data['last_measured'])),
    array(t('Reading Occurence'), $data['reading_occurence']),
    array(t('Frequency of Reading (s)'), $data['freq_read']),
    array(t('Frequency of Transmission (s)'), $data['freq_trans']),
    );
    
  $results3 = db_select('wsnplatform_observation', 'wo')
    ->fields('wo')           
    ->condition('wo.nodeentity_nid', $data['nodeentity_nid'])
    ->orderBy('wo.timestamp', 'DESC')
    ->execute();
  $header3 = array(
    t('Time Stamp'),
    t('Average Temperature'),
    t('Average Humidity'),
    t('Maximum Temperature'),
    t('Minimum Temperature'),
    t('Maximum Humidity'),
    t('Minimum Humidity'),
    t('Water Level'),
    t('Water Salinity'),
    t('Light Level'),
    t('Battery Level')
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
  } 
    $content['raw_markup'] = array(
      '#type' => 'markup',
      '#markup' => '
         <div class="row">
                <div class="col-lg-12">
              <h1>Dashboard <small>Wireless Sensor Network (WSN) Platform Node Overview</small></h1>
            </div>
          </div><!-- /.row -->
          <div class="row">
            <div class="col-lg-12">
              <div class="panel panel-primary">
                <div class="panel-heading">
                  <h3 class="panel-title"><i class="fa fa-bar-chart-o"></i>Historical Chart</h3>
                </div>
                <div class="panel-body">
                  <div id="morris-chart-area">PLACEHOLDER</div>
                </div>
              </div>
            </div>
          </div><!-- /.row -->
          <div class="row">
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
                  <h3 class="panel-title"><i class="fa fa-clock-o"></i>Recent Update</h3>
                </div>
                <div class="panel-body">'.
                theme('table', array('header' => $header, 'rows' => $rows))
                .'</div>
              </div>
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
function wsnplatform_dashboard_multi(){
  $content['raw_markup'] = array(
    '#type' => 'markup',
    '#markup' => '
    <div class = "panel-default">
    <div class = "panel-body"><div class="header-in"><p class ="lead-in">WSN Platform</p></div>
    </div></div>
    <div class = "panel-default">
    <div class = "panel-body">    
    <div class="row">
      <div class="col-md-4" align="center"><a href="wsnplatform/group" title="WSN Platform Group">
          <h1><p><span class="glyphicon glyphicon-user"></span></p></h1></n><h4><p>Group</p></h4><p></p></a>
      </div>    
      <div class="col-md-4" align="center"><a href="wsnplatform/nodeentity" title="WSN Platform Nodeentity">
          <h1><p><span class="glyphicon glyphicon-info-sign"></span></p></h1></n><h4><p>Node Entity</p></h4><p></p></a>
      </div>            
      <div class="col-md-4" align="center"><a href="wsnplatform/sensor" title="WSN Platform Sensor">
          <h1><p><span class="glyphicon glyphicon-camera"></span></p></h1></n><h4><p>Sensor</p></h4><p></p></a>
      </div>
    </div>            
    <div class="row">
      <div class="col-md-4" align="center"><a href="wsnplatform/sensormodel" title="WSN Platform Sensor Model">
          <h1><p><span class="glyphicon glyphicon-comment   "></span></p></h1></n><h4><p>Sensor Model</p></h4><p></p></a>
      </div>    
      <div class="col-md-4" align="center"><a href="wsnplatform/plant" title="WSN Platform Plant">
          <h1><p><span class="glyphicon glyphicon-leaf"></span></p></h1></n><h4><p>Plant Characteristic</p></h4><p></p></a>
      </div>            
      <div class="col-md-4" align="center"><a href="wsnplatform/notification" title="WSN Platform Notification">
          <h1><p><span class="glyphicon glyphicon-phone"></span></p></h1></n><h4><p>Notification</p></h4><p></p></a>
      </div>
    </div>
    <div class="row">
      <div class="col-md-4" align="center"><a href="wsnplatform/datacompression" title="WSN Platform Data Compression">
          <h1><p><span class="glyphicon glyphicon-compressed"></span></p></h1></n><h4><p>Data Compression</p></h4><p></p></a>
      </div>    
      <div class="col-md-4" align="center"><a href="wsnplatform/attribute" title="WSN Platform Attribute">
          <h1><p><span class="glyphicon glyphicon-list-alt"></span></p></h1></n><h4><p>Attributes</p></h4><p></p></a>
      </div>            
    </div>     </div>            
    </div>',
  );
  return $content;
}
