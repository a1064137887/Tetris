
#include "GameFun.h"
int GameLevel = 0;
void main()
{
	srand(time(NULL));
	system("mode con cols=64 lines=25");
	HideCursor();

	cout << "================================================================\n";
	cout << "                          �� �� ˹ �� ��                            \n";
	cout << "================================================================\n";
	cout << "              a,d�������ң�w���Ʊ��Σ�s���٣��ո���ͣ    \n\n";
	cout << "                          ���������ʼ";
	getch();
	PrintUI();
	while (true)
	{
		if (1 == GameOver())
		{
			RandomForm();
			PrintRandomSqare();
			AutoSqareMoveDown();
			DestroySqareLine();
		}
		else if (0 == GameOver())
		{
			color(15); gotoXY(9, 2); cout << "Gamer Over!!";
			gotoXY(21, 0);
			system("pause");
			break;
		}
	}
}
