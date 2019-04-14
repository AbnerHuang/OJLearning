#include <stdio.h>

int main(void){
    int heap[1000];
    int len = 0;
    int ele;
    int path;
    scanf("%d %d",&ele,&path);
    for(int i = 0;i < ele;i++)
    {
        int cur;
        scanf("%d",&cur);
        if(len == 0){
            heap[0] = cur;
            len++;
        }else{
            heap[len]=cur;
            len++;
            int idx = len-1;
            while(idx != 0){
                // printf("%d %d\n",cur,idx);
                int parent = (idx-1)/2;
                if(cur >= heap[parent]) {
                    // printf("heap[idx]:%d idx:%d heap[parent]:%d parent:%d and break\n",heap[idx],idx,heap[parent],parent);
                    break;
                    }
                heap[idx] = heap[parent];
                idx = parent;
            }
            heap[idx] = cur;
            // printf("finally:%d %d\n",cur,idx);
        }
    }
    // for(int i = 0;i < ele;i++){
    //     printf("%d ",heap[i]);
    // }
    // printf("\n");
    for(int i = 0;i < path;i++)
    {
        int pos;
        scanf("%d",&pos);
        pos = pos -1;
        while(pos!=0)
        {printf("%d ",heap[pos]);pos = (pos-1)/2;}
        printf("%d\n",heap[pos]);
    }
}