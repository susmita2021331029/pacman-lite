#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#define row 20
#define column 50

using namespace std;
int point = -5;
int health = 220;
bool game_end = false;

int p1x = rand() % row;
int p1y = rand() % column;
int p2x = rand() % row;
int p2y = rand() % column;
int e1x = rand() % row;
int e1y = rand() % column;
int e2x = rand() % row;
int e2y = rand() % column;
int e3x = rand() % row;
int e3y = rand() % column;
int e4x = rand() % row;
int e4y = rand() % column;
int e5x = rand() % row;
int e5y = rand() % column;
int e6x = rand() % row;
int e6y = rand() % column;

void textcolor (int iColor)
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
/*
       0- black
        1- blue
        2- green
        3- cyan
        4- red
        5- purple
        6- yellow
        7- white
        8- gray
        9- light blue
*/
}

void playfield(char grid[row][column]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if ((i & 1) && (j & 1))
            {
                textcolor(2); // Green color for '.'
                grid[i][j] = '.';
            }
            else if (i == row / 2 && (j & 1))
            {
                textcolor(2); // Green color for '.'
                grid[i][j] = '.';
            }
            else if ((i & 1) && (j == column / 2))
            {
                textcolor(2); // Green color for '.'
                grid[i][j] = '.';
            }
            else if (i == j || i == j / 3 || i == j / 10 || j == i / 10)
            {
                textcolor(3); // Cyan color for '*'
                grid[i][j] = '*';
            }
            else if (i == row / 2 || j == column / 2 || i == 0 || i == row - 1 || j == 0 || j == column - 1)
            {
                textcolor(3); // Cyan color for '*'
                grid[i][j] = '*';
            }
            else if (i == 2 && j == 13)
            {
                textcolor(4); // Red color for 'M'
                grid[i][j] = 'M';
            }
            else if (i == 8 && j == 45)
            {
                textcolor(4); // Red color for 'M'
                grid[i][j] = 'M';
            }
            else if (i == 17 && j == 29)
            {
                textcolor(4); // Red color for 'M'
                grid[i][j] = 'M';
            }
            else if (i == 12 && j == 21)
            {
                textcolor(4); // Red color for 'M'
                grid[i][j] = 'M';
            }
            else
            {
                textcolor(2); // Green color for '.'
                grid[i][j] = '.';
            }
        }
    }
}

void display(char grid[row][column]) {
    cout << "\n\n\n";
    for (int i = 0; i < row; i++) {
        cout << "\t\t\t\t\t\t";
        for (int j = 0; j < column; j++) {
            switch (grid[i][j]) {
                case 'M':
                    textcolor(4); // Red color for 'M'
                    break;

                case '*':
                    textcolor(3); // Cyan color for '*'
                    break;

                case 'E':
                    textcolor (6);
                    break;


                    case '@':
                    textcolor (5);
                    break;

                    case '&':
                    textcolor (5);
                    break;

                default:
                    textcolor(2); // Green color for other characters
                    break;
            }
            cout << grid[i][j];
        }
        cout << "\n";
    }
     cout << "\n";

    cout << " \t \t\t\t\t\t\t Your  health is:   " << health << "\n";
    cout << " \t \t\t\t\t\t\t Your  score is:   " << point << "\n";
}















int flag;

void input(){


	if(kbhit()){
		switch(getch()){
			case 'a':
				flag=1;
				break;

			case 's':
				flag=2;
				break;
			case 'w':
				flag=3;
				break;

			case 'd':
				flag=4;
				break;

		}
	}
}
void setup(char grid[row][column]) {
    // Clear previous player and enemy positions
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (grid[i][j] == '@' ) grid[i][j] = ' ';
            if (grid[i][j] == '$' ) grid[i][j] = ' ';
            if (grid[i][j] == 'E' ) grid[i][j] = '.';
        }
    }
     	switch(flag){

		case 1:
				p1y--;
				p2y++;
				break;

			case 2:
				p1x++;
				p2x--;
				break;
			case 3:
				p1x--;
				p2x++;
				break;

			case 4:
				p1y++;
				p2y--;
				break;

			default:
				break;

	}

    // Check if player 1 consumes a dot
    if (grid[p1x][p1y] == '.') {
        point += 5;
        grid[p1x][p1y] = ' ';  // Remove the consumed dot
    }

    // Check if player 2 consumes a dot
    if (grid[p2x][p2y] == '.') {
        point += 5;
        grid[p2x][p2y] = ' ';  // Remove the consumed dot
    }

    // Check if player 1 or player 2 reaches 'M'
    if (grid[p1x][p1y] == 'M' || grid[p2x][p2y] == 'M') {
        health += 40;
        if (health > 200) health = 200;
    }

    // Check if player 1 or player 2 hits an obstacle
    if (grid[p1x][p1y] == '*' || grid[p2x][p2y] == '*') health -= 20;

     //check for health
     if (health<=0) game_end=true;
    // Check for game end conditions
    //p1 ,p2
        if (abs(p1x-p2x)<=1 && abs(p1y -p2y)<=1   )
         {
          game_end = true;
         }
         //p1,e1
        if (abs(p1x-e1x)<=1 && abs (p1y-e1y)<=1)
         {

             game_end=true;
         }
         //p1,e2
           if (abs(p1x-e2x)<=1 && abs(p1y -e2y)<=1   )
           {
             game_end = true;
           }
         //p1,e3
                 if (abs(p1x-e3x)<=1 && abs(p1y -e3y)<=1   )
         {
          game_end = true;
         }
         //p1,e4
           if (abs(p1x-e4x)<=1 && abs(p1y -e4y)<=1   )
         {
          game_end = true;
         }
         //p1,e5
        if (abs(p1x-e5x)<=1 && abs(p1y -e5y)<=1   )
         {
          game_end = true;
         }
         //p1,e6
           if (abs(p1x-e6x)<=1 && abs(p1y -e6y)<=1   )
         {
          game_end = true;
         }
         //p2,e1
                if (abs(p2x-e1x)<=1 && abs(p2y -e1y)<=1   )
         {
          game_end = true;
         }
         //p2,e2
           if (abs(p2x-e2x)<=1 && abs(p2y -e2y)<=1   )
         {
          game_end = true;
         }
         //p2,e3
                 if (abs(p2x-e3x)<=1 && abs(p2y -e3y)<=1   )
         {
          game_end = true;
         }
         //p2,e4
           if (abs(p2x-e4x)<=1 && abs(p2y -e4y)<=1   )
         {
          game_end = true;
         }
         //p2,e5
                 if (abs(p2x-e5x)<=1 && abs(p2y -e5y)<=1   )
         {
          game_end = true;
         }
         //p2,e6
           if (abs(p2x-e6x)<=1 && abs(p2y -e6y)<=1   )
         {
          game_end = true;
         }





    // Update player positions on the grid
    grid[p1x][p1y] = '@';
    grid[p2x][p2y] = '$';

    // Update enemy positions on the grid without consuming dots
    grid[e1x][e1y] = 'E';
    grid[e2x][e2y] = 'E';
    grid[e3x][e3y] = 'E';
    grid[e4x][e4y] = 'E';
    grid[e5x][e5y] = 'E';
    grid[e6x][e6y] = 'E';

}

void result() {
    system("cls");

            if (game_end)
            {
                cout<<"\n\n\n\n\n";
               cout << "\t\t\t\t\t\t Game over !\n";
               cout << "\t\t\t\t\t\t Your total score is   " << point << "\n";
               cout<<"\t\t\t\t\t\t Better luck next time !!!";
            }

}
void wrapAround(int &x, int &y) {
    x = (x + row) % row;
    y = (y + column) % column;


    if (x < 0) x = row - 1;
    if (y < 0) y = column - 1;
}
void enemyMove() {
    e1x ++;
   // e1y ++  ;
    e2x -- ;
   // e2y ++ ;
   // e3x ++ ;
    e3y ++;
   // e4x ++ ;
    e4y --;
    e5x ++ ;
   //// e5y ++ ;
   // e6x ++ ;
    e6x -- ;
   // e6x++ ;
    wrapAround(e1x, e1y);
    wrapAround(e2x, e2y);
     wrapAround(e3x, e3y);
    wrapAround(e4x, e4y);
     wrapAround(e5x, e5y);
    wrapAround(e6x, e6y);


}
int main() {
    char grid[row][column];
    playfield(grid);
   // textcolor (4);

    // Move the initialization of enemy positions outside the main loop
    e1x = rand() % row;
    e1y = rand() % column;
    e2x = rand() % row;
    e2y = rand() % column;
     p1x = rand() % row;
    p1y = rand() % column;
    p2x = rand() % row;
    p2y = rand() % column;

    while (!game_end) {
        system("cls");
        setup(grid);
        display(grid);

        enemyMove();
        input();

       Sleep (500);

    }
    result();
    return 0;
}











