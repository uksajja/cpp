/*
9. Palindrome Number
Easy

Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
*/
#include<iostream>
#include<string>
#include<climits>


class LeetProb9 {
public:
    bool isPalindrome(int x) {        
        if(x<0) return false;
        int r=0, y=x;
        while(y>0){
            if(r > INT_MAX/10) {
                return false;
            } else {
                r = r*10;
            }
            if( r > INT_MAX - y%10){
                return false;
            } else{
                r = r+y%10;
            }            
            y = y/10;
        }
        if(x==r){
            return true;
        } else {
            return false;
        }  
    }
};

void test_leet_prob9(){
    LeetProb9 p = LeetProb9();
    std::cout << "Is Palindrome (121) : " << p.isPalindrome(121) << std::endl;
    std::cout << "Is Palindrome (-121) : " << p.isPalindrome(-121) << std::endl;
}