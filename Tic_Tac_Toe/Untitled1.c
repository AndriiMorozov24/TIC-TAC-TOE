#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

static int count = 0;
static int WinCount = 0;
static int LoseCount = 0;
static const int Space = 32;

void CleanKeyboardBuffer() {
while(_kbhit()){
getch();
}
}

int Block(int choi[][3], int i);

int FirstMove(int pole[][3]) {
if (pole[0][0] == 1 || pole[0][2] == 1 || pole[2][0] == 1 || pole[2][2] == 1 ) {
return 1;
}
if (pole[0][1] == 1) {
return 3;
}
if (pole[2][1] == 1) {
return 4;
}
if (pole[1][0] == 1) {
return 5;
}
if (pole[1][2] == 1) {
return 6;
}
}

void Clean() {
int j;
for (j=11;j<79;j++) {
gotoxy(j,33);
printf(" ");
gotoxy(j+1,34);
printf(" ");
}
}

int Mozg(int pole[][3]) {
if ( pole[0][0] == 2 && pole[0][1] == 2 && pole[0][2] == 3 ) {
pole[0][2] = 2;
zero(0,2);
return 0;
}
if ( pole[0][0] == 2 && pole[0][2] == 2 && pole[0][1] == 3) {
pole[0][1] = 2;
zero(0,1);
return 0;
}
if ( pole[0][1] == 2 && pole[0][2] == 2 && pole[0][0] == 3 ) {
pole[0][0] = 2;
zero(0,0);
return 0;
}
if ( pole[1][0] == 2 && pole[1][1] == 2 && pole[1][2] == 3 ) {
pole[1][2] = 2;
zero(1,2);
return 0;
}
if ( pole[1][0] == 2 && pole[1][2] == 2 && pole[1][1] == 3) {
pole[1][1] = 2;
zero(1,1);
return 0;
}
if ( pole[1][1] == 2 && pole[1][2] == 2 && pole[1][0] == 3) {
pole[1][0] = 2;
zero(1,0);
return 0;
}
if ( pole[2][0] == 2 && pole[2][1] == 2 && pole[2][2] == 3 ) {
pole[2][2] = 2;
zero(2,2);
return 0;
}
if ( pole[2][0] == 2 && pole[2][2] == 2 && pole[2][1] == 3  ) {
pole[2][1] = 2;
zero(2,1);
return 0;
}
if ( pole[2][1] == 2 && pole[2][2] == 2 && pole[2][0] == 3 ) {
pole[2][0] = 2;
zero(2,0);
return 0;
}
if ( pole[0][0] == 2 && pole[1][0] == 2 && pole[2][0] == 3 ) {
pole[2][0] = 2;
zero(2,0);
return 0;
}
if ( pole[0][0] == 2 && pole[2][0] == 2 && pole[1][0] == 3 ) {
pole[1][0] = 2;
zero(1,0);
return 0;
}
if ( pole[1][0] == 2 && pole[2][0] == 2 && pole[0][0] == 3 ) {
pole[0][0] = 2;
zero(0,0);
return 0;
}
if ( pole[0][1] == 2 && pole[1][1] == 2 && pole[2][1] == 3 ) {
pole[2][1] = 2;
zero(2,1);
return 0;
}
if ( pole[0][1] == 2 && pole[2][1] == 2 && pole[1][1] == 3 ) {
pole[1][1] = 2;
zero(1,1);
return 0;
}
if ( pole[1][1] == 2 && pole[2][1] == 2 && pole[0][1] == 3 ) {
pole[0][1] = 2;
zero(0,1);
return 0;
}
if ( pole[0][2] == 2 && pole[1][2] == 2 && pole[2][2] == 3 ) {
pole[2][2] = 2;
zero(2,2);
return 0;
}
if ( pole[0][2] == 2 && pole[2][2] == 2 && pole[1][2] == 3 ) {
pole[1][2] = 2;
zero(1,2);
return 0;
}
if ( pole[1][2] == 2 && pole[2][2] == 2 && pole[0][2] == 3 ) {
pole[0][2] = 2;
zero(0,2);
return 0;
}
if ( pole[0][0] == 2 && pole[1][1] == 2 && pole[2][2] == 3 ) {
pole[2][2] = 2;
zero(2,2);
return 0;
}
if ( pole[0][0] == 2 && pole[2][2] == 2 && pole[1][1] == 3) {
pole[1][1] = 2;
zero(1,1);
return 0;
}
if ( pole[1][1] == 2 && pole[2][2] == 2 && pole[0][0] == 3 ) {
pole[0][0] = 2;
zero(0,0);
return 0;
}
if ( pole[0][2] == 2 && pole[1][1] == 2 && pole[2][0] == 3) {
pole[2][0] = 2;
zero(2,0);
return 0;
}
if ( pole[0][2] == 2 && pole[2][0] == 2 && pole[1][1] == 3 ) {
pole[1][1] = 2;
zero(1,1);
return 0;
}
if ( pole[1][1] == 2 && pole[2][0] == 2 && pole[0][2] == 3) {
pole[0][2] = 2;
zero(0,2);
return 0;
}
return 1;
}

int KatCheck(int pole[][3]) {
if (pole[0][0] == 3) {
    return 1;
}
if (pole[0][2] == 3) {
    return 2;
}
if (pole[2][0] == 3) {
    return 3;
}
if (pole[2][2] == 3) {
    return 4;
}

return 5;
}

int Kat(int choi[][3]);

int enemy(int pole[][3]) {
if ( pole[0][0] == 1 && pole[0][1] == 1 && pole[0][2] == 3 ) {
return 3;
}
if ( pole[0][0] == 1 && pole[0][2] == 1 && pole[0][1] == 3) {
return 4;
}
if ( pole[0][1] == 1 && pole[0][2] == 1 && pole[0][0] == 3 ) {
return 5;
}
if ( pole[1][0] == 1 && pole[1][1] == 1 && pole[1][2] == 3 ) {
return 6;
}
if ( pole[1][0] == 1 && pole[1][2] == 1 && pole[1][1] == 3) {
return 7;
}
if ( pole[1][1] == 1 && pole[1][2] == 1 && pole[1][0] == 3) {
return 8;
}
if ( pole[2][0] == 1 && pole[2][1] == 1 && pole[2][2] == 3 ) {
return 9;
}
if ( pole[2][0] == 1 && pole[2][2] == 1 && pole[2][1] == 3  ) {
return 10;
}
if ( pole[2][1] == 1 && pole[2][2] == 1 && pole[2][0] == 3 ) {
return 11;
}
if ( pole[0][0] == 1 && pole[1][0] == 1 && pole[2][0] == 3 ) {
return 12;
}
if ( pole[0][0] == 1 && pole[2][0] == 1 && pole[1][0] == 3 ) {
return 13;
}
if ( pole[1][0] == 1 && pole[2][0] == 1 && pole[0][0] == 3 ) {
return 14;
}
if ( pole[0][1] == 1 && pole[1][1] == 1 && pole[2][1] == 3 ) {
return 15;
}
if ( pole[0][1] == 1 && pole[2][1] == 1 && pole[1][1] == 3 ) {
return 16;
}
if ( pole[1][1] == 1 && pole[2][1] == 1 && pole[0][1] == 3 ) {
return 17;
}
if ( pole[0][2] == 1 && pole[1][2] == 1 && pole[2][2] == 3 ) {
return 18;
}
if ( pole[0][2] == 1 && pole[2][2] == 1 && pole[1][2] == 3 ) {
return 19;
}
if ( pole[1][2] == 1 && pole[2][2] == 1 && pole[0][2] == 3 ) {
return 20;
}
if ( pole[0][0] == 1 && pole[1][1] == 1 && pole[2][2] == 3 ) {
return 21;
}
if ( pole[0][0] == 1 && pole[2][2] == 1 && pole[1][1] == 3) {
return 22;
}
if ( pole[1][1] == 1 && pole[2][2] == 1 && pole[0][0] == 3 ) {
return 23;
}
if ( pole[0][2] == 1 && pole[1][1] == 1 && pole[2][0] == 3) {
return 24;
}
if ( pole[0][2] == 1 && pole[2][0] == 1 && pole[1][1] == 3 ) {
return 25;
}
if ( pole[1][1] == 1 && pole[2][0] == 1 && pole[0][2] == 3) {
return 26;
}
return 2;
}

void NewGame() {
gotoxy(0,42);
printf("Do u want to restart, press Y or N ?");
int choi = getch();
if (choi == 110) {
    exit(0);
}
if (choi == 121) {
    system("cls");
    main();
}
NewGame();
}

int WinLoseDraw (int choi[3][3]) {
if (choi[0][0] == 1 && choi[0][1] == 1 && choi[0][2] == 1 || choi[1][0] == 1 && choi[1][1] == 1 && choi[1][2] == 1 || choi[2][0] == 1 && choi[2][1] == 1 && choi[2][2] == 1 || choi[0][0] == 1 && choi[1][1] == 1 && choi[2][2] == 1 || choi[0][2] == 1 && choi[1][1] == 1 && choi[2][0] == 1 || choi[0][0] == 1 && choi[1][0] == 1 && choi[2][0] == 1 || choi[0][1] == 1 && choi[1][1] == 1 && choi[2][1] == 1 || choi[0][2] == 1 && choi[1][2] == 1 && choi[2][2] == 1) {
    return 5;
}
if (choi[0][0] == 2 && choi[0][1] == 2 && choi[0][2] == 2 || choi[1][0] == 2 && choi[1][1] == 2 && choi[1][2] == 2 || choi[2][0] == 2 && choi[2][1] == 2 && choi[2][2] == 2 || choi[0][0] == 2 && choi[1][1] == 2 && choi[2][2] == 2 || choi[0][2] == 2 && choi[1][1] == 2 && choi[2][0] == 2 || choi[0][0] == 2 && choi[1][0] == 2 && choi[2][0] == 2 || choi[0][1] == 2 && choi[1][1] == 2 && choi[2][1] == 2 || choi[0][2] == 2 && choi[1][2] == 2 && choi[2][2] == 2) {
    return 6;
}
}

void Help(int i, int choi[][3]) {
if (i >= 2) {
if (WinLoseDraw(choi) == 5 ) {
gotoxy(0,40);
printf("U won!!!");
WinCount++;
NewGame();
}
if (WinLoseDraw(choi) == 6 ) {
gotoxy(0,40);
printf("U lose!!!");
LoseCount++;
NewGame();
}
}
}

void DeleteHallo() {
gotoxy(0,0);
printf("      \n");
gotoxy(0,1);
printf("             \n");
gotoxy(0,2);
printf("                                                       \n");
gotoxy(0,3);
printf("                                                       \n");
gotoxy(0,4);
printf("      \n");
}

void Hallo() {
printf("Hello\n");
printf("U play with X\n");
printf("After playground appear u can choose coord of ur move\n");
printf("First u choose line from 1-3, then column from 1-3\n");
printf("Enjoy!\n");
Sleep(10000);
}

int RandomColumn () {
int column;
column=rand() % 3;
return column;
}

int RandomLine () {
int line;
line=rand() % 3;
return line;
}

void gotoxy( int column, int line ) {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

void zero(int column, int line);

void krestik(int column, int line) {
int i;
if (line == 0) {
if (column == 0) {
for(i=0;i<10;i++) {
gotoxy(i,i);
printf("*");
}
for(i=10;i>0;i--) {
gotoxy(i,10-i);
printf("*");
}
}
if (column == 1) {
for(i=11;i<21;i++) {
gotoxy(22-i,i);
printf("*");
}
for(i=20;i>10;i--) {
gotoxy(i-10,i);
printf("*");
}
}
if (column == 2) {
for(i=22;i<31;i++) {
gotoxy(32-i,i);
printf("*");
}
for(i=30;i>21;i--) {
gotoxy(i-20,i);
printf("*");
}
}
}
if (line == 1) {
if (column == 0) {
for(i=13;i<23;i++) {
gotoxy(i,i-13);
printf("*");
}
for(i=23;i>13;i--) {
gotoxy(i,23-i);
printf("*");
}
}
if (column == 1) {
for(i=13;i<23;i++) {
gotoxy(i,i-2);
printf("*");
}
for(i=23;i>13;i--) {
gotoxy(i,34-i);
printf("*");
}
}
if (column == 2) {
for(i=13;i<22;i++) {
gotoxy(i,i+9);
printf("*");
}
for(i=23;i>14;i--) {
gotoxy(i,45-i);
printf("*");
}
}
}
if (line == 2) {
if (column == 0) {
for(i=25;i<35;i++) {
gotoxy(i,i-25);
printf("*");
}
for(i=35;i>25;i--) {
gotoxy(i,35-i);
printf("*");
}
}
if (column == 1) {
for(i=25;i<35;i++) {
gotoxy(i,i-14);
printf("*");
}
for(i=35;i>25;i--) {
gotoxy(i,46-i);
printf("*");
}
}
if (column == 2) {
for(i=26;i<35;i++) {
gotoxy(i,i-4);
printf("*");
}
for(i=34;i>25;i--) {
gotoxy(i,56-i);
printf("*");
}
}
}
}

void pole() {
int i;
for(i=0;i<31;i++) {
gotoxy(12,i);
printf("|");
}
for(i=0;i<31;i++) {
gotoxy(24,i);
printf("|");
}
for(i=0;i<37;i++) {
gotoxy(i,10);
printf("-");
}
for(i=0;i<37;i++) {
gotoxy(i,21);
printf("-");
}
gotoxy(0,33);
}

void Game() {
int choi[3][3] = {
{3,3,3},
{3,3,3},
{3,3,3},
};
int i,column,line;
for(i=0;i<5;i++) {
gotoxy(0,33);
printf("Enter line ");
scanf("%d",&column);
column--;
printf("Enter column ");
scanf("%d",&line);
line--;
Clean();
if (column > 2 || column < 0 || line > 2 || line < 0 || choi[column][line] == 1 || choi[column][line] == 2) {
gotoxy(0,35);
printf("Sprobuj jeszcze raz!!!");
i--;
Sleep(2000);
gotoxy(0,35);
printf("                        ");
continue;
}
krestik(column,line);
choi[column][line] = 1;
Help(i,choi);
if ( i == 0 ) {
if (FirstMove(choi) == 1) {
    choi[1][1] = 2;
    zero(1,1);
    continue;
}
if (choi[1][1] == 1) {
Kat(choi);
continue;
}
if (FirstMove(choi) == 3) {
    choi[0][2] = 2;
    zero(0,2);
    continue;
}
if (FirstMove(choi) == 4) {
    choi[2][2] = 2;
    zero(2,2);
    continue;
}
if (FirstMove(choi) == 5) {
    choi[2][0] = 2;
    zero(2,0);
    continue;
}
if (FirstMove(choi) == 6) {
    choi[2][2] = 2;
    zero(2,2);
    continue;
}
}
if ( i == 1 ) {
if ((choi[0][0] == 1 && choi[2][2] == 1) || (choi[0][2] == 1 && choi[2][0] == 1)) {
choi[0][1] = 2;
zero(0,1);
continue;
}
if (Block(choi,i) == 1 && choi[1][1] == 3) {
    choi[1][1] = 2;
    zero(1,1);
    continue;
}
if (choi[0][0] == 1 && choi[1][2] == 1) {
    choi[2][2] = 2;
    zero(2,2);
    continue;
}
if (choi[0][2] == 1 && choi[1][0] == 1) {
    choi[2][0] = 2;
    zero(2,0);
    continue;
}
if (choi[2][0] == 1 && choi[1][2] == 1) {
    choi[0][2] = 2;
    zero(0,2);
    continue;
}
if (choi[2][2] == 1 && choi[1][0] == 1) {
    choi[0][0] = 2;
    zero(0,0);
    continue;
}
if (choi[0][0] == 1 && choi[2][1] == 1) {
    choi[1][0] = 2;
    zero(1,0);
    continue;
}
if (choi[0][2] == 1 && choi[2][1] == 1) {
    choi[1][2] = 2;
    zero(1,2);
    continue;
}
if (choi[2][2] == 1 && choi[0][1] == 1) {
    choi[1][0] = 2;
    zero(1,0);
    continue;
}
if (choi[2][0] == 1 && choi[0][1] == 1) {
    choi[1][2] = 2;
    zero(1,2);
    continue;
}
if (choi[1][1] == 1 && choi[2][2] == 1) {
Kat(choi);
continue;
}
Block(choi,i);
continue;
}
if (i >= 2 && i != 4 ) {
if (Mozg(choi) == 0) {
Help(i,choi);
}
if (Mozg(choi) == 1) {
if (Block(choi,i) == 1) {
    Kat(choi);
    Help(i,choi);
}
}
Block(choi,i);
continue;
}
if (i == 4) {
if (WinLoseDraw(choi)==5) {
 gotoxy(0,40);
 printf("U won!!!");
 count++;
 WinCount++;
 NewGame();
}
gotoxy(0,40);
printf("DRAW!!!");
count++;
NewGame();
}
}
}

void Score() {
gotoxy(40, 21);
printf("Win : %d", WinCount);
gotoxy(50, 21);
printf("Lose : %d", LoseCount);
}

int main(void) {
srand(time(NULL));
if (count == 0) {
Hallo();
DeleteHallo();
}
pole();
Score();
Game();
return 0;
}

int Kat(int choi[][3]) {
int Random1,Random2;
if (KatCheck(choi) == 1) {
choi[0][0] = 2;
zero(0,0);
return 0;
}
if (KatCheck(choi) == 2) {
choi[0][2] = 2;
zero(0,2);
return 0;
}
if (KatCheck(choi) == 3) {
choi[2][0] = 2;
zero(2,0);
return 0;
}
if (KatCheck(choi) == 4) {
choi[2][2] = 2;
zero(2,2);
return 0;
}
if (KatCheck(choi) == 5) {
do {
Random1 = RandomColumn();
Random2 = RandomLine();
} while (choi[Random1][Random2] != 3 );
choi [Random1][Random2] = 2;
zero(Random1,Random2);
return 0;
}
return 1;
}

void zero(int column, int line) {
int i;
if (line == 0) {
if (column == 0) {
for (i=0;i<12;i++) {
gotoxy(i,0);
printf("*");
}
for (i=0;i<12;i++) {
gotoxy(i,9);
printf("*");
}
for (i=0;i<9;i++) {
gotoxy(0,i);
printf("*");
}
for (i=0;i<9;i++) {
gotoxy(11,i);
printf("*");
}
}
if (column == 1) {
for (i=0;i<12;i++) {
gotoxy(i,11);
printf("*");
}
for (i=0;i<12;i++) {
gotoxy(i,20);
printf("*");
}
for (i=11;i<20;i++) {
gotoxy(0,i);
printf("*");
}
for (i=11;i<20;i++) {
gotoxy(11,i);
printf("*");
}
}
if (column == 2) {
for (i=0;i<12;i++) {
gotoxy(i,22);
printf("*");
}
for (i=0;i<12;i++) {
gotoxy(i,30);
printf("*");
}
for (i=22;i<30;i++) {
gotoxy(0,i);
printf("*");
}
for (i=22;i<30;i++) {
gotoxy(11,i);
printf("*");
}
}
}
if (line == 1) {
if (column == 0) {
for (i=13;i<24;i++) {
gotoxy(i,0);
printf("*");
}
for (i=13;i<24;i++) {
gotoxy(i,9);
printf("*");
}
for (i=0;i<9;i++) {
gotoxy(13,i);
printf("*");
}
for (i=0;i<9;i++) {
gotoxy(23,i);
printf("*");
}
}
if (column == 1) {
for (i=13;i<24;i++) {
gotoxy(i,11);
printf("*");
}
for (i=13;i<24;i++) {
gotoxy(i,20);
printf("*");
}
for (i=11;i<20;i++) {
gotoxy(13,i);
printf("*");
}
for (i=11;i<20;i++) {
gotoxy(23,i);
printf("*");
}
}
if (column == 2) {
for (i=13;i<24;i++) {
gotoxy(i,22);
printf("*");
}
for (i=13;i<24;i++) {
gotoxy(i,30);
printf("*");
}
for (i=22;i<30;i++) {
gotoxy(13,i);
printf("*");
}
for (i=22;i<30;i++) {
gotoxy(23,i);
printf("*");
}
}
}
if (line == 2) {
if (column == 0) {
for (i=25;i<35;i++) {
gotoxy(i,0);
printf("*");
}
for (i=25;i<35;i++) {
gotoxy(i,9);
printf("*");
}
for (i=0;i<9;i++) {
gotoxy(25,i);
printf("*");
}
for (i=0;i<10;i++) {
gotoxy(35,i);
printf("*");
}
}
if (column == 1) {
for (i=25;i<36;i++) {
gotoxy(i,11);
printf("*");
}
for (i=25;i<36;i++) {
gotoxy(i,20);
printf("*");
}
for (i=11;i<20;i++) {
gotoxy(25,i);
printf("*");
}
for (i=11;i<20;i++) {
gotoxy(35,i);
printf("*");
}
}
if (column == 2) {
for (i=25;i<36;i++) {
gotoxy(i,22);
printf("*");
}
for (i=25;i<36;i++) {
gotoxy(i,30);
printf("*");
}
for (i=22;i<30;i++) {
gotoxy(25,i);
printf("*");
}
for (i=22;i<30;i++) {
gotoxy(35,i);
printf("*");
}
}
}
}

int Block(int choi[][3], int i) {
if (enemy(choi) == 2) {
return 1;
}
if (enemy(choi) == 3) {
choi[0][2] = 2;
zero(0,2);
Help(i,choi);
count++;
}
if (enemy(choi) == 4) {
choi[0][1] = 2;
zero(0,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 5) {
choi[0][0] = 2;
zero(0,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 6) {
choi[1][2] = 2;
zero(1,2);
Help(i,choi);
count++;
}
if (enemy(choi) == 7) {
choi[1][1] = 2;
zero(1,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 8) {
choi[1][0] = 2;
zero(1,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 9) {
choi[2][2] = 2;
zero(2,2);
Help(i,choi);
count++;
}
if (enemy(choi) == 10) {
choi[2][1] = 2;
zero(2,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 11) {
choi[2][0] = 2;
zero(2,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 12) {
choi[2][0] = 2;
zero(2,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 13) {
choi[1][0] = 2;
zero(1,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 14) {
choi[0][0] = 2;
zero(0,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 15) {
choi[2][1] = 2;
zero(2,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 16) {
choi[1][1] = 2;
zero(1,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 17) {
choi[0][1] = 2;
zero(0,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 18) {
choi[2][2] = 2;
zero(2,2);
Help(i,choi);
count++;
}
if (enemy(choi) == 19) {
choi[1][2] = 2;
zero(1,2);
Help(i,choi);
count++;
}
if (enemy(choi) == 20) {
choi[0][2] = 2;
zero(0,2);
Help(i,choi);
count++;
}
if (enemy(choi) == 21) {
choi[2][2] = 2;
zero(2,2);
Help(i,choi);
count++;
}
if (enemy(choi) == 22) {
choi[1][1] = 2;
zero(1,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 23) {
choi[0][0] = 2;
zero(0,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 24) {
choi[2][0] = 2;
zero(2,0);
Help(i,choi);
count++;
}
if (enemy(choi) == 25) {
choi[1][1] = 2;
zero(1,1);
Help(i,choi);
count++;
}
if (enemy(choi) == 26) {
choi[0][2] = 2;
zero(0,2);
Help(i,choi);
count++;
}
return 0;
}
