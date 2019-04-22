#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void){
    int num;
    map<string,int> treemap;
    cin>>num;
    getchar();
    for(int i = 0 ; i < num ;i++){
        string str;
        getline(cin,str);
        treemap[str]++;
    }
    for(map<string,int>::iterator it = treemap.begin(); it!= treemap.end(); it++){
        printf("%s %.4f%\n",it->first.c_str(),(double)it->second*100/num);
    }
    return 0;
}