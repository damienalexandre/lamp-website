<article class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $unpublished; ?>

  <?php print render($title_prefix); ?>
  <?php if ($title || $new): ?>
  <header>
    <h3<?php print $title_attributes; ?>><?php print $title ?></h3>
    <?php if ($new): ?>
      <em class="new"><?php print $new ?></em>
    <?php endif; ?>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <footer class="submitted clearfix">
    <p class="author-datetime"><?php print $submitted; ?></p>
  </footer>

  <div<?php print $content_attributes; ?>>
    <?php print $picture; ?>
    <?php
      hide($content['links']);
      print render($content);
    ?>
  </div>

  <?php if ($signature): ?>
    <div class="user-signature"><?php print $signature ?></div>
  <?php endif; ?>

  <?php if ($links = render($content['links'])): ?>
    <nav class="clearfix"><?php print $links; ?></nav>
  <?php endif; ?>

</article>
