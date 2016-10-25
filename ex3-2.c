#include <stdio.h>
#include <string.h>

int main(){
    srand(time(NULL));
    int found=0,tries=10;
    char *words[20]={"device","information","computer","programmer","library","file","project","robotics","processor","memory","compiler","technology","cloud","service","application","electronics","server","client","report","cryptography"};
    do{
        int curWord;
        do{curWord = rand()%20;}while(words[curWord]==" ");
        int i,j=strlen(words[curWord]),x,counter;
        char temp[50]={0},answer[50];
        for(i=0;i<j;i++){
            do{x=rand()%j;
            }while(temp[x]!=0);
            temp[x]=*(words[curWord]+i);
        }
        printf("%s\n",temp);
        do{
            counter = 0;
            scanf("%s",&answer);
            char *tmp=answer;
            for(i=0;i<j;i++){
                if(*(tmp+i)==*(words[curWord]+i)){
                    counter++;
                }
            }
            if(counter!=j){
                tries--;
                printf("%d of the letters are in correct place. %d more tries\n",counter,tries);
            }
            else if(counter==j){
                found++;
                printf("You found the word\n");
                words[curWord]=" ";
            }
        }while(counter!=j && tries!=0);
    }while(found!=5 && tries!=0);
    if(found==5)
        printf("Excellent, you found all the words!");
    else
        printf("I'm sorry, no more tries!");
    return 0;
}
