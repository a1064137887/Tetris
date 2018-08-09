#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#define MAXROW 20
#define MAXCOL 10
using namespace std;

void PrintUI();

void gotoXY(int goRow, int goCol);

void HideCursor();

void RandomForm();

void PrintRandomSqare();

void AutoSqareMoveDown();

void SqareMoveDown();

void SqareMoveLeft();

void SqareMoveRight();

int SqareStopBottom();

int CanSqareDown();

void StaticSqare();

int CanSqareLeft();

int CanSqareLeft2();

int CanSqareRight();

int CanSqareRight2();

void PlayerKeyCode();

void SqareChange();

int CanSqareChange();

int GameOver();

int CanLongSqareChange();

void DestroySqareLine();

void color(const unsigned short COLor1);

void RandomFutureForm();