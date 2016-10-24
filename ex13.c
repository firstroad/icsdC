#include <stdio.h>

void clean(){
    char ch;
    while( ( ch = getchar() ) != '\n' && ch != EOF );
}

int main (){
    int limit, i, j, temp, score, min, max, counter=0;
    char name, surname;
    do{
        limit=0;
        printf("Insert limit(1-100): ");
        scanf("%d",&limit);
        clean();
    }while(limit<1 || limit>100);
    for (i=1;i<=3;i++){
        do{
            printf("Insert the first letters of name and surname(ex. AP):\n");
            name = getchar();
            surname = getchar();
            clean();
        }while(!isalpha(name) || !isalpha(surname));
        score=0;
        for(j=1;j<=6;j++){
            do{
                printf("Member %d, insert your grade(1-100): ",j);
                scanf("%d",&temp);
                clean();
            }while(temp<1 || temp>100);
            if(j==1){min=temp; max=temp;}
            else if (min>temp) min=temp;
            else if (max<temp) max=temp;
            score+=temp;
        }
        score=(score-min-max)/4;
        if(score>=limit){printf("Singer %c%c is being promoted with %d points\n",name,surname,score);counter+=1;}
        else printf("Singer %c%c is not being promoted with %d points\n",name,surname,score);
    }
    printf("%d singers chosen and the percentage of the people that weren't chosen is %d%%",counter,((3-counter)*100)/3);
    return 0;
}
