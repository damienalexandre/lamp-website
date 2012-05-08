<?php // at-admin ?>
<div id="page">
  <div class="topbar-wrapper"><div class="container">
    <div id="topbar" class="clearfix">
      <nav id="breadcrumb" role="navigation"><?php print $breadcrumb; ?></nav>
      <?php if ($datetime_rfc): ?>
        <time datetime="<?php print $datetime_iso; ?>"><?php print $datetime_rfc; ?></time>
      <?php endif; ?>
    </div>
  </div></div>
  <div class="content-header"><div class="container">
    <header id="banner" class="clearfix" role="banner">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?><h1 id="page-title"><?php print $title; ?></h1><?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if ($primary_local_tasks): ?>
        <nav id="primary-tasks" class="clearfix<?php print $secondary_local_tasks ? ' with-secondary' : '' ?>" role="navigation">
          <ul class="tabs primary"><?php print render($primary_local_tasks); ?></ul>
        </nav>
      <?php endif; ?>
    </header>
  </div></div>
  <?php if ($secondary_local_tasks): ?>
    <div class="secondary-tasks-wrapper" ><div class="container">
      <nav id="secondary-tasks" class="clearfix" role="navigation">
        <ul class="tabs secondary clearfix"><?php print render($secondary_local_tasks); ?></ul>
      </nav>
    </div></div>
  <?php endif; ?>
  <div class="content-columns"><div class="container clearfix">  
    <div id="columns"><div class="columns-inner clearfix">
      <div id="content-column"><div class="content-inner">
        <?php print render($page['highlighted']); ?>
        <?php print $messages; ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <nav class="actions-wrapper clearfix"><ul class="action-links clearfix"><?php print render($action_links); ?></ul></nav>
        <?php endif; ?>
        <div id="main-content">
          <?php print render($page['content']); ?>
        </div>
      </div></div>
      <?php print render($page['sidebar_first']); ?>
      <?php print render($page['sidebar_second']); ?>
    </div></div>
    <?php if ($page['footer']): ?>
      <footer id="page-footer">
        <?php print render($page['footer']); ?>
      </footer>
    <?php endif; ?>
  </div></div>
</div>
