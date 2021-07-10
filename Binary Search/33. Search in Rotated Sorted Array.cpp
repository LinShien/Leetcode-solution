class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Modified binary search Time: O(logn), Space: O(1)
        // [3,4,5,6,7,0,1,2] target = 4
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[l] <= nums[mid]) {       // left half is well sorted
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {                          // right half is well sorted
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        
        return -1;
    }
};