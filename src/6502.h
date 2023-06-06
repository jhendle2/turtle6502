#ifndef MOS_6502_H
#define MOS_6502_H

#include "common.h"

typedef struct {
    unsigned int id;    /* Keeps track of multiple processors */
    struct {
        register_t  A;  /* Accumulator */
        register_t  X;  /* Index Register 1 */
        register_t  Y;  /* Index Register 2 */
        register_t  SP; /* Stack Pointer */
        dregister_t PC; /* Program Counter (16-bit) */
    } reg;
    struct {
        flag_t N: 1;    /* Negative */
        flag_t V: 1;    /* oVerflow */
        flag_t B: 1;    /* Break */
        flag_t D: 1;    /* Decimal */
        flag_t I: 1;    /* Interrupt disable */
        flag_t Z: 1;    /* Zero */
        flag_t C: 1;    /* Carry*/
    } flag;
} MOS_6502_t;

void dump_MOS_6502(const MOS_6502_t* m6502p);

#endif /* MOS_6502_H */