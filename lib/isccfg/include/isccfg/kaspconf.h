/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * See the COPYRIGHT file distributed with this work for additional
 * information regarding copyright ownership.
 */

#ifndef ISCCFG_KASPCONF_H
#define ISCCFG_KASPCONF_H 1

#include <isc/lang.h>

#include <dns/types.h>

#include <isccfg/cfg.h>

/***
 *** Functions
 ***/

ISC_LANG_BEGINDECLS

isc_result_t
cfg_kasp_fromconfig(const cfg_obj_t *config, isc_mem_t *mctx, isc_log_t *logctx,
		    dns_kasplist_t *kasplist, dns_kasp_t **kaspp);
/*%<
 * Create and configure a KASP. If 'config' is NULL, the default configuration
 * is used. If a 'kasplist' is provided, a lookup happens and if a KASP
 * already exists with the same name, no new KASP is created, and no attach to
 * 'kaspp' happens.
 *
 * Requires:
 *
 *\li  'mctx' is a valid memory context.
 *
 *\li  'logctx' is a valid logging context.
 *
 *\li  'name' is a valid C string.
 *
 *\li  kaspp != NULL && *kaspp == NULL
 *
 * Returns:
 *
 *\li  #ISC_R_SUCCESS  If creating and configuring the KASP succeeds.
 *\li  #ISC_R_EXISTS   If 'kasplist' already has a kasp structure with 'name'.
 *\li  #ISC_R_NOMEMORY
 *
 *\li  Other errors are possible.
 */

ISC_LANG_ENDDECLS

#endif /* ISCCFG_KASPCONF_H */
