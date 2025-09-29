#include <bits/stdc++.h>
#include <cmath>
using namespace std;
class Solution {
  public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int    sz = points.size();
        double max_area = -1.0;
        for (int i = 0; i < sz; i++) {
            auto p1 = points[i];
            for (int j = 0; j < sz; j++) {
                auto p2 = points[j];
                for (int k = 0; k < sz; k++) {
                    auto p3 = points[k];
                    max_area = max(max_area, 0.5 * (fabs(1.0 * p1[0] * (p2[1] - p3[1]) + 1.0 * p2[0] * (p3[1] - p1[1]) + 1.0 * p3[0] * (p1[1] - p2[1]))));
                }
            }
        }
        return max_area;
    }
};

