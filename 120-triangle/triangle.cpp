class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Start from the second last row and move upwards
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < triangle[row].size(); ++col) {
                // Choose the minimum path sum of the two elements just below
                triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
            }
        }
        // The top element will have the minimum path sum
        return triangle[0][0];
    }
};
