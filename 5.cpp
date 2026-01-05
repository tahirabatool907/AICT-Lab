#include <iostream>
#include <windows.h>
using namespace std;
void printmaze();
void gotoxy(int x, int y);
void movePlayer(int x, int y);

main()
{
system("cls");
printmaze();
int x = 3;
int y = 4;
while(true)
{
gotoxy(x, y);
cout << "P";
x = x + 1;
if(x == 21)
{
x = 4;
}
}
}
void movePlayer(int x, int y)
{
gotoxy(x, y);
cout << "P";
gotoxy(x, y);
cout << "P";

}
void printmaze()
{
cout << "#######################" << endl;
cout << "#                     #" << endl;
cout << "#                     #" << endl;
cout << "#                     #" << endl;
cout << "#                     #" << endl;
cout << "#                     #" << endl;
cout << "#                     #" << endl;
cout << "#                     #" << endl;
cout << "#######################" << endl;
}
void gotoxy(int x, int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
