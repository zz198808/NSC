#ifndef XPOOL_H
#define XPOOL_H
#pragma once
#include <pthread>

typedef struct _xpool_t {
    pthread_mutex_t lock;
}xpool_t;

int xpool_init(nsc_server_t* svr);
int xpool_run(nsc_server_t* svr);
int xpool_join(nsc_server_t* svr);
int xpool_destory(nsc_server_t* svr);

#endif // XPOOL_H
