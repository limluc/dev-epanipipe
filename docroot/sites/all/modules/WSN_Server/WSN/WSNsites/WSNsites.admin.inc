<?php

/**
 * @file
 */
function WSNsites_autocomplete($string = '') {
  $matches = array();
  if ($string) {
    $query = db_select('node', 'n');

    $return = $query
      ->addTag('node_access')
      ->fields('n', array('nid', 'title'))
      ->condition('n.type', 'WSNsites')
      ->condition('title', '%' . db_like($string) . '%', 'LIKE')
      ->range(0, 10)
      ->execute();

      foreach ($return as $row) {
        $matches[$row->title] = check_plain($row->title);
      }
    }
  drupal_json_output($matches);
}