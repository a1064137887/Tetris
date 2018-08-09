#include "GameFun.h"

extern int sqareType[2][4] = { 0 };//用来存放形状的数组
extern int sqareFuture[2][4] = { 0 };//用来存放下一个形状的数组
extern char player = 0;//用来存放用户按键
extern int sqareFormNum = -1;//用来记录当前块的形状编号
extern int sqareRow = -1;//用来辅助变形时判断方块的左上角位置
extern int sqareCol = -1;//同上
extern int map[MAXROW][MAXCOL] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

extern int Mytime = 0;//控制下落速度
extern int Myform = -1;//形状分类
extern int score = 0;//分数
extern int ColorNum = rand()%13+1;//颜色控制
extern int ColorNum2 = 0;
extern int GameLevel;
int randForm = rand()%7;

//打印游戏界面
void PrintUI()
{
	system("cls");
	gotoXY(10, 15); cout << "Score:";
	gotoXY(12, 16); cout << score;
	gotoXY(0, 0);
	for (int i = 0; i < MAXROW; i++)
	{
		for (int j = 0; j < MAXCOL; j++)
		{
			switch (map[i][j])
			{
			case 1:cout << "□"; break;
			case 0:cout << "  "; break;
			}
		}
		cout << endl;
	}
}
/*******************************************************************************
Function: void color();颜色控制函数
Description: 改变输出的字体和文本颜色
Calls:	#include<windows.h>
Input: const unsigned short COLor1正整数;0-15改变字体颜色，大于15改变（背景）文本颜色
Output: 字体和文本颜色改变
Return: 无
Others:
文字颜色对应值：
0=黑色	1=蓝色	2=绿色	3=湖蓝色	4=红色	5=紫色	6=黄色	7=白色	8=灰色
9=淡蓝色	10=淡绿色	11=淡浅绿色	12=浅红色	13=浅紫色	14=浅黄色	15=亮白色
底色对应值：
0*16=黑色	16*1=蓝色	16*2=绿色	16*3=湖蓝色	16*4=红色	16*5=紫色
16*6=黄色	16*7=白色	16*8=灰色	16*9=淡蓝色	16*10=淡绿色	16*11=淡浅绿色
16*12=浅红色	16*13=浅紫色	16*14=浅黄色	16*15=亮白色
最终颜色值：底色+文字颜色
*******************************************************************************/
/*-------------------------颜色控制函数begin----------------------------------*/
void color(const unsigned short COLor1)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLor1);
}
//光标移动函数
void gotoXY(int goRow, int goCol)
{
	COORD pos = { 2 * goCol, goRow };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//隐藏光标
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void RandomFutureForm()
{
	switch (randForm)
	{
	case 0:
	{
		sqareFuture[0][0] = 1; sqareFuture[0][1] = 0; sqareFuture[0][2] = 0; sqareFuture[0][3] = 0;
		sqareFuture[1][0] = 1; sqareFuture[1][1] = 1; sqareFuture[1][2] = 1; sqareFuture[1][3] = 0;
	}break;
	case 1:
	{
		sqareFuture[0][0] = 0; sqareFuture[0][1] = 0; sqareFuture[0][2] = 1; sqareFuture[0][3] = 0;
		sqareFuture[1][0] = 1; sqareFuture[1][1] = 1; sqareFuture[1][2] = 1; sqareFuture[1][3] = 0;
	}break;
	case 2:
	{
		sqareFuture[0][0] = 1; sqareFuture[0][1] = 1; sqareFuture[0][2] = 0; sqareFuture[0][3] = 0;
		sqareFuture[1][0] = 0; sqareFuture[1][1] = 1; sqareFuture[1][2] = 1; sqareFuture[1][3] = 0;
	}break;
	case 3:
	{
		sqareFuture[0][0] = 0; sqareFuture[0][1] = 1; sqareFuture[0][2] = 1; sqareFuture[0][3] = 0;
		sqareFuture[1][0] = 1; sqareFuture[1][1] = 1; sqareFuture[1][2] = 0; sqareFuture[1][3] = 0;
	}break;
	case 4:
	{
		sqareFuture[0][0] = 1; sqareFuture[0][1] = 1; sqareFuture[0][2] = 1; sqareFuture[0][3] = 1;
		sqareFuture[1][0] = 0; sqareFuture[1][1] = 0; sqareFuture[1][2] = 0; sqareFuture[1][3] = 0;
	}break;
	case 5:
	{
		sqareFuture[0][0] = 0; sqareFuture[0][1] = 1; sqareFuture[0][2] = 1; sqareFuture[0][3] = 0;
		sqareFuture[1][0] = 0; sqareFuture[1][1] = 1; sqareFuture[1][2] = 1; sqareFuture[1][3] = 0;
	}break;
	case 6:
	{
		sqareFuture[0][0] = 0; sqareFuture[0][1] = 1; sqareFuture[0][2] = 0; sqareFuture[0][3] = 0;
		sqareFuture[1][0] = 1; sqareFuture[1][1] = 1; sqareFuture[1][2] = 1; sqareFuture[1][3] = 0;
	}break;
	}
}
//随机出一个形状
void RandomForm()
{
	srand(time(NULL));
	Myform = randForm;//随机七种形状
	switch (Myform)
	{
		case 0:
		{
			sqareType[0][0] = 1; sqareType[0][1] = 0; sqareType[0][2] = 0; sqareType[0][3] = 0;
			sqareType[1][0] = 1; sqareType[1][1] = 1; sqareType[1][2] = 1; sqareType[1][3] = 0;
			sqareRow = 0;
			sqareCol = 3;
		}break;
		case 1:
		{
			sqareType[0][0] = 0; sqareType[0][1] = 0; sqareType[0][2] = 1; sqareType[0][3] = 0;
			sqareType[1][0] = 1; sqareType[1][1] = 1; sqareType[1][2] = 1; sqareType[1][3] = 0;
			sqareRow = 0;
			sqareCol = 3;
		}break;
		case 2:
		{
			sqareType[0][0] = 1; sqareType[0][1] = 1; sqareType[0][2] = 0; sqareType[0][3] = 0;
			sqareType[1][0] = 0; sqareType[1][1] = 1; sqareType[1][2] = 1; sqareType[1][3] = 0;
			sqareRow = 0;
			sqareCol = 3;
		}break;
		case 3:
		{
			sqareType[0][0] = 0; sqareType[0][1] = 1; sqareType[0][2] = 1; sqareType[0][3] = 0;
			sqareType[1][0] = 1; sqareType[1][1] = 1; sqareType[1][2] = 0; sqareType[1][3] = 0;
			sqareRow = 0;
			sqareCol = 3;
		}break;
		case 4:
		{
			sqareType[0][0] = 1; sqareType[0][1] = 1; sqareType[0][2] = 1; sqareType[0][3] = 1;
			sqareType[1][0] = 0; sqareType[1][1] = 0; sqareType[1][2] = 0; sqareType[1][3] = 0;
			sqareRow = 0;
			sqareCol = 4;
		}break;
		case 5:
		{
			sqareType[0][0] = 0; sqareType[0][1] = 1; sqareType[0][2] = 1; sqareType[0][3] = 0;
			sqareType[1][0] = 0; sqareType[1][1] = 1; sqareType[1][2] = 1; sqareType[1][3] = 0;
		}break;
		case 6:
		{
			sqareType[0][0] = 0; sqareType[0][1] = 1; sqareType[0][2] = 0; sqareType[0][3] = 0;
			sqareType[1][0] = 1; sqareType[1][1] = 1; sqareType[1][2] = 1; sqareType[1][3] = 0;
			sqareRow = 0;
			sqareCol = 3;
		}break;
	}
	sqareFormNum = Myform;
	randForm = rand() % 7;
	RandomFutureForm();
}
//将随机出现的形状打印,并赋给地图值
void PrintRandomSqare()
{
	ColorNum2 = ColorNum;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sqareType[i][j] == 1)
			{
				map[i][j + 3] = 2;
				color(ColorNum2); gotoXY(i, j + 3); cout << "■";
			}
		}
	}
	
	ColorNum = rand() % 13 + 1;
	gotoXY(5, 15);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			gotoXY(5 + i, 15 + j); cout << "  ";
		}
	}
	gotoXY(5, 15);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (sqareFuture[i][j] == 1)
			{
				color(ColorNum);
				gotoXY(5 + i, 15 + j); cout << "■";
			}
		}
	}
	
}
//方块下落一行
void SqareMoveDown()
{
	int i, j;
	for (i = MAXROW - 1; i >= 0; i--)
	{
		for (j = 0; j < MAXCOL; j++)
		{
			if (2 == map[i][j])
			{
				map[i + 1][j] = map[i][j];
				map[i][j] = 0;
				color(ColorNum2);
				gotoXY(i + 1, j); cout << "■";
				gotoXY(i, j); cout << "  ";
			}
		}
	}
}
//方块左移一格
void SqareMoveLeft()
{
	int i, j;
	for (i = MAXROW - 1; i >= 0; i--)
	{
		for (j = 0; j < MAXCOL; j++)
		{
			if (2 == map[i][j])
			{
				map[i][j - 1] = map[i][j];
				map[i][j] = 0;
				color(ColorNum2);
				gotoXY(i, j - 1); cout << "■";
				gotoXY(i, j); cout << "  ";
			}
		}
	}
}
//方块右移一格
void SqareMoveRight()
{
	int i, j;
	for (i = MAXROW - 1; i >= 0; i--)
	{
		for (j = MAXCOL - 1; j > 0; j--)
		{
			if (2 == map[i][j])
			{
				map[i][j + 1] = map[i][j];
				map[i][j] = 0;
				color(ColorNum2);
				gotoXY(i, j + 1); cout << "■";
				gotoXY(i, j); cout << "  ";
			}
		}
	}
}
//方块变形
void SqareChange()
{
	switch (sqareFormNum)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 6:
	{
		int SqareTemp[3][3] = { 0 };//用来存放上五种形状的一个中间数组
		int i, j;
		int STnum = 2;
		for (i = 0; i < 3; i++)//复制方块形状
		{
			for (j = 0; j < 3; j++)
			{
				SqareTemp[i][j] = map[sqareRow + i][sqareCol + j];
				if (2 == map[sqareRow + i][sqareCol + j])
				{
					gotoXY(sqareRow + i, sqareCol + j); cout << "  ";
				}
				map[sqareRow + i][sqareCol + j] = 0;
			}
		}
		for (i = 0; i < 3; i++)//变形之后赋值回map数组
		{
			for (j = 0; j < 3; j++)
			{
				map[sqareRow + i][sqareCol + j] = SqareTemp[STnum][i];
				if (2 == map[sqareRow + i][sqareCol + j])
				{
					color(ColorNum2);
					gotoXY(sqareRow + i, sqareCol + j); cout << "■";
				}
				STnum--;
			}
			STnum = 2;
		}
	}break;
	//长条状
	case 4:
	{
		if (1 == CanLongSqareChange())
		{
			if (2 == map[sqareRow][sqareCol - 1])//图形为竖着
			{
				//清零擦去图形
				map[sqareRow][sqareCol - 1] = 0;
				map[sqareRow][sqareCol + 1] = 0;
				map[sqareRow][sqareCol + 2] = 0;
				gotoXY(sqareRow, sqareCol - 1); cout << "  ";
				gotoXY(sqareRow, sqareCol + 1); cout << "  ";
				gotoXY(sqareRow, sqareCol + 2); cout << "  ";
				//变形赋值，输出图形
				map[sqareRow - 1][sqareCol] = 2;
				map[sqareRow + 1][sqareCol] = 2;
				map[sqareRow + 2][sqareCol] = 2;
				color(ColorNum2);
				gotoXY(sqareRow - 1, sqareCol); cout << "■";
				gotoXY(sqareRow + 1, sqareCol); cout << "■";
				gotoXY(sqareRow + 2, sqareCol); cout << "■";
			}
			else//图形为横着
			{
				//清零擦去图形
				map[sqareRow - 1][sqareCol] = 0;
				map[sqareRow + 1][sqareCol] = 0;
				map[sqareRow + 2][sqareCol] = 0;
				gotoXY(sqareRow - 1, sqareCol); cout << "  ";
				gotoXY(sqareRow + 1, sqareCol); cout << "  ";
				gotoXY(sqareRow + 2, sqareCol); cout << "  ";
				//变形赋值，输出图形
				map[sqareRow][sqareCol - 1] = 2;
				map[sqareRow][sqareCol + 1] = 2;
				map[sqareRow][sqareCol + 2] = 2;
				color(ColorNum2);
				gotoXY(sqareRow, sqareCol - 1); cout << "■";
				gotoXY(sqareRow, sqareCol + 1); cout << "■";
				gotoXY(sqareRow, sqareCol + 2); cout << "■";
			}
		}
	}break;
	//正方形不参与变形
	case 5:
		break;
	}
}

//方块在底停住    1可以落   0不可以
int SqareStopBottom()
{
	for (int i = 0; i < MAXCOL; i++)
	{
		if (2 == map[18][i])
			return 0;
	}
	return 1;
}
//判断GameOver    0 GameOver    1继续
int GameOver()
{
	for (int i = 0; i < 10; i++)
	{
		if (3 == map[0][i])
			return 0;
	}
	return 1;
}
//判断方块能否下落   1可以落   0不可以
int CanSqareDown()
{
	int i, j;
	for (i = MAXROW - 1; i >= 0; i--)
	{
		for (j = 0; j < MAXCOL; j++)
		{
			if (2 == map[i][j])
			{
				if (3 == map[i + 1][j])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
//判断方块能否左移（边界）   1可以移   0不可以
int CanSqareLeft()
{
	for (int i = 0; i < MAXROW; i++)
	{
		if (2 == map[i][1])
			return 0;
	}
	return 1;
}
//判断方块能否左移（与其他块）    1可以移   0不可以
int CanSqareLeft2()
{
	int i, j;
	for (i = 0; i < MAXROW; i++)
	{
		for (j = 0; j < MAXCOL; j++)
		{
			if (2 == map[i][j])
			{
				if (3 == map[i][j - 1])
					return 0;
			}
		}
	}
	return 1;
}
//判断方块能否右移（边界）   1可以移   0不可以
int CanSqareRight()
{
	for (int i = 0; i < MAXROW; i++)
	{
		if (2 == map[i][8])
			return 0;
	}
	return 1;
}
//判断方块能否右移（与其他块）    1可以移   0不可以
int CanSqareRight2()
{
	int i, j;
	for (i = 0; i < MAXROW; i++)
	{
		for (j = 8; j > 0; j--)
		{
			if (2 == map[i][j])
			{
				if (3 == map[i][j + 1])
					return 0;
			}
		}
	}
	return 1;
}
//判断方块普通的五种形状能否变形    1可以变   0不可以
int CanSqareChange()
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (3 == map[sqareRow + i][sqareCol + j] || 1 == map[sqareRow + i][sqareCol + j])
				return 0;
		}
	}
	return 1;
}
//判断长条形状能否变形    1可以变    0不可以变
int CanLongSqareChange()
{
	int i, j;
	for (i = -1; i < 3; i++)
	{
		for (j = -1; j < 3; j++)
		{
			if (3 == map[sqareRow + i][sqareCol + j] || 1 == map[sqareRow + i][sqareCol + j] || 2== map[0][sqareCol+j])
				return 0;
		}
	}
	return 1;
}
//方块不能移动之后改变数组值   2改变成3
void StaticSqare()
{
	for (int i = MAXROW - 1; i >= 0; i--)
	{
		for (int j = 0; j < MAXCOL; j++)
		{
			if (2 == map[i][j])
			{
				map[i][j] = 3;
				if (2 == GameLevel){ gotoXY(i, j); cout << "  "; }
				else{ color(14); gotoXY(i, j); cout << "■"; }
			}
		}
	}
}
//消除行
void DestroySqareLine()
{
	int i, j, sum = 0, nLine = 0;
	for (i = MAXROW - 1; i >= 0; i--)
	{
		for (j = 1; j < 9; j++)
		{
			sum += map[i][j];
		}
		if (24 == sum)//满足条件消除行
		{
			for (nLine = i, j = 1; j < 9; j++)//把满行赋值0并擦除
			{
				map[nLine][j] = 0;
				if (2 == GameLevel){ color(0); }
				else{ color(rand() % 13 + 1); } 
				gotoXY(nLine, j); cout << "※";
				_sleep(20);
			}
			for (nLine = i - 1; nLine >= 0; nLine--)
			{
				for (j = 1; j < 9; j++)
				{
					map[nLine + 1][j] = map[nLine][j];
					switch (map[nLine + 1][j])
					{
						case 0:gotoXY(nLine + 1, j); cout << "  "; break;
						case 3:
						{
							if (2 == GameLevel)
							{gotoXY(nLine + 1, j); cout << "  ";}
							else 
							{ color(14); gotoXY(nLine + 1, j); cout << "■"; }
						} break;
					}
				}
			}
			score += 10;
			color(15); gotoXY(12, 16); cout << score;
			i = MAXROW;
		}
		sum = 0;
	}
}
//接收用户输入，做出相应动作的函数
void PlayerKeyCode()
{
	player = getch();
	switch (player)
	{
		case 'a':
		case 'A':
		{
			if (1 == CanSqareLeft() && 1 == CanSqareLeft2())
			{
				SqareMoveLeft();
				sqareCol--;
			}
		}break;
		case 'd':
		case 'D':
		{
			if (1 == CanSqareRight() && 1 == CanSqareRight2())
			{
				SqareMoveRight();
				sqareCol++;
			}
		}break;
		case 'w':
		case 'W':
		{
			if (1 == CanSqareChange())
			{
				SqareChange();
			}
		}break;
		case 's':
		case 'S':
		{
			Mytime = 500;
		}break;
		case ' '://暂停
		{
			getch();
		}break;
	}
}

//方块自然下落
void AutoSqareMoveDown()
{
	while (true)
	{
		if (_kbhit())
		{
			PlayerKeyCode();//接收用户输入，做出相应动作的函数
		}
		Mytime++;
		if (1 == SqareStopBottom() && 1 == CanSqareDown())
		{
			if (Mytime >= 30)
			{
				SqareMoveDown();
				sqareRow++;
				Mytime = 0;
			}
		}
		else if (0 == SqareStopBottom() || 0 == CanSqareDown())
		{
			StaticSqare();
			break;
		}
		_sleep(10);
	}
}

