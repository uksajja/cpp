#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

#include <gmock/gmock.h>

std::string addBinaryEfficient(std::string a, std::string b) {
    if (a == "") return b;
    if (b == "") return a;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    std::string result = "";
    while (i >= 0 || j >= 0 || carry != 0) {
        if (i >= 0) {
            carry += a[i--] - 48;
        }
        if (j >= 0) {
            carry += b[j--] - 48;
        }
        result += (carry % 2 + 48);
        carry /= 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string addBinary(std::string a, std::string b) {
    if (a == "" && b == "") return "";
    std::stack<char> st;
    char c = '0';
    int i = a.length() - 1; int  j = b.length() - 1;
    while (i >= 0 && j > 0) {
        if (a[i] == b[j] && b[j] == '0' && c == '0') {
            st.push('0');
        }
        else if (a[i] == b[j] && b[j] == '0' && c == '1') {
            st.push('1'); c = '0';
        }
        else if (a[i] == b[j] && b[j] == '1' && c == '0') {
            st.push('0'); c = '1';
        }
        else if (a[i] == b[j] && b[j] == '1' && c == '1') {
            st.push('1');
            c = '1';
        }
        else if (a[i] != b[j] && c == '0') {
            st.push('1');
        }
        else if (a[i] != b[j] && c == '1') {
            st.push('0');
            c = '1';
        }
        i--; j--;
    }
    while (i >= 0) {
        if (c == '0') {
            st.push(a[i]);
        }
        else {
            if (a[i] == '1') {
                st.push('0'); c = '1';
            }
            else {
                st.push('1');
                c = '0';
            }
        }
        i--;
    }

    while (j >= 0) {
        if (c == '0') {
            st.push(b[j]);
        }
        else {
            if (b[j] == '1') {
                st.push('0');
                c = '1';
            }
            else {
                st.push('1');
                c = '0';
            }
        }
        j--;
    }
    if (c == '1')st.push(c);
    std::string result;
    std::cout << st.size() << std::endl;

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

TEST(LC, AddBinary) {
    std::string a = "11";
    std::string b = "1011";

    EXPECT_EQ("1110", addBinaryEfficient(a, b));
    EXPECT_EQ("1110", addBinary(a, b));
}
