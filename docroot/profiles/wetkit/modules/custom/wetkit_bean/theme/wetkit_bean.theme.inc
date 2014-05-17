<?php
/**
 * @file
 * Bean example plugin theme templates for article listing.
 */

/**
 * Define theme templates.
 */
function theme_wetkit_highlight_settings(&$variables) {
  return l($variables['text'], $variables['path'], array('attributes' => array('class' => array('more-link'))));
}

/**
 * Themes a field collection to match a Tabbed Interface pattern.
 */
function theme_wetkit_slide_collection($variables) {
  $bean      = $variables['bean'];
  $items     = $variables['items'];
  $use_pager = $variables['use_pager'];

  // Collect image urls.
  $images = array();
  foreach ($items as $item_key => $data) {
    $key = array_keys($data['data']['entity']['field_collection_item']);
    $key = array_pop($key);
    $item = &$data['data']['entity']['field_collection_item'][$key];

    if ($bean->data['image_style'] == '<none>') {
      $images[] = file_create_url($item['field_slide_image'][0]['#item']['uri']);
    }
    else {
      $images[] = image_style_url($item['field_slide_image'][0]['#image_style'], $item['field_slide_image'][0]['#item']['uri']);
    }
  }

  // Collect title fields.
  $titles = array();
  foreach ($items as $item_key => $data) {
    $key = array_keys($data['data']['entity']['field_collection_item']);
    $key = array_pop($key);
    $item = $data['data']['entity']['field_collection_item'][$key];

    $titles[] = $item['field_slide_headline']['#items'][0]['safe_value'];
  }

  drupal_alter('wetkit_slide_slideshow', $items, $images, $bean);
  foreach ($items as $key => $data) {
    $items[$key] = drupal_render($data['data']);
  }

  // Add unique id.
  $id = drupal_html_id('bean-slide');

  // Add settings for this slideshow.
  $data = $bean->data;
  $data['id'] = $id;
  $data['images'] = $images;

  // Support Tabbed Interface.
  if ($data['slideshow_plugin'] === 'wetkit_slide:tabbedinterface') {

    // Plugin Effects.
    $effects = array(
      'animate_effect' => isset($data['plugin_settings']['animate_effect']) ? $data['plugin_settings']['animate_effect'] : '',
      'autoplay' => isset($data['plugin_settings']['autoplay']) && $data['plugin_settings']['autoplay'] ? 'auto-play' : '',
      'rotate_effect' => isset($data['plugin_settings']['rotate_effect']) ? $data['plugin_settings']['rotate_effect'] : '',
      'tabs_style_effect' => isset($data['plugin_settings']['tabs_style_effect']) ? $data['plugin_settings']['tabs_style_effect'] : '',
    );

    $css_classes = implode(" ", array_values($effects));
    $title = t('Tab List');
    $header = theme('wetkit_slide_header', array('items' => $titles, 'title' => $title, 'type' => 'ul', 'attributes' => array('class' => array('tabs'))));
    $output = theme('wetkit_slide_tab_panels', array('items' => $items, 'title' => $title, 'type' => 'div', 'attributes' => array('class' => array('tabs-panel'))));
    $output = '<div class="wet-boew-tabbedinterface ' . $css_classes . '">' . $header . $output . '</div>';
  }
  // Support FlexSlider and jQuery.Cycle.
  else {
    $output = theme('item_list', array('items' => $items, 'attributes' => array('class' => array('slides'))));
    $output = '<div id="' . $id . '" class="bean-slide clearfix">' . $output . '</div>';
  }

  drupal_add_js(array(
    'wetkitbean' => array(
      'slideshows' => array($data),
    ),
  ), 'setting');

  return $output;
}

/**
 * Themes the Tabbed Interface header.
 */
function theme_wetkit_slide_header($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  $output = '';
  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';

    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $i++;
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }

      $output .= '<li><a href="#tabs' . $i . '">' . $item . "</a></li>\n";
    }

    $output .= "</$type>";
  }
  return $output;
}

/**
 * Themes the Tabbed Interface panels.
 */
function theme_wetkit_slide_tab_panels($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  $output = '';
  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = '<section>' . $item . '</section>';
      }

      $attributes['id'][] = "tabs$i";
      $attributes['class'][] = "tabs-content-pad";

      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }

      $output .= '<div' . drupal_attributes($attributes) . '>' . $data . "</div>\n";

    }
    $output .= "</$type>";
  }
  return $output;
}

/**
 * Themes a field collection to match a Video pattern.
 */
function theme_wetkit_media_collection($variables) {
  $bean      = $variables['bean'];
  $items     = $variables['items'];
  $use_pager = $variables['use_pager'];

  $media_attributes = array();
  $source_attributes = array();
  $track_attributes = array();
  $wrapper_attributes = array();
  $type_of_media = '';
  $output = '';

  // Collect media.
  foreach ($items as $item_key => $data) {
    $key = array_keys($data['data']['entity']['field_collection_item']);
    $key = array_pop($key);
    $item = $data['data']['entity']['field_collection_item'][$key];

    $source_attributes = array(
      'src' => file_create_url($item['field_media_file'][0]['#file']->uri),
      'type' => $item['field_media_file'][0]['#file']->filemime,
    );

    $audio_types = array(
      'audio/mpeg',
      'audio/ogg',
    );
    if (in_array($item['field_media_file'][0]['#file']->filemime, $audio_types)) {
      $type_of_media = 'audio';
    }
    else {
      $type_of_media = 'video';
    }
  }

  // Collect the poster.
  $poster = array();
  foreach ($items as $item_key => $data) {
    $key = array_keys($data['data']['entity']['field_collection_item']);
    $key = array_pop($key);
    $item = &$data['data']['entity']['field_collection_item'][$key];

    if ($bean->data['image_style'] == '<none>') {
      $poster[] = file_create_url($item['field_media_poster'][0]['#item']['uri']);
    }
    else {
      $poster[] = image_style_url($item['field_media_poster'][0]['#image_style'], $item['field_media_poster'][0]['#item']['uri']);
    }
  }

  // Attribute handling.
  $media_attributes['width'] = '480';
  $media_attributes['height'] = '270';
  if ($type_of_media == 'video') {
    $media_attributes['poster'] = $poster;
  }
  $wrapper_attributes['class'] = 'wet-boew-multimedia ' . $bean->media_span;

  // Collect the caption.
  foreach ($items as $item_key => $data) {
    $key = array_keys($data['data']['entity']['field_collection_item']);
    $key = array_pop($key);
    $item = $data['data']['entity']['field_collection_item'][$key];

    $track_attributes = array(
      'data-type' => $item['field_media_caption'][0]['#file']->filemime,
      'kind' => 'captions',
      'src' => file_create_url($item['field_media_caption'][0]['#file']->uri),
    );
  }

  // Final Render.
  if ($type_of_media == 'audio') {
    $output .= '<div' . drupal_attributes($wrapper_attributes) . '><audio' . drupal_attributes($media_attributes) . '>';
    $output .= '<source' . drupal_attributes($source_attributes) . ' />';
    $output .= '</audio></div>';
  }
  else {
    $output .= '<div' . drupal_attributes($wrapper_attributes) . '><video' . drupal_attributes($media_attributes) . '>';
    $output .= '<source' . drupal_attributes($source_attributes) . ' />';
    $output .= '<track' . drupal_attributes($track_attributes) . ' />';
    $output .= '</video></div>';
  }

  return $output;
}

/**
 * Themes a slideout tab.
 */
function theme_wetkit_slideout(&$variables) {
  $show_title = $variables['show_title'];
  $hide_title = $variables['hide_title'];
  $contents = $variables['contents'];
  $output = '<div class="wet-boew-slideout" data-wet-boew=';

  if (empty($hide_title)) {
    $hide_title = $show_title;
  }
  $output .= "'{\"txtShow\": \"$show_title\", \"txtHide\": \"$hide_title\"}'>";

  $output .= drupal_render_children($contents);

  $output .= '</div>';
  return $output;
}
