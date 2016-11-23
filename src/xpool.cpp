/***************************************************************************
*
* Copyright (c) 2010 Baidu.com, Inc. All Rights Reserved
*
*
/***************************************************************************


/**
* @File Name: xpool.cpp
* @author: terazhang@tencent.com
* @Created Time: 16/11/23 00:53:24
* version
* brief
*
**/
#include "xpool.h"
#include <iostream>

int xpool_init(nsc_server_t* svr) {
    if (svr->pool == NULL) {
        svr->pool = malloc(sizeof(xpool_t));
        if (svr->pool == NULL) {
            std::cout << "malloc happen error" << std::endl;
            return -1;
        }
    }
    pthread_mutex_init(&((xpool_t*)&svr->pool)->lock, NULL);
    return 0;
}

void xpool_work_func(void* param) {
    server_pdata_t* data = (server_pdata_t*)param;
    nsc_server_t* svr = (nsc_server_t*)data->p_parent;
    xpool_t* pool = svr->pool;
    struct sockaddr_in caddr;
    socklen_t clen = sizeof(caddr);

    set_pthread_data(data);

    while (svr->run) {
        pthread_mutex_lock(&pool->lock);
        data->fd = accept(svr->svr_socket, (struct sockaddr*)&caddr, &clen);
        pthread_mutex_unlock(&pool->lock);
        if (svr->cb_native() != 0) {
            break;
        }
        close(data->fd);
        data->fd = -1;

    }
}



int xpool_run(nsc_server_t* svr) {
    int i = 0;
    int ret = 0;
    for (;i < svr->thread_num; ++i) {
        ret = pthread_create(&svr->data[i].pid, NULL, xpool_work_func, &svr->data[i]);
        if (ret != 0) {
            std::cout << "pthread create happen error" << std::endl;
            return -1;
        }
    }
    return 0;
}

int xpool_join(nsc_server_t* svr) {
    int i = 0;
    int ret = 0;
    for (; i < svr->thread_num; ++i) {
        ret = pthread_join(svr->data[i].pid, NULL);
    }
    return 0;
}

int xpool_join(nsc_server_t* svr) {
    xpool_t* pool = (xpool_t*)svr->pool;
    if (pool == NULL) {
        return 0;
    }
    pthread_mutex_destory(&pool->lock);
    if (pool != NULL) {
        free(svr->pool);
    }
    svr->pool = NULL;
    return 0;
}
