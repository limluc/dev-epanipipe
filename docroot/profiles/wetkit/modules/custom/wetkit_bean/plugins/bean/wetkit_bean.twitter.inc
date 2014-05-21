<?php
/**
 * @file
 * Listing bean plugin.
 */

class WetKitTwitterBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    $values = array(
      'twitter_settings' => array(
        'configure_twitter_widget' => 'span-2',
        'custom_css' => '',
        'widget_type' => '',
        'username' => '',
        'search_query' => '',
        'widget_id' => '',
        'tweet_limit' => '',
      ),
    );

    return array_merge(parent::values(), $values);
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();

    $form['twitter_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Configure Twitter Widget'),
      '#tree' => TRUE,
      '#weight' => -8,
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
    );
    $form['twitter_settings']['configure_twitter_widget'] = array(
      '#type' => 'select',
      '#title' => t('Configure Share Span'),
      '#options' => array(
        'span-2' => t('Span 2'),
        'span-3' => t('Span 3'),
        'span-4' => t('Span 4'),
        'span-5' => t('Span 5'),
        'span-6' => t('Span 6'),
        'span-7' => t('Span 7'),
        'span-8' => t('Span 8'),
      ),
      '#default_value' => isset($bean->twitter_settings['configure_twitter_widget']) ? $bean->twitter_settings['configure_twitter_widget'] : '',
    );
    $form['twitter_settings']['custom_css'] = array(
      '#type' => 'textfield',
      '#title' => t('Configure Twitter Custom CSS'),
      '#default_value' => isset($bean->twitter_settings['custom_css']) ? $bean->twitter_settings['custom_css'] : '',
      '#size' => 60,
      '#maxlength' => 128,
      '#required' => FALSE,
    );
    $form['twitter_settings']['widget_type'] = array(
      '#type' => 'select',
      '#title' => t('Twitter widget type'),
      '#description' => t('Shows the user\'s most recent tweets.'),
      '#options' => array(
        'profile' => t('Profile'),
        'search' => t('Search'),
      ),
      '#default_value' => isset($bean->twitter_settings['widget_type']) ? $bean->twitter_settings['widget_type'] : '',
      '#required' => TRUE,
    );
    $form['twitter_settings']['username'] = array(
      '#type' => 'textfield',
      '#title' => t('Twitter user name: @'),
      '#size' => 25,
      '#maxlength' => 25,
      '#default_value' => isset($bean->twitter_settings['username']) ? $bean->twitter_settings['username'] : '',
      '#states' => array(
        'visible' => array(
          ':input[name="twitter_settings[widget_type]"]' => array('value' => 'profile'),
        ),
      ),
    );
    $form['twitter_settings']['search_query'] = array(
      '#type' => 'textfield',
      '#title' => t('Twitter search query'),
      '#size' => 25,
      '#maxlength' => 25,
      '#default_value' => isset($bean->twitter_settings['search_query']) ? $bean->twitter_settings['search_query'] : '',
      '#states' => array(
        'visible' => array(
          ':input[name="twitter_settings[widget_type]"]' => array('value' => 'search'),
        ),
      ),
    );
    $form['twitter_settings']['widget_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Twitter widget ID'),
      '#description' => t('Widget ID provided by twitter. The ID is required for the widget to work and must be created on https://twitter.com/settings/widgets'),
      '#size' => 80,
      '#maxlength' => 80,
      '#default_value' => isset($bean->twitter_settings['widget_id']) ? $bean->twitter_settings['widget_id'] : '',
      '#required' => TRUE,
    );

    $form['twitter_settings']['tweet_limit'] = array(
      '#type' => 'select',
      '#title' => t('Tweet limit'),
      '#default_value' => isset($bean->twitter_settings['tweet_limit']) ? $bean->twitter_settings['tweet_limit'] : '',
      '#options' => array('' => drupal_map_assoc(range(1, 20))),
      '#description' => t('Fix the size of a timeline to a preset number of Tweets between 1 and 20. The timeline will render the specified number of Tweets from the timeline, expanding the height of the widget to display all Tweets without scrolling.'),
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {

    $span = isset($bean->twitter_settings['configure_twitter_widget']) ? $bean->twitter_settings['configure_twitter_widget'] : '';
    $custom_css = isset($bean->twitter_settings['custom_css']) ? $bean->twitter_settings['custom_css'] : '';

    $widget_id = isset($bean->twitter_settings['widget_id']) ? $bean->twitter_settings['widget_id'] : '';
    $widget_type = isset($bean->twitter_settings['widget_type']) ? $bean->twitter_settings['widget_type'] : 'search';
    $username = isset($bean->twitter_settings['username']) ? $bean->twitter_settings['username'] : '';
    $search_query = isset($bean->twitter_settings['search_query']) ? $bean->twitter_settings['search_query'] : '';
    $tweet_limit = isset($bean->twitter_settings['tweet_limit']) ? 'data-tweet-limit="' . $bean->twitter_settings['tweet_limit'] . '"' : '';

    $url = "https://twitter.com/";
    switch ($widget_type) {
      case 'profile':
        $url .= $username;
      case 'search':
        $url .= 'search?q=' . $search_query;
    }

    $title = field_get_items('bean', $bean, 'title_field');
    $title = field_view_value('bean', $bean, 'title_field', $title[0], array());
    $title = render($title);

    $content = array();

    $markup = '<div class="wet-boew-webwidget ' . $span . '"><div class="widget-container">
                <section>
                  <h3 class="background-accent">' . $title . '</h3>
                  <article><a class="twitter-timeline" href="' . $url . '" data-widget-id="' . $widget_id . '" ' . $tweet_limit . '>Tweets</a></article>
                </section>
              </div></div>';
    $content['share_twitter']['#markup'] = $markup;

    return $content;
  }
}
