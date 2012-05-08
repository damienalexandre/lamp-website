<aside class="feed-source">
  <?php if ($source_description): ?>
    <header class="feed-description"><?php print $source_description; ?></header>
  <?php endif; ?>
  <?php print $source_icon; ?>
  <?php print $source_image; ?>
  <p class="feed-url">
    <strong><?php print t('URL:'); ?></strong> <a href="<?php print $source_url; ?>"><?php print $source_url; ?></a>
  </p>
  <p class="feed-updated">
    <strong><?php print t('Updated:'); ?></strong> <?php print $last_checked; ?>
  </p>
</aside>
