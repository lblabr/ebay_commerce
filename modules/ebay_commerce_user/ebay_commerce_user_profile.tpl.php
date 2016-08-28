<?php

/**
 * @file
 * Default theme implementation to display the discount start page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $variables: List all variables
 */
?>

<?php

 // Some shortcuts for easy editing and readability.
  $ebay_user = $variables['ebay_user'];
  $ebay_settings = $variables['ebay_user_settings'];
  $store = $variables['ebay_user']['store'];

?>

<?php if ($ebay_user) : ?>
  <h1>eBay User profile</h1>

  <h2>Profile</h2>
  <div><?php print $ebay_user['userid']?></div>
  <div><?php print $ebay_user['email'] ?></div>

  <?php if ($store['storeowner']) : ?>
    <div><a href=<?php print $store['storeurl']?>>View store</a></div>
  <?php endif ?>

  <h2>Settings</h2>

  <div><?php print $ebay_settings['mode']?></div>
  <div><?php print $ebay_settings['api'] ?></div>
  <div><?php print $ebay_settings['site'] ?></div>
  <div><?php print $ebay_settings['currency'] ?></div>
  <div><?php print $ebay_settings['language'] ?></div>
  <div><?php print $ebay_settings['warning-level'] ?></div>
  <div><?php print $ebay_settings['tracking'] ?></div>
  <div><?php print $ebay_settings['developer-id'] ?></div>
  <div><?php print $ebay_settings['application-id'] ?></div>
  <div><?php print $ebay_settings['cert-id'] ?></div>
  <div><?php print $ebay_settings['url']?></div>
  <div><?php print $ebay_settings['token']?></div>
  <div><?php print $ebay_settings['paypal']?></div>


  <?php if ($store['storeowner']) : ?>
    <div><a href=<?php print $store['storeurl']?>>View store</a></div>
  <?php endif ?>
<?php endif ?>

<?php if (!$ebay_user) : ?>

<h1>'Please enter <a href="/admin/ebay/settings">connection setting and credentials </a>
before making a connection.'</h1>

<?php endif ?>
