#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    vector<vector<int>> dif(n + 2, vector<int>(n + 2, 0));
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        dif[x1][y1]++;
        dif[x1][y2 + 1]--;
        dif[x2 + 1][y1]--;
        dif[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dif[i][j] += dif[i - 1][j] + dif[i][j - 1] - dif[i - 1][j - 1];
            cout << dif[i][j] << ' ';
        }
        cout << endl;
    }
}