#ifndef NSC_CORE_H
#define NSC_CORE_H
#pragma once

#include <iostream>
#include "common/common.h"
#include <pthread>


typedef int(*callback_proc)();
typedef int(*nsc_handle_func_t)();

typedef struct _server_pdata_t {
    pthread pid;
    uint32_t thread_idx;
    in_addr_t ip;
    int fd;

    void* read_buf;
    uint32_t read_buf_size;
    void* write_buf;
    uint32_t write_buf_size;
    void* user_buf;
    uint32_t user_buf_size;
    void* p_parent;//point to nsc_server_t
}server_pdata_t;

typedef struct _nsc_server_t {
    char server_name[BUF_len];
    uint32_t connect_type;
    uint32_t connect_timeout;
    uint32_t read_timeout;
    uint32_t write_timeout;

    uint32_t pthread_num;
    uint32_t listen_port;
    uint32_t backlog;
    bool run;
    int svr_socket;
    //thread_data
    server_pdata_t* data;

    //pool
    void* pool;
    //buf
    void** user_readbuf;
    uint32_t user_readbuf_len;
    void** user_writebuf;
    uint32_t user_writebuf_len;

    //call back
    callback_proc cb_native;
    callback_proc cb_del;
    callback_proc cb_check_pack;

    nsc_handle_func_t start_func;
    nsc_handle_func_t end_func;
}nsc_server_t;


#endif // NSC_CORE_H
