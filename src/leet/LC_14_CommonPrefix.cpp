/*

14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

*/

#include<iostream>
#include<string>
#include<vector>

class LeetProb14 {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int l = strs[0].size();        
        for(std::vector<std::string>::iterator it=strs.begin(); it != strs.end(); it++){
            for(int i=0; i<l; i++){
                if ((*it)[i] != strs[0][i]) {
                    l = i;
                    break;
                }
            }
        }
        //std::cout << "minStr: " << minStr << "l = " << l << std::endl;
        return(strs[0].substr(0,l));
        
    }
};
void test_leet_prob14(){
    LeetProb14 p = LeetProb14();
    std::vector<std::string> strs ={"flower","flow","flight"};
    std::cout << p.longestCommonPrefix(strs) << std::endl;
    std::vector<std::string> strs1 ={"dog","racecar","car"};
    std::cout << p.longestCommonPrefix(strs1) << std::endl;

}