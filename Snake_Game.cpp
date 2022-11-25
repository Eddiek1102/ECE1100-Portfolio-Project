#include <iostream> 
#include <conio.h> 
#include <windows.h> 

using std::cout; 
using std::cin; 
using std::endl; 

bool game_Over; 

const int width{30};
const int height{20};

int x{};
int y{}; 

int fruit_x{};
int fruit_y{}; 

int score{}; 

int tail_x[100], tail_y[100]; 
int nTail; 

enum direction {STOP = 0, LEFT, RIGHT, UP, DOWN}; 
direction dir; 

void setup(){
    game_Over = false; 
    dir = STOP; 
    x = width / 2; 
    y = height / 2; 

    fruit_x = rand() % width; 
    fruit_y = rand() % height; 

    score = 0; 
}

void draw(){
     system("cls"); //system("clear");
    for (int i = 0; i < width+2; i++)
        cout << "-";
    cout << endl;
 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "|";
            if (i == y && j == x)
                cout << "E";
            else if (i == fruit_y && j == fruit_x)
                cout << "f";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tail_x[k] == j && tail_y[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
                 
 
            if (j == width - 1)
                cout << "|";
        }
        cout << endl;
    }
 
    for (int i = 0; i < width+2; i++)
        cout << "-";
    cout << endl;
    cout << "Score:" << score << endl;
}

void input(){
    if (_kbhit()){
        switch (_getch()){
            case('w'):
            dir = UP; 
            break;

            case('s'): 
            dir = DOWN; 
            break; 

            case('a'): 
            dir = LEFT; 
            break; 

            case('d'): 
            dir = RIGHT; 
            break;

            case ('x'):
            game_Over = true; 
            break; 
        }
    }
}

void game_logic(){
    int prev_x = tail_x[0]; 
    int prev_y = tail_y[0]; 

    int prev_2x{};
    int prev_2y{}; 

    tail_x[0] = x; 
    tail_y[0] = y; 

    for (int i = 1; i < nTail; i++){
        prev_2x = tail_x[i]; 
        prev_2y = tail_y[i]; 
        tail_x[i] = prev_x; 
        tail_y[i] = prev_y;

        prev_x = prev_2x; 
        prev_y = prev_2y; 
    }
    switch (dir){
        case UP: 
        y--; 
        break; 

        case DOWN: 
        y++; 
        break; 

        case RIGHT: 
        x++; 
        break; 

        case LEFT: 
        x--; 
        break; 

        default: 
        break; 
    }

    if (x >= width){
        x = 0; 
    }
    else if (x < 0) {
        x = width - 1; 
    }

    if (y >= height){
        y = 0; 
    }
    else if (y < 0){
        y = height - 1; 
    }

    for (int i = 0; i < nTail; i++){
        if ((tail_x[i] == x) && (tail_y[i] == y)){
            game_Over = true; 
        }
    }

    if ((x == fruit_x) && (y == fruit_y)){
        score += 10; 
        fruit_x = rand() % width; 
        fruit_y = rand() % height; 
        nTail++; 
    }
}

int main(){
    setup(); 
    draw();
    while (!game_Over){
        draw();
        input(); 
        game_logic();
        Sleep(10);
    }
    return 0; 
}