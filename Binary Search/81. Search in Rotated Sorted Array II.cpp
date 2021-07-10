class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Modified binary search Time: worst case O(n) (all elements are the same), Space: O(1)
        // [3 1 2 3 3 3 3] target = 2
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
                     
            if (nums[l] < nums[mid]) {
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[l] == nums[mid]) {  // eliminate the duplicate elements which would not affect our final result
                ++l;
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        
        return false;
    }
};