
  #Gpanels

  Gpanels are drop in multi-column snippets for displaying blocks in 
  vertical columns.
 
  How to use a Gpanel:
  
  CSS
  In your themes info file un-comment the required CSS file - you can
  have fixed width or fluid width Gpanels. Most of the time the fluid
  width CSS is most useful. The fixed width Gpanel CSS is useful if
  the width of the containing DIV is 960px and you want a pixel
  perfect layout.
 
  PHP
  1. Copy and paste a Gpanel into your page.tpl.php file.
  2. Uncomment the matching regions in your subthemes info file.
  3. Clear the cache (in Performance settings) to refresh the theme registry. 
  
  Now you can add blocks to the Gpanel regions.
  
  Fluid width Gpanels are built with percentages and expand to fill their containing
  element, normally a div. They will stretch and compress so it does not 
  matter how wide the page is, or what unit you use to set the page width.
  
  Gpanels in Page Templates:
  
  You can paste a fluid width Gpanel almost anywhere in page.tpl.php and they will 
  display correctly. If you embed a Gpanel into an existing region you
  may have to alter the conditional logic for the Gpanel to show up.




   