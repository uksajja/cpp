#include <vector>
#include <string>
#include <iostream>

#include <gmock/gmock.h>

void showVec(std::vector<std::string>& strVec){
    std::cout << std::endl;
    for (auto str : strVec){
        std::cout << str << ",";
    }
    std::cout << std::endl;
}

std::vector<std::string> letterCombinations(std::string digits){
    if (digits == "")  return {};
    std::string str_list[] = { "abc", "def", "ghi", "jkl","mno", "pqrs","tuv","wxyz" };
    std::vector<std::string> outvec{};
    for (char c : digits) {
        std::string current = str_list[c - 50];
        std::vector<std::string> tempvec{};
        for (char ch : current){
            std::string tempstr = { ch };
            for (auto str : outvec) {
                tempvec.push_back(str + tempstr);
            }
            if(outvec.empty()){
                tempvec.push_back(tempstr);
            } 
        }
        
        if(!tempvec.empty())
            outvec = tempvec;
    }   
    return outvec;
}
TEST(LC, PhoneLetter1) {
    std::vector<std::string> strVec = letterCombinations("");
    EXPECT_THAT(strVec, ::testing::ContainerEq(std::vector<std::string>{}));
}
TEST(LC, PhoneLetter2){
    std::vector<std::string> strVec = letterCombinations("2");
    EXPECT_THAT(strVec, ::testing::ContainerEq(std::vector<std::string>{ "a","b","c"}));
}
TEST(LC, PhoneLetter3){
    std::vector<std::string> strVec = letterCombinations("7");
    EXPECT_THAT(strVec, ::testing::ContainerEq(std::vector<std::string>{ "p", "q", "r", "s"}));
}
TEST(LC, PhoneLetter4){
    std::vector<std::string> strVec = letterCombinations("23");
    EXPECT_THAT(strVec, ::testing::ContainerEq(std::vector<std::string>{ "ad", "bd", "cd", "ae", "be", "ce", "af", "bf", "cf" }));
}