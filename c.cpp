#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <cmath>
using namespace std;

const int width = 20;
const int height = 10;

char maze[height][width + 1] = {
    "###################",
    "#P      #         #",
    "# ####### ####### #",
    "#         #       #",
    "##### ### # ##### #",
    "#     #   #     # #",
    "# ### ##### ### # #",
    "#   #       #   # #",
    "#   #########   E#",
    "###################"
};

int playerX, playerY;
int enemyX, enemyY;
bool gameOver = false;

void setup() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 'P') { playerX = j; playerY = i; }
            if (maze[i][j] == 'E') { enemyX = j; enemyY = i; }
        }
    }
}

void draw() {
    system("cls");
    for (int i = 0; i < height; i++)
        cout << maze[i] << endl;
    cout << "\nUse Arrow Keys to Move | Q to Quit" << endl;
}

void movePlayer(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;
    if (maze[newY][newX] == ' ') {
        maze[playerY][playerX] = ' ';
        playerX = newX;
        playerY = newY;
        maze[playerY][playerX] = 'P';
    }
}

void moveEnemy() {
    int dx = 0, dy = 0;
    if (enemyX < playerX) dx = 1;
    else if (enemyX > playerX) dx = -1;
    if (enemyY < playerY) dy = 1;
    else if (enemyY > playerY) dy = -1;

    int newX = enemyX + dx;
    int newY = enemyY + dy;

    if (maze[newY][newX] == ' ' || maze[newY][newX] == 'P') {
        if (maze[newY][newX] == 'P') {
            system("cls");
            cout << "\n💀 Enemy caught you! Game Over!\n";
            gameOver = true;
            return;
        }
        maze[enemyY][enemyX] = ' ';
        enemyX = newX;
        enemyY = newY;
        maze[enemyY][enemyX] = 'E';
    }
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        if (_kbhit()) {
            char key = _getch();
            if (key == 0 || key == -32) key = _getch();
            if (key == 72) movePlayer(0, -1); // up
            else if (key == 80) movePlayer(0, 1); // down
            else if (key == 75) movePlayer(-1, 0); // left
            else if (key == 77) movePlayer(1, 0); // right
            else if (key == 'q' || key == 'Q') break;
        }
        moveEnemy();
        Sleep(300);
    }

    cout << "\nThanks for playing!\n";
}
