/*
Convert a non-negative integer num to its English words representation.

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

*/


#include <iostream>
#include <string>
#include <vector>

#include <gmock/gmock.h>

std::string numberToWordsUpto1000(int num);
std::string numberToWords(int num);

std::string numberToWordsUpto1000(int num) {
    std::string words = "";
    std::vector<std::string> str1 = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    std::vector<std::string> str10{ "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    std::vector<std::string> str11{ "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    while (num) {
        if (num >= 100) {
            words += str1[num / 100] + " Hundred";
            num %= 100;
            if (num) {
                words += " ";
                }
            }
        else if (num >= 20) {
            words += str10[num / 10];
            num %= 10;
            if (num) {
                words += " ";
                }
            }
        else if (num >= 10) {
            words += str11[num - 10];
            num = 0;
            }
        else {
            words += str1[num];
            num /= 10;
            }
        }
    return words;
    }
std::string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
        }
    std::string words = "";
    int r = 0;
    while (num > 0) {
        if (num >= 1000000000) {
            r = num % 1000000000;
            num /= 1000000000;
            words += numberToWordsUpto1000(num) + " Billion";
            }
        else if (num >= 1000000) {
            r = num % 1000000;
            num /= 1000000;
            words += numberToWordsUpto1000(num) + " Million";
            }
        else if (num >= 1000) {
            r = num % 1000;
            num /= 1000;
            words += numberToWordsUpto1000(num) + " Thousand";
            }
        else {
            words += numberToWordsUpto1000(num);
            num /= 1000;
            r = 0;
            }
        num = r;
        if (r > 0)
            words += " ";
        }
    return words;
    }

TEST(LC, NumToWords) {
    int num = 203045079;
    EXPECT_EQ(numberToWords(num), "Two Hundred Three Million Forty Five Thousand Seventy Nine");
    }