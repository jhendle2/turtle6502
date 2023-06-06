#include "mem.h"

#include <stdio.h>
#include <stdlib.h>

#define forAllAddresses for (address_t a = MIN_ADDRESS; a < MAX_ADDRESS; a++)

void clear(memory_t* bank)                      { forAllAddresses (*bank)[a] = EMPTY; }
void fill(memory_t* bank, const dregister_t val){ forAllAddresses (*bank)[a] = val; }
void fill_consecutive(memory_t* bank)           { forAllAddresses (*bank)[a] = a; (*bank)[MAX_ADDRESS] = MAX_ADDRESS & 0xFF; }
void fill_random(memory_t* bank)                { forAllAddresses (*bank)[a] = rand() & 0xFF; }

void dump(const memory_t* bank) {
    forAllAddresses printf("0x%04x : 0x%02x\n", a, (*bank)[a]);
}
void dumpbw(const memory_t* bank, const address_t low, const address_t high) {
    if (low == high)
        printf("0x%04x : 0x%02x\n", low, (*bank)[low]);
    else for (address_t a = low; a < high; a++)
        printf("0x%04x : 0x%02x\n", a, (*bank)[a]);
}
void dumppage(const memory_t* bank, const address_t low) {
    printf("0x%04x : ", low);
    for (address_t a = low; a < low + PAGE_SZ; a++) {
        printf("%02x ", (*bank)[a]);
    } printf("\n");
}

void dumppages(const memory_t* bank) {
    for (address_t high = MIN_ADDRESS >> 4; high <= MAX_ADDRESS >> 4; high++) {
        printf("0x%04x : ", high << 4);
        for (address_t a = 0; a < PAGE_SZ; a++) {
            printf("%02x ", (*bank)[high*DPAGE_SZ+a]);
        } printf("\n");
        printf("0x%04x : ", high << 4 | 0x8);
        for (address_t a = PAGE_SZ; a < DPAGE_SZ; a++) {
            printf("%02x ", (*bank)[high*DPAGE_SZ+a]);
        } printf("\n");
    }
}
void dumpdpage(const memory_t* bank, const address_t low) {
    printf("0x%04x : ", low);
    for (address_t a = low; a < low + DPAGE_SZ; a++) {
        printf("%02x ", (*bank)[a]);
    } printf("\n");
}

void dumpdpages(const memory_t* bank) {
    for (address_t high = MIN_ADDRESS >> 4; high <= MAX_ADDRESS >> 4; high++) {
        printf("0x%04x : ", high << 4);
        for (address_t a = 0; a < DPAGE_SZ; a++) {
            printf("%02x ", (*bank)[high*DPAGE_SZ+a]);
        } printf("\n");
    }
}

void dumpasciipage(const memory_t* bank, const address_t low) {
    printf("0x%04x : ", low);
    for (address_t a = low; a < low + DPAGE_SZ; a++) {
        const char c = (*bank)[a];
        printf("%c", (c >= ' ' && c <= '~') ? c : '.');
    } printf("\n");
}
void dumpasciipages(const memory_t* bank) {
    for (address_t high = MIN_ADDRESS >> 4; high <= MAX_ADDRESS >> 4; high++) {
        printf("0x%04x : ", high << 4);
        for (address_t a = 0; a < DPAGE_SZ; a++) {
            const char c = (*bank)[high*DPAGE_SZ+a];
            printf("%c", (c >= ' ' && c <= '~') ? c : '.');
        } printf("\n");
    }
}

dregister_t peek(const memory_t* bank, const address_t addr) {
    return (*bank)[addr];
}
dregister_t poke(memory_t* bank, const address_t addr, const address_t val) {
    const address_t old = (*bank)[addr];
    (*bank)[addr] = val;
    return old;
}