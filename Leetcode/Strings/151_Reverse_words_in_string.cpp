// Given an input string, reverse the string word by word.

// Example 1:
// Input: "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// https://leetcode.com/problems/reverse-words-in-a-string/


// Solution 1:
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string revString = "";
        
        while(ss>>word)
        {
            if(revString.size() == 0)
                revString += word;
            else
                revString = word + " " + revString;
        }        
        return revString;
    }
};

// Solution 2
class Solution {
public:
    string reverseWords(string s) {
        string revString;
        string word;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != ' ')
                word += s[i];
            else
            {
                if(revString.length() == 0)
                    revString += word;
                else
                    revString = word + " " + revString;
                word = "";
                while(s[i+1] == ' ' && i+1<s.length())
                    i++;
            }
        }
        if(word != "" && revString != "")
            word += " ";
        revString = word + revString;
        return revString;
    }
};
