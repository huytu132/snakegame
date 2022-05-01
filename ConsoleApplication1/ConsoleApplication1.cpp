#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, FruitX, FruitY, score;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    FruitX = rand() % width;
    FruitY = rand() % height;
    score = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < width+1; i++)cout << "#";
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j==width-1)cout << "#";
            if (i == y && j == x)cout << "O";
            else if (i == FruitY && j == FruitX)cout << "F";
            else cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < width+1; i++)cout << "#";
    cout << endl;
    cout << score << endl;
}

void Input() {
    while (_kbhit()) {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'w':
            dir = UP;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
            system("pause");
        }
    }
}

void Logic() {
    switch (dir) {
    case UP:
        y--;
        break;
    case RIGHT:
        x++;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    default:
        break;
    }
    if (y > width  || y < 0 || x < 0 || x > height) {
        gameOver = true;
        cout << "\nChoi ngu\n";
    }
    if (x == FruitX && y == FruitY) {
        score++;
        FruitX = rand() % width;
        FruitY = rand() % height;
    }
}

int main()
{
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
    }
    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
