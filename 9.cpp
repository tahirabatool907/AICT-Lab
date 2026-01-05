#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);

int main()
{
int x=40,y=5,dir=1;
while(true){
system("cls");
gotoxy(x, y);
cout<<"*";
Sleep(100);
y+=dir;
if(y==20||y==5) dir*=-1;
}
}
void gotoxy(int x, int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
