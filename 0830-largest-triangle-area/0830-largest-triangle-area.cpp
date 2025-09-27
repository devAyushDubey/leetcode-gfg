class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        int i = 0, j = 0, k = 0;
        for(i=0; i<n-2; i++) {
            vector<int> p1 = points[i];
            for(j = i+1; j<n-1; j++) {
                vector<int> p2 = points[j];
                for(k=j+1; k<n; k++) {
                    vector<int> p3 = points[k];
                    double f1 = (p2[1] - p3[1])/2.0;
                    double f2 = (p3[1] - p1[1])/2.0;
                    double f3 = (p1[1] - p2[1])/2.0;
                    double area = abs((p1[0]*f1) + (p2[0]*f2) + (p3[0]*f3));
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};