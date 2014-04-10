Pidgin plugins
==============

In this repository I will be uploading whatever plugins I develop for Pidgin.
For now, since I just started a short while ago, it only contains a simple plugin to
reverse messages sent if a selected token is included in them.

##Requirements and installation

Two things are needed in order to compile a plugin for Pidgin:

####glib

To install glib just run:

* apt-get install libglib2.0

####libpurple

Which is the library containing all the development sources and headers needed for Pidgin Plugins, as well as some example plugins to help new developers get started.
You can get a pidgin .tar file with libpurple [here](http://sourceforge.net/projects/pidgin/ "here") (don't forget to './configure' and 'make' it, as explained in this [tutorial](https://developer.pidgin.im/wiki/CHowTo/BasicPluginHowto "tutorial").

####Compilation

A Makefile file is provided in this repository. It will be updated when new plugins are added.
This Makefile automatically creates a '~/.purple/plugins' directory if it doesn't exist, as it is needed to store new plugins, and puts the plugin .so file inside said directory.
To compile the plugins, run:

* make

**NOTE:** The Makefile file assumes that your libpurple directory (where you extracted and configured the pidgin .tar) is the same as mine, so you might have to change the **LIBPURPLE** flag so that the libpurple path matches that of yours.

After compilation, everything should be ready, so just run Pidgin and the new plugin should show under the 'Tools -> Plugins' menu.

##Windows installation

Inside the **dll** folder are included .dll files of the plugins for their use in Windows. In order to make the plugin work in Windows you have to move the appropriate .dll file to your %APPDATA%/.purple/plugins folder.

**NOTE:** The 'plugins' folder might not exist inside your '.purple' folder. In that case, just manually create it.