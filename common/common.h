#ifndef COMMON_H
#define COMMON_H
#pragma once

#include <stdint.h>

const uint32_t BUF_len = 1024;

enum {
    NSCSVR_XPOOL = 0,
    NSCSVR_CPOOL,
    NSCSVR_EPOOL,
};

enum {
    CONNECT_TIMEOUT = 200,
    READ_TIMEOUT = 200,
    WRITE_TIMEOUT = 300,
    BACK_LOG = 10000,
};

#endif // COMMON_H
