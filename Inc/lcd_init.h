#ifndef __LCD_INIT_H
#define __LCD_INIT_H


#include "main.h"

#define USE_HORIZONTAL 1  //���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����


#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 128
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 128
#endif



//-----------------LCD�˿ڶ���---------------- 
#define LCD_RES_Clr() HAL_GPIO_WritePin(LCD_RES_Pin_GPIO_Port, LCD_RES_Pin_Pin, GPIO_PIN_RESET)//RES
#define LCD_RES_Set() HAL_GPIO_WritePin(LCD_RES_Pin_GPIO_Port, LCD_RES_Pin_Pin, GPIO_PIN_SET)

#define LCD_DC_Clr() HAL_GPIO_WritePin(LCD_DC_Pin_GPIO_Port, LCD_DC_Pin_Pin, GPIO_PIN_RESET)//DC
#define LCD_DC_Set() HAL_GPIO_WritePin(LCD_DC_Pin_GPIO_Port, LCD_DC_Pin_Pin, GPIO_PIN_SET)
 		     
#define LCD_CS_Clr()  HAL_GPIO_WritePin(LCD_CS_Pin_GPIO_Port, LCD_CS_Pin_Pin, GPIO_PIN_RESET)///CS
#define LCD_CS_Set()  HAL_GPIO_WritePin(LCD_CS_Pin_GPIO_Port, LCD_CS_Pin_Pin, GPIO_PIN_SET)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(LCD_BLK_Pin_GPIO_Port, LCD_BLK_Pin_Pin, GPIO_PIN_RESET)///BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(LCD_BLK_Pin_GPIO_Port, LCD_BLK_Pin_Pin, GPIO_PIN_SET)

void LCD_GPIO_Init(void);//��ʼ��GPIO
void LCD_Writ_Bus(uint8_t dat);//ģ��SPIʱ��
void LCD_WR_DATA8(uint8_t dat);//д��һ���ֽ�
void LCD_WR_DATA(uint16_t dat);//д�������ֽ�
void LCD_WR_REG(uint8_t dat);//д��һ��ָ��
void LCD_Address_Set(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);//�������꺯��
void LCD_Init(void);//LCD��ʼ��
#endif



