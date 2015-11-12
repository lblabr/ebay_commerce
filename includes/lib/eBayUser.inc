<?php

/**
*
*/
class eBayLoadUser extends eBayLoad
{

  private $identifier;
  private $ebay_user_token;
  private $ebay_user_email;
  private $ebay_store_owner;
  private $ebay_store_url;
  private $ebay_store_site;

  public function eBayUser($id) {
    $responses = $this->eBayData();
         foreach ($responses as $response) {

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
            'id' => $identifier,
            'email' => $name,
            'store'=> array(
              'owner' => $store_owner,
              'url' => $store_url,
              'site' => $store_site,
             ),
            'token' => $token,
          );
        }
        return $ebay;
    }

  }
