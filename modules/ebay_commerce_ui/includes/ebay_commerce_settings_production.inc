<?php

/**
 * @file
 * Production settings form.
 */

/**
 * Building the form for the ebay setting page.
 */
function ebay_admin_page_settings_production_form() {

  // VERTICAL TABS HOLDER.
  $form['ebay_commerce_ui_settings'] = array(
    '#type' => 'vertical_tabs',
  );

  // FIRST FIELD SET.
  $form['first'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Credentials'),
    '#collapsible' => TRUE,
    '#description' => t('User Credentials'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  $form['first']['ebay_commerce_ui_user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('eBay ID'),
    '#default_value' => variable_get('ebay_commerce_ui_user_id'),
    '#description' => t('Enter your ebay user name or get one <a href="!link">here</a>',
    array(
      '!link' => url('https://ebay.com/'),
    )),
    '#size' => 60,
    '#maxlength' => 128,
  );

  $form['first']['ebay_commerce_ui_paypal_id'] = array(
    '#type' => 'textfield',
    '#title' => t('PayPal ID'),
    '#default_value' => variable_get('ebay_commerce_ui_paypal_id'),
    '#description' => t('Enter your PayPal user name or get one <a href="!link">here</a>',
    array(
      '!link' => url('https://paypal.com//'),
    )),
    '#size' => 60,
    '#maxlength' => 128,
  );

  // SECOND FIELD SET.
  $form['second'] = array(
    '#type' => 'fieldset',
    '#title' => t('Connection'),
    '#collapsible' => TRUE,
    '#description' => t('Connection'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  $form['second']['ebay_commerce_ui_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL to post data to'),
    '#default_value' => variable_get('ebay_commerce_ui_url'),
    '#description' => t('Enter URL like : https://api.ebay.com/ws/api.dll'),
    '#size' => 60,
    '#maxlength' => 128,
  );

  // THIRD FIELD SET.
  $form['third'] = array(
    '#type' => 'fieldset',
    '#title' => t('Developer Credentials'),
    '#collapsible' => TRUE,
    '#description' => t('Developer Credentials'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  $form['third']['ebay_commerce_ui_dev_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Dev ID'),
    '#default_value' => variable_get('ebay_commerce_ui_dev_id'),
    '#description' => t('Enter Dev ID.'),
    '#size' => 40,
    '#maxlength' => 128,
  );

  $form['third']['ebay_commerce_ui_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('App ID'),
    '#default_value' => variable_get('ebay_commerce_ui_app_id'),
    '#description' => t('Enter App ID.'),
    '#size' => 40,
    '#maxlength' => 128,
  );

  $form['third']['ebay_commerce_ui_cert_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Cert ID'),
    '#default_value' => variable_get('ebay_commerce_ui_cert_id'),
    '#description' => t('Enter Cert ID.'),
    '#size' => 40,
    '#maxlength' => 128,
  );

  // FOURTH FIELD SET.
  $form['fourth'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Token'),
    '#collapsible' => TRUE,
    '#description' => t('User Token'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  $form['fourth']['ebay_commerce_ui_user_token'] = array(
    '#type' => 'textarea',
    '#title' => t('User Token'),
    '#default_value' => variable_get('ebay_commerce_ui_user_token'),
    '#description' => t('Enter User Token'),
  );

  // FIFTH FIELD SET.
  $form['fifth'] = array(
    '#type' => 'fieldset',
    '#title' => t('Checklist'),
    '#collapsible' => TRUE,
    '#description' => t('Checklist'),
    '#group' => 'ebay_commerce_ui_settings',
  );

  // CHECKLIST.
  $form['fifth']['ebay_commerce_ui_checklist_register'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('ebay_commerce_ui_checklist_register'),
    '#title' => t('<a href="!loginlink">Register for eBay Developers Program.</a>',
    array(
      '!loginlink' => url('https://go.developer.ebay.com/developers/ebay'),
    )),
  );

  $form['fifth']['ebay_commerce_ui_checklist_account'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('ebay_commerce_ui_checklist_account'),
    '#title' => t('<a href="!loginlink">Register eBay user account.</a>',
    array(
      '!loginlink' => url('https://go.developer.ebay.com/developers/ebay'),
    )),
  );

  $form['fifth']['ebay_commerce_ui_checklist_paypal'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('ebay_commerce_ui_checklist_paypal'),
    '#title' => t('<a href="!loginlink">Register for a PayPal Account.</a>',
    array(
      '!loginlink' => url('https://developer.paypal.com/'),
    )),
  );

  // Submit button call back.
  $form['#submit'][] = 'ebay_admin_settings_production_submit';
  return system_settings_form($form);

}

/**
 * Logic behind the form submit.
 */
function ebay_admin_settings_production_submit($form, $form_state) {
  // Kept it empty, intentionally.
}
