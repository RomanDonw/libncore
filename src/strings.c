/*
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include "libncore.h"

const char *n_panicmsg_mutexlock = "Unable to lock mutex in critical library section.";
const char *n_panicmsg_mutexunlock = "Unable to unlock mutex in critical library section.";
const char *n_panicmsg_mutexdestroyduringlibrarycleanup = "Unable to destroy mutex of mutexes list during library cleanup.";