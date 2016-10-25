#include <stdio.h>

int main(){
    int n,i,j;
    do{
        printf("Insert an odd number to display its magic square: ");
        scanf("%d",&n);
    }while(n%2==0 || n<3);

    int grammh = n-1,sthlh = n/2,tab[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            tab[i][j]=0;
    }

    for(j=1;j<=n*n;j++){
        tab[grammh][sthlh]=j;
        int x=grammh, y=sthlh;
        grammh++; sthlh++;
        if(grammh==n) grammh=0;
        if(sthlh==n) sthlh=0;
        if(tab[grammh][sthlh]!=0){
            grammh=x-1;
            sthlh=y;
        }
    }

    for(i=0;i<n+1;i++){
        for(j=0;j<n;j++)
            printf("+----");
        printf("+\n");
        if(i==n)break;
        printf("|");
        for(j=0;j<n;j++)
            printf("%4d|",tab[i][j]);
        printf("\n");
    }
    return 0;
}
