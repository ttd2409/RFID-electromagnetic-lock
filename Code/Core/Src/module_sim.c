#include "module_sim.h"

sim_t sim=
{
		.arrRec="",
		.charRec=0,
		.countRec=0,
		.dataDoneFrame=false,
		.enReaddata=false
};


void sim_print(const char *fmt, ...)
{
  static char buffer[256];
  unsigned int len=0;
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);
  len=strlen(buffer);
  HAL_UART_Transmit(&huart2,buffer,len,100);
}

void finger(const char *fmt, ...)
{
  static char buffer[256];
  unsigned int len=0;
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);
  len=strlen(buffer);
  HAL_UART_Transmit(&huart1,buffer,len,100);
}


bool sim_send_sms(char* sdt, char noi_dung[200])
{
	sim_print("AT+CMGF=1\r\n"); HAL_Delay(200);
	sim_print("AT+CMGS=\"%s\"\r\n",sdt); HAL_Delay(200);
	sim_print("%s", noi_dung); HAL_Delay(200);
	char buf[1]={0x1a};
	HAL_UART_Transmit(&huart2,buf,1,100);
   return true;
}


