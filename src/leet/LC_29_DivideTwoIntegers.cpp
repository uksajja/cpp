#include <iostream>
#include <cmath>

#include <gmock/gmock.h>

/*Incomplete
Incomplete
Incomplete
Incomplete
Incomplete
*/

int divide(int dividend, int divisor){
    if (dividend == divisor) return 1;

    bool negative = (divisor < 0) != (dividend < 0);
    if (dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }
    if (dividend == INT_MAX && divisor == -1) return -INT_MAX;

    if (dividend == 0 || divisor == 1){
        return dividend;
    }

    if (divisor < 0){
        if (divisor == INT_MIN){
            divisor = INT_MAX;
        }
        else{
            divisor = -divisor;
        }
    }
    if (dividend < 0){
        if (dividend == INT_MIN){
            dividend = INT_MAX;
        }
        else{
            dividend = -dividend;
        }
    }
    if (divisor > dividend) return 0;
    int ans = 1, sum = divisor;

    while (sum <= dividend - divisor){
        sum += divisor;
        ans++;
        if (sum == INT_MAX) break;
    }
    if (negative) ans = -ans;
    return ans;
}
TEST(LC, Division1){
    EXPECT_EQ(0, divide(0, 3));
}
TEST(LC, Division2){
    EXPECT_EQ(0, divide(10, 30));
}
TEST(LC, Division3){
    EXPECT_EQ(0, divide(10, -30));
}
TEST(LC, Division4){
    EXPECT_EQ(100000, divide(100000, 1));
}
TEST(LC, Division5){
    EXPECT_EQ(-2, divide(7, -3));
}
/*TEST(LC, Division6){
    EXPECT_EQ(-1073741824, divide(-2147483648, 2));
}*/
TEST(LC, Division7){
    EXPECT_EQ(1073741823, divide(2147483647, 2));
}
TEST(LC, Division8){
    EXPECT_EQ(-2147483647, divide(2147483647, -1));
}
TEST(LC, Division9){
    EXPECT_EQ(2147483647, divide(-2147483648, -1));
}


