<?php
/**
 * @file
 * wetkit_language.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function wetkit_language_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['en'] = array(
  'wetkit_metatag_creator' => 'Web Experience Toolkit',
);
  $realm_variables['language']['fr'] = array(
  'wetkit_metatag_creator' => 'Boîte à outils de l\'expérience Web',
  'pathauto_ignore_words' => 'à, ainsi, alors, après, aussi, avant, avec, car, certes, chez, comme, ceci, cela, d\', dans, de, dehors, depuis, derrière, des, donc, en, ensuite, envers, et, etc, ici, jusqu, jusque, l, la, le, les, là, mais, même, ni, or, où, par, pendant, pour, près, sans, sauf, selon, sous, sur, tout, un, une, vers, vu',
);

return $realm_variables;
}
