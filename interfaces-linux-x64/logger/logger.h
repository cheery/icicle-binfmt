typedef struct logger {
    void (*log)(uint8*);
    void (*logerror)(uint8*);
}* LOGGER;
