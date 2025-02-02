/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000
*/


#include<iostream>
#include<vector>
#include<string>
class LeetProb6 {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows==1) { return s;}
        int l = s.size(); 
        std::string str;       
        for(int i=1; i<=numRows; i++){
            int indx = i-1;
            int a = 2*(numRows-i);
            int b = 2*(i-1); 
            str.push_back(s[indx]);           
            while(indx < l){                
                if(a!=0) {indx = indx+a; if (indx< l) str.push_back(s[indx]);}
                if(b!=0) {indx = indx+b; if (indx< l) str.push_back(s[indx]);}
            }
        }
       
        return str;
    }
};
void test_leet_prob6(){
    std::cout << "\n------------------------------------------------------------" << std::endl;
    std::cout << "    Test : LeetCode Problem 6                               " << std::endl;
    std::cout << "------------------------------------------------------------" << std::endl;
    LeetProb6 p = LeetProb6();
    std::string s = "PAYPALISHIRING";
    std::string str = p.convert(s, 3);
    std::cout <<str<<std::endl;
    str = p.convert(s, 4);
    std::cout <<str<<std::endl;
    str = p.convert(s, 5);
    std::cout <<str<<std::endl;
    s = "A";
    str = p.convert(s, 1);
    std::cout <<str<<std::endl;
    s = "A";
    str = p.convert(s, 2);
    std::cout <<str<<std::endl;
    s = "AB";
    str = p.convert(s, 1);
    std::cout <<str<<std::endl;
}