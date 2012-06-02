Coup de pied dans la LAMP
=========================

Wut?
----

Ceci est le contenu d'une présentation donnée à l'occasion du Forum PHP 2012 à Paris.

Consulter la présentation
-------------------------

La présentation se trouve dans le dossier `Slideshow`,
elle est au format [Impress.js](https://github.com/bartaz/impress.js) et n'est donc pas compatible avec les
navigateurs sans support de la 3D CSS.

Si le rendu est impossible dans votre navigateur, vous pouvez consulter la présentation en désactivant Javascript.

Une [version PDF est aussi disponible](https://github.com/downloads/damienalexandre/lamp-website/coup-de-pied-dans-la-lamp-v0.1.pdf)
dans les téléchargements - mais c'est moins classe.

Reproduire les benchs
---------------------

L'instance de Drupal utilisée se trouve dans le dossier `Drupal/`,
10000 contenus ont été générés avec le module `devel`.

Le cache et le Cron sont à désactiver dans les options.

Dans `Tools/` vous trouverez le script `benchsiege.sh`, vous aurez bien sûr
besoin de [Siege](http://www.joedog.org/siege-home/), et de mettre votre propre domaine
dans le fichier `urls.txt`.

Pour le test `sysbench`, lancez le script `sysb-read.sh` depuis la machine host.

Le script `logparse` vous permet d'extraire des urls depuis vos logs Apache (utile pour constituer un urls.txt
représentatif de votre traffic).

Auteurs
-------

- Benjamin Clay - @ternel
- Damien Alexandre - @damienalexandre

Licence
-------

L'ensemble des contenus de ce dépot sont sous Licence BEERWARE (voir `LICENSE`).

![That's all](https://github.com/damienalexandre/lamp-website/raw/master/Slideshow/img/thatsall.gif)
