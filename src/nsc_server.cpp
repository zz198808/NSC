/***************************************************************************
*
* Copyright (c) 2016 Tencent.com, Inc. All Rights Reserved
*
*
/***************************************************************************


/**
* @File Name: nsc_server.cpp
* @author: terazhang@tencent.com
* @Created Time: 16/11/23 00:28:34
* version
* brief
*
**/

#include "nsc_server.h"

nsc_server_t* nsc_server_create(const std::string& svr_name) {
    nsc_server_t* svr =  (nsc_server_t*)malloc(sizeof(nsc_server_t));
    if (svr == NULL) {
        return NULL;
    }
    svr->connect_type = NSCSVR_XPOOL;
    svr->connect_timeout = 0;
    svr->read_timeout = 0;
    svr->write_timeout = 0;
    svr->pthread_num = 0;
    svr->listen_port = 0;
    svr->backlog = 1000;
    svr->data = NULL;
    svr->pool = NULL;
    svr->user_readbuf = NULL;
    svr->user_writebuf = NULL;
    svr->cb_native = NULL;
    svr->cb_del = NULL;
    svr->cb_check_pack = NULL;
    svr->start_func = NULL;
    svr->end_func = NULL;

    return svr;
}

