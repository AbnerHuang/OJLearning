#include <stdio.h>

int main(void){
    // int maxsum = 0;
    int num = 0;
    scanf("%d",&num);
    int array[num];
    for(int i = 0;i < num;i++)
    {
        scanf("%d",&array[i]);
    }
    /** 算法1 **/
    // for(int i = 0;i < num;i++)
    // {
    //     for(int j = 0;j < num;j++)
    //     {
    //         int sum = 0;
    //         for(int k = i;k < j;k++)
    //         {sum += array[k];}
    //         if(sum>maxsum) {maxsum = sum;/*printf("%d\n",maxsum);*/}
    //     }
    // }
    /*** 算法二，去除算法一中的重复计算 **/
    // for(int i = 0;i < num;i++)
    // {
    //     int sum = 0;
    //     for(int j = i;j < num;j++)
    //     {
    //         sum += array[j];
    //         if(sum>maxsum) {maxsum = sum;}
    //     }
    // }
    /***  算法三 采用动态规划的思想 ***/
    int maxsum = array[0];
    int sum = array[0];
    for(int i = 1;i < num;i++)
    {
        if(sum+array[i]>array[i])
            sum += array[i];
        else
            sum = array[i];
        if(sum>maxsum)
            maxsum = sum;
    }
    printf("%d\n",maxsum);
}