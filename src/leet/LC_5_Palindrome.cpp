
/*
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

*/
#include<iostream>
#include<string>

class Prob5 {
public:
    std::string longestPalindrome(std::string s) {
        int i,j,k,l;
        int max = 0;
        int len = s.size();
        std::string str;
        for(i=0; i<len; i++){
            for(j=i; j<len; j++){
                for(k=i,l=j; k<=l; k++,l--){
                    if(s[k]!=s[l]) break;
                }
                if(k>l){
                    //std::cout << str << std::endl;                   
                    if (max < j-i+1) {
                        max = j-i+1;
                        str="";
                        for(int indx=i; indx<=j; indx++)
                            str.push_back(s[indx]);
                        //std::cout << str << std::endl;
                    }
                }
            }
        }
        return str;
    }
};
void test_leet_prob5(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : LeetCode Problem 5                               " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    Prob5 p = Prob5();
    std::string str="babad";
    std::string pstr;
    pstr = p.longestPalindrome(str);
    std::cout << "Longest Palindrome String: " << pstr << std::endl;
    str="cbbd";
    pstr = p.longestPalindrome(str);
    std::cout << "Longest Palindrome String: " << pstr << std::endl;
}