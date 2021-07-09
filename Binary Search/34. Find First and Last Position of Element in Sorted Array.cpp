class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Binary Search Time: O(logn * 2), Space: O(1)
        return {find_first_occurrence(nums, target), find_last_occurrence(nums, target)};
    }
    
private:
    int find_first_occurrence(const vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int index = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
            
            if (nums[mid] == target) {
                index = mid;
            }
        }
        
        return index;
    }
    
    int find_last_occurrence(const vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int index = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            
            if (nums[mid] == target) {
                index = mid;
            }
        }
        
        return index;
    }
};