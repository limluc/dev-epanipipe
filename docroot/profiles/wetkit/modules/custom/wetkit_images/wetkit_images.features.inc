<?php
/**
 * @file
 * wetkit_images.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wetkit_images_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function wetkit_images_image_default_styles() {
  $styles = array();

  // Exported image style: wetkit_image_featured.
  $styles['wetkit_image_featured'] = array(
    'name' => 'wetkit_image_featured',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      3 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 480,
          'height' => 260,
          'anchor' => 'center-center',
        ),
        'weight' => 3,
      ),
    ),
    'label' => 'wetkit_image_featured',
  );

  // Exported image style: wetkit_image_full.
  $styles['wetkit_image_full'] = array(
    'name' => 'wetkit_image_full',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 960,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'wetkit_image_full',
  );

  // Exported image style: wetkit_image_half.
  $styles['wetkit_image_half'] = array(
    'name' => 'wetkit_image_half',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'wetkit_image_half',
  );

  // Exported image style: wetkit_image_mobile.
  $styles['wetkit_image_mobile'] = array(
    'name' => 'wetkit_image_mobile',
    'label' => 'wetkit_image_mobile',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wetkit_image_narrow.
  $styles['wetkit_image_narrow'] = array(
    'name' => 'wetkit_image_narrow',
    'label' => 'wetkit_image_narrow',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 940,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: wetkit_image_quarter.
  $styles['wetkit_image_quarter'] = array(
    'name' => 'wetkit_image_quarter',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 240,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'wetkit_image_quarter',
  );

  // Exported image style: wetkit_image_spotlight.
  $styles['wetkit_image_spotlight'] = array(
    'name' => 'wetkit_image_spotlight',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most use',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 960,
          'height' => 560,
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'wetkit_image_spotlight',
  );

  // Exported image style: wetkit_image_square.
  $styles['wetkit_image_square'] = array(
    'name' => 'wetkit_image_square',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'wetkit_image_square',
  );

  // Exported image style: wetkit_image_thumbnail.
  $styles['wetkit_image_thumbnail'] = array(
    'name' => 'wetkit_image_thumbnail',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 80,
          'height' => 80,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'wetkit_image_thumbnail',
  );

  // Exported image style: wetkit_image_video.
  $styles['wetkit_image_video'] = array(
    'name' => 'wetkit_image_video',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 390,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'wetkit_image_video',
  );

  // Exported image style: wetkit_image_wide.
  $styles['wetkit_image_wide'] = array(
    'name' => 'wetkit_image_wide',
    'label' => 'wetkit_image_wide',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1180,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
