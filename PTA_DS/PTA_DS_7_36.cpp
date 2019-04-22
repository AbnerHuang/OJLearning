#include <stdio.h>
#include <queue>

using namespace std;

#define MAXN 10001

bool graph[MAXN][MAXN];
bool visited[MAXN];

double BFS(int k,int node);

int main(void){
    int node,edge;
    scanf("%d %d",&node,&edge);
    for(int i = 1;i <= node;i++)
    {
        for(int j = 1;j <= node;j++)
        {
            graph[i][j] = false;
        }
        visited[i] = false;
    }
    for(int i = 0;i < edge;i++){
        int head,tail;
        scanf("%d %d",&head,&tail);
        graph[head][tail] = graph[tail][head] = 1;
    }
    int calcnum;
    scanf("%d",&calcnum);
    bool flag = false;
    for(int i = 0;i <calcnum;i++){
        int k;
        double cc;
        scanf("%d",&k);
        if(flag==false) {
            cc = BFS(k,node);
            printf("Cc(%d)=%0.2f\n",k,cc);
            }
        else printf("Cc(%d)=%0.2f\n",k,0.0);
        if(cc == 0) flag = true; 
    }
    return 0;
}

double BFS(int start,int node){
    for(int i = 1;i < MAXN;i++)
    {
        visited[i] = false;
    }
    queue<int> bfsqueue;
    int dis[node+1];int visit = 0;
    double sumdis = 0.0;
    visited[start] = true; 
    for(int i = 1;i <= node;i++){
        if(graph[start][i] == true && visited[i] == false){
            bfsqueue.push(i);
            dis[i] = 1;
            sumdis += dis[i];
            visit++;
            visited[i] = true;
            // printf("start:%d->node:%d:dis:%d\n",start,i,dis[i]);
        }
    }
    while(bfsqueue.size()>0){
        int cur = bfsqueue.front();
        bfsqueue.pop();
        for(int i = 1;i <= node;i++){
            if(graph[cur][i]== true && visited[i]==false){
                bfsqueue.push(i);
                dis[i] = dis[cur]+1;
                sumdis += dis[i];
                visit++;
                visited[i] = true;
            // printf("cur:%d->node:%d:dis:%d\n",cur,i,dis[i]);
            }
        }
    }
    double result = (double) (node - 1)/sumdis;
    if(visit != node - 1) return 0;
    else return result;
}