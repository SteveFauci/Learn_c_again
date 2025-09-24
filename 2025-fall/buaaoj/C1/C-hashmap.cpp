#include<cstdio>
#include<unordered_map>
#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    string temp;
    unordered_map<string,int> my_map;
    while(n--){
        cin>>temp;
        my_map[temp]++;
    }
    for(auto &p : my_map){
        if(p.second == 5){
            cout << p.first << endl;
        }
    }
    return 0;
}