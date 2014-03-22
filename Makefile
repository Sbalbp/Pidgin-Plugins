GLIB_CFLAGS = `pkg-config --libs --cflags glib-2.0`
LIBPURPLE = -I ~/development/pidgin-2.10.9/libpurple
SRC = src
SO = so
PLUGIN_DIR = ~/.purple/plugins

all: $(PLUGIN_DIR) $(SO) $(SO)/reverser.so
	cp -fv $(SO)/reverser.so $(PLUGIN_DIR)/reverser.so

$(PLUGIN_DIR):
	mkdir -p $(PLUGIN_DIR)

$(SO):
	mkdir -p $(SO)

$(SO)/reverser.so: $(SRC)/reverser.c
	gcc -shared -o $(SO)/reverser.so $(SRC)/reverser.c $(GLIB_CFLAGS) $(LIBPURPLE)