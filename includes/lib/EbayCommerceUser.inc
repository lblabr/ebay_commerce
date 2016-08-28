<?php

/**
 * @file
 * Ebay Commerce User.
 */

/**
 * Ebay Load User.
 */
class EbayCommerceLoadUser extends EbayCommerceLoad {

  /**
   * User data.
   */
  public function eBayUser($id) {
    $ebay = array();
    $responses = $this->eBayData();
    if ($responses) {
      foreach ($responses as $response) {
        /** @var DOMElement|DOMNodeList $response */
        $variable = $response->getElementsByTagName('EIASToken');
        $token = $variable->item(0)->nodeValue;

        $variable = $response->getElementsByTagName($id);
        $identifier = strtolower($variable->item(0)->nodeValue);

        $variable = $response->getElementsByTagName('Email');
        $name = $variable->item(0)->nodeValue;

        $variable = $response->getElementsByTagName('StoreOwner');
        $store_owner = $variable->item(0)->nodeValue;

        $variable = $response->getElementsByTagName('StoreURL');
        $store_url = $variable->item(0)->nodeValue;

        $variable = $response->getElementsByTagName('StoreSite');
        $store_site = $variable->item(0)->nodeValue;

        $ebay = array(
          'userid' => $identifier,
          'email' => $name,
          'store' => array(
            'storeowner' => $store_owner,
            'storeurl' => $store_url,
            'storesite' => $store_site,
          ),
          'eiastoken' => $token,
        );
      }
      return $ebay;
    }
  }

}
