#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(void){
    queue<int> oddqueue;    // odd queue is window A
    queue<int> evenqueue;   // even queue is window B
    int cusnum;int num;
    int time = 0;
    cin>>cusnum;
    for(int i = 0;i <  cusnum;i++)
    {
        cin>>num;
        if(num%2==0) evenqueue.push(num);
        else oddqueue.push(num);
    }
    while(oddqueue.size()>0 || evenqueue.size()>0)
    {
        time++;
        if(oddqueue.size()>0) {
            cout<<oddqueue.front();
            oddqueue.pop();
            if(oddqueue.size()+evenqueue.size() != 0) cout<<" ";
        }
        if(time%2==0){
            time=0;
            if(evenqueue.size()>0){
            cout<<evenqueue.front();
            evenqueue.pop();}
            if(oddqueue.size()+evenqueue.size() != 0) cout<<" ";
        }
    }
    cout<<endl;

}