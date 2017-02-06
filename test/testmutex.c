/* testthread.c (Thread) */

/***********************************************************************
*  This code is part of the multithreading libarary.
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

#include <stdio.h>
#include <stdlib.h>
#include "thread.h"

int volatile active = 0;
int volatile error = 0;
pthread_mutex_t mutex;
int use_mutex = 0;

long wait(int id) {
  long cnt = 10;
  cnt *= id;
  do{
    if (active != id) {
      error = 1;
    }
    thread_sleep(1);
    cnt--;
  } while (cnt != 0);
  return cnt;
}

void worker(int id) {
  
  if (use_mutex) {
    pthread_mutex_lock(&mutex);
  }
  
  active = id;

  printf("  Started work on  %d\n",id);
  wait(id);
  printf("  Stopped work on  %d\n", id);
  if (use_mutex) {
    pthread_mutex_unlock(&mutex);
  }
}

void *run(void *arg) {
  int id;
  id = *(int *)arg;
  worker(id);
  pthread_exit(NULL);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t t;
  int id1 = 4;
  int rc;
 
  printf("Without mutex\n");
  error = 0;
  rc = pthread_create(&t, NULL, run, (void *)&id1);
  if (rc){
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(EXIT_FAILURE);
  }
  worker(1);
  worker(8);

  thread_sleep(100);

  if (error == 0) {
    printf ("No threading\n");
    return EXIT_FAILURE;    
  }

  pthread_mutex_init(&mutex, NULL);
  use_mutex = 1;

  printf("With mutex\n");
  error = 0;
  rc = pthread_create(&t, NULL, run, (void *)&id1);
  if (rc){
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(EXIT_FAILURE);
  }
  worker(1);
  worker(8);

  thread_sleep(100);

  if (error != 0) {
    printf ("No mutex\n");
    return EXIT_FAILURE;    
  }
  
  pthread_mutex_destroy(&mutex);

  return EXIT_SUCCESS;
}
