<article class="feed-item">
  <header>
    <h2 class="title feed-item-title">
      <a href="<?php print $feed_url; ?>"><?php print $feed_title; ?></a>
    </h2>
    <p class="feed-item-meta">
      <?php if ($source_url) : ?>
        <a href="<?php print $source_url; ?>" class="feed-item-source"><?php print $source_title; ?></a> -
      <?php endif; ?>
      <time datetime="<?php print $datetime; ?>"><?php print $source_date; ?></time>
    </p>
  </header>
  <?php if ($content) : ?>
    <div class="content"><?php print $content; ?></div>
  <?php endif; ?>
  <?php if ($categories): ?>
    <footer>
      <p><strong><?php print t('Categories'); ?></strong> - <?php print implode(', ', $categories); ?></p>
    </footer>
  <?php endif; ?>
</article>
