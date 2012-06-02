
-- SUBTHEME SETUP --

1. Copy and paste adaptivetheme_subtheme, it doesn't matter where you place
   the copied version as long as its in a theme directory. For example if you
   are using sites/all/themes you can place it there - so you end up with:

   sites/all/themes/footheme

2. Rename the info file and edit the info file details. For example lets assume
   you want your theme to be called "footheme", the name of the info file will
   be "footheme.info". Once you have renamed the file open it up and change the
   "name" to footheme and change the description to suit your taste.

3. Edit the theme_settings.php and template.php files - here we will be replacing
   "adaptivetheme_subtheme" with your themes name, in this case "footheme" - this
   must match the name you gave to the info file. The easy way is to just use
   search and replace.

4. For additional information on using Adaptivetheme view the information in
   adaptivetheme/adaptivetheme/README.txt

Any problems please post an issue in the Adaptivethemes issue queue on Drupal.org:
http://drupal.org/project/issues/adaptivetheme

Maintainer:
* Jeff Burnz http://drupal.org/user/61393
