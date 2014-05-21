<?php
/**
 * @file
 * Listing bean plugin.
 */

class WetKitSearchBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'title_settings' => array(
        'backgrounds' => 'background-accent',
      ),
      'search_placeholder' => array(
        'placeholder_text' => 'e.g. population',
      ),
    );

    return array_merge(parent::values(), $values);
  }
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form['title_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure Title'),
      '#tree' => TRUE,
      '#weight' => -8,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['title_settings']['backgrounds'] = array(
      '#type' => 'select',
      '#title' => t('Configure Backgrounds'),
      '#options' => array(
        '' => t('None'),
        'background-white' => t('Background White'),
        'background-light' => t('Background Light'),
        'background-medium' => t('Background Medium'),
        'background-dark' => t('Background Dark'),
        'background-accent' => t('Background Accent'),
        'background-highlight' => t('Background Highlight'),
      ),
      '#default_value' => isset($bean->title_settings['backgrounds']) ? $bean->title_settings['backgrounds'] : '',
    );

    $form['search_placeholder'] = array(
      '#type' => 'fieldset',
      '#title' => t('Placeholder Value'),
      '#tree' => TRUE,
      '#weight' => -8,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['search_placeholder']['placeholder_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter the text to be used in the placeholder text area.'),
      '#default_value' => isset($bean->search_placeholder['placeholder_text']) ? $bean->search_placeholder['placeholder_text'] : '',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => FALSE,
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    // Title Field.
    $title = field_get_items('bean', $bean, 'title_field');
    $title = field_view_value('bean', $bean, 'title_field', $title[0], array());
    $title = render($title);

    // Search Path.
    $search_path = field_get_items('bean', $bean, 'field_bean_search_path');
    $search_path = field_view_value('bean', $bean, 'field_bean_search_path', $search_path[0], array());
    $search_path = render($search_path);

    // Background Styles.
    $background = isset($bean->title_settings['backgrounds']) ? $bean->title_settings['backgrounds'] : '';

    // Placeholder Value.
    $placeholder = isset($bean->search_placeholder['placeholder_text']) ? $bean->search_placeholder['placeholder_text'] : '';

    // Unique ID for Accessibility.
    $unique_id = 'gcwu-srch-delta-' . $bean->bid;

    $content = array();
    $markup = '<form method="get" action="' . $search_path . '">
              <h2 class="' . $background . ' font-medium">' . $title . '</h2>
              <div class="module">
                <p>
                  <label class="wb-invisible" for="' . $unique_id . '">Search Data</label>
                  <input type="search" id="' . $unique_id . '" class="search" name="q" size="30" value="" autocomplete="off" placeholder="" />
                  <button class="gcwu-srch-submit" type="submit" value="Search">' . t('Submit') . '</button>
                </p>
              </div>
            </form>';
    $content['search_bean_box']['#markup'] = $markup;

    return $content;
  }
}