#include <algorithm>
#include <vector>
#include <numeric>

#include <gmock/gmock.h>

TEST(GENERATE, gen1) {
    std::vector<int> v(5);
    std::generate(v.begin(), v.end(), [i = 1]() mutable {return i++;});
    std::for_each(v.begin(), v.end(), [](int i) {std::cout << i << " ";});
}
TEST(IOTA, iota) {
    std::vector<int> v(10);
    int val = 1;
    std::iota(v.begin(), v.end(), val);
    std::for_each(v.begin(), v.end(), [](int i) {std::cout << i << " ";});
}
bool constexpr isBadVersion(int i) { return (i == 4); }
TEST(FIND, Findif) {
    std::vector<int> v(5);
    std::generate(v.begin(), v.end(), [i = 1]() mutable { return i++; });
    auto pos = std::find_if(v.begin(), v.end(), [](int i) { return isBadVersion(i); });
    EXPECT_EQ(std::distance(v.begin(), pos) + 1, 4);
}

TEST(BOUNDS, low) {
    std::vector<int> v{ 1,2,3,4,5 };
    auto low = std::lower_bound(v.begin(), v.end(), 3.9);
    auto up = std::upper_bound(v.begin(), v.end(), 3.9);
    std::cout << "Lower bound : " << std::distance(v.begin(), low) << "Upper bound :" << std::distance(v.begin(), up) << std::endl;
    std::cout << "low Value: " << *low << " up Value: " << *up << std::endl;
}
TEST(SORT, compsort) {
    std::vector<int> v{ 1,2,3,4,5 };
    double target = 3.714286;
    auto comp = [&](int a, int b) { return (fabs(a - target) < fabs(b - target)); };

    std::sort(v.begin(), v.end(), comp);
    std::vector<int> ans(v.begin(), v.begin() + 2);
    for (auto& item : ans) {
        std::cout << item << "  ";
    }
}

TEST(MINMAX, max1) {
    std::vector<int> v{ 7, 1, 5, 3, 6, 4 };
    int price = v[0];
    //auto diff = [&](int a) { return (a - price); };
    auto comp = [](int a, int b) { return(a > b ? a : b);};
    auto print = [](int a) { std::cout << a << "  "; };
    auto m = std::max_element(v.begin() + 1, v.end(), comp);
    print(*m);
}

TEST(UNIQUE, vectorunique) {
    std::vector<int>v{ 1,1,2,2,2,2,3,4,4,4,4 };
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
    EXPECT_THAT(v, ::testing::ContainerEq(std::vector{ 1,2,3,4 }));
}





