<?php
/**
 * @file
 * wetkit_demo.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function wetkit_demo_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'wetkit_demo_panel_front';
  $page->task = 'page';
  $page->admin_title = 'WetKit Demo Front';
  $page->admin_description = 'This is a demo panel for WetKit so folks can see the magic';
  $page->path = 'demo';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Homepage Demo',
    'name' => 'main-menu',
    'weight' => '-10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_wetkit_demo_panel_front_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'wetkit_demo_panel_front';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Demo Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'sutherland';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'contentmain' => NULL,
      'footer' => NULL,
      'sutherland_top' => NULL,
      'sutherland_first' => NULL,
      'sutherland_second' => NULL,
      'sutherland_third' => NULL,
      'sutherland_bottom' => NULL,
    ),
    'sidebar' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Homepage Demo';
  $display->uuid = 'f434ee22-6e3e-9b44-a9d4-b7c4547f9236';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-58cc44ff-0714-cd44-1926-1aa1e66533a1';
    $pane->panel = 'sutherland_bottom';
    $pane->type = 'block';
    $pane->subtype = 'bean-stay-connected';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '58cc44ff-0714-cd44-1926-1aa1e66533a1';
    $display->content['new-58cc44ff-0714-cd44-1926-1aa1e66533a1'] = $pane;
    $display->panels['sutherland_bottom'][0] = 'new-58cc44ff-0714-cd44-1926-1aa1e66533a1';
    $pane = new stdClass();
    $pane->pid = 'new-673f621a-6667-3cc4-e51d-31865bc28dd5';
    $pane->panel = 'sutherland_first';
    $pane->type = 'views_panes';
    $pane->subtype = 'headlines_front_page-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'widget_title' => NULL,
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '673f621a-6667-3cc4-e51d-31865bc28dd5';
    $display->content['new-673f621a-6667-3cc4-e51d-31865bc28dd5'] = $pane;
    $display->panels['sutherland_first'][0] = 'new-673f621a-6667-3cc4-e51d-31865bc28dd5';
    $pane = new stdClass();
    $pane->pid = 'new-318e3336-b899-3564-85eb-82c899b4be0f';
    $pane->panel = 'sutherland_second';
    $pane->type = 'block';
    $pane->subtype = 'bean-videos';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '318e3336-b899-3564-85eb-82c899b4be0f';
    $display->content['new-318e3336-b899-3564-85eb-82c899b4be0f'] = $pane;
    $display->panels['sutherland_second'][0] = 'new-318e3336-b899-3564-85eb-82c899b4be0f';
    $pane = new stdClass();
    $pane->pid = 'new-56e85812-54bb-8124-5d5e-2e13dd16b972';
    $pane->panel = 'sutherland_third';
    $pane->type = 'block';
    $pane->subtype = 'bean-priorities';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '56e85812-54bb-8124-5d5e-2e13dd16b972';
    $display->content['new-56e85812-54bb-8124-5d5e-2e13dd16b972'] = $pane;
    $display->panels['sutherland_third'][0] = 'new-56e85812-54bb-8124-5d5e-2e13dd16b972';
    $pane = new stdClass();
    $pane->pid = 'new-6b59bb72-83b6-7974-4d87-b18cfee098ca';
    $pane->panel = 'sutherland_third';
    $pane->type = 'block';
    $pane->subtype = 'bean-minister';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6b59bb72-83b6-7974-4d87-b18cfee098ca';
    $display->content['new-6b59bb72-83b6-7974-4d87-b18cfee098ca'] = $pane;
    $display->panels['sutherland_third'][1] = 'new-6b59bb72-83b6-7974-4d87-b18cfee098ca';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['wetkit_demo_panel_front'] = $page;

  return $pages;

}
