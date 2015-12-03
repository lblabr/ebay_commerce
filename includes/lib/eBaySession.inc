<?php

/**
 * Create eBay sessions.
 * TODO : Meaby use https://www.drupal.org/project/xautoload
 */

class eBaySession {

  private $action;

/**	__construct
 *
 */

public function __construct($ebay_action) {
  $this->action = $ebay_action;
}


/**
 * sendHttpRequest
 * Sends a HTTP request to the server for this session
 * Input:	$requestBody
 * Output:	The HTTP Response as a String
 */

public function sendHttpRequest($requestBody) {

  //build eBay headers using variables passed via constructor
  $headers = $this->buildEbayHeaders();
  //initialise a CURL session
  $connection = curl_init();
  //set the server we are using (could be Sandbox or Production server)
  curl_setopt($connection, CURLOPT_URL, EBAY_SERVER_URL);
  //stop CURL from verifying the peer's certificate
  curl_setopt($connection, CURLOPT_SSL_VERIFYPEER, 0);
  curl_setopt($connection, CURLOPT_SSL_VERIFYHOST, 0);
  //set the headers using the array of headers
  curl_setopt($connection, CURLOPT_HTTPHEADER, $headers);
  //set method as POST
  curl_setopt($connection, CURLOPT_POST, 1);
  //set the XML body of the request
  curl_setopt($connection, CURLOPT_POSTFIELDS, $requestBody);
  //set it to return the transfer as a string from curl_exec
  curl_setopt($connection, CURLOPT_RETURNTRANSFER, 1);
  //Send the Request
  $response = curl_exec($connection);
  //close the connection
  curl_close($connection);
  //return the response
  return $response;

}


/**
 * buildEbayHeaders
 * Generates an array of string to be used as the headers for the HTTP request to eBay
 * Output:	String Array of Headers applicable for this call
 */

private function buildEbayHeaders() {

  $headers = array (
    'X-EBAY-API-DEV-NAME:' . EBAY_DEVELOPER_ID,
    'X-EBAY-API-APP-NAME:' . EBAY_APPLICATION_ID,
    'X-EBAY-API-CERT-NAME:' . EBAY_CERT_ID,
    'X-EBAY-API-SITEID:' . EBAY_SITE,
    'X-EBAY-API-CALL-NAME:' . $this->action,
    'X-EBAY-API-COMPATIBILITY-LEVEL:' . EBAY_API,
 );

return $headers;

}

} //End Class

