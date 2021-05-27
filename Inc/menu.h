#ifndef __MENU_H
#define __MENU_H			  	 
#include "main.h"
#include "stdlib.h"
#include  "sys.h"
 
typedef struct{
	u8 current_index;	//��ŵ�ǰ����������ţ�
	u8 down_index;		//��Ű��¡�down�����£�����ʱ��Ҫ��ת���������ţ�
	u8 up_index;		//��Ű��¡�up�����ϣ�����ʱ��Ҫ��ת���������ţ�
	u8 enter_index;		//��Ű��¡�enter�����룩����ʱ��Ҫ��ת�������ţ�
	u8 esc_index;		//��Ű��¡�esc���˳�������ʱ��Ҫ��ת�������ţ�
	void (*operate)();	//����ָ���������ŵ�ǰ����������Ҫִ�еĺ�������ڵ�ַ��
}Key_index_struct;
 

 extern Key_index_struct const Key_table[17];

void LCD_display(int i);
void mainWindow(void);

void menu1(void);
void menu2(void);
void menu3(void);
void menu4(void);
 
void subMenu1_1(void);
void subMenu1_2(void);
void subMenu1_3(void);
void subMenu1_4(void);
 
void subMenu2_1(void);
void subMenu2_2(void);
void subMenu2_3(void);
void subMenu2_4(void);
 
void subMenu3_1(void);
void subMenu3_2(void);
void subMenu3_3(void);
void subMenu3_4(void);

#endif
