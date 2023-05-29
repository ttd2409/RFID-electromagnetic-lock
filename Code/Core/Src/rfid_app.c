#include "rfid_app.h"

uint8_t   k;
uint8_t   i;
uint8_t   j;
uint8_t   b;
uint8_t   q;
uint8_t   en;
uint8_t   ok;
uint8_t   comand;
uint8_t   txBuffer[8] = "";
uint8_t   retstr[10];
uint8_t   rxBuffer[8];
uint8_t   lastID[4];
uint8_t   memID[8] = "9C55A1B5";
uint8_t   str[MFRC522_MAX_LEN];
char rfid_code[20]="";

uint8_t hex_to_char(uint8_t data)
{
  uint8_t number;

  if (rxBuffer[data] < 58) number = (rxBuffer[data]-48)*16; else number = (rxBuffer[data]-55)*16;
  data++;
  if (rxBuffer[data] < 58) number = number+(rxBuffer[data]-48); else number = number+(rxBuffer[data]-55);
  return number;
}

// char number to string hex (FF) (Only big letters!)
void char_to_hex(uint8_t data)
{
  uint8_t digits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

  if (data < 16)
  {
    retstr[0] = '0';
    retstr[1] = digits[data];
  } else {
    retstr[0] = digits[(data & 0xF0)>>4];
    retstr[1] = digits[(data & 0x0F)];
  }
}

void read_rfid()
{

	if (!MFRC522_Request(PICC_REQIDL, str))
	{
	  if (!MFRC522_Anticoll(str))
	  {
	    j = 0;
	    q = 0;
	    b = 9;
	    en = 1;

	    for (i=0; i<4; i++) if (lastID[i] != str[i]) j = 1;               // Repeat test
	    //if (j && en)
	    {
	      q = 0;
	      en = 0;
	      for (i=0; i<4; i++) lastID[i] = str[i];
	      for (i=0; i<4; i++)
	      {
	        char_to_hex(str[i]);
	        txBuffer[b] = retstr[0];
	        b++;
	        txBuffer[b] = retstr[1];
	        b++;
	      }

	      //gửi mã thẻ RFID
	      char *temp;
	      for(int i=14;i<18;i++)
	      {
	        char txtTemp[1]="";
	        if(txBuffer[i]!=0)
	        {
	          //sprintf(txtTemp,"%x",txBuffer[i]);
	          sprintf(txtTemp,"%x",txBuffer[i]);

	          if(strlen(rfid_code)==0) memcpy(rfid_code,txtTemp,1);
	          else strcat(rfid_code,txtTemp);

	        }
	      }

	      //sim_print(rfid_code);
	      //sim_print("\n\r");

	      //đợi 1s
	      HAL_Delay(300);
	      ok = 1;
	      for (i=0; i<8; i++) if (txBuffer[9+i] != memID[i]) ok = 0;
	    }
	  }
	}//


	q++;
	if (!q)
	{
	  en = 1;               // Delay against scan kode
	  for (i=0; i<4; i++) lastID[i] = 0;  // Delay reading the same card 3s
	}

}








