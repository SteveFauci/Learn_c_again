#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int returnDist(vector<int>& pt1, vector<int>& pt2){
        return abs(pt1[0] - pt2[0]) + abs(pt1[1] - pt2[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        vector<vector<int>> my_mat(n,vector<int>(n,0));
        vector<int> inMST(n,0);
        vector<int> key(n,2147483647);
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                my_mat[i][j] = my_mat[j][i] = returnDist(points[i], points[j]);
            }
        }
        key[0] = 0;// inMST[0] = 1;
        for(int cnt = 0; cnt < n; cnt++){
            int nextNode = -1;
            for(int i = 0; i < n; i++){
                if(!inMST[i] && (nextNode == -1 || key[i] < key[nextNode])){
                    nextNode = i;
                }
            }
            inMST[nextNode] = 1;
            res += key[nextNode];
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && my_mat[nextNode][i] < key[i]) {
                    key[i] = my_mat[nextNode][i];
                }
            }
        }
        return res;
    }
};