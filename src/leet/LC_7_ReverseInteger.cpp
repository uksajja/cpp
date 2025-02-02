/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1

*/


#include<iostream>
#include<cmath>

class LeetProb7 {
public:
    int reverse(int x) {
       if(x<=INT_MIN || x>=INT_MAX || x==0){
            return 0;
        }    
        int y = x>0 ? x : -x;
        int r=0;
        while(y>0) {
            if(r > INT_MAX/10) {
                return 0;
            } else {
                r = r*10;
            }
            if( r > INT_MAX - y%10){
                return 0;
            } else{
                r = r+y%10;
            }            
            y = y/10;
        }
       return(x>=0?r:-r);
    }
};
void test_leet_prob7() {
    LeetProb7 p= LeetProb7();
    std::cout << "INT_MIN:  " << INT_MIN << " INT_MAX: " << INT_MAX << std::endl;
    int x = -std::pow(2, 31);
    std::cout << "x:  " << x << " reverse: " << p.reverse(x) << std::endl;
    int y = std::pow(2, 31)-1;
    std::cout << "y:  " << y << " reverse: " << p.reverse(y) << std::endl;
    int z = std::pow(2, 31)-2;
    std::cout << "z:  " << z << " reverse: " << p.reverse(z) << std::endl;
    
    int w = 2147447412;
    std::cout << "w:  " << w  <<  " reverse: " << p.reverse(w) << std::endl;
    int l = -2147447412;
    std::cout << "l:  " << l <<  " reverse: " << p.reverse(l) << std::endl;
    int m = 1234567899;
    std::cout << "m:  " << m <<  " reverse: " << p.reverse(m) << std::endl;
}