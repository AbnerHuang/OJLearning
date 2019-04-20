#include <stdio.h>

int main(void){
    int num,exp;
    int cycle = 0;
    while(scanf("%d %d",&num,&exp)!=EOF){
        if(exp!=0 && num!=0) cycle++;
        if(cycle!=1&&cycle!=0&&exp!=0&&num!=0) printf(" ");
        if(exp==0 || num ==0) continue;
        else{
            printf("%d %d",num*exp,exp-1);
        }
    }
    if (cycle!=0) printf("\n");
    else printf("0 0\n");
}