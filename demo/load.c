#include <icicle.h>
#include <logger.h>

int load(REQUIRE require){
    LOGGER logger;
    if (logger = require("logger")){
        logger->log("hello log");
    }
}
