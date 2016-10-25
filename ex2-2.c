#include <stdio.h>

void refresh(int tab[23][79],int uX,int uY){
    int i,j;
    for (i=0;i<23;i++){
        for (j=0;j<79;j++){
            if(tab[i][j]==1)        printf("X");
            else if(i==uX && j==uY) printf("O");
            else if(tab[i][j]==4)   printf("#");
            else                    printf(" ");
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    int tab[23][79]={0}, i, j, userC, uX, uY, msg, t=0;
    for (i=0;i<23;i++){
        for (j=0;j<79;j++){
            if(i==0 || i==22 || j==0 || j==78)
                tab[i][j]=1;
        }
    }
    for (i=0;i<30;i++){
        
        int x=rand()%19+2, y=rand()%75+2, z, flag=0;
        for (z=x-1;z<=x+1;z++){
            for (j=y-1;j<=y+1;j++){
                if (tab[z][j]==1) 
                    flag=1;
            }
        }
        if(flag==1) i--; 
        else tab[x][y]=1; 
    }
    for (i=0;i<20;i++){
        int x=rand()%20+2, y=rand()%76+2;
        if(tab[x][y]==1 || tab[x][y]==2) i--; 
        else tab[x][y]=2;
    }
    do{
        uX=rand()%21+1; uY=rand()%77+1;
    }while(tab[uX][uY]==1);
    refresh(tab,uX,uY); 
    do{
        printf("\n8-up,2-down,4-left,6-right,0-exit: ");
        msg=0; userC=10; fflush(stdin); scanf("%d",&userC);
        switch(userC){
            case 2:
                if(tab[uX+1][uY]==1) msg=2;
                else uX++;
                break;
            case 4:
                if(tab[uX][uY-1]==1) msg=4;
                else uY--;
                break;
            case 6:
                if (tab[uX][uY+1]==1) msg=6;
                else uY++;
                break;
            case 8:
                if (tab[uX-1][uY]==1) msg=8;
                else uX--;
                break;
            case 0:         
                break;
            default:        
                msg=3;
            }
        if(tab[uX][uY]==2){ 
            msg=1; t++; tab[uX][uY]=4;  
        }   
        refresh(tab,uX,uY); 
        switch(msg){
            case 1: printf("You found the treasure no%d",t);
                break;
            case 3: printf("Wrong Input");
                break;
            case 2: printf("Can't go down");
                break;
            case 4:  printf("Can't go left");
                break;
            case 6: printf("Can't go right");
                break;
            case 8: printf("Can't go up");
                break;
        }
    }while(userC!=0 && t<20); 
    if(t==20) printf("\nCongratulations! You have found all the treasures!");
    return 0;
}
