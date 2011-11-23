#include <icicle.h>

#include <stdlib.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#include <sys/mman.h>

void* icicle_require(char* name);

int main(int argc, char* argv[]){
    char* progname;
    int fd;
    char* load_addr;
    struct icicle_header header;
    size_t hsz = sizeof(header);
    int (*load)(REQUIRE);
    int noticicle;

    if (argc < 2){
        fprintf(stderr, "usage: load prog\n");
        return 1;
    }

    progname = argv[1];
    fd = open(progname, O_RDONLY);
    noticicle = 0;
    noticicle |= (read(fd, &header, hsz) != hsz);
    noticicle |= (header.magic != ICICLE_MAGIC);
    if (noticicle){
        fprintf(stderr, "load: %s is not an icicle\n", progname);
        return 1;
    }
    
    load_addr = mmap(
        NULL,
        header.size,
        PROT_EXEC|PROT_READ|PROT_WRITE,
        MAP_PRIVATE,
        fd,
        0
    );

    load = (int (*)(REQUIRE))(load_addr+header.entry);

    printf("load successful\n");

    load(icicle_require);

    printf("exit successful\n");

    close(fd);

    return 0;
}
