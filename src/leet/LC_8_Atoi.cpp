
/*

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/


#include<iostream>
#include<string>
#include<climits>


class LeetProb8 {
public:
    int myAtoi(std::string s) {
        int num = 0, i=0, j=0;
        while (s[i]!=0 && s[i]==32) i++;
        if(s[i]!=0 ) {
            if (s[i]==45){
                j=-1; i++;
            } else if (s[i]==43){
                j=1;i++;
            }            
        }
        while(s[i]!=0){            
            if(s[i]>=48 && s[i]<=57 ) {
                if (j>=0){ //positive number
                    if(num > INT_MAX/10){
                        num = INT_MAX;                        
                    } else {
                        num = num*10;
                        if(num >= INT_MAX - (s[i]-48)){//parenthesis is very important
                            num = INT_MAX;
                        } else {
                            num = num + (s[i]-48);//parenthesis is very important
                        }                        
                    }                                       
                } else {//negative number
                    if(num <= INT_MIN/10){
                        num = INT_MIN;                        
                    } else {
                        num = num*10;               
                        if(num  <= INT_MIN + (s[i]-48)){ //parenthesis is very important
                            num = INT_MIN;
                        } else {
                            num = num -(s[i]-48); //parenthesis is very important
                        }
                    }    
                }
                i++;
                //std::cout << num << std::endl;
            } else {
                break;
            }
        }
        return num;       
    }
    int myAtoi1(std::string s) {
        int num = 0, i=0, j=0;
        while (s[i]==32) i++;
        if (s[i]==45){
            j=-1; i++;
        } else if (s[i]==43){
            j=1;i++;
        }            
        if (j>=0){ //positive number
            while(s[i]>=48 && s[i]<=57){                           
                if(num > INT_MAX/10){
                    num = INT_MAX;                        
                } else {
                    num = num*10;
                    if(num >= INT_MAX - (s[i]-48)){//parenthesis is very important
                        num = INT_MAX;
                    } else {
                        num = num + (s[i]-48);//parenthesis is very important
                    }                        
                }
                i++;                                      
            }
        } else {//negative number
            while(s[i]>=48 && s[i]<=57){                           
                if(num < INT_MIN/10){
                    num = INT_MIN;                        
                } else {
                    num = num*10;               
                    if(num  <= INT_MIN + (s[i]-48)){ //parenthesis is very important
                        num = INT_MIN;
                    } else {
                        num = num -(s[i]-48); //parenthesis is very important
                    }
                }                   
                i++;
                //std::cout << num << std::endl;
            } 
        }
        return num;       
    }
};

void test_leet_prob8(){
    LeetProb8 p = LeetProb8();
    std::string s;   
    
    s = "0032";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: 32" << std::endl;
    s = "00000-42a1234";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: 0" << std::endl;
    s = "words and 987";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: 0" << std::endl;
    s = "-1123u3761867";
    std::cout << "string: " << s << " num: " << p.myAtoi(s) << "Ans: -1123" << std::endl;
    s = "00000-42a1234";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: 0" << std::endl;
    s = "-91283472332";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: -2147483648" << std::endl;
    s = "-115579378e25";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: -115579378" << std::endl;
    s = "-+12";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: 0" << std::endl;
    s = "21474836460";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: 2147483647" << std::endl;
    s = "2147483646";
    std::cout << "string: " << s << " num: " << p.myAtoi(s)<< "Ans: 2147483646" << std::endl;
}