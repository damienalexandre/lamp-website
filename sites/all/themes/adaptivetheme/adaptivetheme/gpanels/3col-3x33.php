<?php

/**
 * @file 3col-3x33.php
 * Gpanel code snippet to display 3x33% width regions as columns.
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
<!-- Three column 3x33 Gpanel -->
<?php if ($page['three_33_first'] || $page['three_33_second'] || $page['three_33_third']): ?>
  <div class="three-3x33 gpanel clearfix">
    <?php print render($page['three_33_first']); ?>
    <?php print render($page['three_33_second']); ?>
    <?php print render($page['three_33_third']); ?>
  </div>
<?php endif; ?>
