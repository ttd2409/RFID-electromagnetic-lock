#ifndef RFID_APP_H
#define RFID_APP_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdarg.h>

#include "mfrc522.h"

extern uint8_t   k;
extern uint8_t   i;
extern uint8_t   j;
extern uint8_t   b;
extern uint8_t   q;
extern uint8_t   en;
extern uint8_t   ok;
extern uint8_t   comand;
extern uint8_t   txBuffer[8];
extern uint8_t   retstr[10];
extern uint8_t   rxBuffer[8];
extern uint8_t   lastID[4];
extern uint8_t   memID[8];
extern uint8_t   str[MFRC522_MAX_LEN];
extern char rfid_code[20];

uint8_t hex_to_char(uint8_t data);
void char_to_hex(uint8_t data);
void read_rfid();





#endif

