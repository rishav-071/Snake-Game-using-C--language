#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
#include<conio.h>dd

int width=50,height=20,x,y,fx,fy,direct,score=0,end=0,piece=0;
int tx[100],ty[100],p;

void setup(){
    x=width/2;
    y=height/2;
    fx=rand()%47+2;
    fy=rand()%17+2;
}

void logic(){
    for(int i=piece-1;i>0;i--){
        tx[i]=tx[i-1];
        ty[i]=ty[i-1];
        for(int j=i-2;j>0;j--) if(tx[j]==tx[i] && ty[j]==ty[i]) end=1;
        for(int j=i+1;j<piece-1;j++) if(tx[j]==tx[i] && ty[j]==ty[i]) end=1;
    }
    tx[0]=x;
    ty[0]=y;
    switch(direct){
        case 1:{
            y--;
            break;
        }
        case 2:{
            x++;
            break;
        }
        case 3:{
            y++;
            break;
        }
        case 4:{
            x--;
            break;
        }
    }

    if(x==fx && y==fy){
        fx=rand()%47+2;
        fy=rand()%17+2;
        piece++;
        score++;
    }

    p=direct;

    if(x==1 || x==width || y==1 || y==height) end=1;
}

void direction(){
    if(kbhit()){
        switch(getch()){
            case 'w':{
                if(p!=3) direct=1;
                break;
            }
            case 'd':{
                if(p!=4) direct=2;
                break;
            }
            case 's':{
                if(p!=1) direct=3;
                break;
            }
            case 'a':{
                if(p!=2) direct=4;
                break;
            }
            case 'x':{
                end=1;
                break;
            }
        }
    }
}

void draw(){
    system("cls");
    for(int j=1;j<=height;j++){
        for(int i=1;i<=width;i++){
            if(j==height) printf("%c",-33);
            else if(i==1 || i==width || j==1) printf("%c",-37);
            else if(j==y && i==x) printf("%c",2);
            else if(i==fx && j==fy) printf("%c",-2);
            else{
                int ch=0;
                for(int k=1;k<=piece;k++){
                    if(i==tx[k-1] && j==ty[k-1]){
                        printf(".");
                        ch++;
                    }
                }
                if(ch==0) printf(" ");
            }
        }
        printf("\n");
    }
    printf("Score : %d",score);
}

int main(){
    setup();
    while(end==0){
        direction();
        draw();
        logic();
    }
    return 0;
}