<li class="search-result">
  <h3 class="title"><a href="<?php print $url; ?>"><?php print $title; ?></a></h3>
  <?php if ($snippet or $info_split): ?>
    <div class="search-snippet-info">
      <?php if ($snippet) : ?>
        <p class="search-snippet"><?php print $snippet; ?></p>
      <?php endif; ?>

      <?php if ($info_split) : ?>
        <p class="search-info">
          <?php $separator = ''; ?>

          <?php if (isset($info_split['type'])) : ?>
            <span class="search-info-type"><?php print $info_split['type']; ?></span>
            <?php $separator = $info_separator; ?>
          <?php endif; ?>

          <?php if (isset($info_split['user'])) : ?>
            <span class="search-info-user"><?php print $separator . $info_split['user']; ?></span>
            <?php $separator = $info_separator; ?>
          <?php endif; ?>

          <?php if (isset($info_split['date'])) : ?>
            <span class="search-info-date"><?php print $separator . $info_split['date']; ?></span>
            <?php $separator = $info_separator; ?>
          <?php endif; ?>

          <?php if (isset($info_split['comment'])) : ?>
            <span class="search-info-comment"><?php print $separator . $info_split['comment']; ?></span>
            <?php $separator = $info_separator; ?>
          <?php endif; ?>

          <?php if (isset($info_split['upload'])) : ?>
            <span class="search-info-upload"><?php print $separator . $info_split['upload']; ?></span>
          <?php endif; ?>
        </p>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</li>
