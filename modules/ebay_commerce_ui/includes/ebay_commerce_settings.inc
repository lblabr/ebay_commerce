<?php

/**
 * Building the form for the ebay setting page.
 */

function ebay_commerce_settings_form() {

/**
 * This is to specify the vertical tab holder.
 * One page can have two vertical tabs, but it's always one main tab with sub tabs.
 */

  $form['settingsform'] = array(
    '#type' => 'vertical_tabs',
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'ebay_commerce_ui') . '/includes/css/ebay_commerce_settings.css',
  );

  /* FIRST FIELDSET. */
  $form['first'] = array(
    '#type' => 'fieldset',
    '#title' => 'Basic',
    '#collapsible' => TRUE,
    '#description' => '',
    '#group' => 'settingsform'
  );

  // Select eBay Mode Sandbox or Production.
  $form['first']['ebay_settings_mode'] = array(
    '#type' => 'select',
    '#title' => 'Ebay Mode',
    '#default_value' => variable_get('ebay_settings_mode'),
    '#options' => array(
      'production' => t('Production'),
      'sandbox' => t('Sandbox'),
     ),
    '#ajax' => array(
      'callback' => 'ebay_admin_settings_ajax_callback_mode',
     ),
  );

  // Select eBay API version
  $form['first']['ebay_settings_api'] = array(
    '#type' => 'select',
    '#title' => 'API version',
    '#default_value' => variable_get('ebay_settings_api'),
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
      'callback' => 'ebay_admin_settings_ajax_callback_api',
    ),
  );

  // Select Site ID
  $form['first']['ebay_settings_site_id'] = array(
    '#type' => 'select',
    '#title' => 'Default Site ID',
    '#description' => 'The eBay site you want to upload to.',
    '#default_value' => variable_get('ebay_settings_site_id'),
    '#options' => ebay_commerce_select_site(),
    '#ajax' => array(
      'callback' => 'ebay_admin_settings_ajax_callback_site_id',
    ),
  );

  // Select Default Currency Settings
  $form['first']['ebay_settings_currency'] = array(
  '#type' => 'select',
  '#title' => 'Default currency',
  '#description' => 'The currency should match the site.',
  '#default_value' => variable_get('ebay_settings_currency'),
  '#options' => ebay_commerce_select_currency(),
  '#ajax' => array(
    'callback' => 'ebay_admin_settings_ajax_callback_currency',
   ),
  );

  // Select Country
  $form['first']['ebay_settings_country'] = array(
    '#type' => 'select',
    '#title' => 'Your country',
    '#description' => 'The country your operating from.',
    '#default_value' => variable_get('ebay_settings_country'),
    '#options' => ebay_commerce_select_country(),
    '#ajax' => array(
      'callback' => 'ebay_admin_settings_ajax_callback_country',
    ),
  );


  // Select Error Language
  $form['first']['ebay_settings_errorlanguage'] = array(
    '#type' => 'select',
    '#title' => 'ErrorLanguage',
    '#default_value' => variable_get('ebay_settings_errorlanguage'),
    '#options' => array(
      'en_US' => t('en_US'),
      'nl_NL' => t('nl_NL'),
     ),
    '#ajax' => array(
        'callback' => 'ebay_admin_settings_ajax_callback_errorlanguage',
     ),
  );

  // Select warninglevel
  $form['first']['ebay_settings_warninglevel'] = array(
    '#type' => 'select',
    '#title' => 'WarningLevel',
    '#default_value' => variable_get('ebay_settings_warninglevel'),
    '#options' => array(
      'High' => t('High'),
      'Low' => t('Low'),
    ),
    '#ajax' => array(
        'callback' => 'ebay_admin_settings_ajax_callback_warninglevel',
     ),
  );

  // Select InventoryTrackingMethod
  $form['first']['ebay_settings_inventory_tracking'] = array(
    '#type' => 'select',
    '#title' => 'Inventory Tracking',
    '#default_value' => variable_get('ebay_settings_inventory_tracking'),
    '#options' => array(
    'ItemID' => t('eBay-objectnumber'),
    'SKU' => t('SKU'),
    ),
    '#ajax' => array(
        'callback' => 'ebay_admin_settings_ajax_callback_inventory_tracking',
     ),
  );

  // Select Condition
  $form['first']['ebay_settings_condition_id'] = array(
  '#type' => 'select',
  '#title' =>'Condition',
  '#default_value' => variable_get('ebay_settings_condition_id'),
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
      'callback' => 'ebay_admin_settings_ajax_callback_condition_id',
   ),
  );

  $form['#submit'][] = 'ebay_admin_settings_submit'; //Submit button call back.

  return system_settings_form($form);

}



/**
 * Logic behind the form submit.
 */

function ebay_admin_settings_submit($form, $form_state) {
  // Kept it empty, intentionally.
}


/**
 * eBay Mode submit.
 */

function ebay_admin_settings_ajax_callback_mode($form, $form_state) {
  variable_set('ebay_settings_mode', $form_state['values']['ebay_settings_mode']);
}

/**
 * eBay API submit.
 */

function ebay_admin_settings_ajax_callback_api($form, $form_state) {
  variable_set('ebay_settings_api', $form_state['values']['ebay_settings_api']);
}

/**
 * eBay Site ID submit.
 */

function ebay_admin_settings_ajax_callback_site_id($form, $form_state) {
  variable_set('ebay_settings_site_id', $form_state['values']['ebay_settings_site_id']);
}

/**
 * eBay Currency submit.
 */

function ebay_admin_settings_ajax_callback_currency($form, $form_state) {
  variable_set('ebay_settings_currency', $form_state['values']['ebay_settings_currency']);
}

/**
 * eBay country submit.
 */

function ebay_admin_settings_ajax_callback_country($form, $form_state) {
  variable_set('ebay_settings_country',$form_state['values']['ebay_settings_country']);
}


/**
 * eBay Errorlanguage submit.
 */

function ebay_admin_settings_ajax_callback_errorlanguage($form, $form_state) {
  variable_set('ebay_settings_errorlanguage', $form_state['values']['ebay_settings_errorlanguage']);
}

/**
 * eBay Warninglevel submit.
 */

function ebay_admin_settings_ajax_callback_warninglevel($form, $form_state) {
  variable_set('ebay_settings_warninglevel', $form_state['values']['ebay_settings_warninglevel']);
}

/**
 * eBay InventoryTrackingMethod submit.
 */

function ebay_admin_settings_ajax_callback_inventory_tracking($form, $form_state) {
  variable_set('ebay_settings_inventory_tracking', $form_state['values']['ebay_settings_inventory_tracking']);
}


/**
 * eBay Condition_id.
 */

function ebay_admin_settings_ajax_callback_condition_id($form, $form_state) {
  variable_set('ebay_settings_condition_id', $form_state['values']['ebay_settings_condition_id']);
}


/**
 * Load site values from database to fill a select list.
 */
function ebay_commerce_select_site(){

  $result = ebay_commerce_load_site();
  $options = array();
    foreach ($result as $key => $record) {
      $options[$record->siteid] = $record->site;
    }
  asort($options);
  return $options;
}


/**
 * Load currency values from database to fill a select list.
 */
function ebay_commerce_select_currency(){

  $result = ebay_commerce_load_currency();
  $options = array();
    foreach ($result as $key => $record) {
      $options[strtoupper($record->currency)] = $record->description;
    }
  asort($options);
  return $options;
}


/**
 * Load country values from database to fill a select list.
 */
function ebay_commerce_select_country(){

  $result = ebay_commerce_load_country();
  $options = array();
    foreach ($result as $key => $record) {
      $options[strtoupper($record->country)] = $record->description;
    }
  asort($options);
  return $options;
}
