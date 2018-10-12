/*
 *  Off-the-Record Messaging plugin for pidgin
 *  Copyright (C) 2004-2018  Ian Goldberg, Rob Smits,
 *                           Chris Alexander, Willy Lew,
 *                           Nikita Borisov
 *                           <otr@cypherpunks.ca>
 *                           The pidgin-otrng contributors
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of version 2 of the GNU General Public License as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __OTRG_PLUGIN_CONVERSATION_H__
#define __OTRG_PLUGIN_CONVERSATION_H__

typedef struct {
  char *account;
  char *protocol;
  char *peer;
  uint16_t their_instance_tag;
  uint16_t our_instance_tag;
} otrng_plugin_conversation;

otrng_plugin_conversation *otrng_plugin_conversation_new(const char *account,
                                                         const char *protocol,
                                                         const char *peer);

#endif // __OTRG_PLUGIN_CONVERSATION_H__
