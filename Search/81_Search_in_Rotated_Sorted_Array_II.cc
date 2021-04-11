// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
// solution: two binary search
class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 1)
            return nums[0] == target;
       
        int low = 0, high = n-1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            } else if (nums[mid] >= nums[low]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }

};
