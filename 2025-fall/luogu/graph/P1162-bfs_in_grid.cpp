#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node{
    int x,y;
    Node(int x1, int y1):x(x1),y(y1){}
};
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> grid[i][j]; 
        }
    }
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<Node> myQue;
    for(int i = 0; i < n; i++){
        if(grid[i][0] == 0) myQue.push(Node(i,0));
        if(grid[i][n - 1] == 0)myQue.push(Node(i,n - 1));
        visited[i][0] = 1;
        visited[i][n - 1] = 1;
    }
    for(int j = 0; j < n; j++){
        if(grid[0][j] == 0) myQue.push(Node(0,j));
        if(grid[n - 1][j] == 0)myQue.push(Node(n - 1,j));
        visited[0][j] = 1;
        visited[n - 1][j] = 1;
    }
    while(!myQue.empty()){
        Node temp = myQue.front();
        myQue.pop();
        for(int i = 0; i < 4; i++){
            int x = temp.x + dx[i];
            int y = temp.y + dy[i];
            if(x < 0 || x >= n || y < 0 || y >= n || visited[x][y] == 1 || grid[x][y] == 1){
                continue;
            }
            myQue.push(Node(x,y));
            visited[x][y] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] && !grid[i][j]){
                cout << "0 ";
            }else if(grid[i][j]){
                cout << "1 ";
            }else{
                cout << "2 ";
            }
        }
        cout << endl;
    }
    return 0;
}