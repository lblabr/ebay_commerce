<?php

/**
 * @file
 * Building the form for the ebay setting page.
 */

/**
 * Implements hook_form().
 */
function ebay_commerce_ui_settings_form() {
  // Vertical tab holder.
  $form['ebay_commerce_ui_settings'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'ebay_commerce_ui') . '/includes/css/ebay_commerce_settings.css',
  );

  // First field set.
  $form['first'] = array(
    '#type' => 'fieldset',
    '#title' => 'Basic',
    '#collapsible' => TRUE,
    '#description' => t('Basic'),
    '#group' => 'ebay_commerce_ui_settings',
  );
  $form['first'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enter your other details below'),
    '#description' => t('These are all optional'),
  );

  // Select eBay Mode Sandbox or Production.
  $form['first']['ebay_commerce_ui_mode'] = array(
    '#type' => 'select',
    '#title' => 'Ebay Mode',
    '#description' => t('Sandbox or production mode.'),
    '#default_value' => EBAY_COMMERCE_MODE,
    '#options' => array(
      'sandbox' => t('Sandbox'),
      'production' => t('Production'),
    ),
  );

  // Select eBay API version.
  $form['first']['ebay_commerce_ui_api'] = array(
    '#type' => 'select',
    '#title' => 'API version',
    '#description' => t('eBay API version to use.'),
    '#default_value' => EBAY_COMMERCE_API,
    '#options' => array(
      '841' => t('841'),
      '845' => t('845'),
      '847' => t('847'),
      '848' => t('848'),
      '849' => t('849'),
      '850' => t('850'),
      '945' => t('945'),
    ),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_api',
    ),
  );

  // Select Site ID.
  $form['first']['ebay_commerce_ui_site_id'] = array(
    '#type' => 'select',
    '#title' => 'Default Site ID',
    '#description' => t('The eBay site you want to upload to.'),
    '#default_value' => EBAY_COMMERCE_SITE,
    '#options' => ebay_commerce_select_site(),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_site_id',
    ),
  );

  // Select Default Currency Settings.
  $form['first']['ebay_commerce_ui_currency'] = array(
    '#type' => 'select',
    '#title' => 'Default currency',
    '#description' => t('The currency should match the site.'),
    '#default_value' => EBAY_COMMERCE_CURRENCY,
    '#options' => ebay_commerce_select_currency(),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_currency',
    ),
  );

  // Select Country.
  $form['first']['ebay_commerce_ui_country'] = array(
    '#type' => 'select',
    '#title' => 'Your country',
    '#description' => t('The country your operating from.'),
    '#default_value' => EBAY_COMMERCE_COUNTRY,
    '#options' => ebay_commerce_select_country(),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_country',
    ),
  );

  // Select Error Language.
  $form['first']['ebay_commerce_ui_error_language'] = array(
    '#type' => 'select',
    '#title' => 'Error language',
    '#description' => t('The language to display the errors in.'),
    '#default_value' => EBAY_COMMERCE_ERROR_LANGUAGE,
    '#options' => array(
      'en_US' => t('en_US'),
      'nl_NL' => t('nl_NL'),
    ),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_error_language',
    ),
  );

  // Select warning level.
  $form['first']['ebay_commerce_ui_warning_level'] = array(
    '#type' => 'select',
    '#title' => 'Warning level',
    '#description' => t('The warning level.'),
    '#default_value' => EBAY_COMMERCE_WARNING_LEVEL,
    '#options' => array(
      'High' => t('High'),
      'Low' => t('Low'),
    ),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_warning_level',
    ),
  );

  // Select Inventory tracking method.
  $form['first']['ebay_commerce_ui_inventory_tracking'] = array(
    '#type' => 'select',
    '#title' => 'Inventory Tracking',
    '#description' => t('How u want eBay to track your products.'),
    '#default_value' => EBAY_COMMERCE_INVENTORY_TRACKING,
    '#options' => array(
      'ItemID' => t('eBay-objectnumber'),
      'SKU' => t('SKU'),
    ),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_inventory_tracking',
    ),
  );

  // Select Condition.
  $form['first']['ebay_commerce_ui_condition_id'] = array(
    '#type' => 'select',
    '#title' => 'Condition',
    '#description' => t('The default product condition.'),
    '#default_value' => EBAY_COMMERCE_CONDITION,
    '#options' => array(
      '1000' => t('New'),
      '1500' => t('New other (see details)'),
      '1750' => t('New with defects'),
      '2000' => t('Manufacturer refurbished'),
      '2500' => t('Seller refurbished'),
      '3000' => t('Used'),
      '4000' => t('Very Good'),
      '5000' => t('Good'),
      '6000' => t('Acceptable'),
      '7000' => t('For parts or not working'),
    ),
    '#ajax' => array(
      'callback' => 'ebay_commerce_ui_ajax_callback_condition_id',
    ),
  );

  // Submit button call back.
  $form['#submit'][] = 'ebay_commerce_ui_settings_submit';

  return system_settings_form($form);

}

/**
 * Logic behind the form submit.
 */
function ebay_commerce_ui_settings_submit($form, $form_state) {
  // code.
}

/**
 * EBay Mode submit.
 */
function ebay_commerce_ui_ajax_callback_mode($form, $form_state) {
  variable_set('ebay_commerce_ui_mode', $form_state['values']['ebay_commerce_ui_mode']);
}

/**
 * EBay API submit.
 */
function ebay_commerce_ui_ajax_callback_api($form, $form_state) {
  variable_set('ebay_commerce_ui_api', $form_state['values']['ebay_commerce_ui_api']);
}

/**
 * EBay Site ID submit.
 */
function ebay_commerce_ui_ajax_callback_site_id($form, $form_state) {
  variable_set('ebay_commerce_ui_site_id', $form_state['values']['ebay_commerce_ui_site_id']);
}

/**
 * EBay Currency submit.
 */
function ebay_commerce_ui_ajax_callback_currency($form, $form_state) {
  variable_set('ebay_commerce_ui_currency', $form_state['values']['ebay_commerce_ui_currency']);
}

/**
 * EBay country submit.
 */
function ebay_commerce_ui_ajax_callback_country($form, $form_state) {
  variable_set('ebay_commerce_ui_country', $form_state['values']['ebay_commerce_ui_country']);
}

/**
 * EBay error language submit.
 */
function ebay_commerce_ui_ajax_callback_error_language($form, $form_state) {
  variable_set('ebay_commerce_ui_error_language', $form_state['values']['ebay_commerce_ui_error_language']);
}

/**
 * EBay Warning level submit.
 */
function ebay_commerce_ui_ajax_callback_warning_level($form, $form_state) {
  variable_set('ebay_commerce_ui_warning_level', $form_state['values']['ebay_commerce_ui_warning_level']);
}

/**
 * EBay InventoryTrackingMethod submit.
 */
function ebay_commerce_ui_ajax_callback_inventory_tracking($form, $form_state) {
  variable_set('ebay_commerce_ui_inventory_tracking', $form_state['values']['ebay_commerce_ui_inventory_tracking']);
}

/**
 * EBay Condition_id.
 */
function ebay_commerce_ui_ajax_callback_condition_id($form, $form_state) {
  variable_set('ebay_commerce_ui_condition_id', $form_state['values']['ebay_commerce_ui_condition_id']);
}

/**
 * Select sites.
 *
 * @return array
 *   list of sites.
 */
function ebay_commerce_select_site() {

  if (module_exists('ebay_commerce_loader')) {
    if (ebay_commerce_settings_check()) {
      $result = ebay_commerce_load_site();
      $options = array();
      foreach ($result as $record) {
        $options[$record->siteid] = $record->site;
      }
    }
  }
  else {
    $options = array(
      '0' => t('US'),
      '146' => t('NL'),
    );
  }
  asort($options);
  return $options;
}

/**
 * Select currency.
 *
 * @return array
 *   List of currencies.
 */
function ebay_commerce_select_currency() {

  if (module_exists('ebay_commerce_loader')) {
    if (ebay_commerce_settings_check()) {
      $result = ebay_commerce_load_currency();
      $options = array();
      foreach ($result as $record) {
        $options[strtoupper($record->currency)] = $record->description;
      }
    }
  }
  else {
    $options = array(
      'USD' => t('US Dollar'),
      'EUR' => t('Euro'),
    );
  }
  asort($options);
  return $options;
}

/**
 * Select country.
 *
 * @return array
 *   List of countries.
 */
function ebay_commerce_select_country() {

  if (module_exists('ebay_commerce_loader')) {
    if (ebay_commerce_settings_check()) {
      $result = ebay_commerce_load_country();
      $options = array();
      foreach ($result as $record) {
        $options[strtoupper($record->country)] = $record->description;
      }
    }
  }
  else {
    $options = array(
      'US' => t('United States'),
      'NL' => t('Netherlands'),
    );
  }
  asort($options);
  return $options;
}
