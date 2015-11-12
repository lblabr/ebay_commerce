<?php

/**
*
*/
class eBayLoad
{
    private $_action;
    private $_xml_body;
    private $_tagname;

  public function __construct($action, $xml, $tagname) {
    $this->_action = $action;
    $this->_xml_body = $xml;
    $this->_tagname = $tagname;
  }

  public function eBayData() {
     $record = ebay_commerce_action($this->_action, $this->_xml_body);
     if ($record) {
      foreach ($record as $value) {
        $response = $value->getElementsByTagName($this->_tagname);
      }
    }
     return $response;
  }

  public function eBayElement($id, $data) {
    $responses = $this->eBayData();
    foreach ($responses as $response) {
        $variable = $response->getElementsByTagName($id);
        $identifier = strtolower($variable->item(0)->nodeValue);

        $variable = $response->getElementsByTagName($data);
        $name = $variable->item(0)->nodeValue;

        $ebay[$identifier] = array(
          strtolower($id) => $identifier,
          strtolower($data) => $name,
        );
      }

  return $ebay;
  }

} // End Class
