#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define WIDTH  20
#define HEIGHT 15

int snakeX[200],snakeY[200];
int length;
int foodX,foodY;
int dirX,dirY;
int i,x,y;

void spawnFood(){//刷新食物函数
    int ok=0;
    while(!ok){
        ok=1;
        foodX=rand()%WIDTH;
        foodY=rand()%HEIGHT;
        for(i=0;i<length;i++){
            if(foodX==snakeX[i]&&foodY==snakeY[i]){
                ok=0;
                break;//重新生成food
            }
        }
    }
}

void init(){//初始化函数
    length=3;
    snakeX[0] = 5, snakeY[0] = 5;
    snakeX[1] = 4; snakeY[1] = 5;
    snakeX[2] = 3; snakeY[2] = 5;
    dirX = 1; dirY = 0;
    srand(time(0));//根据开局时间生成srand
    spawnFood();
}

void draw(){//画格函数
    system("cls");
    for(y=0;y<HEIGHT;y++){
        for(x=0;x<WIDTH;x++){
            int printed=0;
            if(x==foodX&&y==foodY){
                printf("*");
                printed=1;
            }
            for(i=0;i<length&&!printed;i++){
                if(x==snakeX[i]&&y==snakeY[i]){
                    if(i==0)printf("O");
                    else    printf("o");
                    printed=1;
                }
            }
            if(printed==0)printf(" ");
        }
        printf("\n");
    }
    printf("长度: %d  用 WASD 控制\n", length);
}
void input(){//读取输入并控制方向
    char c;
    if(kbhit()){
        c=getch();
        if(c=='w'&& dirY != 1){dirX= 0;dirY=-1;}
        if(c=='s'&& dirY != -1) {dirX = 0; dirY = 1;}
        if(c=='a'&& dirX != 1) {dirX = -1; dirY = 0;}
        if(c=='d'&& dirX != -1) {dirX = 1; dirY = 0;}
    }
}
int moveSnake(){//蛇的移动
    int newX=snakeX[0]+dirX;
    int newY=snakeY[0]+dirY;
    if (newX<0||newX>=WIDTH||newY<0||newY>=HEIGHT)return 0;
    for(i=0;i<length-1;i++){
        if(snakeX[i]==newX&&snakeY[i]==newY)return 0;
    }
    for(i=length;i>0;i--){
        snakeX[i]=snakeX[i-1];
        snakeY[i]=snakeY[i-1];
    }
    snakeX[0]=newX;
    snakeY[0]=newY;
    if(newX==foodX&&newY==foodY){
        length++;
        spawnFood();
}
return 1;
}
int main(){//主函数
    init();
    while(1){
        draw();//食物函数的调用在画格函数里运行
        input();
        if(!moveSnake())break;
        Sleep(150);
    }
    printf("\n游戏结束！最终长度: %d\n", length);
    system("pause");
    return 0;
}