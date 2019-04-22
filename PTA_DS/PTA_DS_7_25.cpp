#include <stdio.h>

int main(void){
    int stunum,clunum;
    scanf("%d %d",&stunum,&clunum);
    int unionset[stunum+1];
    int count[stunum+1];
    for(int i = 1;i <= stunum;i++){
        unionset[i] = i;
        count[i] = 0;
    }
    for(int i = 1;i <= clunum;i++){
        int memnum;
        scanf("%d",&memnum);
        int root;
        for(int j = 0;j<memnum;j++){
            int curnum,rootcur;
            scanf("%d",&curnum);
            rootcur = curnum;
            while(rootcur != unionset[rootcur]){
                rootcur = unionset[rootcur];
            }
            if(j != 0 && rootcur!= root) {
                unionset[rootcur] = root;
            }
            else {
                root = rootcur;
            }
        }
    }
    int maxnum = 0;
    for(int i = 1;i<=stunum;i++)
    {
        int idx = i;
        while(unionset[idx] != idx){
            idx = unionset[idx];
        }
        count[idx]++;
        if(count[idx] > maxnum) maxnum = count[idx];
    }
    printf("%d\n",maxnum);
    return 0;
}

// #define MAXSTU 30001
// #define MAXCLU 1001

// bool relation[MAXSTU][MAXCLU];
// bool visited[MAXSTU];

// int main(void){
//     int stunum,clunum;
//     scanf("%d %d",&stunum,&clunum);
//     for(int i = 1;i <= stunum;i++)
//     {
//         for(int j = 1;j<=clunum;j++)
//         {
//             relation[i][j] = false;
//         }
//         visited[i] = false;
//     }
//     for(int i = 1;i <= clunum;i++){
//         int memnum;
//         scanf("%d",&memnum);
//         for(int j = 0;j<memnum;j++){
//             int curmem;
//             scanf("%d",&curmem);
//             relation[curmem][i] = true;
//         }
//     }
//     int maxnum = 0;
//     for(int i = 1;i <=clunum;i++){
//         int count = 0;
//         for(int j = 1;j<=stunum;j++){
//             if(relation[j][i]==true&&visited[j]==false){
//                 count++;
//                 for(int k = 1;k<=stunum;k++){
//                     if(relation[k][i]==true&&k!=j)
//                     count++;
//                 }
//                 visited[j] = true;
//             }
//         }
//         printf("club%d:%d\n",i,count);
//         if(count>maxnum) maxnum = count;
//     }
//     printf("%d\n",maxnum);
//     return 0;
// }