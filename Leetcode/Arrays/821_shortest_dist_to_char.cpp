// Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

// Example 1:
// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

// Note:
// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.

// https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        
        vector<int> retVec (n, INT_MAX);
        
        // Initialize pos to >= abs(n)
        // It gets overwritten in two passes
        int pos = -n;
        
        // Forward pass
        for(int i=0; i<S.size(); i++)
        {
            if(S[i] == C)
                pos = i;
            
            retVec[i] = i - pos;
        }
        
        // Backward pass
        for(int i=pos-1; i>=0; i--)
        {
            if(S[i] == C)
                pos = i;
            
            retVec[i] = min(retVec[i], pos - i);
        }
        
        return retVec;
    }
};