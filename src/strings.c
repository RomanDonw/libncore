#include "libncore.h"

const char *n_panicmsg_mutexlock = "Unable to lock mutex in critical library section.";
const char *n_panicmsg_mutexunlock = "Unable to unlock mutex in critical library section.";
const char *n_panicmsg_mutexdestroyduringlibrarycleanup = "Unable to destroy mutex of mutexes list during library cleanup.";