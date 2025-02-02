/*
3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Input: s = "vdvf"
Output: 3
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;

class LeetProb3 {
public:

    int lengthOfLongestSubstring(string s) {
        unsigned int i=0, j=0, k =0, max=0;
        for(i=0; s[i]!=0; i++){
            for(j=i+1; s[j]!=0;j++){
                for(k=i; k<j&&s[j]!=s[k]; k++);
                    if(k!=j) {
                        break;
                    }
            }
            if(max < j-i) max = j-i;
        }            
        return max;        
    }
    //Following does not work for the last example "vdvf"
    int lengthOfLongestSubstring1(string s) {
        int l=0, max = 0;
        vector<int> indx = {0};
        unsigned int i=0, j=0;
        for(i=0; s[i]!=0; i++){
            for(j=indx[l]; j<i && s[i]!=s[j]; j++);
            if(j!=i) {indx.push_back(i); l++;}                   
        }
        indx.push_back(i);
        for(l=indx.size()-1; l>0; l--){
            if (max <= indx.at(l)-indx.at(l-1)) max = indx.at(l)-indx.at(l-1);
        }              
        return max;        
    }
};
void test_leet_prob3(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : LeetCode Problem 3                               " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    LeetProb3 p =LeetProb3();
    std::string s="thethemtheythesethethat";
    int l = p.lengthOfLongestSubstring(s);
    std::cout << "l = " << l <<std::endl;
}