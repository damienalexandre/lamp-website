
Some tips:

* There are additional README files in both the subtheme and base theme directories,
  please refer to both of these before starting work on your subtheme.

* For help setting up your subtheme refer to the README in the adaptivetheme_subtheme
  directory, and/or the online docs: http://adaptivethemes.com/documentation/adaptivetheme-7x-2x

* The theme is built with HTML5 and large chunks of CSS3 and CSS2.1 - it has very
  little deliberate support for IE6 (I have not tested in IE6 and have no intention
  of supporting IE6). It has been tested in IE9 and performs very well (given
  that IE9 is beta at time of writing).
 
* Due to the ongoing specification changes for RDFa in HTML5 the doctype and version
  information may change in a point release, or not, depending. Right now things are
  working (afaict - I am no RDFa expert).

* Validation - to validate this theme you must disable the RDF module - because the W3C
  validator cannot handle the doctype and will freak out. When you disable the RDF module
  the doctype will automatically change and you will be able to validate it against HTML5 as
  per usual. I would suggest using a lint tool instead in any case, validation is only so useful
  and for HTML5 I think lint + outline tools are more realistic tools for building in HTML5.

* For dark style themes there's a dark.css file, just uncomment it in the info file,
  however understand at the moment the dark stylesheet needs major work and is not
  really ready for production, at all, as in don't even think about it unless you
  want some major headache or want to submit a patch for the theme (yay!).

* If you have some problem with the theme settings, clear the cache and/or the
  theme registry. D7 lost the wonderful "Reset to defaults" setting (why oh why),
  so be aware that adding/removing/editing theme settings from the info file can be a
  huge pita and browses like IE7 can actually freak out if when you do this (due to caching).
  If you do alter the info file theme setting defaults you may have to disable the theme, then
  re-enable it to get everything to kick in  - I had many issues with this during development
  of the theme for D7.
 
* If you don't use Firebug then get it now, this theme has many pre written CSS
  selectors. The subtheme was designed for porting right from the get go and makes it
  really easy as long as you don't fight the work-flow, embrace it:)
 
 
 So I hope you enjoy the theme and it somehow eases the development of your sites theme, after all
 that's all it was ever designed for - to build a nice theme without breaking your back to learn
 all the stuff that goes into building a complex Drupal theme.
 
 Cheers,
 
 Jeff Burnz
 Adaptivethemes.com
 
 