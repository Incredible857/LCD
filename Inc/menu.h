#ifndef __MENU_H
#define __MENU_H			  	 
#include "main.h"
#include "stdlib.h"
#include  "sys.h"
 
typedef struct{
	u8 current_index;	//存放当前界面的索引号；
	u8 down_index;		//存放按下“down（向下）”键时需要跳转到的索引号；
	u8 up_index;		//存放按下“up（向上）”键时需要跳转到的索引号；
	u8 enter_index;		//存放按下“enter（进入）”键时需要跳转的索引号；
	u8 esc_index;		//存放按下“esc（退出）”键时需要跳转的索引号；
	void (*operate)();	//函数指针变量，存放当前索引号下需要执行的函数的入口地址。
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
