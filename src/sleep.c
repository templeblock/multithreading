/* sleep.c (Threading) */

/***********************************************************************
*  This code is part of ...
*
*  Copyright (C) 2011 Heinrich Schuchardt (xypron.glpk@gmx.de)
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
***********************************************************************/

/**
 * @file sleep.c
 * @brief Sleep function.
 *
 */

#include "thread.h"
#include <time.h>

/**
 * @brief Let thread sleep.
 * @param msecs duration in milliseconds
 */
#ifdef SQLWIN
void sleep(long msecs) {
  Sleep((DWORD) msecs);
}
#else
void sleep(long msecs) {
  struct timespec ts;
  ts.tv_sec = msecs / 1000;
  ts.tv_nsec = 1000000 * (msecs % 1000);
  nanosleep(&ts, NULL);
}
#endif

