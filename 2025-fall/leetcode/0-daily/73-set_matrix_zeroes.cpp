// #include<vector>
// #include<queue>
// using namespace std;
// class Solution {
// public:
//     struct QNode{
//         int x,y;
//         QNode(int x1,int y1): x(x1), y(y1){}
//     };
//     void setZeroes(vector<vector<int>>& matrix) {
//         queue<QNode> my_que;
//         int m = matrix.size(), n = matrix[0].size();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(!matrix[i][j]) my_que.push(QNode(i,j));
//             }
//         }  
//         while(!my_que.empty()){
//             auto tmp = my_que.front();
//             for(int i = 0; i < m; i++){
//                 matrix[i][tmp.y] = 0;
//             }
//             for(int j = 0; j < n; j++){
//                 matrix[tmp.x][j] = 0;
//             }
//             my_que.pop();
//         }
//         return;
//     }
// };

#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> zeroRows(m, false);
        vector<bool> zeroCols(n, false);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (zeroRows[i] || zeroCols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};