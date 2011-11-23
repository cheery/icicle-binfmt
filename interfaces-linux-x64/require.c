#include "interfaces.h"
#include <stdio.h>

struct interface {
    char* name;
    void* (*load_interface)();
    void* instance;
};

struct interface interfaces[] = {
    { "logger", load_logger, 0 },
    { 0, 0, 0 },
};

void* icicle_require(char* name){
    printf("require called\n");
    struct interface* c = interfaces;

    while (c->name) {
        if (strcmp(c->name, name) == 0)
            break;
        c++;
    }
    if (c->name){
        if (!c->instance){
            c->instance = c->load_interface();
            printf("requires (%s)\n", name);
        }
        if (!c->instance){
            printf("requires (%s), but load fail\n", name);
        }
        return c->instance;
    }
    printf("requires (%s), but not found.\n", name);

    return 0;
}
