/*
10. Regular Expression Matching
Hard

Companies
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
*/
#include<iostream>
#include<string>
#include<climits>

class LeetProb10 {
public:
    bool isMatch(std::string s, std::string p) {
        int i=0, j=0;
        char ch;
        while(s[i]!=0 && p[j]!=0) {
            if(p[j]=='.' || s[i]==p[j]) {i++;}
            else if(p[j] == '*'){  
                ch = p[j-1];              
                while(s[i]!=0 && (s[i]==p[j-1]||p[j-1]=='.')) {i++;}
            } 
            j++;           
        }
        if(s[i]!=0) {
            return false;
        } else if (p[j]!=0){
            while(p[j]!=0 ) {j++;}
            if(p[j-1]!=ch) {
                return false;
            }else {
                return true;
            }
        } else {
            return true;
        }               
    }
};

void test_leet_prob10(){
    LeetProb10 p = LeetProb10();
    std::string str;
    std::string pattern;
    str = "aa";
    pattern = "a";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : "  << p.isMatch(str, pattern)<< " Ans: false" << std::endl;
    str = "aa";
    pattern = "a*";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: true" << std::endl;
    str = "ab";
    pattern = ".*";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: true" << std::endl;
    str = "aaa";
    pattern = "ab*a*c*a";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: true" << std::endl;
    str = "aab";
    pattern = "c*a*b";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: true " << std::endl;
    str = "ab";
    pattern = ".*c";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: false " << std::endl;
    str = "aaa";
    pattern = "a*a";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: true " << std::endl;
    str = "aab";
    pattern = "c*a**b";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: false " << std::endl;
    str = "a";
    pattern = "ab*";
    std::cout << "string: " << str << " Pattern: " << pattern << "    isMatch(str, pattern) : " << p.isMatch(str, pattern)<< " Ans: true " << std::endl;
    
}
 