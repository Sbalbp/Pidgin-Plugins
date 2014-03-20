Pidgin plugins
==============

In this repository I will be uploading whatever plugins I develop for Pidgin.
For now, since I just started a short while ago, it only contains a simple plugin to
reverse messages sent if a selected token is included in them.

##Requirement and installation

These [tutorials](https://developer.pidgin.im/wiki/CHowTo "tutorials") should help anyone to get
started on basic plugin development and installation, as they did for me. After completing the
first [tutorial](https://developer.pidgin.im/wiki/CHowTo/BasicPluginHowto "tutorial") you should
have everything set and ready: just move any plugin C source to your plugin development folder
(you should have created it during the first tutorial) and run the following:

* make <name_of_plugin>.so
* cp <name_of_plugin>.so ~/.purple/plugins

The 'plugins' directory might not exist inside the '.purple' directory. Just create it so that it can
store the .so files.

After this run Pidgin and the new plugin should show under the 'Tools -> Plugins' menu.