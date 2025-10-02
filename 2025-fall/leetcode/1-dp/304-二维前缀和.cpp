#include <bits/stdc++.h>
using namespace std;
class NumMatrix {
  private:
    vector<vector<int>> sum;
  public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        sum.resize(m + 1,vector<int>(n+1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1];
    }
};

// class NumMatrix {
//   private:
//     vector<vector<int>> my_mat;
//     int sum = 0;
//   public:
//     NumMatrix(vector<vector<int>>& matrix) {
//         if(matrix.size()==0)return;
//         my_mat = matrix;
//     }
//     int sumRegion(int row1, int col1, int row2, int col2) {
//         if(my_mat.empty())return 0;
//         sum = 0;
//         for(int i = row1; i <=row2; i++){
//             for(int j = col1; j <=col2; j++){
//                 sum+=my_mat[i][j];
//             }
//         }
//         return sum;
//     }
// };
