<?php

/**
 * @file 2col-66-33.php
 * Gpanel code snippet to display two regions (66%/33%) as columns.
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
<!-- Two column 66-33 Gpanel -->
<?php if ($page['two_66_33_first'] || $page['two_66_33_second']): ?>
  <div class="two-66-33 gpanel clearfix">
    <?php print render($page['two_66_33_first']); ?>
    <?php print render($page['two_66_33_second']); ?>
  </div>
<?php endif; ?>
