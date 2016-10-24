#include <stdio.h>
int main(){
    int sum=0,i;
    for (i=1;i<=100;i++){
        sum+=i*i;
        if(i%20==0){
            printf("%d\n",sum);
        }
    }
    return 0;
}
