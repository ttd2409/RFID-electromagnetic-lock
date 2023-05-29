#ifndef MODULE_SIM_H
#define MODULE_SIM_H

#include "stm32f1xx_hal.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdarg.h>

#include "usart.h"
#include "gpio.h"

#define SIM_START '>'
#define SIM_STOP '<'

typedef struct
{
	char charRec;
	bool dataDoneFrame;
	bool enReaddata;
	char arrRec[100];
	uint16_t countRec;
}sim_t;

extern sim_t sim;

void sim_print(const char *fmt, ...);
void finger(const char *fmt, ...);
bool sim_send_sms(char* sdt, char noi_dung[200]);












#endif

