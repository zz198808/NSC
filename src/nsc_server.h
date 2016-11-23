#ifndef NSC_SERVER_H
#define NSC_SERVER_H
#pragma once
#include "nsc_core.h"
#include <string>

nsc_server_t* nsc_server_create(const std::string& svr_name);
int nsc_server_set_threadstartfun(nsc_server_t* svr, nsc_handle_func_t op)
int nsc_server_set_threadstopfun(nsc_server_t* svr, nsc_handle_func_t op)

#endif // NSC_SERVER_H
