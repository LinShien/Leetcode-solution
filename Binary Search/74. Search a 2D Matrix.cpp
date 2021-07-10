class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search the whole matrix Time: O(log(m*n)), Space: O(1)
        int l = 0;        
        int r = matrix.size() * matrix[0].size() - 1;
        const int col_size = matrix[0].size();
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (matrix[mid / col_size][mid % col_size] == target) {
                return true;
            } else if (matrix[mid / col_size][mid % col_size] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return false;
    }
};