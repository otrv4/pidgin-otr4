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

#ifndef __OTRNG_FINGERPRINT_H__
#define __OTRNG_FINGERPRINT_H__

#include <glib.h>

#include <libotr-ng/client.h>

#include <plugin.h>

#define FINGERPRINT_STORE_FILE_NAME_V4 "otr4.fingerprints"

typedef struct {
  char *protocol;
  char *account;
  char *username;
  char fp[OTRNG_FPRINT_HUMAN_LEN];
  int trusted; // 0 - no, 1 - yes
} otrng_plugin_fingerprint;

otrng_conversation_s *
otrng_plugin_fingerprint_to_otr_conversation(otrng_plugin_fingerprint *f);

GList *otrng_plugin_fingerprint_get_all(void);

otrng_plugin_fingerprint *otrng_plugin_fingerprint_get_active(const char *peer);

void otrng_plugin_fingerprint_forget(const char fp[OTRNG_FPRINT_HUMAN_LEN]);

void otrng_fingerprints_set_callbacks(otrng_client_callbacks_s *cb);

gboolean otrng_plugin_fingerprints_load(PurplePlugin *handle);

gboolean otrng_plugin_fingerprints_unload(PurplePlugin *handle);

void write_fingerprints_cb_v3(void *opdata);
void confirm_fingerprint_cb_v3(void *opdata, OtrlUserState us,
                               const char *accountname, const char *protocol,
                               const char *username,
                               unsigned char fingerprint[20]);

#endif
