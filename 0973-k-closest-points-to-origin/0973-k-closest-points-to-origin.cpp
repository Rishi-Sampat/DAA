class Solution {
public:
    static int squaredDis(vector<int>& points) {
        return points[0] * points[0] + points[1] * points[1];
    }

    static bool cmp(vector<int>& p1, vector<int>& p2) {
        return squaredDis(p1) < squaredDis(p2);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), cmp);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};