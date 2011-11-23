typedef unsigned long long uint64;

typedef void* REQUIRE(char* name);

struct icicle_header {
    uint64 magic;
    uint64 entry;
    uint64 size;
};

#define ICICLE_MAGIC 0x00656c636963692e 
