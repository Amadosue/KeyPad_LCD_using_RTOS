/*
 * KeyPad_LCD_RTOS_app.c
 *
 * Created: 1/19/2018 1:32:47 PM
 *  Author: NewUsername
 */ 


#include "FreeRTOS.h"
#include "semphr.h"
#include "stdMacros.h"
#include "task.h"
#include "LCD.h"
#include "KeyPad.h"

 QueueHandle_t myQueue;

 void KeyPad (void *pv);
 void LCD (void *pv);
 

int main(void)
{
	 myQueue = xQueueCreate(4,sizeof(char));
	 xTaskCreate(KeyPad,"debug",100,NULL,1,NULL);
	 xTaskCreate(LCD,"debug",100,NULL,2,NULL);
	 vTaskStartScheduler();	
}

void KeyPad (void *pv)
{
	KeyPad_init();
	while(1)
	{
		uint8_t data=KeyPad_read();
		if(data!=0)
		{
			xQueueSend(myQueue,&data,1000);
		}
		vTaskDelay(300);
	}
	
}

void LCD (void *pv)
{
	lcd_init();
	while(1)
	{
		uint8_t dataRec;
		BaseType_t data=xQueueReceive(myQueue,&dataRec,1000);
		if(data==pdPASS)
		{
			lcd_write_cmd_char(dataRec,1);
		}
		
		else
		{
			
		}
		//vTaskDelay(1000);
	}
}