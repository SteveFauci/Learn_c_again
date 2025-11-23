#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<pair<int,int>> courses;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        courses.push_back({a,b});
    }
    sort(courses.begin(), courses.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first; 
    });
    int cnt = 0;
    int last_end = -1;
    for(auto course : courses){
        if(course.first >= last_end){
            cnt++;
            last_end = course.second;
        }
    }
    cout << cnt;
}