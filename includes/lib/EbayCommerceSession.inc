<?php

/**
 * @file
 * Create eBay sessions.
 */

/**
 * BaySession.
 */
class EbayCommerceSession {

  private $action;

  /**
   * Construct.
   *
   * @todo add comments.
   */
  public function __construct($ebay_action) {
    $this->action = $ebay_action;
  }

  /**
   * Sends a HTTP request to the server for this session.
   *
   * @param string $request_body
   *    Xml data we want to post to eBay.
   *
   * @return DOMNode|DOMElement
   *    returns FALSE is no errors were found.
   */
  public function sendHttpRequest($request_body) {

    // Build eBay headers using variables passed via constructor.
    $headers = $this->buildEbayHeaders();
    // Initialise a CURL session.
    $connection = curl_init();
    // Set the server we are using (could be Sandbox or Production server).
    curl_setopt($connection, CURLOPT_URL, EBAY_COMMERCE_SERVER_URL);
    // Stop CURL from verifying the peer's certificate.
    curl_setopt($connection, CURLOPT_SSL_VERIFYPEER, 1);
    curl_setopt($connection, CURLOPT_SSL_VERIFYHOST, 0);
    // Set the headers using the array of headers.
    curl_setopt($connection, CURLOPT_HTTPHEADER, $headers);
    // Set method as POST.
    curl_setopt($connection, CURLOPT_POST, 1);
    // Set the XML body of the request.
    curl_setopt($connection, CURLOPT_POSTFIELDS, $request_body);
    // Set it to return the transfer as a string from curl_exec.
    curl_setopt($connection, CURLOPT_RETURNTRANSFER, 1);
    // Send the Request.
    $response = curl_exec($connection);
    // Close the connection.
    curl_close($connection);
    // Return the response.
    return $response;

  }

  /**
   * BuildEbayHeaders.
   *
   * Generates an array of strings to be used as
   * the headers for the HTTP request to eBay.
   *
   * @return String Array
   *    Headers applicable for this call.
   */
  private function buildEbayHeaders() {

    $headers = array(
      'X-EBAY-API-DEV-NAME:' . EBAY_COMMERCE_DEVELOPER_ID,
      'X-EBAY-API-APP-NAME:' . EBAY_COMMERCE_APPLICATION_ID,
      'X-EBAY-API-CERT-NAME:' . EBAY_COMMERCE_CERT_ID,
      'X-EBAY-API-SITEID:' . EBAY_COMMERCE_SITE,
      'X-EBAY-API-CALL-NAME:' . $this->action,
      'X-EBAY-API-COMPATIBILITY-LEVEL:' . EBAY_COMMERCE_API,
    );

    return $headers;

  }

}
