<div class="texture-overlay">
  <div id="page" class="container">

    <header id="header" class="clearfix" role="banner">
      <div class="header-inner clearfix">
        <div id="branding">
          <?php if ($linked_site_logo): ?>
            <div id="logo"><?php print $linked_site_logo; ?></div>
          <?php endif; ?>
          <?php if ($site_name || $site_slogan): ?>
            <hgroup<?php if (!$site_slogan && $hide_site_name): ?> class="<?php print $visibility; ?>"<?php endif; ?>>
              <?php if ($site_name): ?>
                <h1 id="site-name"<?php if ($hide_site_name): ?> class="<?php print $visibility; ?>"<?php endif; ?>><?php print $site_name; ?></h1>
              <?php endif; ?>
              <?php if ($site_slogan): ?>
                <h2 id="site-slogan"><?php print $site_slogan; ?></h2>
              <?php endif; ?>
            </hgroup>
          <?php endif; ?>
        </div>
        <?php print render($page['header']); ?> <!-- /header region -->
      </div>
    </header> <!-- /header -->

    <?php print render($page['menu_bar']); ?> <!-- /menu bar -->

    <?php print $messages; ?> <!-- /message -->
    <?php print render($page['help']); ?> <!-- /help -->

    <?php if ($breadcrumb): ?>
      <nav id="breadcrumb"><?php print $breadcrumb; ?></nav> <!-- /breadcrumb -->
    <?php endif; ?>

    <?php print render($page['secondary_content']); ?> <!-- /secondary-content -->

    <!-- Three column 3x33 Gpanel -->
    <?php if ($page['three_33_first'] || $page['three_33_second'] || $page['three_33_third']): ?>
      <div class="three-3x33 gpanel clearfix">
        <?php print render($page['three_33_first']); ?>
        <?php print render($page['three_33_second']); ?>
        <?php print render($page['three_33_third']); ?>
      </div>
    <?php endif; ?>

    <div id="columns"><div class="columns-inner clearfix">
      <div id="content-column"><div class="content-inner">

        <?php print render($page['highlight']); ?> <!-- /highlight -->

        <?php $tag = $title ? 'section' : 'div'; ?>
        <<?php print $tag; ?> id="main-content" role="main">

          <?php print render($title_prefix); ?>
          <?php if ($title || $primary_local_tasks || $secondary_local_tasks || $action_links = render($action_links)): ?>
            <header class="clearfix">
              <?php if ($title): ?>
                <h1 id="page-title"><?php print $title; ?></h1>
              <?php endif; ?>
              <?php if ($primary_local_tasks || $secondary_local_tasks || $action_links): ?>
                <div id="tasks" class="clearfix">
                  <?php if ($primary_local_tasks): ?>
                    <ul class="tabs primary clearfix"><?php print render($primary_local_tasks); ?></ul>
                  <?php endif; ?>
                  <?php if ($secondary_local_tasks): ?>
                    <ul class="tabs secondary clearfix"><?php print render($secondary_local_tasks); ?></ul>
                  <?php endif; ?>
                  <?php if ($action_links = render($action_links)): ?>
                    <ul class="action-links clearfix"><?php print $action_links; ?></ul>
                  <?php endif; ?>
                </div>
              <?php endif; ?>
            </header>
          <?php endif; ?>
          <?php print render($title_suffix); ?>

          <?php print render($page['content']); ?> <!-- /content -->

          <?php print $feed_icons; ?> <!-- /feed icons -->

        </<?php print $tag; ?>> <!-- /main-content -->

        <?php print render($page['content_aside']); ?> <!-- /content-aside -->

      </div></div> <!-- /content-column -->

      <?php print render($page['sidebar_first']); ?>
      <?php print render($page['sidebar_second']); ?>

    </div></div> <!-- /columns -->

    <?php print render($page['tertiary_content']); ?> <!-- /tertiary-content -->

    <!-- Four column Gpanel -->
    <?php if ($page['four_first'] || $page['four_second'] || $page['four_third'] || $page['four_fourth']): ?>
      <div class="four-4x25 gpanel clearfix">
        <?php print render($page['four_first']); ?>
        <?php print render($page['four_second']); ?>
        <?php print render($page['four_third']); ?>
        <?php print render($page['four_fourth']); ?>
      </div>
    <?php endif; ?>

    <?php if ($page['footer'] || $feed_icons): ?>
      <footer id="footer" role="contentinfo"><div id="footer-inner" class="clearfix">
        <?php print render($page['footer']); ?> <!-- /footer region -->
      </div></footer> <!-- /footer/footer-inner -->
    <?php endif; ?>

  </div> <!-- /page -->
</div> <!-- /texture overlay -->