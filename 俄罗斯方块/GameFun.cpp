#include "GameFun.h"

extern int sqareType[2][4] = { 0 };//���������״������
extern int sqareFuture[2][4] = { 0 };//���������һ����״������
extern char player = 0;//��������û�����
extern int sqareFormNum = -1;//������¼��ǰ�����״���
extern int sqareRow = -1;//������������ʱ�жϷ�������Ͻ�λ��
extern int sqareCol = -1;//ͬ��
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

extern int Mytime = 0;//���������ٶ�
extern int Myform = -1;//��״����
extern int score = 0;//����
extern int ColorNum = rand()%13+1;//��ɫ����
extern int ColorNum2 = 0;
extern int GameLevel;
int randForm = rand()%7;

//��ӡ��Ϸ����
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
			case 1:cout << "��"; break;
			case 0:cout << "  "; break;
			}
		}
		cout << endl;
	}
}
/*******************************************************************************
Function: void color();��ɫ���ƺ���
Description: �ı������������ı���ɫ
Calls:	#include<windows.h>
Input: const unsigned short COLor1������;0-15�ı�������ɫ������15�ı䣨�������ı���ɫ
Output: ������ı���ɫ�ı�
Return: ��
Others:
������ɫ��Ӧֵ��
0=��ɫ	1=��ɫ	2=��ɫ	3=����ɫ	4=��ɫ	5=��ɫ	6=��ɫ	7=��ɫ	8=��ɫ
9=����ɫ	10=����ɫ	11=��ǳ��ɫ	12=ǳ��ɫ	13=ǳ��ɫ	14=ǳ��ɫ	15=����ɫ
��ɫ��Ӧֵ��
0*16=��ɫ	16*1=��ɫ	16*2=��ɫ	16*3=����ɫ	16*4=��ɫ	16*5=��ɫ
16*6=��ɫ	16*7=��ɫ	16*8=��ɫ	16*9=����ɫ	16*10=����ɫ	16*11=��ǳ��ɫ
16*12=ǳ��ɫ	16*13=ǳ��ɫ	16*14=ǳ��ɫ	16*15=����ɫ
������ɫֵ����ɫ+������ɫ
*******************************************************************************/
/*-------------------------��ɫ���ƺ���begin----------------------------------*/
void color(const unsigned short COLor1)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLor1);
}
//����ƶ�����
void gotoXY(int goRow, int goCol)
{
	COORD pos = { 2 * goCol, goRow };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//���ع��
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
//�����һ����״
void RandomForm()
{
	srand(time(NULL));
	Myform = randForm;//���������״
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
//��������ֵ���״��ӡ,��������ͼֵ
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
				color(ColorNum2); gotoXY(i, j + 3); cout << "��";
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
				gotoXY(5 + i, 15 + j); cout << "��";
			}
		}
	}
	
}
//��������һ��
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
				gotoXY(i + 1, j); cout << "��";
				gotoXY(i, j); cout << "  ";
			}
		}
	}
}
//��������һ��
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
				gotoXY(i, j - 1); cout << "��";
				gotoXY(i, j); cout << "  ";
			}
		}
	}
}
//��������һ��
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
				gotoXY(i, j + 1); cout << "��";
				gotoXY(i, j); cout << "  ";
			}
		}
	}
}
//�������
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
		int SqareTemp[3][3] = { 0 };//���������������״��һ���м�����
		int i, j;
		int STnum = 2;
		for (i = 0; i < 3; i++)//���Ʒ�����״
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
		for (i = 0; i < 3; i++)//����֮��ֵ��map����
		{
			for (j = 0; j < 3; j++)
			{
				map[sqareRow + i][sqareCol + j] = SqareTemp[STnum][i];
				if (2 == map[sqareRow + i][sqareCol + j])
				{
					color(ColorNum2);
					gotoXY(sqareRow + i, sqareCol + j); cout << "��";
				}
				STnum--;
			}
			STnum = 2;
		}
	}break;
	//����״
	case 4:
	{
		if (1 == CanLongSqareChange())
		{
			if (2 == map[sqareRow][sqareCol - 1])//ͼ��Ϊ����
			{
				//�����ȥͼ��
				map[sqareRow][sqareCol - 1] = 0;
				map[sqareRow][sqareCol + 1] = 0;
				map[sqareRow][sqareCol + 2] = 0;
				gotoXY(sqareRow, sqareCol - 1); cout << "  ";
				gotoXY(sqareRow, sqareCol + 1); cout << "  ";
				gotoXY(sqareRow, sqareCol + 2); cout << "  ";
				//���θ�ֵ�����ͼ��
				map[sqareRow - 1][sqareCol] = 2;
				map[sqareRow + 1][sqareCol] = 2;
				map[sqareRow + 2][sqareCol] = 2;
				color(ColorNum2);
				gotoXY(sqareRow - 1, sqareCol); cout << "��";
				gotoXY(sqareRow + 1, sqareCol); cout << "��";
				gotoXY(sqareRow + 2, sqareCol); cout << "��";
			}
			else//ͼ��Ϊ����
			{
				//�����ȥͼ��
				map[sqareRow - 1][sqareCol] = 0;
				map[sqareRow + 1][sqareCol] = 0;
				map[sqareRow + 2][sqareCol] = 0;
				gotoXY(sqareRow - 1, sqareCol); cout << "  ";
				gotoXY(sqareRow + 1, sqareCol); cout << "  ";
				gotoXY(sqareRow + 2, sqareCol); cout << "  ";
				//���θ�ֵ�����ͼ��
				map[sqareRow][sqareCol - 1] = 2;
				map[sqareRow][sqareCol + 1] = 2;
				map[sqareRow][sqareCol + 2] = 2;
				color(ColorNum2);
				gotoXY(sqareRow, sqareCol - 1); cout << "��";
				gotoXY(sqareRow, sqareCol + 1); cout << "��";
				gotoXY(sqareRow, sqareCol + 2); cout << "��";
			}
		}
	}break;
	//�����β��������
	case 5:
		break;
	}
}

//�����ڵ�ͣס    1������   0������
int SqareStopBottom()
{
	for (int i = 0; i < MAXCOL; i++)
	{
		if (2 == map[18][i])
			return 0;
	}
	return 1;
}
//�ж�GameOver    0 GameOver    1����
int GameOver()
{
	for (int i = 0; i < 10; i++)
	{
		if (3 == map[0][i])
			return 0;
	}
	return 1;
}
//�жϷ����ܷ�����   1������   0������
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
//�жϷ����ܷ����ƣ��߽磩   1������   0������
int CanSqareLeft()
{
	for (int i = 0; i < MAXROW; i++)
	{
		if (2 == map[i][1])
			return 0;
	}
	return 1;
}
//�жϷ����ܷ����ƣ��������飩    1������   0������
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
//�жϷ����ܷ����ƣ��߽磩   1������   0������
int CanSqareRight()
{
	for (int i = 0; i < MAXROW; i++)
	{
		if (2 == map[i][8])
			return 0;
	}
	return 1;
}
//�жϷ����ܷ����ƣ��������飩    1������   0������
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
//�жϷ�����ͨ��������״�ܷ����    1���Ա�   0������
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
//�жϳ�����״�ܷ����    1���Ա�    0�����Ա�
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
//���鲻���ƶ�֮��ı�����ֵ   2�ı��3
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
				else{ color(14); gotoXY(i, j); cout << "��"; }
			}
		}
	}
}
//������
void DestroySqareLine()
{
	int i, j, sum = 0, nLine = 0;
	for (i = MAXROW - 1; i >= 0; i--)
	{
		for (j = 1; j < 9; j++)
		{
			sum += map[i][j];
		}
		if (24 == sum)//��������������
		{
			for (nLine = i, j = 1; j < 9; j++)//�����и�ֵ0������
			{
				map[nLine][j] = 0;
				if (2 == GameLevel){ color(0); }
				else{ color(rand() % 13 + 1); } 
				gotoXY(nLine, j); cout << "��";
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
							{ color(14); gotoXY(nLine + 1, j); cout << "��"; }
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
//�����û����룬������Ӧ�����ĺ���
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
		case ' '://��ͣ
		{
			getch();
		}break;
	}
}

//������Ȼ����
void AutoSqareMoveDown()
{
	while (true)
	{
		if (_kbhit())
		{
			PlayerKeyCode();//�����û����룬������Ӧ�����ĺ���
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

