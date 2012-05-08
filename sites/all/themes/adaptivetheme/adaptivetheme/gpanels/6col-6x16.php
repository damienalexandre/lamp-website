<?php

/**
 * @file 6col-6x16.php
 * Gpanel code snippet to display 6x16% width regions as columns.
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
<!-- Six column Gpanel -->
<?php if ($page['six_first'] || $page['six_second'] || $page['six_third'] || $page['six_fourth'] || $page['six_fifth'] || $page['six_sixth']): ?>
  <div class="six-6x16 gpanel clearfix">
    <?php print render($page['six_first']); ?>
    <?php print render($page['six_second']); ?>
    <?php print render($page['six_third']); ?>
    <?php print render($page['six_fourth']); ?>
    <?php print render($page['six_fifth']); ?>
    <?php print render($page['six_sixth']); ?>
  </div>
<?php endif; ?>
