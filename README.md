Pidgin plugins
==============

In this repository I will be uploading whatever plugins I develop for Pidgin.
For now, since I just started a short while ago, it only contains a simple plugin to
reverse messages sent if a selected token is included in them.

##Requirements and installation

These [tutorials](https://developer.pidgin.im/wiki/CHowTo "tutorials") should help anyone to get
started on basic plugin development and installation, as they did for me.

After following the tutorials you should already have a local installation of libpurple as well as glib.
If you don't, you can get a pidgin tar file with libpurple [here](http://sourceforge.net/projects/pidgin/ "here") (don't forget to ./configure and make it, as explained in this [tutorial](https://developer.pidgin.im/wiki/CHowTo/BasicPluginHowto "tutorial").
As for glib, just run:

* apt-get install libglib2.0

To compile the plugins just run the Makefile file (take into account that you might have to modify it so that the libpurple location matches that of yours):

* make

If the compilation goes wrong it might be because the 'plugins' directory does not exist inside the '.purple' directory. Just create it so that the .so files can be stored inside it.

After this run Pidgin and the new plugin should show under the 'Tools -> Plugins' menu.