#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<stdbool.h>

struct Pair{
    int num;
    char color[10];
    bool isSpecial;
    char property[20];
}cards_set[50];

void gotoxy(int x, int y){
    COORD Pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void _setCommonCards(){
    // 0: 빨강 0, 1~18 : 빨강 1~9 2개씩,
    int idx = 0;
    //red set
    // 숫자 0 카드
    cards_set[idx].num = 0;
    strcpy(cards_set[idx].color, "red");
    cards_set[idx].isSpecial = false;
    idx++;
    //숫자 1~9 카드
    for(int i=1;i<=9;i++){
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "red");
        cards_set[idx].isSpecial = false;
        idx++;
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "red");
        cards_set[idx].isSpecial = false;
        idx++;
    }
    //+2 카드
    strcpy(cards_set[idx].color, "red");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    strcpy(cards_set[idx].color, "red");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    //순서 바꾸기
    strcpy(cards_set[idx].color, "red");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    strcpy(cards_set[idx].color, "red");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    //건너뛰기
    strcpy(cards_set[idx].color, "red");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;
    strcpy(cards_set[idx].color, "red");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;

    //yellow set
    // 숫자 0 카드
    cards_set[idx].num = 0;
    strcpy(cards_set[idx].color, "yellow");
    cards_set[idx].isSpecial = false;
    idx++;
    //숫자 1~9 카드
    for(int i=1;i<=9;i++){
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "yellow");
        cards_set[idx].isSpecial = false;
        idx++;
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "yellow");
        cards_set[idx].isSpecial = false;
        idx++;
    }
    //+2 카드
    strcpy(cards_set[idx].color, "yellow");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    strcpy(cards_set[idx].color, "yellow");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    //순서 바꾸기
    strcpy(cards_set[idx].color, "yellow");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    strcpy(cards_set[idx].color, "yellow");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    //건너뛰기
    strcpy(cards_set[idx].color, "yellow");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;
    strcpy(cards_set[idx].color, "yellow");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;

    //green set
    // 숫자 0 카드
    cards_set[idx].num = 0;
    strcpy(cards_set[idx].color, "green");
    cards_set[idx].isSpecial = false;
    idx++;
    //숫자 1~9 카드
    for(int i=1;i<=9;i++){
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "green");
        cards_set[idx].isSpecial = false;
        idx++;
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "green");
        cards_set[idx].isSpecial = false;
        idx++;
    }
    //+2 카드
    strcpy(cards_set[idx].color, "green");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    strcpy(cards_set[idx].color, "green");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    //순서 바꾸기
    strcpy(cards_set[idx].color, "green");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    strcpy(cards_set[idx].color, "green");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    //건너뛰기
    strcpy(cards_set[idx].color, "green");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;
    strcpy(cards_set[idx].color, "green");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;

    //blue set
    // 숫자 0 카드
    cards_set[idx].num = 0;
    strcpy(cards_set[idx].color, "blue");
    cards_set[idx].isSpecial = false;
    idx++;
    //숫자 1~9 카드
    for(int i=1;i<=9;i++){
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "blue");
        cards_set[idx].isSpecial = false;
        idx++;
        cards_set[idx].num = i;
        strcpy(cards_set[idx].color, "blue");
        cards_set[idx].isSpecial = false;
        idx++;
    }
    //+2 카드
    strcpy(cards_set[idx].color, "blue");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    strcpy(cards_set[idx].color, "blue");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "+2");
    idx++;
    //순서 바꾸기
    strcpy(cards_set[idx].color, "blue");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    strcpy(cards_set[idx].color, "blue");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "change_order");
    idx++;
    //건너뛰기
    strcpy(cards_set[idx].color, "blue");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;
    strcpy(cards_set[idx].color, "blue");
    cards_set[idx].isSpecial = true;
    strcpy(cards_set[idx].property, "skip");
    idx++;

    //black card set

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
    gotoxy(50,5);
    printf(".______       __    __   __       _______     _______.\n");
    gotoxy(50,6);
    printf("|   _  \\     |  |  |  | |  |     |   ____|   /       |\n");
    gotoxy(50,7);
    printf("|  |_)  |    |  |  |  | |  |     |  |__     |   (----`\n");
    gotoxy(50,8);
    printf("|      /     |  |  |  | |  |     |   __|     \\   \\    \n");
    gotoxy(50,9);
    printf("|  |\\  \\----.|  `--'  | |  `----.|  |____.----)   |   \n");
    gotoxy(50,10);
    printf("| _| `._____| \\______/  |_______||_______|_______/    \n");
    Sleep(1000);
    gotoxy(50,17);
    printf("1. 이 게임은 play2048.co의 2048을 토대로 만들어졌습니다.");
    Sleep(500);
    gotoxy(52,19);
    printf("2. 수가 2048인 블록이 만들어지면 게임이 종료됩니다.");
    Sleep(500);
    gotoxy(60,21);
    printf("3. WASD를 이용해 조작합니다.");
    Sleep(500);
    gotoxy(63,23);
    printf("4. 게임을 즐기세요 !");
    Sleep(1000);
    system("cls");
}

int main(){
    system("title Uno_in_C"); // 프로세스 이름
    system("mode con: cols=200 lines=50"); // !콘솔창 크기
    system("COLOR 0F"); //!배경색, 글자색
    _setCommonCards();
    _printtitle();
    _printrules();

}
