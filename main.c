#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<conio.h>
int arr4[4][4];
int arr5[5][5];
int checkarr4[4][4];
int checkarr5[5][5];
int checkifchanged=0;
int highscore4x4=0;
int score4x4=0;
int highscore5x5=0;
int score5x5=0;
char numbers[15][10][10];
void gotoxy(int x, int y){
    COORD Pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

int random16(){
    return rand()%16;
}

int random2or4(){
    int randint = rand()%10;
    if (randint == 0){
        return 4;
    }
    else return 2;
}

void _printtitle(){
    gotoxy(50,5);
    printf("_______________      _____   ______   .__         _________  \n");
    gotoxy(50,6);
    printf("\\_____  \\   _  \\    /  |  | /  __  \\  |__| ____   \\_   ___ \ \n");
    gotoxy(50,7);
    printf(" /  ____/  /_\\  \\  /   |  |_>      <  |  |/    \\  /    \\  \\/ \n");
    gotoxy(50,8);
    printf("/       \\  \\_/   \\/    ^   /   --   \\ |  |   |  \\ \\     \\____\n");
    gotoxy(50,9);
    printf("\\_______ \\_____  /\\____   |\\______  / |__|___|  /  \\______  /\n");
    gotoxy(50,10);
    printf("        \\/     \\/      |__|       \\/          \\/          \\/ \n");
    gotoxy(50,11);
    printf("                                                             \n");
    Sleep(1000);
    system("cls");
}

void _printrules(){
    gotoxy(52,5);
    printf(".______       __    __   __       _______     _______.\n");
    gotoxy(52,6);
    printf("|   _  \\     |  |  |  | |  |     |   ____|   /       |\n");
    gotoxy(52,7);
    printf("|  |_)  |    |  |  |  | |  |     |  |__     |   (----`\n");
    gotoxy(52,8);
    printf("|      /     |  |  |  | |  |     |   __|     \\   \\    \n");
    gotoxy(52,9);
    printf("|  |\\  \\----.|  `--'  | |  `----.|  |____.----)   |   \n");
    gotoxy(52,10);
    printf("| _| `._____| \\______/  |_______||_______|_______/    \n");
    Sleep(1000);
    gotoxy(50,17);
    printf("1. 이 게임은 play2048.co의 2048을 토대로 만들어졌습니다.");
    Sleep(800);
    gotoxy(52,19);
    printf("2. 수가 2048인 블록이 만들어지면 게임이 종료됩니다.");
    Sleep(800);
    gotoxy(63,21);
    printf("3. WASD를 이용해 조작합니다.");
    Sleep(800);
    gotoxy(67,23);
    printf("4. 게임을 즐기세요 !");
    Sleep(2000);
    system("cls");
}

int _printmain(){
    gotoxy(51,5);
    printf("                                                                        \n");
    gotoxy(51,6);
    printf("  _________      .__                 __      _________.__               \n");
    gotoxy(51,7);
    printf(" /   _____/ ____ |  |   ____   _____/  |_   /   _____/|__|_______ ____  \n");
    gotoxy(51,8);
    printf(" \\_____  \\_/ __ \\|  | _/ __ \\_/ ___\\   __\\  \\_____  \\ |  \\___   // __ \\ \n");
    gotoxy(51,9);
    printf(" /        \\  ___/|  |_\\  ___/\\  \___|  |    /        \\|  |/    /\\  ___/ \n");
    gotoxy(51,10);
    printf("/_______  /\\___  >____/\\___  >\\___  >__|   /_______  /|__/_____ \\___  >\n");
    gotoxy(51,11);
    printf("        \\/     \\/          \\/     \\/               \\/          \\/    \\/ \n");
    gotoxy(51,12);
    printf("                                                                        \n");
    Sleep(500);

    gotoxy(38,17);
    printf("   _____           _____  \n");
    gotoxy(110,17);
    printf(" .________        .________\n");
    Sleep(150);

    gotoxy(38,18);
    printf("  /  |  |___  ___ /  |  | \n");
    gotoxy(110,18);
    printf(" |   ____/__  ___ |   ____/\n");
    Sleep(150);

    gotoxy(38,19);
    printf(" /   |  |\\  \\/  //   |  |_\n");
    gotoxy(110,19);
    printf(" |____  \\\\  \\/  / |____  \\ \n");
    Sleep(150);

    gotoxy(38,20);
    printf("/    ^   />    </    ^   /\n");
    gotoxy(110,20);
    printf(" /       \\>    <  /       \\ \n");
    Sleep(150);

    gotoxy(38,21);
    printf("\\____   |/__/\\_ \\____   | \n");
    gotoxy(110,21);
    printf("/______  /__/\\_ \\/______  /\n");
    Sleep(150);

    gotoxy(38,22);
    printf("     |__|      \\/    |__| \n");
    gotoxy(110,22);
    printf("       \\/      \\/       \\/ \n");
    Sleep(150);

    gotoxy(23,30);
    printf("__________                                   _____                   .________   __             _________ __                 __   \n");
    gotoxy(23,31);
    printf("\\______   \\_______   ____   ______ ______   /  |  |    ___________   |   ____/ _/  |_  ____    /   _____//  |______ ________/  |_ \n");
    gotoxy(23,32);
    printf(" |     ___/\\_  __ \\_/ __ \\ /  ___//  ___/  /   |  |_  /  _ \\_  __ \\  |____  \\  \\   __\\/  _ \\   \\_____  \\\\   __\\__  \\\\_  __ \\   __\\ \n");
    gotoxy(23,33);
    printf(" |    |     |  | \\/\\  ___/ \\___ \\ \\___ \\  /    ^   / (  <_> )  | \\/  /       \\  |  | (  <_> )  /        \\|  |  / __ \\|  | \\/|  |  \n");
    gotoxy(23,34);
    printf(" |____|     |__|    \\___  >____  >____  > \\____   |   \\____/|__|    /______  /  |__|  \\____/  /_______  /|__| (____  /__|   |__|  \n");
    gotoxy(23,35);
    printf("                        \\/     \\/     \\/       |__|                        \\/                         \\/           \\/             \n");

    char c = _getch();
    int n = c - '0';

    system("cls");
    return n;
}

void _write4x4standard(int rowstart, int rowend, int columnstart, int columnend){
    gotoxy(rowstart+2,columnstart-1);
    printf("12345678901234567890123456789012345678901234567890123456789012345678901234567890");
    gotoxy(rowstart,columnstart);
    printf("┏");
    gotoxy(rowend,columnstart);
    printf("┓");
    for(int i=rowstart+1;i<=rowend-1;i++){
        gotoxy(i,columnstart);
        printf("─");
    }
    Sleep(50);
    for(int i=columnstart+1;i<=columnend-1;i++){
        gotoxy(rowstart,i);
        printf("│");
        gotoxy(rowend,i);
        printf("│");
        Sleep(50);
    }
    gotoxy(rowstart,columnend);
    printf("└");
    gotoxy(rowend,columnend);
    printf("┛");
    for(int i=rowstart+1;i<=rowend-1;i++){
        gotoxy(i,columnend);
        printf("─");
    }
    Sleep(500);
}

void _print2(int rowstart,int colstart){
    gotoxy(rowstart,colstart);
    printf("   ────────────────┐  ");
    gotoxy(rowstart,colstart+1);
    printf("                   │");
    gotoxy(rowstart,colstart+2);
    printf("                   │");
    gotoxy(rowstart,colstart+3);
    printf("                   │");
    gotoxy(rowstart,colstart+4);
    printf("  ┌────────────────┘  ");
    gotoxy(rowstart,colstart+5);
    printf("  │                  ");
    gotoxy(rowstart,colstart+6);
    printf("  │                  ");
    gotoxy(rowstart,colstart+7);
    printf("  │                  ");
    gotoxy(rowstart,colstart+8);
    printf("  │                  ");
    gotoxy(rowstart,colstart+9);
    printf("  └────────────────  ");
};

void _print4(int rowstart,int colstart){
    gotoxy(rowstart,colstart);
    printf(" │        │");
    gotoxy(rowstart,colstart+1);
    printf(" │        │");
    gotoxy(rowstart,colstart+2);
    printf(" │        │");
    gotoxy(rowstart,colstart+3);
    printf(" │        │");
    gotoxy(rowstart,colstart+4);
    printf(" └────────┼───────");
    gotoxy(rowstart,colstart+5);
    printf("          │");
    gotoxy(rowstart,colstart+6);
    printf("          │");
    gotoxy(rowstart,colstart+7);
    printf("          │");
    gotoxy(rowstart,colstart+8);
    printf("          │");
    gotoxy(rowstart,colstart+9);
    printf("          │");
};

void _print8(int rowstart,int colstart){

    gotoxy(rowstart,colstart);
    printf(" ┌────────────────┐");
    gotoxy(rowstart,colstart+1);
    printf(" │                │");
    gotoxy(rowstart,colstart+2);
    printf(" │                │");
    gotoxy(rowstart,colstart+3);
    printf(" │                │");
    gotoxy(rowstart,colstart+4);
    printf(" ├────────────────┤");
    gotoxy(rowstart,colstart+5);
    printf(" │                │");
    gotoxy(rowstart,colstart+6);
    printf(" │                │");
    gotoxy(rowstart,colstart+7);
    printf(" │                │");
    gotoxy(rowstart,colstart+8);
    printf(" │                │");
    gotoxy(rowstart,colstart+9);
    printf(" └────────────────┘");
};

void _resetcheckarr4x4(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            checkarr4[i][j] = 0;
        }
    }
}

void _resetcheckarr5x5(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            checkarr5[i][j] = 0;
        }
    }
}

void _scoreadd4x4(int n){
    score4x4 = score4x4 + n;
}

void _scoreadd5x5(int n){
    score5x5 = score5x5 + n;
}

void _logicw4x4(){
    while(1){
        for(int i=1;i<4;i++){
            for(int j=0;j<4;j++){
                if(arr4[i-1][j] == 0){
                    arr4[i-1][j] = arr4[i][j];
                    arr4[i][j] = 0;
                    checkarr4[i-1][j] = checkarr4[i][j];
                    checkarr4[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr4[i-1][j] != 0){
                    if(arr4[i-1][j] == arr4[i][j]){
                        arr4[i-1][j] = arr4[i][j]*2;
                        arr4[i][j] = 0;
                        checkarr4[i-1][j] = 1;
                        checkarr4[i][j] = 0;
                        checkifchanged++;
                        _scoreadd4x4(arr4[i-1][j]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=1;i<4;i++){
            for(int j=0;j<4;j++){
                if((arr4[i][j] != 0 && arr4[i-1][j] == 0) || (((arr4[i][j] == arr4[i-1][j]) && arr4[i][j] != 0 ) && (checkarr4[i][j] ==0 &&checkarr4[i-1][j] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr4x4();
            break;
        }
    }
}

void _logicw5x5(){
    while(1){
        for(int i=1;i<5;i++){
            for(int j=0;j<5;j++){
                if(arr5[i-1][j] == 0){
                    arr5[i-1][j] = arr5[i][j];
                    arr5[i][j] = 0;
                    checkarr5[i-1][j] = checkarr5[i][j];
                    checkarr5[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr5[i-1][j] != 0){
                    if(arr5[i-1][j] == arr5[i][j]){
                        arr5[i-1][j] = arr5[i][j]*2;
                        arr5[i][j] = 0;
                        checkarr5[i-1][j] = 1;
                        checkarr5[i][j] = 0;
                        checkifchanged++;
                        _scoreadd5x5(arr5[i-1][j]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=1;i<5;i++){
            for(int j=0;j<5;j++){
                if((arr5[i][j] != 0 && arr5[i-1][j] == 0) || (((arr5[i][j] == arr5[i-1][j]) && arr5[i][j] != 0 ) && (checkarr5[i][j] ==0 &&checkarr5[i-1][j] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr5x5();
            break;
        }
    }
}

void _logica4x4(){
    while(1){
        for(int i=0;i<4;i++){
            for(int j=1;j<4;j++){
                if(arr4[i][j-1] == 0){
                    arr4[i][j-1] = arr4[i][j];
                    arr4[i][j] = 0;
                    checkarr4[i][j-1] = checkarr4[i][j];
                    checkarr4[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr4[i][j-1] != 0){
                    if(arr4[i][j-1] == arr4[i][j]){
                        arr4[i][j-1] = arr4[i][j]*2;
                        arr4[i][j] = 0;
                        checkarr4[i][j-1] = 1;
                        checkarr4[i][j] = 0;
                        checkifchanged++;
                        _scoreadd4x4(arr4[i][j-1]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=0;i<4;i++){
            for(int j=1;j<4;j++){
                if((arr4[i][j] != 0 && arr4[i][j-1] == 0) || (((arr4[i][j] == arr4[i][j-1]) && arr4[i][j] != 0 ) && (checkarr4[i][j] ==0 &&checkarr4[i][j-1] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr4x4();
            break;
        }
    }
}

void _logica5x5(){
    while(1){
        for(int i=0;i<5;i++){
            for(int j=1;j<5;j++){
                if(arr5[i][j-1] == 0){
                    arr5[i][j-1] = arr5[i][j];
                    arr5[i][j] = 0;
                    checkarr5[i][j-1] = checkarr5[i][j];
                    checkarr5[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr5[i][j-1] != 0){
                    if(arr5[i][j-1] == arr5[i][j]){
                        arr5[i][j-1] = arr5[i][j]*2;
                        arr5[i][j] = 0;
                        checkarr5[i][j-1] = 1;
                        checkarr5[i][j] = 0;
                        checkifchanged++;
                        _scoreadd4x4(arr5[i][j-1]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=0;i<5;i++){
            for(int j=1;j<5;j++){
                if((arr5[i][j] != 0 && arr5[i][j-1] == 0) || (((arr5[i][j] == arr5[i][j-1]) && arr5[i][j] != 0 ) && (checkarr5[i][j] ==0 &&checkarr5[i][j-1] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr5x5();
            break;
        }
    }
}

void _logics4x4(){
    while(1){
        for(int i=2;i>=0;i--){
            for(int j=0;j<4;j++){
                if(arr4[i+1][j] == 0){
                    arr4[i+1][j] = arr4[i][j];
                    arr4[i][j] = 0;
                    checkarr4[i+1][j] = checkarr4[i][j];
                    checkarr4[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr4[i+1][j] != 0){
                    if(arr4[i+1][j] == arr4[i][j]){
                        arr4[i+1][j] = arr4[i][j]*2;
                        arr4[i][j] = 0;
                        checkarr4[i+1][j] = 1;
                        checkarr4[i][j] = 0;
                        checkifchanged++;
                        _scoreadd4x4(arr4[i+1][j]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<4;j++){
                if((arr4[i][j] != 0 && arr4[i+1][j] == 0) || (((arr4[i][j] == arr4[i+1][j]) && arr4[i][j] != 0 ) && (checkarr4[i][j] ==0 &&checkarr4[i+1][j] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr4x4();
            break;
        }
    }
}

void _logics5x5(){
    while(1){
        for(int i=3;i>=0;i--){
            for(int j=0;j<5;j++){
                if(arr5[i+1][j] == 0){
                    arr5[i+1][j] = arr5[i][j];
                    arr5[i][j] = 0;
                    checkarr5[i+1][j] = checkarr5[i][j];
                    checkarr5[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr5[i+1][j] != 0){
                    if(arr5[i+1][j] == arr5[i][j]){
                        arr5[i+1][j] = arr5[i][j]*2;
                        arr5[i][j] = 0;
                        checkarr5[i+1][j] = 1;
                        checkarr5[i][j] = 0;
                        checkifchanged++;
                        _scoreadd5x5(arr5[i+1][j]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                if((arr5[i][j] != 0 && arr5[i+1][j] == 0) || (((arr5[i][j] == arr5[i+1][j]) && arr5[i][j] != 0 ) && (checkarr5[i][j] ==0 &&checkarr5[i+1][j] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr5x5();
            break;
        }
    }
}

void _logicd4x4(){
    while(1){
        for(int i=0;i<4;i++){
            for(int j=2;j>=0;j--){
                if(arr4[i][j+1] == 0){
                    arr4[i][j+1] = arr4[i][j];
                    arr4[i][j] = 0;
                    checkarr4[i][j+1] = checkarr4[i][j];
                    checkarr4[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr4[i][j+1] != 0){
                    if(arr4[i][j+1] == arr4[i][j]){
                        arr4[i][j+1] = arr4[i][j]*2;
                        arr4[i][j] = 0;
                        checkarr4[i][j+1] = 1;
                        checkarr4[i][j] = 0;
                        checkifchanged++;
                        _scoreadd4x4(arr4[i][j+1]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if((arr4[i][j] != 0 && arr4[i][j+1] == 0) || (((arr4[i][j] == arr4[i][j+1]) && arr4[i][j] != 0 ) && (checkarr4[i][j] ==0 &&checkarr4[i][j+1] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr4x4();
            break;
        }
    }
}

void _logicd5x5(){
    while(1){
        for(int i=0;i<5;i++){
            for(int j=3;j>=0;j--){
                if(arr5[i][j+1] == 0){
                    arr5[i][j+1] = arr5[i][j];
                    arr5[i][j] = 0;
                    checkarr5[i][j+1] = checkarr5[i][j];
                    checkarr5[i][j] = 0;
                    checkifchanged++;
                }
                else if(arr5[i][j+1] != 0){
                    if(arr5[i][j+1] == arr5[i][j]){
                        arr5[i][j+1] = arr5[i][j]*2;
                        arr5[i][j] = 0;
                        checkarr5[i][j+1] = 1;
                        checkarr5[i][j] = 0;
                        checkifchanged++;
                        _scoreadd5x5(arr5[i][j+1]);
                    }
                }
            }
        }
        int check = 0;
        for(int i=0;i<5;i++){
            for(int j=0;j<4;j++){
                if((arr5[i][j] != 0 && arr5[i][j+1] == 0) || (((arr5[i][j] == arr5[i][j+1]) && arr5[i][j] != 0 ) && (checkarr5[i][j] ==0 &&checkarr5[i][j+1] == 0) )){
                    check++;
                }
            }
        }
        if(check == 0){
            _resetcheckarr5x5();
            break;
        }
    }
}

void _logicaddnewnum4x4(){
    int n = rand()%10;
    int howmanyadd;
    if(0<=n && n <= 6) howmanyadd = 1;
    else howmanyadd = 0;
    int newpos1;
    int newnum1 = random2or4();
    while(1){
        newpos1 = random16();
        if(arr4[newpos1/4][newpos1%4] == 0){
            break;
        }
    }
    arr4[newpos1/4][newpos1%4] = newnum1;
}

void _logicaddnewnum5x5(){
    int n = rand()%10;
    int howmanyadd;
    if(0<=n && n <= 6) howmanyadd = 1;
    else howmanyadd = 0;
    int newpos1;
    int newnum1 = random2or4();
    while(1){
        newpos1 = random16();
        if(arr5[newpos1/5][newpos1%5] == 0){
            break;
        }
    }
    arr5[newpos1/5][newpos1%5] = newnum1;
}

int _checkifclear4x4(){
    int check = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr4[i][j] == 2048){
                check = 1;
            }
        }
    }
    if(check == 1) return 1;
    else return 0;
}

int _checkifclear5x5(){
    int check = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr5[i][j] == 2048){
                check = 1;
            }
        }
    }
    if(check == 1) return 1;
    else return 0;
}

void _printclearscreen4x4(int n){
    system("cls");
    gotoxy(45,5);
    printf("_________                                     __        .__          __  .__           ");
    gotoxy(45,6);
    printf("\\_   ___ \\  ____   ____    ________________ _/  |_ __ __|  | _____ _/  |_|__| ____   ____  ");
    gotoxy(45,7);
    printf("/    \\  \\/ /  _ \\ /    \\  / ___\\_  __ \\__  \\\\   __\\  |  \\  | \\__  \\\\   __\\  |/  _ \\ /    \\ ");
    gotoxy(45,8);
    printf("\\     \\___(  <_> )   |  \\/ /_/  >  | \\// __ \\|  | |  |  /  |__/ __ \\|  | |  (  <_> )   |  \\");
    gotoxy(45,9);
    printf(" \\______  /\\____/|___|  /\\___  /|__|  (____  /__| |____/|____(____  /__| |__|\\____/|___|  /");
    gotoxy(45,10);
    printf("        \\/            \\//_____/            \\/                     \\/                    \\/ ");
    gotoxy(62,15);
    printf("Your Score : %d",score4x4);
    gotoxy(98,15);
    if(score4x4 > highscore4x4) highscore4x4 = score4x4;
    printf("High Score : %d",highscore4x4);

}


void _printclearscreen5x5(int n){
    system("cls");
    gotoxy(45,5);
    printf("_________                                     __        .__          __  .__           ");
    gotoxy(45,6);
    printf("\\_   ___ \\  ____   ____    ________________ _/  |_ __ __|  | _____ _/  |_|__| ____   ____  ");
    gotoxy(45,7);
    printf("/    \\  \\/ /  _ \\ /    \\  / ___\\_  __ \\__  \\\\   __\\  |  \\  | \\__  \\\\   __\\  |/  _ \\ /    \\ ");
    gotoxy(45,8);
    printf("\\     \\___(  <_> )   |  \\/ /_/  >  | \\// __ \\|  | |  |  /  |__/ __ \\|  | |  (  <_> )   |  \\");
    gotoxy(45,9);
    printf(" \\______  /\\____/|___|  /\\___  /|__|  (____  /__| |____/|____(____  /__| |__|\\____/|___|  /");
    gotoxy(45,10);
    printf("        \\/            \\//_____/            \\/                     \\/                    \\/ ");
    gotoxy(62,15);
    printf("Your Score : %d",score5x5);
    gotoxy(98,15);
    if(score5x5 > highscore5x5) highscore5x5 = score5x5;
    printf("High Score : %d",highscore5x5);

}

void _print4x4(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",arr4[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("score : %d\n",score4x4);
}

void _print5x5(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",arr5[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("score : %d\n",score5x5);
}

void _play4x4(){
    // 31~50, 51~70, 71~90, 91~110
    // 3~12, 13~22, 23~32, 33~42
    int rowstart = 30;
    int rowend = 112;
    int columnstart = 2;
    int columnend = 44;
    //_write4x4standard(rowstart,rowend,columnstart,columnend);
    int startingpos1=random16();
    int startingpos2=random16();
    int startingnum1 = random2or4();
    int startingnum2 = random2or4();
    arr4[startingpos1 / 4][startingnum1 % 4] = startingnum1;
    arr4[startingpos2 / 4][startingnum2 % 4] = startingnum2;
    _print4x4();
    while(1){
        char inputkey;
        inputkey = _getch();
        if(inputkey == 'w'){
            _logicw4x4();
        }
        else if(inputkey == 'a'){
            _logica4x4();
        }
        else if(inputkey == 's'){
            _logics4x4();
        }
        else if(inputkey == 'd'){
            _logicd4x4();
        }
        if(checkifchanged != 0) _logicaddnewnum4x4();
        checkifchanged = 0;
        _print4x4();
        int ischecked = _checkifclear4x4();
        if(ischecked == 1){
            _printclearscreen4x4(4);
            break;
        }
    }
}

void _play5x5(){
    // 31~50, 51~70, 71~90, 91~110
    // 3~12, 13~22, 23~32, 33~42
    int rowstart = 30;
    int rowend = 112;
    int columnstart = 2;
    int columnend = 44;
    //_write4x4standard(rowstart,rowend,columnstart,columnend);
    int startingpos1=random16();
    int startingpos2=random16();
    int startingnum1 = random2or4();
    int startingnum2 = random2or4();
    arr5[startingpos1 / 5][startingnum1 % 5] = startingnum1;
    arr5[startingpos2 / 5][startingnum2 % 5] = startingnum2;
    _print5x5();
    while(1){
        char inputkey;
        inputkey = _getch();
        if(inputkey == 'w'){
            _logicw5x5();
        }
        else if(inputkey == 'a'){
            _logica5x5();
        }
        else if(inputkey == 's'){
            _logics5x5();
        }
        else if(inputkey == 'd'){
            _logicd5x5();
        }
        if(checkifchanged != 0){
            _logicaddnewnum5x5();
        }
        checkifchanged = 0;
        _print5x5();
        int ischecked = _checkifclear5x5();
        if(ischecked == 1){
            _printclearscreen5x5(5);
            break;
        }
    }
}

int main(){
    srand(time(NULL));
    system("title 2048_in_C"); // 프로세스 이름
    system("mode con: cols=180 lines=60"); // !콘솔창 크기
    system("COLOR 0F"); //!배경색, 글자색
    //_printtitle();
    //_printrules();
    int selected_round;
    selected_round = _printmain();
    if(selected_round == 4){
        _play4x4();
    }
    else{
        _play5x5();
    }
}
