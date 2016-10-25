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

void pvp(){
    fflush(stdin);
    char plr1[20], plr2[20], tab[5][5]={};
    int i, j, end=0, counter=0, x, y;
    printf("Insert the name of the 1st player: "); gets(plr1);
    printf("Insert the name of the 2nd player: "); gets(plr2);
    do{
        counter++;
        display(tab);
        do{
            printf("Player %s insert x and y ( ex 4.5 )(1-5): ",(counter%2!=0)?plr1:plr2);
            x=10; y=10;
            fflush(stdin); scanf("%d.%d",&x,&y);
            x--; y--;
        }while(tab[x][y]!=0 || x<0 || x>4 || y<0 || y>4);
        tab[x][y]=(counter%2!=0)?'+':'-';
    }while(check(x,y,tab)==-1 && counter<25);
    if(check(x,y,tab)==1)
        printf("Winner is %s",(counter%2!=0)?plr1:plr2);
    else printf("Draw");
}

void cpu(char tab[5][5],int *px,int *py){
    srand(time(NULL));
    int x,y,i;
    do{
        if(*px>5){
            x=2; y=2;
            break;
        }
        int flagX=0,flagY=0;

        for(i=0;i<5;i++){
            if(tab[*px][i]=='-')flagX++;
            if(tab[i][*py]=='-') flagY++;
        }

        if(flagX==4){
            for(i=0;i<5;i++){
                if(tab[*px][i]==0){
                    x=*px;
                    y=i;
                }
            }
        }

        else if(flagY==4){
            for(i=0;i<5;i++){
                if(tab[i][*py]==0){
                    x=i;
                    y=*py;
                }
            }
        }

        else{
            int j,flag=0;
            for(i=*px-1;i<*px+1;i++){
                for(j=*py-1;j<*py+1;j++){
                    if(tab[i][j]==0)flag=1;
                }
            }
            if(flag==1){
                x=*px+(rand()%3-1);
                y=*py+(rand()%3-1);
            }
            else {
                x=rand()%5;
                y=rand()%5;
            }
        }
    }while(tab[x][y]!=0 || x<0 || x>4 || y<0 || y>4);
    *px=x; *py=y; tab[x][y]='+';
}

void pvcpu(){
    fflush(stdin);
    char plr[20], tab[5][5]={};
    int i, j, end=0, counter=0, x, y, *px=&x, *py=&y;
    printf("Insert your name: "); gets(plr);
    do{
        counter++;
        if(counter%2==0){
            do{
            printf("Insert x and y ( ex 4.5 )(1-5): ");
            x=10; y=10;
            fflush(stdin); scanf("%d.%d",&x,&y);
            x--; y--;
        }while(tab[x][y]!=0 || x<0 || x>4 || y<0 || y>4);
        tab[x][y]='-';
        }
        else {
            cpu(tab,px,py);
            display(tab);
        }
    }while(check(x,y,tab)==-1 && counter<25);
    if(check(x,y,tab)==1){
        if(counter%2==0)display(tab);
        printf("The winner is %s",(counter%2==0)?plr:"CPU");
    }
    else printf("Draw");
};

int main(){
    int choice;
    do{
        printf("\nInsert 1 to play with another player or 2 to play with your pc or 0 to exit: ");
        fflush(stdin); scanf("%d",&choice);
        if(choice==1)
            pvp();
        else if(choice==2)
            pvcpu();
        else if(choice==0)
            return 0;
    }while(choice!=0);
}
