/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (49.01%)
 * Likes:    23438
 * Dislikes: 654
 * Total Accepted:    3.4M
 * Total Submissions: 6.9M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findOccurence(const vector<int>& nums, int target, bool first) {
        int low = 0, high = nums.size() - 1;
        int mid, ans = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (first) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findOccurence(nums, target, true);
        int last = findOccurence(nums, target, false);
        return {first, last};
    }       
};
// @lc code=end

