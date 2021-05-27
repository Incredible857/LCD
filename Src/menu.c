#include "main.h"
#include "lcd.h"
#include "lcd_init.h"
#include "menu.h"


u8 nowIndex = 0;

Key_index_struct const Key_table[17]=
{
	
    {0, 0, 0, 1, 0,(*mainWindow)},//一级界面
	{1, 2, 4, 5, 0,(*menu1)},//二级界面第一行
	{2, 3, 1, 9, 0,(*menu2)},//二级界面第二行
	{3, 4, 2, 13, 0,(*menu3)},//二级界面第三行
	{4, 1, 3, 0, 0,(*menu4)},//退出
	
	{5, 6, 8, 5, 0,(*subMenu1_1)},//三级界面,menu1选中第1行
	{6, 7, 5, 6, 0,(*subMenu1_2)},//menu1三级界面第2行
	{7, 8, 6, 7, 0,(*subMenu1_3)},//menu1三级界面第3行
	{8, 5, 7, 1, 0,(*subMenu1_4)},//menu1三级界面第4行
	
	{9 , 10, 12,  9, 0,(*subMenu2_1)},//menu2三级界面第1行
	{10, 11,  9, 10, 0,(*subMenu2_2)},//menu2三级界面第2行
	{11, 12, 10, 11, 0,(*subMenu2_3)},//menu2三级界面第3行
	{12,  9, 11, 2, 0,(*subMenu2_4)},//menu2三级界面第4行
	
	{13, 14, 16, 13, 0,(*subMenu3_1)},//menu3三级界面第1行
	{14, 15, 13, 14, 0,(*subMenu3_2)},//menu3三级界面第2行
	{15, 16, 14, 15, 0,(*subMenu3_3)},//menu3三级界面第3行
	{16, 13, 15, 3, 0,(*subMenu3_4)},//menu3三级界面第4行
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
	//OLED_Refresh_Gram();//刷新显存

}


void mainWindow(void)
{
	LCD_ShowString(35,2,(u8 *)"LSY",BLACK,YELLOW,32,1);//主界面
	LCD_ShowString(20,60,(u8 *)"menu display",BLACK,YELLOW,16,1);//主界面
}




void menu1(void)
{
	LCD_ShowString(2,0, (u8 *)"menu1       ",BLACK,YELLOW,16,0);//以空格填充，不要用Tab填充，反白显示
	LCD_ShowString(2,16,(u8 *)"menu2       ",BLACK,YELLOW,16,1);//正常显示
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


//=======================子菜单1==========================
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


//======================子菜单2===========================
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


//======================子菜单3===========================
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

