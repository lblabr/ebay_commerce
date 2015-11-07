<?php
/**
* Building the form for the ebay setting page.
*/
function ebay_admin_page_settings_production_form() {
 /* VERTICAL TABS HOLDER */
	$form['settingsform'] = array(
	'#type' => 'vertical_tabs',
	);
/* FIRST FIELDSET. */
	$form['first'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Credentials'),
    '#collapsible' => TRUE,
    '#description' => t(''),
    '#group' => 'settingsform'
	);
	$form['first']['ebay_user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('eBay ID'),
    '#default_value' => variable_get('ebay_user_id'),
    '#description' => t('Enter your ebay user name or get one <a href="!link">here</a>' , array('!link' => url('https://ebay.com/')) ),
	'#size' => 60,
	'#maxlength' => 128,
	);
	$form['first']['ebay_admin_production_paypal_id'] = array(
    '#type' => 'textfield',
    '#title' => t('PayPal ID'),
    '#default_value' => variable_get('ebay_admin_production_paypal_id'),
    '#description' => t('Enter your PayPal user name or get one <a href="!link">here</a>' , array('!link' => url('https://paypal.com//')) ),
	'#size' => 60,
	'#maxlength' => 128,
	);
/* SECOND FIELDSET. */
	$form['second'] = array(
    '#type' => 'fieldset',
    '#title' => t('Connection'),
    '#collapsible' => TRUE,
    '#description' => t(''),
    '#group' => 'settingsform'
	);
	$form['second']['ebay_admin_production_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL to post data to'),
    '#default_value' => variable_get('ebay_admin_production_url'),
    '#description' => t('Enter URL like : https://api.ebay.com/ws/api.dll'),
	'#size' => 60,
	'#maxlength' => 128,
	);
/* THIRD FIELDSET. */
	$form['third'] = array(
    '#type' => 'fieldset',
    '#title' => t('Developer Credentials'),
    '#collapsible' => TRUE,
    '#description' => t(''),
    '#group' => 'settingsform'
	);
	$form['third']['ebay_admin_production_dev_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Dev ID'),
    '#default_value' => variable_get('ebay_admin_production_dev_id'),
    '#description' => t('Enter Dev ID.'),
	'#size' => 40,
	'#maxlength' => 128,
	);
	$form['third']['ebay_admin_production_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('App ID'),
    '#default_value' => variable_get('ebay_admin_production_app_id'),
    '#description' => t('Enter App ID.'),
	'#size' => 40,
	'#maxlength' => 128,
	);
	$form['third']['ebay_admin_production_cert_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Cert ID'),
    '#default_value' => variable_get('ebay_admin_production_cert_id'),
    '#description' => t('Enter Cert ID.'),
	'#size' => 40,
	'#maxlength' => 128,
	);
/* FOURTH FIELDSET. */
	$form['fourth'] = array(
    '#type' => 'fieldset',
    '#title' => t('User Token'),
    '#collapsible' => TRUE,
    '#description' => t(''),
    '#group' => 'settingsform'
	);
    $form['fourth']['ebay_admin_production_usertoken'] = array(
    '#type' => 'textarea',
    '#title' => t('User Token'),
    '#default_value' => variable_get('ebay_admin_production_usertoken'),
    '#description' => t('Enter User Token'),
	);
/* FIFTH FIELDSET. */
	$form['fifth'] = array(
    '#type' => 'fieldset',
    '#title' => t('Checklist'),
    '#collapsible' => TRUE,
    '#description' => t(''),
    '#group' => 'settingsform'
	);
    // CHECKLIST
	$form['fifth']['ebay_checklist_register_developer_program'] = array(
	'#type' =>'checkbox',
    '#default_value' => variable_get('ebay_admin_production_cert_id'),
	'#title' =>  t('<a href="!loginlink">Register for eBay Developers Program.</a>' , array('!loginlink' => url('https://go.developer.ebay.com/developers/ebay')) ),
	);
	$form['fifth']['ebay_checklist_register_production_user'] = array(
	'#type' => 'checkbox',
	'#default_value' => variable_get('ebay_admin_production_cert_id'),
	'#title' =>  t('<a href="!loginlink">Register eBay user account.</a>' , array('!loginlink' => url('https://go.developer.ebay.com/developers/ebay')) ),
	);
	$form['fifth']['ebay_checklist_register_paypal_production_account'] = array(
	'#type' =>'checkbox',
	'#default_value' => variable_get('ebay_admin_production_cert_id'),
	'#title' =>  t('<a href="!loginlink">Register for a PayPal Account.</a>' , array('!loginlink' => url('https://developer.paypal.com/')) ),
	);
/* SUBMIT BUTTON */
  $form['#submit'][] = 'ebay_admin_settings_production_submit'; //Submit button call back.
  return system_settings_form($form);
}
/**
* Logic behind the form submit.
*/
function ebay_admin_settings_production_submit($form, $form_state) {
  // Kept it empty, intentionally.
}