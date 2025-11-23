#include<bits/stdc++.h>
#include <cctype>
#include <queue>
using namespace std;

int main(){
    vector<long long> count(52,0);
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF){
        if(isupper(ch)){
            count[ch - 'A' + 26]++;
        }else if(islower(ch)){
            count[ch - 'a']++;
        }
    }
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < 52; i++){
        if(count[i] > 0){
            pq.push(count[i]);
        }
    }
    if(pq.size() <= 1){
        cout << 0;
        return 0;
    }
    long long unsigned totalLen = 0;
    while(pq.size() > 1){
        long long node1 = pq.top(); pq.pop();
        long long node2 = pq.top(); pq.pop();
        pq.push(node1 + node2);
        totalLen += node1 + node2;
    }
    cout << totalLen << endl;
}