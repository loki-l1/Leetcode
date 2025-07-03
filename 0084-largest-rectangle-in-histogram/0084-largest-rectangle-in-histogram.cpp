class Solution {
public:
    vector<int> rightmin(vector<int> &heights, int n) {
        stack<int> s;
        vector<int> right(n);

        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return right;
    }
    vector<int> leftMin(vector<int> &heights, int n)

    {
        stack<int> s;
        vector<int> left(n);
        for (int i = 0; i < n; i++) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return left;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> r = rightmin(heights, n);
        vector <int> l= leftMin(heights, n);
        int max = 0;
        int curAr;
        for (int i = 0; i < n; i++) {
            curAr = heights[i] * (r[i] - l[i] - 1);
            if (curAr > max) {
                max = curAr;
            }
        }
        return max;
    }
};