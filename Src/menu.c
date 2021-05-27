#include "main.h"
#include "lcd.h"
#include "lcd_init.h"
#include "menu.h"


u8 nowIndex = 0;

Key_index_struct const Key_table[17]=
{
	
    {0, 0, 0, 1, 0,(*mainWindow)},//һ������
	{1, 2, 4, 5, 0,(*menu1)},//���������һ��
	{2, 3, 1, 9, 0,(*menu2)},//��������ڶ���
	{3, 4, 2, 13, 0,(*menu3)},//�������������
	{4, 1, 3, 0, 0,(*menu4)},//�˳�
	
	{5, 6, 8, 5, 0,(*subMenu1_1)},//��������,menu1ѡ�е�1��
	{6, 7, 5, 6, 0,(*subMenu1_2)},//menu1���������2��
	{7, 8, 6, 7, 0,(*subMenu1_3)},//menu1���������3��
	{8, 5, 7, 1, 0,(*subMenu1_4)},//menu1���������4��
	
	{9 , 10, 12,  9, 0,(*subMenu2_1)},//menu2���������1��
	{10, 11,  9, 10, 0,(*subMenu2_2)},//menu2���������2��
	{11, 12, 10, 11, 0,(*subMenu2_3)},//menu2���������3��
	{12,  9, 11, 2, 0,(*subMenu2_4)},//menu2���������4��
	
	{13, 14, 16, 13, 0,(*subMenu3_1)},//menu3���������1��
	{14, 15, 13, 14, 0,(*subMenu3_2)},//menu3���������2��
	{15, 16, 14, 15, 0,(*subMenu3_3)},//menu3���������3��
	{16, 13, 15, 3, 0,(*subMenu3_4)},//menu3���������4��
};



void LCD_display(int i){
	switch(i)
	{
		case 0: //down
			nowIndex=Key_table[nowIndex].down_index;
		    LCD_Fill(0,0,128,160,WHITE);
		break;
		case 1: // up
			nowIndex=Key_table[nowIndex].up_index;
		    LCD_Fill(0,0,128,160,WHITE);
		break;
		case 2:// Enter
			nowIndex=Key_table[nowIndex].enter_index;
		    LCD_Fill(0,0,128,160,WHITE);
		break;
		case 3:// Esc
			nowIndex=Key_table[nowIndex].esc_index;
		    LCD_Fill(0,0,128,160,WHITE);
		break;
		
			
	}
	
	
	Key_table[nowIndex].operate();
	//OLED_Refresh_Gram();//ˢ���Դ�

}


void mainWindow(void)
{
	LCD_ShowString(35,2,(u8 *)"LSY",BLACK,YELLOW,32,1);//������
	LCD_ShowString(20,60,(u8 *)"menu display",BLACK,YELLOW,16,1);//������
}




void menu1(void)
{
	LCD_ShowString(2,0, (u8 *)"menu1       ",BLACK,YELLOW,16,0);//�Կո���䣬��Ҫ��Tab��䣬������ʾ
	LCD_ShowString(2,16,(u8 *)"menu2       ",BLACK,YELLOW,16,1);//������ʾ
	LCD_ShowString(2,32,(u8 *)"menu3       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void menu2(void)
{
	LCD_ShowString(2,0, (u8 *)"menu1       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"menu2       ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,32,(u8 *)"menu3       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void menu3(void)
{
	LCD_ShowString(2,0, (u8 *)"menu1       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"menu2       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"menu3       ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void menu4(void)
{
	LCD_ShowString(2,0, (u8 *)"menu1       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"menu2       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"menu3       ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,0);
}


//=======================�Ӳ˵�1==========================
void subMenu1_1(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu1_1  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,16,(u8 *)"subMenu1_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu1_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu1_2(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu1_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu1_2  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,32,(u8 *)"subMenu1_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu1_3(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu1_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu1_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu1_3  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu1_4(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu1_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu1_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu1_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,0);
}


//======================�Ӳ˵�2===========================
void subMenu2_1(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu2_1  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,16,(u8 *)"subMenu2_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu2_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu2_2(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu2_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu2_2  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,32,(u8 *)"subMenu2_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu2_3(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu2_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu2_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu2_3  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu2_4(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu2_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu2_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu2_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,0);
}


//======================�Ӳ˵�3===========================
void subMenu3_1(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu3_1  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,16,(u8 *)"subMenu3_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu3_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu3_2(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu3_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu3_2  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,32,(u8 *)"subMenu3_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu3_3(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu3_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu3_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu3_3  ",BLACK,YELLOW,16,0);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,1);
}
void subMenu3_4(void)
{
	LCD_ShowString(2,0, (u8 *)"subMenu3_1  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,16,(u8 *)"subMenu3_2  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,32,(u8 *)"subMenu3_3  ",BLACK,YELLOW,16,1);
	LCD_ShowString(2,48,(u8 *)"exit        ",BLACK,YELLOW,16,0);

}

