#include "6502.h"

#include <stdio.h>

void dump_MOS_6502(const MOS_6502_t* m6502p) {
    printf("MOS_6502(%d)\n", m6502p->id);
    printf("  A= 0x%02x\n", m6502p->reg.A);
    printf("  X= 0x%02x\n", m6502p->reg.X);
    printf("  Y= 0x%02x\n\n", m6502p->reg.Y);
    printf("  SP=0x%02x\n", m6502p->reg.SP);
    printf("  PC=0x%02x\n\n", m6502p->reg.PC);
    printf("  N%d V%d B%d D%d\n  I%d Z%d C%d\n",
            m6502p->flag.N, m6502p->flag.V, m6502p->flag.B,
            m6502p->flag.D, m6502p->flag.I, m6502p->flag.Z,
            m6502p->flag.C);
    printf("MOS_6502(%d)\n\n", m6502p->id);
}