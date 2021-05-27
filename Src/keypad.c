#include "main.h"
#include "keypad.h"
#include "stdio.h"
#include "lcd.h"
#include "lcd_init.h"



static KEY_GPIO_PIN OUT_KEY_PIN[] = //static表示只在本文件内有效，即让别的文件可以继续定义这个
{
  OUT_KEY_PORT_PIN
};

static KEY_GPIO_PIN IN_KEY_PIN[] = //static表示只在本文件内有效，即让别的文件可以继续定义这个
{
  IN_KEY_PORT_PIN
};


int Scan44Key(void)
{
   int KeyValue = -1;
   int i=0,j=0,k=0;

   for (i = 0; i < OUT_KEY_COUNT; i++) 
	{
		for (j = 0; j < OUT_KEY_COUNT; j++) 
		{
			if(i==j) HAL_GPIO_WritePin(OUT_KEY_PIN[j].port, OUT_KEY_PIN[j].pin, GPIO_PIN_SET);
			else     HAL_GPIO_WritePin(OUT_KEY_PIN[j].port, OUT_KEY_PIN[j].pin, GPIO_PIN_RESET);
			
		    for (k = 0; k < IN_KEY_COUNT; k++) 
	        {
			    if(HAL_GPIO_ReadPin(IN_KEY_PIN[k].port, IN_KEY_PIN[k].pin)>0)  
				 HAL_Delay(200);
				if(HAL_GPIO_ReadPin(IN_KEY_PIN[k].port, IN_KEY_PIN[k].pin)>0)
                 KeyValue= (3-i)+(k*4);
	        }
		}
	 } 
     return  KeyValue;
}


//void KeyHandle(int iKey)
//{	
//	if(iKey>=0)
//	{
//		 if((iKey+1)/4.0==1)         printf("key A be pressed \r\n",iKey);
//		 else if((iKey+1)/4.0==2)    printf("key B be pressed \r\n");
//		 else if((iKey+1)/4.0==3)    printf("key C be pressed\r\n");
//		 else if((iKey+1)/4.0==4)    printf("KEY D be pressed\r\n");
//		 else if(iKey==12)           printf("KEY * be pressed\r\n");
//		 else if(iKey==13)           printf("KEY 9 be pressed\r\n"); 
//		 else if(iKey==14)           
//		 {
//			 printf("KEY # be pressed\r\n");
//		 }
//		 else
//		 {
//			 int i;
//			 i=iKey-((iKey+1)/4);
//			 printf("key %d be pressed \r\n",iKey);
//     }	
// }

// }






 