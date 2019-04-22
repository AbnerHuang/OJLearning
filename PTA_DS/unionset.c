// a file contains operations for disjoint-set
#include <stdio.h>

#define MAXN 100001

int father[MAXN];

void initialize(){
    for(int i = 0;i < MAXN;i++){
        father[i] = i;//assign the element itself as its the parent node
    }
}

// return the root node number of node x
int findRoot(int x){
    int idx = x;
    while(father[idx]!=idx){
        // when the parent node num does not equal num itself
        // it is yet not root node
        idx = father[idx];
        // turn the the parent node
    }
    return idx;
}

void unite(int a,int b){
    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA != rootB)
        father[rootA] = rootB;
}

int findfatherCompress(int x) {
    int idx = x;
    while(father[x] != x){
        x = father[x];
    }//when out of the cycle , x is the root node num

    while(father[idx]!=idx){
        int pos = father[idx];//record the parent node
        father[idx] = x; // assign root node to current node
        idx = pos; // process the original parent node next cycle 
    }

}

int main(void){
    
}

