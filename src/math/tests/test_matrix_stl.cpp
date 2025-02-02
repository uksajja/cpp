/*
Test MatrixSTL class 
*/

#include<iostream>
#include<gtest/gtest.h>
#include <gmock/gmock.h>

#include "matrix.hpp"

TEST(MATRIXSTL, init1){
    MatrixSTL<int> m1 = MatrixSTL(3,3,1);
    MatrixSTL<int> m2 = MatrixSTL(3,3,2);
    MatrixSTL<int> m = m1+m2;
    EXPECT_THAT(m.getRows(), 3);
    EXPECT_THAT(m.getCols(), 3);
    EXPECT_TRUE(m == MatrixSTL(3,3,3));
}
TEST(MATRIXSTL, init2){
    std::vector<std::vector<double>> data = {{1,2,3}, {4,5,6}, {7,8,9}};
    MatrixSTL<double> m = MatrixSTL(data);
    m.display();
    //MatrixSTL<double> m2 = m / 2.0;
    //m2.display();
}
TEST(MATRIXSTL, operator1){
    std::vector<std::vector<double>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<double>> data2 = { {4,5,6}, {7,8,9}, {1,2,3} };
    std::vector<std::vector<double>> result = { {5,7,9}, {11,13,15}, {8,10,12} };
    MatrixSTL<double> m1 = MatrixSTL(data1);
    MatrixSTL<double> m2 = MatrixSTL(data2);
    MatrixSTL<double> m3(3,3,0);
    MatrixSTL<double> mresult = MatrixSTL(result);
    m3 = m1+m2;
    EXPECT_TRUE(m3 == mresult);
}
TEST(MATRIXSTL, operator2){
    std::vector<std::vector<double>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<double>> data2 = { {4,5,6}, {7,8,9}, {1,2,3} };
    std::vector<std::vector<double>> result = { { 3,3,3 }, { 3,3,3 }, { -6,-6,-6 } };
    MatrixSTL<double> m1 = MatrixSTL(data1);
    MatrixSTL<double> m2 = MatrixSTL(data2);
    MatrixSTL<double> m3(3,3,0);
    MatrixSTL<double> mresult = MatrixSTL(result);
    m3 = m2-m1;
    EXPECT_TRUE(m3 == mresult);
}
TEST(MATRIXSTL, operator3){
    std::vector<std::vector<double>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<double>> data2 = { {1,0,0}, {0,1,0}, {0,0,1} };
    
    MatrixSTL<double> m1 = MatrixSTL(data1);
    MatrixSTL<double> m2 = MatrixSTL(data2);
    MatrixSTL<double> m3(3,3,0);
    m3 = m1*m2;
    EXPECT_TRUE(m3 == m1);
}
TEST(MATRIXSTL, operator4){
    std::vector<std::vector<int>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<int>> data2 = { {4,5,6}, {7,8,9}, {1,2,3} };
    std::vector<std::vector<int>> result = { { 3,3,3 }, { 3,3,3 }, { -6,-6,-6 } };
    MatrixSTL<int> m1 = MatrixSTL(data1);
    MatrixSTL<int> m2 = MatrixSTL(data2);
    MatrixSTL<int> mresult = MatrixSTL(result);
    m2 -= m1;
    EXPECT_TRUE(m2 == mresult);
}
TEST(MATRIXSTL, operator5){
    std::vector<std::vector<double>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<double>> data2 = { {4,5,6}, {7,8,9}, {1,2,3} };
    std::vector<std::vector<double>> result = { {5,7,9}, {11,13,15}, {8,10,12} };
    MatrixSTL<double> m1 = MatrixSTL(data1);
    MatrixSTL<double> m2 = MatrixSTL(data2);
    MatrixSTL<double> mresult = MatrixSTL(result);
    m1 += m2;
//m1.display();
    EXPECT_TRUE(m1 == mresult);
}

TEST(MATRIXSTL, operator6) {
    std::vector<std::vector<int>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<int>> data2 = { {4,5,6}, {7,8,9}, {1,2,3} };
    std::vector<std::vector<int>> result ={ { 3,3,3 }, { 3,3,3 }, { -6,-6,-6 } };
    MatrixSTL<int> m1 = MatrixSTL(data1);
    MatrixSTL<int> m2 = MatrixSTL(data2);
    MatrixSTL<int> mresult = MatrixSTL(result);
    m2 -= m1;
    EXPECT_TRUE(m2==mresult);
}
TEST(MATRIXSTL, operator7){
    std::vector<std::vector<int>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<int>> result = { {5,2,3}, {4,9,6}, {7,8,13} };
    MatrixSTL<int> m1 = MatrixSTL(data1);
    MatrixSTL<int> m2 = MatrixSTL(3,3,0);
    MatrixSTL<int> mresult = MatrixSTL(result);
    const int& a =4;
    m2 = m1+a;
    //m2.display();
    EXPECT_TRUE(m2 == mresult);
}
TEST(MATRIXSTL, operator8){
    std::vector<std::vector<int>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<int>> result = { {-1,2,3}, {4,3,6}, {7,6,7} };
    MatrixSTL<int> m1 = MatrixSTL(data1);
    MatrixSTL<int> m2 = MatrixSTL(3, 3, 0);
    MatrixSTL<int> mresult = MatrixSTL(result);
    const int& a = 2;
    m2 = m1 - a;
    //m2.display();
    EXPECT_TRUE(m2 == mresult);
}
TEST(MATRIXSTL, operator9){
    std::vector<std::vector<int>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<int>> result = { {2,4,6}, {8,10,12}, {14,16,18} };
    MatrixSTL<int> m1 = MatrixSTL(data1);
    MatrixSTL<int> m2 = MatrixSTL(3, 3, 0);
    MatrixSTL<int> mresult = MatrixSTL(result);
    const int& a = 2;
    m2 = m1 * a;
    //m2.display();
    EXPECT_TRUE(m2 == mresult);
}
TEST(MATRIXSTL, operator10){
    std::vector<std::vector<double>> data1 = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::vector<std::vector<double>> result = { {0.5,1.0,1.5}, {2.0,2.5,3.0}, {3.5,4.0,4.5} };
    MatrixSTL<double> m1 = MatrixSTL(data1);
    MatrixSTL<double> m2 = MatrixSTL(3, 3, 0.0);
    MatrixSTL<double> mresult = MatrixSTL(result);
    const int& a = 2;
    m2 = m1 / a;
    //m2.display();
    EXPECT_TRUE(m2 == mresult);
}