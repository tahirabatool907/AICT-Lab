#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y);

int main()
{
system("cls");
int y = 5;
string name = "HASSAN";
for(int i = 0;i<name.length();i++){
gotoxy(10,y++);
cout<<name[i];
Sleep(200);
}
}
void gotoxy(int x, int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
