<section class="<?php print drupal_html_class($title); ?>">
  <?php if ($title) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <dl<?php print $attributes; ?>>
    <?php print $profile_items; ?>
  </dl>
</section>
