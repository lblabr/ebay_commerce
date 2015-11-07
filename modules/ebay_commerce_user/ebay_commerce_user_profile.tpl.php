<?php

/**
 * @file
 * Default theme implementation to display the discount start page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $variables: List all variables
 *
 */
?>

<?php

  dsm($variables);

 // Some shortcuts for easy editing and readability.
  $ebay_user = $variables['ebay_user'];
  $store = $variables['ebay_user']['store']

?>

  <h1>eBay User profile</h1>

  <div><?php print $ebay_user['id']?></div>
  <div><?php print $ebay_user['email'] ?></div>

  <?php if ($store['owner']) : ?>
    <div><a href=<?php print $store['url']?>>View store</a></div>
  <?php endif ?>
