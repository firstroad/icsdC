#include <stdio.h>

void display(char tab[5][5]){
    int i,j;
    for (i=0;i<6;i++){
        printf("+--+--+--+--+--+\n");
        if(i==5){break;}
        for(j=0;j<5;j++)
            printf("|%2c",tab[i][j]);
        printf("|\n");
    }
}

int check(int x, int y, char tab[5][5]){
    int i, j, temp=-1;
    if(x==y){
        for(i=0;i<4;i++){
            if (tab[i][i]!=tab[i+1][i+1]){
                temp=-1;
                break;
            }
            else temp=1;
        }
    }
    if(temp==1)return temp;
    if(x==4-y){
        for(i=0;i<4;i++){
            if(tab[i][4-i]!=tab[i+1][4-(i+1)]){
                temp=-1;
                break;
            }
            else temp=1;
        }
    }
    if(temp==1)return temp;
    for(i=0;i<4;i++){
        if(tab[x][i]!=tab[x][i+1]){
            temp=-1;
            break;
        }
        else temp=1;
    }
    if(temp==1)return temp;
    for(i=0;i<4;i++){
        if(tab[i][y]!=tab[i+1][y]){
            temp=-1;
            break;
        }
        else temp=1;
    }
    return temp;
}

int main(){
    char plr1[20], plr2[20], tab[5][5]={};
    int i, j, end=0, counter=0, x, y;
    printf("Insert the name of the 1st player: "); gets(plr1);
    printf("Insert the name of the 2nd player: "); gets(plr2);
    do{
        counter++;
        display(tab);
        do{
            printf("Player %s, insert x and y ( ex 4.5 )(1-5): ",(counter%2!=0)?plr1:plr2);
            x=10; y=10;
            fflush(stdin); scanf("%d.%d",&x,&y);
            x--; y--;
        }while(tab[x][y]!=0 || x<0 || x>4 || y<0 || y>4);
        tab[x][y]=(counter%2!=0)?'+':'-';
    }while(check(x,y,tab)==-1 && counter<25);
    if(check(x,y,tab)==1)
        printf("The winner is %s",(counter%2!=0)?plr1:plr2);
    else printf("Draw");
    return 0;
}
