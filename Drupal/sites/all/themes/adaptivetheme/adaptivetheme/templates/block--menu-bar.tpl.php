<?php if ($content): // try to print nothing if block has no content ?>
  <nav id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <?php print render($title_prefix); ?>
    <?php if ($block->subject): ?>
      <h2<?php print $title_attributes; ?>><?php print $block->subject; ?></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <div class="menu-wrapper clearfix"><?php print $content ?></div>
  </nav>
<?php endif; ?>
