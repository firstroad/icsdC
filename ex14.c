#include <stdio.h>
int main (){
    char temp;
    int par=0,guil=0,dash=0,x=1,y=1;
    do {
        temp = getchar();
        switch (temp) {
            case '(': par++; break;
            case ')': par--; break;
            case '«': guil++; break;
            case '»': guil--; break;
            case '-': if(dash==0){dash--;} else dash++; break;
            case '\n': x++;y=0; break;
        }
        if(temp==')' && par<0){
            printf("Closing parenthesis on line %d and column %d without opening one.\n",x,y);
            par++;
        }
        else if(temp=='»' && guil<0){
            printf("Closing guillemet on line %d and column %d without opening one.\n",x,y);
            guil++;
        }
        y++;
    }while(temp!=EOF);
    if (par>0 || guil>0 || dash>0){
        printf("%d parentheses/h,\n%d guillemets/o\nand %d dashes are open",par,guil,dash);
    }
    return 0;
}
