#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#include "common.h"

#define MIN_ADDRESS 0x0000
#define MAX_ADDRESS 0x00FF
// #define MAX_ADDRESS 0xFFFF
#define EMPTY       0x0000
#define FULL        0xFFFF
#define PAGE_SZ     8
#define DPAGE_SZ    PAGE_SZ*2
typedef dregister_t memory_t[MAX_ADDRESS+1];

void clear(memory_t* bank);
void fill(memory_t* bank, const dregister_t val);
void fill_consecutive(memory_t* bank);
void fill_random(memory_t* bank);

void dump(const memory_t* bank);
void dumpbw(const memory_t* bank, const address_t low, const address_t high);
void dumppage(const memory_t* bank, const address_t low);
void dumppages(const memory_t* bank);
void dumpdpage(const memory_t* bank, const address_t low);
void dumpdpages(const memory_t* bank);

void dumpasciipage(const memory_t* bank, const address_t low);
void dumpasciipages(const memory_t* bank);

dregister_t peek(const memory_t* bank, const address_t addr);
dregister_t poke(memory_t* bank, const address_t addr, const address_t val);

#endif /* MEMORY_H */