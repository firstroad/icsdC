#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int i,lettersNum[26]={0};
    char *words[20];
    printf("Insert 20 words. Press Enter after every word you enter.\n");
    for(i=0;i<20;i++){
        char temp[50];
        char *tmp=temp;
        printf("%2d: ",i+1);
        scanf("%s",temp);
        words[i] = malloc(strlen(temp)*sizeof(char)+1);
        strcpy(words[i],tmp);
        int j=0;
        while(*(tmp+j)!='\0'){
            if(*(tmp+j)>=65 && *(tmp+j)<=90){lettersNum[(*(tmp+j)-65)]++;}
            if(*(tmp+j)>=97 && *(tmp+j)<=122){lettersNum[(*(tmp+j)-97)]++;}
            j++;
        }
        free(words[i]);
    }
    for(i=0;i<26;i++){
        printf("\n[%c]: ",i+65);
        int j;
        for(j=0;j<(lettersNum[i]/10);j++){printf("*");}
        for(j=0;j<(lettersNum[i]%10);j++){printf("-");}
    }
    return 0;
}
