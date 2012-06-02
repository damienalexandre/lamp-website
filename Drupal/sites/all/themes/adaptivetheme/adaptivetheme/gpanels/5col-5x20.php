<?php

/**
 * @file 5col-5x20.php
 * Gpanel code snippet to display 5x20% width regions as columns.
 *
 * GPanels are drop in multi-column snippets for displaying blocks in
 * vertical columns, such as 2 columns, 3 columns or 4 columns.
 *
 * How to use a Gpanel:
 * 1. Copy and paste a Gpanel into your page.tpl.php file.
 * 2. Uncomment the matching regions in your subthemes info file.
 * 3. Clear the cache (in Performance settings) to refresh the theme registry.
 *
 * Now you can add blocks to the regions as per normal. The layout CSS for
 * these regions is already set up so there is nothing more to do.
 *
 * Gpanels are fluid, meaning they stretch and compress with the page width.
 */
?>
<!-- Five column Gpanel -->
<?php if ($page['five_first'] || $page['five_second'] || $page['five_third'] || $page['five_fourth'] || $page['five_fifth']): ?>
  <div class="five-5x20 gpanel clearfix">
    <?php print render($page['five_first']); ?>
    <?php print render($page['five_second']); ?>
    <?php print render($page['five_third']); ?>
    <?php print render($page['five_fourth']); ?>
    <?php print render($page['five_fifth']); ?>
  </div>
<?php endif; ?>
