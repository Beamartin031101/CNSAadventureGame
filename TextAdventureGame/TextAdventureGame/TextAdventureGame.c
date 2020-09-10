// 줄을 그을 때는 리소스 파일의 txt을 참고해 주세요
// 한글은 영어 2자만큼의 칸을 차지하고, ASCII안에 있는 것들은 1자만큼의 칸을 사용합니다

// include --start--
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<Windows.h>
// include --end--

// fun --start--
void drawFrame();
void drawUp();
void drawMid();
void drawDown();
void gotoxy(int x, int y);
// fun --end--

// const --start--
const int WIDTH = 100;
const int HEIGHT = 25;
// const --end--


int run = 1;

int main() {
	drawFrame();
	return 0;
}

// 나머지는 안 건들여도 됨. 그냥 width값이랑 height값만 조작하면 사각형을 바꿀 수 있음. 
// 이것을 통해서 겉에 게임 상자를 만듬. (주의 - 반드시 글을 쓰고 프레임그리기를 작동시킬 것)
void drawFrame() {
	drawUp();
	drawMid();
	drawDown();
}

void drawUp() {
	gotoxy(0, 0);
	for (int i = 0; i <= WIDTH + 1; i++) {
		switch (i)
		{
		case 0:
			printf("┌"); 
			break;
		case 101 :
			printf("┐");
			break;
		default:
			printf("─");
			break;
		}
	}
}

void drawMid() {
	for (int i = 0; i < HEIGHT; i++) {
		gotoxy(0,i+1);
		printf("│");
		gotoxy(WIDTH +1,i+1);
		printf("│");
	}
}

void drawDown() {
	gotoxy(0, HEIGHT + 1);
	for (int i = 0; i <= WIDTH + 1; i++) {
		switch (i)
		{
		case 0:
			printf("└");
			break;
		case 101:
			printf("┘");
			break;
		default:
			printf("─");
			break;
		}
	}
}
void gotoxy(int x, int y) {
	COORD pos = { (short)x,(short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}