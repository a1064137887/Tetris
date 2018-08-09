
#include "GameFun.h"
int GameLevel = 0;
void main()
{
	srand(time(NULL));
	system("mode con cols=64 lines=25");
	HideCursor();

	cout << "================================================================\n";
	cout << "                          俄 罗 斯 方 块                            \n";
	cout << "================================================================\n";
	cout << "              a,d控制左右，w控制变形，s加速，空格暂停    \n\n";
	cout << "                          按任意键开始";
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
