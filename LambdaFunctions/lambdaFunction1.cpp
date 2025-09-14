
class Solution {
 public:
  // double triangleArea(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
  //     return 0.5 * abs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) +
  //                      p3[0] * (p1[1] - p2[1]));
  // }

  double largestTriangleArea(vector<vector<int>>& points) {
    double mx_area = 0.0;
    int n = points.size();

    // cout << fixed << setprecision(5);

    auto triangleArea = [&](vector<int>& p1, vector<int>& p2,
                            vector<int>& p3) -> double {
      return 0.5 * abs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) +
                       p3[0] * (p1[1] - p2[1]));
    };

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          vector<int> point1 = points[i];
          vector<int> point2 = points[j];
          vector<int> point3 = points[k];

          double a1 = triangleArea(point1, point2, point3);
          mx_area = max(mx_area, a1);
        }
      }
    }

    return mx_area;
  }
};

/*
Note :


& inside [] means capture all outer variables by reference
(so the lambda can access points, mx_area, etc. directly by reference).

But in your case, you don’t use any outer variables inside the lambda.
All needed data is passed as parameters (p1, p2, p3).



*/