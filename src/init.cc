//
// Created by Anton on 11/05/15.
//

#include <iostream>
#include <v8.h>
#include <node.h>
#include <node_object_wrap.h>
#include <node_version.h>
#include <node_buffer.h>
#include <nan.h>
#include "ltc.h"

using namespace v8;
using namespace node;

extern "C" void
init(Handle<Object> target) {
    NanScope();
};

NODE_MODULE(node_ltc, init)
