#include <stdio.h>
int main(){
    srand(time(NULL));
    int x, no1, no2, plr1score=0, plr2score=0, winner=0;
    do {
        x=rand()%100+1;
        do {
            printf("Player 1, insert number (1-100): ");
            scanf("%d",&no1);
            printf("Player 2, insert number (1-100): ");
            scanf("%d",&no2);
        }while(no1>100 || no1<1 || no2<1 || no2>100);
        if (abs(no1-x)<abs(no2-x)) plr1score++;
        else if (abs(no2-x)<abs(no1-x)) plr2score++;
        printf("Secret number: %d Score: %d-%d\n",x,plr1score,plr2score);
        if (plr1score==5){winner=1;}
        else if (plr2score==5){winner=2;}
    }while(winner==0);
    printf("Player %d won!!!",winner);
    return 0;
}
