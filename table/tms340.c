/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPLv3
 *
 * Copyright 2010-2020 by Michael Kohn
 *
 */

#include "table/tms340.h"

struct _table_tms340 table_tms340[] =
{
  { "addxy",  0xe000, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "cmpxy",  0xe400, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "cpw",    0xe600, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "cvxyl",  0xe800, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "dray",   0xf600, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "fill",   0x0fc0, 0xffff, 1, { OP_L,          OP_NONE,       OP_NONE }},
  { "fill",   0x0fe0, 0xffff, 1, { OP_XY,         OP_NONE,       OP_NONE }},
  { "movx",   0xec00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "movy",   0xee00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "pixblt", 0x0f80, 0xffff, 2, { OP_B,          OP_L,          OP_NONE }},
  { "pixblt", 0x0fa0, 0xffff, 2, { OP_B,          OP_XY,         OP_NONE }},
  { "pixblt", 0x0f00, 0xffff, 2, { OP_L,          OP_L,          OP_NONE }},
  { "pixblt", 0x0f20, 0xffff, 2, { OP_L,          OP_XY,         OP_NONE }},
  { "pixblt", 0x0f40, 0xffff, 2, { OP_XY,         OP_L,          OP_NONE }},
  { "pixblt", 0x0f60, 0xffff, 2, { OP_XY,         OP_XY,         OP_NONE }},
  { "pixt",   0xf800, 0xfe00, 2, { OP_REG,        OP_P_REG,      OP_NONE }},
  { "pixt",   0xf000, 0xfe00, 2, { OP_REG,        OP_P_REG_XY,   OP_NONE }},
  { "pixt",   0xfa00, 0xfe00, 2, { OP_P_REG,      OP_REG,        OP_NONE }},
  { "pixt",   0xfc00, 0xfe00, 2, { OP_P_REG,      OP_P_REG,      OP_NONE }},
  { "pixt",   0xf200, 0xfe00, 2, { OP_P_REG_XY,   OP_REG,        OP_NONE }},
  { "pixt",   0xf400, 0xfe00, 2, { OP_P_REG_XY,   OP_P_REG_XY,   OP_NONE }},
  { "subxy",  0xe200, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "line",   0xdf1a, 0xff7f, 1, { OP_Z,          OP_NONE,       OP_NONE }},
  { "movb",   0x8c00, 0xfe00, 2, { OP_REG,        OP_P_REG,      OP_NONE }},
  { "movb",   0x8e00, 0xfe00, 2, { OP_P_REG,      OP_REG,        OP_NONE }},
  { "movb",   0x9c00, 0xfe00, 2, { OP_P_REG,      OP_P_REG,      OP_NONE }},
  { "movb",   0xac00, 0xfe00, 2, { OP_P_REG,      OP_P_REG_DISP, OP_NONE }},
  { "movb",   0xae00, 0xfe00, 2, { OP_P_REG_DISP, OP_REG,        OP_NONE }},
  { "movb",   0xbc00, 0xfe00, 2, { OP_P_REG_DISP, OP_P_REG_DISP, OP_NONE }},
  { "movb",   0x05e0, 0xffe0, 2, { OP_REG,        OP_AT_ADDR,    OP_NONE }},
  { "movb",   0x07e0, 0xffe0, 2, { OP_AT_ADDR,    OP_REG,        OP_NONE }},
  { "movb",   0x0340, 0xffff, 2, { OP_AT_ADDR,    OP_AT_ADDR,    OP_NONE }},
  { "move",   0x4c00, 0xfc00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "move",   0x8000, 0xfc00, 3, { OP_REG,        OP_P_REG,      OP_F }},
  { "move",   0xa000, 0xfc00, 3, { OP_REG,        OP_MP_REG,     OP_F }},
  { "move",   0x9000, 0xfc00, 3, { OP_REG,        OP_P_REG_P,    OP_F }},
  { "move",   0x8400, 0xfc00, 3, { OP_P_REG,      OP_REG,        OP_F }},
  { "move",   0xa400, 0xfc00, 3, { OP_MP_REG,     OP_REG,        OP_F }},
  { "move",   0x9400, 0xfc00, 3, { OP_P_REG_P,    OP_REG,        OP_F }},
  { "move",   0x8800, 0xfc00, 3, { OP_P_REG,      OP_P_REG,      OP_F }},
  { "move",   0xa800, 0xfc00, 3, { OP_MP_REG,     OP_MP_REG,     OP_F }},
  { "move",   0x9800, 0xfc00, 3, { OP_P_REG_P,    OP_P_REG_P,    OP_F }},
  { "move",   0xb000, 0xfc00, 3, { OP_REG,        OP_P_REG_DISP, OP_F }},
  { "move",   0xb400, 0xfc00, 3, { OP_P_REG_DISP, OP_REG,        OP_F }},
  { "move",   0xd000, 0xfc00, 3, { OP_P_REG_DISP, OP_P_REG_P,    OP_F }},
  { "move",   0xb800, 0xfc00, 3, { OP_P_REG_DISP, OP_P_REG_DISP, OP_F }},
  { "move",   0x0580, 0xfde0, 3, { OP_REG,        OP_AT_ADDR,    OP_F }},
  { "move",   0x05a0, 0xfde0, 3, { OP_AT_ADDR,    OP_REG,        OP_F }},
  { "move",   0xd400, 0xfde0, 3, { OP_AT_ADDR,    OP_P_REG_P,    OP_F }},
  { "move",   0x05c0, 0xfdf0, 3, { OP_AT_ADDR,    OP_AT_ADDR,    OP_F }},
  { "abs",    0x0380, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "add",    0x4000, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "addc",   0x4200, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "addi",   0x0b00, 0xffe0, 2, { OP_IW,         OP_REG,        OP_NONE }},
  { "addi",   0x0b20, 0xffe0, 2, { OP_IL,         OP_REG,        OP_NONE }},
  { "addk",   0x1000, 0xf000, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "and",    0x5000, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "andi",   0x0b80, 0xffe0, 2, { OP_IL,         OP_REG,        OP_NONE }},
  { "andn",   0x5200, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "andni",  0x0b80, 0xffe0, 2, { OP_IL,         OP_REG,        OP_NONE }},
  { "btst",   0x1c00, 0xfc00, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "btst",   0x4a00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "clr",    0x5600, 0xfe00, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "clrc",   0x0320, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "cmp",    0x0b40, 0xffe0, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "cmpi",   0x0b40, 0xffe0, 2, { OP_IW,         OP_REG,        OP_NONE }},
  { "cmpi",   0x0b60, 0xffe0, 2, { OP_IL,         OP_REG,        OP_NONE }},
  { "dec",    0x1420, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "dint",   0x0360, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "divs",   0x5800, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "divu",   0x5a00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "eint",   0x0d60, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "exgf",   0xd500, 0xfde0, 2, { OP_REG,        OP_F,          OP_NONE }},
  { "lmo",    0x6a00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "mmfm",   0x09a0, 0xffe0, 2, { OP_REG,        OP_LIST,       OP_NONE }},
  { "mmtm",   0x0980, 0xffe0, 2, { OP_REG,        OP_LIST,       OP_NONE }},
  { "mods",   0x6c00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "modu",   0x6e00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "movi",   0x09c0, 0xffe0, 2, { OP_IW,         OP_REG,        OP_NONE }},
  { "movi",   0x09e0, 0xffe0, 2, { OP_IL,         OP_REG,        OP_NONE }},
  { "movk",   0x1800, 0xfc00, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "mpys",   0x5c00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "mpyu",   0x5e00, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "neg",    0x03a0, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "negb",   0x03c0, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "nop",    0x0300, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "not",    0x03e0, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "or",     0x5400, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "ori",    0x0ba0, 0xffe0, 2, { OP_L,          OP_REG,        OP_NONE }},
  { "rl",     0x3000, 0xf000, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "rl",     0x6800, 0xfc00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "setc",   0x0de0, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "setf",   0x0540, 0xfdc0, 3, { OP_FS,         OP_FE,         OP_F }},
  { "sext",   0x0500, 0xfde0, 2, { OP_REG,        OP_F,          OP_NONE }},
  { "sla",    0x2000, 0xf000, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "sla",    0x6000, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "sll",    0x2400, 0xfc00, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "sll",    0x6200, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "sra",    0x2800, 0xfc00, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "sra",    0x6400, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "srl",    0x2c00, 0xfc00, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "srl",    0x6600, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "sub",    0x4400, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "subb",   0x4600, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "subi",   0x0be0, 0xffe0, 2, { OP_IW,         OP_REG,        OP_NONE }},
  { "subi",   0x0de0, 0xffe0, 2, { OP_IL,         OP_REG,        OP_NONE }},
  { "subk",   0x1400, 0xfc00, 2, { OP_K,          OP_REG,        OP_NONE }},
  { "xor",    0x5600, 0xfe00, 2, { OP_REG,        OP_REG,        OP_NONE }},
  { "xori",   0x0bc0, 0xffe0, 2, { OP_IL,         OP_REG,        OP_NONE }},
  { "zext",   0x0520, 0xfde0, 2, { OP_REG,        OP_F,          OP_NONE }},
  { "call",   0x0920, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "calla",  0x0d5f, 0xffff, 1, { OP_ADDRESS,    OP_NONE,       OP_NONE }},
  { "callr",  0x0d3f, 0xffff, 1, { OP_ADDRESS,    OP_NONE,       OP_NONE }},
  { "dsj",    0x0d80, 0xffe0, 2, { OP_REG,        OP_ADDRESS,    OP_NONE }},
  { "dsjeq",  0x0da0, 0xffe0, 2, { OP_REG,        OP_ADDRESS,    OP_NONE }},
  { "dsjne",  0x0dc0, 0xffc0, 2, { OP_REG,        OP_ADDRESS,    OP_NONE }},
  { "dsjs",   0x3800, 0xf800, 2, { OP_REG,        OP_ADDRESS,    OP_NONE }},
  { "emu",    0x0100, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "exgpc",  0x0120, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "getpc",  0x0140, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "getst",  0x0180, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "jacc",   0xc080, 0xf0ff, 1, { OP_ADDRESS,    OP_NONE,       OP_NONE }},
  { "jrcc",   0xc000, 0xf0ff, 1, { OP_ADDRESS,    OP_NONE,       OP_NONE }},
  { "jrcc",   0xc000, 0xf000, 1, { OP_ADDRESS,    OP_NONE,       OP_NONE }},
  { "jump",   0x0160, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "popst",  0x01c0, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "pushst", 0x01e0, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "putst",  0x01a0, 0xffe0, 1, { OP_REG,        OP_NONE,       OP_NONE }},
  { "reti",   0x0940, 0xffff, 0, { OP_NONE,       OP_NONE,       OP_NONE }},
  { "rets",   0x0960, 0xffe0, 1, { OP_NN,         OP_NONE,       OP_NONE }},
  { "trap",   0x0900, 0xffe0, 1, { OP_N,          OP_NONE,       OP_NONE }},
  { NULL,          0,      0, 0, {    0,               0,            0 }}
};
