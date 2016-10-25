#include <stdio.h>
#include <stdlib.h>

int mystrlen(char *s){
    int counter = 0;
    while(*s!='\0'){
        *s++;
        counter++;
    }
    return counter;
}
int mystrcmp(char *s1, char *s2){
    int i;
    for(i=0;i<mystrlen(s1);i++){
        if(*(s1+i)==*(s2+i)){
            *s1++; *s2++;
        }
        else return -1;
    }
    return 0;
}
char *mystrcat(char *s1, char *s2){
    while(*s1){
        s1++;
    }
    while(*s2){
        *s1 = *s2;
        s2++;
        s1++;
    }
    *s1 = '\0';
    return s1;
}
int mystrstr(char *s1, char *s2){
    int i,l1=mystrlen(s1),l2=mystrlen(s2),counter=0;
    for(i=0;i<l1;i++){
        if(*(s1+i)==*(s2+counter)){
            counter++;
            if(counter==l2){ return 1; }
        }
        else counter=0;
    }
    return -1;
}
int main(){
    char string1[] = "ICSD";
    char string2[] = "ICSD";
    char string3[] = "Information and Communication Systems Engineering";
    char string4[] = "hgfhjfjg";
    char string5[] = "Information";
    printf("mystrlen: The length of \"%s\" is %d\n",string1,mystrlen(string1));
    printf("mystrcmp: 0=Same, -1=Different : %d\n",mystrcmp(string1,string2));
    printf("mystrcat: \"%s\" and \"%s\" = ",string1,string2); mystrcat(string1,string2);printf("\"%s\"\n",string1);
    printf("mystrstr: \"%s\" doesn't belong to \"%s\" so %d\n",string4,string3,mystrstr(string3,string4));
    printf("mystrstr: \"%s\" belongs to \"%s\" so %d",string5,string3,mystrstr(string3,string5));
    return 0;
}
