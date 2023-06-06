#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "6502.h"
#include "mem.h"

#define MAX_BUF_SZ 80

int main() {
    srand(time(NULL));

    bool exit_flag = false;

    MOS_6502_t m6502 = {0};
    dump_MOS_6502(&m6502);

    memory_t bank = {0};
    // fill_random(&bank);
    // fill(&bank, 0xae);
    fill_consecutive(&bank);
    // poke(&bank, 0x0000, 'x');

    // dumpbw(&bank, 0xffff, 0xffff);
    // dumppages(&bank);
    // dumpdpages(&bank);
    dumpasciipages(&bank);

    return EXIT_SUCCESS;

    char buf[MAX_BUF_SZ];
    while (!exit_flag) {
        printf("> ");
        fgets(buf, MAX_BUF_SZ, stdin);
        
        if (buf[0] == 'q' || buf[0] == 'Q') exit_flag = true;
    } 

    return EXIT_SUCCESS;
}