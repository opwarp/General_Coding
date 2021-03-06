// Given an array nums and a value val, remove all instances of that value in-place and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.
// Example 1:
// Given nums = [3,2,2,3], val = 3,
// Your function should return length = 2, with the first two elements of nums being 2.

// https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int s=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == val)
                s++;
            else
                nums[i-s] = nums[i];
        }
        return nums.size()-s;
    }
};

// Solution 2:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] != val)
                nums[start++] = nums[i];
        }
        return start;
    }
};
