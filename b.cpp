#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
using namespace std;

const char PLAYER = '@';
const char ENEMY = 'E';
const char WALL = '#';
const char EMPTY = ' ';

vector<string> maze = {
    "#############################",
    "#@    #       #      #     #",
    "# ### # ##### # #### # ### #",
    "# #   #     # #    # #   # #",
    "# # ##### # # #### # ### # #",
    "# #     # # #    # #   # # #",
    "# ##### # # #### # ### # # #",
    "#     # # # #    #     #   #",
    "##### # # # # ########### ##",
    "#     #   #   #           #E",
    "#############################"
};

int rows = maze.size();
int cols = maze[0].size();

struct Entity {
    int x, y;
    int dx, dy;
    char symbol;
};

Entity player;
vector<Entity> enemies;
bool gameOver = false;
int score = 0;

// Function to locate player and enemies
void initGame() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == PLAYER) {
                player = {j, i, 0, 0, PLAYER};
                maze[i][j] = EMPTY;
            } else if (maze[i][j] == ENEMY) {
                Entity e = {j, i, 1, 0, ENEMY}; // default enemy moves horizontally
                enemies.push_back(e);
                maze[i][j] = EMPTY;
            }
        }
    }

    // Add extra enemies (different patterns)
    enemies.push_back({5, 8, 0, 1, ENEMY});   // vertical enemy
    enemies.push_back({15, 4, 1, 1, ENEMY});  // diagonal enemy
}

// Draw the maze
void drawMaze() {
    system("cls");
    vector<string> screen = maze;
    screen[player.y][player.x] = PLAYER;
    for (auto &e : enemies)
        screen[e.y][e.x] = ENEMY;

    for (auto &line : screen)
        cout << line << endl;

    cout << "\nUse Arrow Keys to Move | Q to Quit\n";
    cout << "Score: " << score << endl;
}

// Check if cell is walkable
bool isWalkable(int x, int y) {
    return (maze[y][x] != WALL);
}

// Player movement
void movePlayer() {
    if (_kbhit()) {
        int key = _getch();
        if (key == 0 || key == 224) {
            key = _getch();
            int nx = player.x;
            int ny = player.y;
            switch (key) {
                case 72: ny--; break; // Up
                case 80: ny++; break; // Down
                case 75: nx--; break; // Left
                case 77: nx++; break; // Right
            }
            if (isWalkable(nx, ny)) {
                player.x = nx;
                player.y = ny;
                score++;
            }
        } else if (key == 'q' || key == 'Q') {
            gameOver = true;
        }
    }
}

// Enemy movement logic
void moveEnemies() {
    for (auto &e : enemies) {
        int nx = e.x + e.dx;
        int ny = e.y + e.dy;

        // if enemy hits wall, reverse direction
        if (!isWalkable(nx, ny)) {
            if (e.dy == 0 && e.dx != 0) e.dx = -e.dx; // horizontal
            else if (e.dx == 0 && e.dy != 0) e.dy = -e.dy; // vertical
            else { e.dx = -e.dx; e.dy = -e.dy; } // diagonal
            nx = e.x + e.dx;
            ny = e.y + e.dy;
        }

        if (isWalkable(nx, ny)) {
            e.x = nx;
            e.y = ny;
        }
    }
}

// Check collision
void checkCollision() {
    for (auto &e : enemies) {
        if (player.x == e.x && player.y == e.y) {
            gameOver = true;
            cout << "\n💥 You were caught by an enemy! GAME OVER 💥\n";
            break;
        }
    }
}

// Main game loop
void gameLoop() {
    while (!gameOver) {
        drawMaze();
        movePlayer();
        moveEnemies();
        checkCollision();
        Sleep(150); // control speed
    }
}

int main() {
    cout << "==============================\n";
    cout << "     2D MAZE GAME - TASK 03   \n";
    cout << "==============================\n";
    cout << "Controls:\n";
    cout << "👉 Arrow Keys = Move Player (@)\n";
    cout << "👉 Avoid Enemies (E)\n";
    cout << "👉 Walls (#) = Boundaries\n";
    cout << "👉 Press Q to Quit\n\n";
    cout << "Press any key to Start...";
    _getch();

    initGame();
    gameLoop();

    cout << "\nFinal Score: " << score << endl;
    cout << "Thanks for playing!\n";
}
