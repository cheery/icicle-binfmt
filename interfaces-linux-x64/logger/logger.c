#include <icicle.h>
#include <stdio.h>
#include "logger.h"

static void logger_log(uint8* text){
    fprintf(stderr, "%s\n", text);
};

static void logerror(uint8* text){
    fprintf(stderr, "error: %s\n", text);
};

static struct logger
logger_interface = {
    logger_log,
    logerror
};

void* load_logger(){
    return &logger_interface;
}
