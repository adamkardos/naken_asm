/**
 *  naken_asm assembler.
 *  Author: Michael Kohn
 *   Email: mike@mikekohn.net
 *     Web: http://www.mikekohn.net/
 * License: GPL
 *
 * Copyright 2010-2013 by Michael Kohn
 *
 * 65XX file by Joe Davisson
 *
 */

#include "table_65xx.h"

#define unused -1
#define abs 0
#define absx 1
#define absy 2
#define imm 3
#define imp 4
#define ind 5
#define indx 6
#define indy 7
#define rel 8
#define zp 9
#define zpx 10
#define zpy 11

struct _opcodes_65xx opcodes_65xx[] = {
  // name    abs ,absx,absy,imm ,imp ,ind ,indx,indy,rel, zp  ,zpx ,zpy
  { "adc", { 0x6D,0x7D,0x79,0x69,0xFF,0xFF,0x61,0x71,0xFF,0x65,0x75,0xFF } },
  { "and", { 0x2D,0x3D,0x39,0x29,0xFF,0xFF,0x21,0x31,0xFF,0x25,0x35,0xFF } },
  { "asl", { 0x0E,0x1E,0xFF,0xFF,0x0A,0xFF,0xFF,0xFF,0xFF,0x06,0x16,0xFF } },
  { "bcc", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x90,0xFF,0xFF,0xFF } },
  { "bcs", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xB0,0xFF,0xFF,0xFF } },
  { "beq", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0xFF,0xFF,0xFF } },
  { "bmi", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x30,0xFF,0xFF,0xFF } },
  { "bne", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD0,0xFF,0xFF,0xFF } },
  { "bpl", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x10,0xFF,0xFF,0xFF } },
  { "bvc", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x50,0xFF,0xFF,0xFF } },
  { "bvs", { 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x70,0xFF,0xFF,0xFF } },
  { "brk", { 0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "bit", { 0x2C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x24,0xFF,0xFF } },
  { "clc", { 0xFF,0xFF,0xFF,0xFF,0x18,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "cld", { 0xFF,0xFF,0xFF,0xFF,0xD8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "cli", { 0xFF,0xFF,0xFF,0xFF,0x58,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "clv", { 0xFF,0xFF,0xFF,0xFF,0xB8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "cmp", { 0xCD,0xDD,0xD9,0xC9,0xFF,0xFF,0xC1,0xD1,0xFF,0xC5,0xD5,0xFF } },
  { "cpx", { 0xEC,0xFF,0xFF,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0xE4,0xFF,0xFF } },
  { "cpy", { 0xCC,0xFF,0xFF,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xC4,0xFF,0xFF } },
  { "dec", { 0xCE,0xDE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC6,0xD6,0xFF } },
  { "dex", { 0xFF,0xFF,0xFF,0xFF,0xCA,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "dey", { 0xFF,0xFF,0xFF,0xFF,0x88,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "eor", { 0x4D,0x5D,0x59,0x49,0xFF,0xFF,0x41,0x51,0xFF,0x45,0x55,0xFF } },
  { "inc", { 0xEE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE6,0xF6,0xFF } },
  { "inx", { 0xFF,0xFF,0xFF,0xFF,0xE8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "iny", { 0xFF,0xFF,0xFF,0xFF,0xC8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "jmp", { 0x4C,0xFF,0xFF,0xFF,0xFF,0x6C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "jsr", { 0x20,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "lda", { 0xAD,0xBD,0xB9,0xA9,0xFF,0xFF,0xA1,0xB1,0xFF,0xA5,0xB5,0xFF } },
  { "ldx", { 0xAE,0xFF,0xBE,0xA2,0xFF,0xFF,0xFF,0xFF,0xFF,0xA6,0xFF,0xB6 } },
  { "ldy", { 0xAC,0xBC,0xFF,0xA0,0xFF,0xFF,0xFF,0xFF,0xFF,0xA4,0xB4,0xFF } },
  { "lsr", { 0x4E,0x5E,0xFF,0xFF,0x4A,0xFF,0xFF,0xFF,0xFF,0x46,0x56,0xFF } },
  { "nop", { 0xFF,0xFF,0xFF,0xFF,0xEA,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "ora", { 0x0D,0x1D,0x19,0x09,0xFF,0xFF,0x01,0x11,0xFF,0x05,0x15,0xFF } },
  { "pha", { 0xFF,0xFF,0xFF,0xFF,0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "php", { 0xFF,0xFF,0xFF,0xFF,0x08,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "pla", { 0xFF,0xFF,0xFF,0xFF,0x68,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "plp", { 0xFF,0xFF,0xFF,0xFF,0x28,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "rol", { 0x2E,0x3E,0xFF,0xFF,0x2A,0xFF,0xFF,0xFF,0xFF,0x26,0x36,0xFF } },
  { "ror", { 0x6E,0x7E,0xFF,0xFF,0x6A,0xFF,0xFF,0xFF,0xFF,0x66,0x76,0xFF } },
  { "rti", { 0xFF,0xFF,0xFF,0xFF,0x40,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "rts", { 0xFF,0xFF,0xFF,0xFF,0x60,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "sbc", { 0xED,0xFD,0xF9,0xE9,0xFF,0xFF,0xE1,0xF1,0xFF,0xE5,0xF5,0xFF } },
  { "sec", { 0xFF,0xFF,0xFF,0xFF,0x38,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "sed", { 0xFF,0xFF,0xFF,0xFF,0xF8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "sei", { 0xFF,0xFF,0xFF,0xFF,0x78,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "sta", { 0x8D,0x9D,0x99,0xFF,0xFF,0xFF,0x81,0x91,0xFF,0x85,0x95,0xFF } },
  { "stx", { 0x8E,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x86,0xFF,0x96 } },
  { "sty", { 0x8C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x84,0x94,0xFF } },
  { "tax", { 0xFF,0xFF,0xFF,0xFF,0xAA,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "tay", { 0xFF,0xFF,0xFF,0xFF,0xA8,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "tsx", { 0xFF,0xFF,0xFF,0xFF,0xBA,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "txa", { 0xFF,0xFF,0xFF,0xFF,0x8A,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "txs", { 0xFF,0xFF,0xFF,0xFF,0x9A,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } },
  { "tya", { 0xFF,0xFF,0xFF,0xFF,0x98,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF } }
};

struct _cycles_65xx cycles_65xx[] = {
  // op,   cyc, inc, mode
  { 0x00,  7,   0,   imp },
  { 0x01,  6,   0,   indx },
  { 0x02,  0,   0,   unused },
  { 0x03,  0,   0,   unused },
  { 0x04,  0,   0,   unused },
  { 0x05,  3,   0,   zp },
  { 0x06,  5,   0,   zp },
  { 0x07,  0,   0,   unused },
  { 0x08,  3,   0,   imp },
  { 0x09,  2,   0,   imm },
  { 0x0a,  2,   0,   imp },
  { 0x0b,  0,   0,   unused },
  { 0x0c,  0,   0,   unused },
  { 0x0d,  4,   0,   abs },
  { 0x0e,  6,   0,   abs },
  { 0x0f,  0,   0,   unused },
  { 0x10,  2,   0,   rel },
  { 0x11,  5,   1,   indy },
  { 0x12,  0,   0,   unused },
  { 0x13,  0,   0,   unused },
  { 0x14,  0,   0,   unused },
  { 0x15,  4,   0,   zpx },
  { 0x16,  6,   0,   zpx },
  { 0x17,  0,   0,   unused },
  { 0x18,  2,   0,   imp },
  { 0x19,  4,   1,   absy },
  { 0x1a,  0,   0,   unused },
  { 0x1b,  0,   0,   unused },
  { 0x1c,  0,   0,   unused },
  { 0x1d,  4,   1,   absx },
  { 0x1e,  7,   0,   absx },
  { 0x1f,  0,   0,   unused },
  { 0x20,  6,   0,   abs },
  { 0x21,  6,   0,   indx },
  { 0x22,  0,   0,   unused },
  { 0x23,  0,   0,   unused },
  { 0x24,  3,   0,   zp },
  { 0x25,  3,   0,   zp },
  { 0x26,  5,   0,   zp },
  { 0x27,  0,   0,   unused },
  { 0x28,  4,   0,   imp },
  { 0x29,  2,   0,   imm },
  { 0x2a,  2,   0,   imp },
  { 0x2b,  0,   0,   unused },
  { 0x2c,  4,   0,   abs },
  { 0x2d,  4,   0,   abs },
  { 0x2e,  6,   0,   abs },
  { 0x2f,  0,   0,   unused },
  { 0x30,  2,   0,   rel },
  { 0x31,  5,   1,   indy },
  { 0x32,  0,   0,   unused },
  { 0x33,  0,   0,   unused },
  { 0x34,  0,   0,   unused },
  { 0x35,  4,   0,   zpx },
  { 0x36,  6,   0,   zpx },
  { 0x37,  0,   0,   unused },
  { 0x38,  2,   0,   imp },
  { 0x39,  4,   1,   absy },
  { 0x3a,  0,   0,   unused },
  { 0x3b,  0,   0,   unused },
  { 0x3c,  0,   0,   unused },
  { 0x3d,  4,   1,   absx },
  { 0x3e,  7,   0,   absx },
  { 0x3f,  0,   0,   unused },
  { 0x40,  6,   0,   imp },
  { 0x41,  6,   0,   indx },
  { 0x42,  0,   0,   unused },
  { 0x43,  0,   0,   unused },
  { 0x44,  0,   0,   unused },
  { 0x45,  3,   0,   zp },
  { 0x46,  3,   0,   zp },
  { 0x47,  0,   0,   unused },
  { 0x48,  3,   0,   imp },
  { 0x49,  2,   0,   imm },
  { 0x4a,  2,   0,   imp },
  { 0x4b,  0,   0,   unused },
  { 0x4c,  3,   0,   abs },
  { 0x4d,  4,   0,   abs },
  { 0x4e,  6,   0,   abs },
  { 0x4f,  0,   0,   unused },
  { 0x50,  2,   0,   rel },
  { 0x51,  5,   1,   indy },
  { 0x52,  0,   0,   unused },
  { 0x53,  0,   0,   unused },
  { 0x54,  0,   0,   unused },
  { 0x55,  4,   0,   zpx },
  { 0x56,  6,   0,   zpx },
  { 0x57,  0,   0,   unused },
  { 0x58,  2,   0,   imp },
  { 0x59,  4,   1,   absy },
  { 0x5a,  0,   0,   unused },
  { 0x5b,  0,   0,   unused },
  { 0x5c,  0,   0,   unused },
  { 0x5d,  4,   1,   absx },
  { 0x5e,  7,   0,   absx },
  { 0x5f,  0,   0,   unused },
  { 0x60,  6,   0,   imp },
  { 0x61,  6,   0,   indx },
  { 0x62,  0,   0,   unused },
  { 0x63,  0,   0,   unused },
  { 0x64,  0,   0,   unused },
  { 0x65,  3,   0,   zp },
  { 0x66,  3,   0,   zp },
  { 0x67,  0,   0,   unused },
  { 0x68,  4,   0,   imp },
  { 0x69,  2,   0,   imm },
  { 0x6a,  2,   0,   imp },
  { 0x6b,  0,   0,   unused },
  { 0x6c,  5,   0,   ind },
  { 0x6d,  4,   0,   abs },
  { 0x6e,  6,   0,   abs },
  { 0x6f,  0,   0,   unused },
  { 0x70,  2,   0,   rel },
  { 0x71,  5,   1,   indy },
  { 0x72,  0,   0,   unused },
  { 0x73,  0,   0,   unused },
  { 0x74,  0,   0,   unused },
  { 0x75,  4,   0,   zpx },
  { 0x76,  6,   0,   zpx },
  { 0x77,  0,   0,   unused },
  { 0x78,  2,   0,   imp },
  { 0x79,  4,   1,   absy },
  { 0x7a,  0,   0,   unused },
  { 0x7b,  0,   0,   unused },
  { 0x7c,  0,   0,   unused },
  { 0x7d,  4,   1,   absx },
  { 0x7e,  7,   0,   absx },
  { 0x7f,  0,   0,   unused },
  { 0x80,  0,   0,   unused },
  { 0x81,  6,   0,   indx },
  { 0x82,  0,   0,   unused },
  { 0x83,  0,   0,   unused },
  { 0x84,  3,   0,   zp },
  { 0x85,  3,   0,   zp },
  { 0x86,  3,   0,   zp },
  { 0x87,  0,   0,   unused },
  { 0x88,  2,   0,   imp },
  { 0x89,  0,   0,   unused },
  { 0x8a,  2,   0,   imp },
  { 0x8b,  0,   0,   unused },
  { 0x8c,  4,   0,   abs },
  { 0x8d,  4,   0,   abs },
  { 0x8e,  4,   0,   abs },
  { 0x8f,  0,   0,   unused },
  { 0x90,  2,   0,   rel },
  { 0x91,  6,   0,   indy },
  { 0x92,  0,   0,   unused },
  { 0x93,  0,   0,   unused },
  { 0x94,  4,   0,   zpx },
  { 0x95,  4,   0,   zpx },
  { 0x96,  4,   0,   zpy },
  { 0x97,  0,   0,   unused },
  { 0x98,  2,   0,   imp },
  { 0x99,  5,   0,   absy },
  { 0x9a,  0,   0,   imp },
  { 0x9b,  0,   0,   unused },
  { 0x9c,  0,   0,   unused },
  { 0x9d,  5,   0,   absx },
  { 0x9e,  0,   0,   unused },
  { 0x9f,  0,   0,   unused },
  { 0xa0,  2,   0,   imm },
  { 0xa1,  6,   0,   indx },
  { 0xa2,  2,   0,   imm },
  { 0xa3,  0,   0,   unused },
  { 0xa4,  3,   0,   zp },
  { 0xa5,  3,   0,   zp },
  { 0xa6,  3,   0,   zp },
  { 0xa7,  0,   0,   unused },
  { 0xa8,  2,   0,   imp },
  { 0xa9,  2,   0,   imm },
  { 0xaa,  2,   0,   imp },
  { 0xab,  0,   0,   unused },
  { 0xac,  4,   0,   abs },
  { 0xad,  4,   0,   abs },
  { 0xae,  4,   0,   abs },
  { 0xaf,  0,   0,   unused },
  { 0xb0,  2,   0,   rel },
  { 0xb1,  5,   1,   indy },
  { 0xb2,  0,   0,   unused },
  { 0xb3,  0,   0,   unused },
  { 0xb4,  4,   0,   zpx },
  { 0xb5,  4,   0,   zpx },
  { 0xb6,  4,   0,   zpy },
  { 0xb7,  0,   0,   unused },
  { 0xb8,  2,   0,   imp },
  { 0xb9,  4,   1,   absy },
  { 0xba,  2,   0,   imp },
  { 0xbb,  0,   0,   unused },
  { 0xbc,  4,   1,   absx },
  { 0xbd,  4,   1,   absx },
  { 0xbe,  4,   1,   absy },
  { 0xbf,  0,   0,   unused },
  { 0xc0,  2,   0,   imm },
  { 0xc1,  6,   0,   indx },
  { 0xc2,  0,   0,   unused },
  { 0xc3,  0,   0,   unused },
  { 0xc4,  3,   0,   zp },
  { 0xc5,  3,   0,   zp },
  { 0xc6,  5,   0,   zp },
  { 0xc7,  0,   0,   unused },
  { 0xc8,  2,   0,   imp },
  { 0xc9,  2,   0,   imm },
  { 0xca,  2,   0,   imp },
  { 0xcb,  0,   0,   unused },
  { 0xcc,  4,   0,   abs },
  { 0xcd,  4,   0,   abs },
  { 0xce,  6,   0,   abs },
  { 0xcf,  0,   0,   unused },
  { 0xd0,  2,   0,   rel },
  { 0xd1,  5,   1,   indy },
  { 0xd2,  0,   0,   unused },
  { 0xd3,  0,   0,   unused },
  { 0xd4,  0,   0,   unused },
  { 0xd5,  4,   0,   zpx },
  { 0xd6,  6,   0,   zpx },
  { 0xd7,  0,   0,   unused },
  { 0xd8,  2,   0,   imp },
  { 0xd9,  4,   1,   absy },
  { 0xda,  0,   0,   unused },
  { 0xdb,  0,   0,   unused },
  { 0xdc,  0,   0,   unused },
  { 0xdd,  4,   1,   absx },
  { 0xde,  7,   0,   absx },
  { 0xdf,  0,   0,   unused },
  { 0xe0,  2,   0,   imm },
  { 0xe1,  6,   0,   indx },
  { 0xe2,  0,   0,   unused },
  { 0xe3,  0,   0,   unused },
  { 0xe4,  3,   0,   zp },
  { 0xe5,  3,   0,   zp },
  { 0xe6,  5,   0,   zp },
  { 0xe7,  0,   0,   unused },
  { 0xe8,  2,   0,   imp },
  { 0xe9,  2,   0,   imm },
  { 0xea,  2,   0,   imp },
  { 0xeb,  0,   0,   unused },
  { 0xec,  4,   0,   abs },
  { 0xed,  4,   0,   abs },
  { 0xee,  6,   0,   abs },
  { 0xef,  0,   0,   unused },
  { 0xf0,  2,   0,   rel },
  { 0xf1,  5,   1,   indy },
  { 0xf2,  0,   0,   unused },
  { 0xf3,  0,   0,   unused },
  { 0xf4,  0,   0,   unused },
  { 0xf5,  4,   0,   zpx },
  { 0xf6,  6,   0,   zpx },
  { 0xf7,  0,   0,   unused },
  { 0xf8,  2,   0,   imp },
  { 0xf9,  4,   1,   absy },
  { 0xfa,  0,   0,   unused },
  { 0xfb,  0,   0,   unused },
  { 0xfc,  0,   0,   unused },
  { 0xfd,  4,   1,   absx },
  { 0xfe,  7,   0,   absx },
  { 0xff,  0,   0,   unused },
};

