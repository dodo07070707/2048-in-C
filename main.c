#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>

void gotoxy(int x, int y){
    COORD Pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
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
    printf("__________                                ________                     _____     __             _________ __                 __   \n");
    gotoxy(23,31);
    printf("\\______   \\_______   ____   ______ ______ \\_____  \    ___________     /  |  |  _/  |_  ____    /   _____//  |______ ________/  |_ \n");
    gotoxy(23,32);
    printf(" |     ___/\\_  __ \\_/ __ \\ /  ___//  ___/   _<__  <   /  _ \\\\_  __ \\\\   /   |  |_ \\   __\\/  _ \\   \\_____  \\\\   __\\__  \\\\_  __ \\   __\\ \n");
    gotoxy(23,33);
    printf(" |    |     |  | \\/\\  ___/ \\___ \\ \\___ \\   /       \\ <  <_> >  | \\/ /    ^   /  |  | <  <_> >  _______  \\|  |  / __ \\|  | \\/|  |  ");
    gotoxy(23,34);
    printf(" |____|     |__|    \\___  >____  >____  > /______  /  \\____/|__|    \\____   |   |__|  \\____/  /_______  /|__| (____  /__|   |__|  \n");
    gotoxy(23,35);
    printf("                        \\/     \\/     \\/         \\/                      |__|                         \\/           \\/             \n");

    int n;
    scanf("%d",&n);
    system("cls");
    return n;
}

void _play4x4(){
    int rowstart = 30;
    int rowend = 114;
    int columnstart = 5;
    int columnend = 47;
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

int main(){
    system("title 2048_in_C"); // 프로세스 이름
    system("mode con: cols=180 lines=50"); // !콘솔창 크기
    system("COLOR 0F"); //!배경색, 글자색
    //_printtitle();
    //_printrules();
    int selected_round;
    selected_round = _printmain();
    if(selected_round == 4){
        _play4x4();
    }
    else{
        //_play5x5();
    }
}
