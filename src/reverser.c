/*
 * Message reverser plugin.
 *
 * Copyright (C) 2014 Sergio Balbuena.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02111-1301, USA.
 */

#define PLUGIN_ID "core-sbalbp-reverser"

#include "internal.h"

#include <string.h>

#include "debug.h"
#include "signals.h"
#include "version.h"

// Token whose presence in a message decides whether or not it is reversed
const char reverse_token[] = "***";

// Function to parse a message and reverse it if the chosen token is present
static void parse(char *msg){

	int it, original_length, last, max_it;
	char* token_start;

	if(msg != NULL){
		// Check if token '***' is present
		if((token_start = strstr(msg, reverse_token)) != NULL){
			original_length = strlen(msg);

			// First we get rid of the '***' token
			memmove(token_start, token_start+3, strlen(msg)-(token_start-msg)-2);
			msg = (char*)realloc(msg, original_length-2);

			last = strlen(msg)-1;
			max_it = strlen(msg)/2;
			// Here we reverse the rest of the message
			for(it=0; it<max_it; it++){
				char aux = msg[it];
				msg[it] = msg[last-it];
				msg[last-it] = aux;
			}
		}
	}
}

/****************************************************************************************************/
/*--------------------------------------CALLBACK DEFINITIONS----------------------------------------*/
/****************************************************************************************************/

static gboolean writing_im_msg_cb(PurpleAccount *account, const char *who, char **message,
				PurpleConversation *conv, PurpleMessageFlags flags, void *data){

	parse(*message);
	return FALSE;
}

static void sending_im_msg_cb(PurpleAccount *account, char *recipient, char **message, void *data){

	parse(*message);
}

static gboolean writing_chat_msg_cb(PurpleAccount *account, const char *who, char **message,
				PurpleConversation *conv, PurpleMessageFlags flags, void *data){

	parse(*message);
	return FALSE;
}

static void sending_chat_msg_cb(PurpleAccount *account, char *recipient, char **message, void *data){

	parse(*message);
}

/****************************************************************************************************/
/*----------------------------------------PLUGIN FUNCTIONS------------------------------------------*/
/****************************************************************************************************/

static gboolean plugin_load(PurplePlugin *plugin){

	void *conv_handle = purple_conversations_get_handle();

	/*
	 * Here we bind the different callbacks to the appropriate events.
	 * The events 'writing' and 'sending' are both fired before actually
	 * writing/sending the message, which allows us to manipulate it
	 * on the callback and display/send a different message (in our case
	 * it will be reversed if the chosen token is present).
	 */
	purple_signal_connect(conv_handle, "writing-im-msg",
						plugin, PURPLE_CALLBACK(writing_im_msg_cb), NULL);
	purple_signal_connect(conv_handle, "sending-im-msg",
						plugin, PURPLE_CALLBACK(sending_im_msg_cb), NULL);
	purple_signal_connect(conv_handle, "writing-chat-msg",
						plugin, PURPLE_CALLBACK(writing_chat_msg_cb), NULL);
	purple_signal_connect(conv_handle, "sending-chat-msg",
						plugin, PURPLE_CALLBACK(sending_chat_msg_cb), NULL);

	return TRUE;
}

static gboolean plugin_unload(PurplePlugin *plugin){

	purple_signals_disconnect_by_handle(plugin);

	return TRUE;
}

static PurplePluginInfo info =
{
	PURPLE_PLUGIN_MAGIC,
	PURPLE_MAJOR_VERSION,
	PURPLE_MINOR_VERSION,
	PURPLE_PLUGIN_STANDARD,
	NULL,
	0,
	NULL,
	PURPLE_PRIORITY_DEFAULT,

	PLUGIN_ID,														// id
	N_("Message reverser"),											// name
	DISPLAY_VERSION,												// version
	N_("Reverses the message sent if '***' is present in it."),		// summary
	N_("Reverses the message sent if '***' is present in it."),		// description
	"Sergio Balbuena <sbalbp@gmail.com>",							// author
	PURPLE_WEBSITE,													// homepage

	plugin_load,													// load
	plugin_unload,													// unload
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL
};

static void init_plugin(PurplePlugin *plugin){
}

PURPLE_INIT_PLUGIN(reverser, init_plugin, info)