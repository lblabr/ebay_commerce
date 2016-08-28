<?php

/**
 * @file
 * Sandbox settings.
 */

/**
 * Building form for the eBay Sandbox setting page.
 */
function ebay_admin_page_settings_sandbox_form() {

  // VERTICAL TABS HOLDER.
  $form['ebay_commerce_ui_settings'] = array(
    '#type' => 'vertical_tabs',
  );

  /* FIRST FIELDSET. */
  $form['first'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Credentials'),
    '#collapsible' => TRUE,
    '#description' => t('User Credentials'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  $form['first']['ebay_commerce_ui_sandbox_user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('eBay ID'),
  // variable_get('ebay_commerce_ui_sandbox_user_id'),.
    '#default_value' => EBAY_COMMERCE_USER_ID,
    '#description' => t('Enter your ebay sandbox user name or get one <a href="!link">here</a>',
    array(
      '!link' => url('https://developer.ebay.com/DevZone/sandboxuser/default.aspx'),
    )),
    '#size' => 60,
    '#maxlength' => 128,
  );

  $form['first']['ebay_commerce_ui_sandbox_paypal_id'] = array(
    '#type' => 'textfield',
    '#title' => t('PayPal ID'),
  // variable_get('ebay_commerce_ui_sandbox_paypal_id'),.
    '#default_value' => EBAY_COMMERCE_USER_PAYPAL,
    '#description' => t('Enter your PayPal sandbox user name or get one <a href="!link">here</a>',
    array(
      '!link' => url('https://developer.paypal.com//'),
    )),
    '#size' => 60,
    '#maxlength' => 128,
  );
  /* SECOND FIELDSET. */
  $form['second'] = array(
    '#type' => 'fieldset',
    '#title' => t('Connection'),
    '#collapsible' => TRUE,
    '#description' => t('Connection'),
    '#group' => 'ebay_commerce_ui_settings',
  );
  $form['second']['ebay_commerce_ui_sandbox_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL to post data to'),
    '#default_value' => EBAY_COMMERCE_SERVER_URL,
    '#description' => t('Enter URL like : https://api.sandbox.ebay.com/ws/api.dll'),
    '#size' => 60,
    '#maxlength' => 128,
  );

  /* THIRD FIELDSET. */
  $form['third'] = array(
    '#type' => 'fieldset',
    '#title' => t('Developer Credentials'),
    '#collapsible' => TRUE,
    '#description' => t('Developer Credentials'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  $form['third']['ebay_commerce_ui_sandbox_dev_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Dev ID'),
  // variable_get('ebay_commerce_ui_sandbox_dev_id'),.
    '#default_value' => EBAY_COMMERCE_DEVELOPER_ID,
    '#description' => t('Enter Dev ID.'),
    '#size' => 40,
    '#maxlength' => 128,
  );

  $form['third']['ebay_commerce_ui_sandbox_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('App ID'),
  // variable_get('ebay_commerce_ui_sandbox_app_id'),.
    '#default_value' => EBAY_COMMERCE_APPLICATION_ID,
    '#description' => t('Enter App ID.'),
    '#size' => 40,
    '#maxlength' => 128,
  );

  $form['third']['ebay_commerce_ui_sandbox_cert_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Cert ID'),
  // variable_get('ebay_commerce_ui_sandbox_cert_id'),.
    '#default_value' => EBAY_COMMERCE_CERT_ID,
    '#description' => t('Enter Cert ID.'),
    '#size' => 40,
    '#maxlength' => 128,
  );

  /* FOURTH FIELDSET. */
  $form['fourth'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Token'),
    '#collapsible' => TRUE,
    '#description' => t('User Token'),
    '#group' => 'ebay_commerce_ui_settings',
  );
  $form['fourth']['ebay_commerce_ui_sandbox_user_token'] = array(
    '#type' => 'textarea',
    '#title' => t('User Token'),
  // variable_get('ebay_commerce_ui_sandbox_user_token'),.
    '#default_value' => EBAY_COMMERCE_USER_TOKEN,
    '#description' => t('Enter User Token'),
  );

  /* FIFTH FIELDSET. */
  $form['fifth'] = array(
    '#type' => 'fieldset',
    '#title' => t('Checklist'),
    '#collapsible' => TRUE,
    '#description' => t('Checklist'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  // CHECKLIST.
  $form['fifth']['ebay_commerce_ui_sandbox_checklist_register'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('ebay_commerce_ui_sandbox_checklist_register'),
    '#title' => t('<a href="!loginlink">Register for eBay Developers Program.</a>', array('!loginlink' => url('https://go.developer.ebay.com/developers/ebay'))),
  );
  $form['fifth']['ebay_commerce_ui_sandbox_checklist_account'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('ebay_commerce_ui_sandbox_checklist_account'),
    '#title' => t('<a href="!loginlink">Register eBay Sandbox user account.</a>', array('!loginlink' => url('https://go.developer.ebay.com/developers/ebay'))),
  );
  $form['fifth']['ebay_commerce_ui_sandbox_checklist_paypal'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('ebay_commerce_ui_sandbox_checklist_paypal'),
    '#title' => t('<a href="!loginlink">Register for a PayPal Sandbox Account.</a>', array('!loginlink' => url('https://developer.paypal.com/'))),
  );

  // Submit button call back.
  $form['#submit'][] = 'ebay_admin_settings_sandbox_submit';

  return system_settings_form($form);

}

/**
 * Logic behind the form submit.
 */
function ebay_admin_settings_sandbox_submit($form, $form_state) {
  $ebay = ebay_commerce_get_time();
  if ($ebay) {
    drupal_set_message(t('Connected to ebay on @time', array(
      '@time' => $ebay->time_format,
    )));
  }
  else {
    drupal_set_message(t('Could not connect to eBay, check your credentials and make sure are connected to the internet.'));
  }
}
