// Given an array of non-negative integers arr, you are initially positioned at start index of the array.
// When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

// Notice that you can not jump outside of the array at any time.

// Example 1:
// Input: arr = [4,2,3,0,3,1,2], start = 5
// Output: true
// Explanation: 
// All possible ways to reach at index 3 with value 0 are: 
// index 5 -> index 4 -> index 1 -> index 3 
// index 5 -> index 6 -> index 4 -> index 1 -> index 3 

// Example 2:
// Input: arr = [4,2,3,0,3,1,2], start = 0
// Output: true 
// Explanation: 
// One possible way to reach at index 3 with value 0 is: 
// index 0 -> index 4 -> index 1 -> index 3

// Example 3:
// Input: arr = [3,0,2,1,2], start = 2
// Output: false
// Explanation: There is no way to reach at index 1 with value 0.

// Constraints:
// 1 <= arr.length <= 5 * 10^4
// 0 <= arr[i] < arr.length
// 0 <= start < arr.length

// https://leetcode.com/problems/jump-game-iii/

// *********************************************************************
// DFS approach
// *********************************************************************
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited (arr.size(), false);
        return DFS(arr, visited, start);
    }
    
    bool DFS(vector<int>& arr, vector<bool>& visited, int index)
    {
        if(arr[index] == 0)
            return true;
        
        visited[index] = true;
        
        int leftIndex = index - arr[index];
        int rightIndex = index + arr[index];
        bool flag = false;
        
        if(leftIndex >= 0 && !visited[leftIndex])
            flag = DFS(arr, visited, leftIndex);
        if(!flag && rightIndex < arr.size() && !visited[rightIndex])
            flag = DFS(arr, visited, rightIndex);
        
        return flag;
    }
};

// *********************************************************************
// BFS approach
// *********************************************************************
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr.size() == 0)
            return false;
        
        return BFS(arr, start);
    }
    
    bool BFS(vector<int>& arr, int& idx)
    {
        queue<int> q1;
        q1.push(idx);
        vector<bool> visited (arr.size(), false);
        
        while(!q1.empty())
        {
            int qSize = q1.size();
            while(qSize--)
            {
                int currIdx = q1.front();
                q1.pop();
                
                if(arr[currIdx] == 0)
                    return true;
                
                visited[currIdx] = true;
                
                int nextIdx = currIdx + arr[currIdx];
                int prevIdx = currIdx - arr[currIdx];
                
                if(nextIdx < arr.size() && !visited[nextIdx])
                    q1.push(nextIdx);
                
                if(prevIdx >= 0 && !visited[prevIdx])
                    q1.push(prevIdx);
            }
        }
        return false;
    }
};
