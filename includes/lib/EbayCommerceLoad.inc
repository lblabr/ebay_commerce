<?php

/**
 * @file
 * Commerce loading class.
 *
 * @todo add comments to code.
 * @todo check if function names comply with coding standards.
 */

/**
 * EbayCommerceLoad.
 */
class EbayCommerceLoad {
  private $ebayAction;
  private $xmlBody;
  private $tagName;

  /**
   * Construct.
   */
  public function __construct($action, $xml, $tag_name) {
    $this->ebayAction = $action;
    $this->xmlBody = $xml;
    $this->tagName = $tag_name;
  }

  /**
   * EbayData.
   *
   * @return DOMNode|string
   *    If success we return xml-data else inform user.
   */
  public function eBayData() {
    $record = ebay_commerce_action($this->ebayAction, $this->xmlBody);
    if ($record) {
      foreach ($record as $value) {
        /** @var DOMElement|DOMNodeList $value */
        $response = $value->getElementsByTagName($this->tagName);
      }
    }
    if (isset($response)) {
      return $response;
    }
    else {
      drupal_set_message(t("No data received from eBay server."), 'status', FALSE);
    }

  }

  /**
   * Ebay Elements.
   *
   * @param string $id
   *    Ok.
   * @param $string $data
   *    Ok.
   *
   * @return DOMElement $ebay
   *    XML Element
   */
  public function eBayElement($id, $data) {
    $ebay = array();
    $responses = $this->eBayData();
    if ($responses) {
      foreach ($responses as $response) {
        /** @var DOMElement|DOMNodeList $response */
        $variable = $response->getElementsByTagName($id);
        $identifier = strtolower($variable->item(0)->nodeValue);

        $variable = $response->getElementsByTagName($data);
        $name = $variable->item(0)->nodeValue;

        $ebay[$identifier] = array(
          strtolower($id) => $identifier,
          strtolower($data) => $name,
        );
      }
    }
    return $ebay;
  }

}
