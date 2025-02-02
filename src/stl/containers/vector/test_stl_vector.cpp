// Test STL Vector

#include <gmock/gmock.h>
#include <vector>

void show_vec_pair(const std::vector<std::pair<int, int>>& v) {
    for(auto& ivec : v){
        std::cout << "(" << ivec.first << "," << ivec.second << ")  ";
    }
    std::cout << std::endl;
}


TEST(STLVECTOR, vector_pair){
    std::vector<std::pair<int, int>> v;
    std::vector<std::pair<int, int>> res = {{0,1}, {1,2},{2,3}};
    v.push_back({0,1});
    v.emplace_back(1,2);
    v.emplace_back(2,3);   
    EXPECT_THAT(v, ::testing::ContainerEq(res));
    show_vec_pair(v);
}
TEST(STLVECTOR, vector_vector_pair){
    std::vector<std::vector<std::pair<int, int>>> vv;
    std::vector<std::vector<std::pair<int, int>>> res{{{0,1}, {0,2}},
                                                        {{1,2}, {1,3}},
                                                        {{2,3}, {2,4}},
                                                        {{3,4}},
                                                        {{5,6}},
                                                        {{7,8}, {-1,-2}}
                                                    };

    vv.push_back({{0,1}, {0,2}});
    vv.push_back({{1,2}, {1,3}});
    vv.push_back({{2,3}, {2,4}});
    int a=3,b=4;
    vv.push_back({{a,b}});
    vv.insert(vv.end(), {{5,6}});
    vv.push_back({{7,8}, {-1,-2}});
    vv.shrink_to_fit();

    EXPECT_THAT(vv, ::testing::ContainerEq(res));
    
    for(auto& i : res){
        for(auto& ivec : i) {
            std::cout << "(" << ivec.first << "," << ivec.second << ")  ";
        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl;
}
TEST(STLVECTOR, vector_vector_pair2){
    std::vector<std::vector<std::pair<int, int>>> vv;
    std::vector<std::pair<int, int>> v;

    vv.reserve(3);
    v.emplace_back(0,1);
    v.emplace_back(0,2);
    v.emplace_back(1,2);
    v.emplace_back(1,3);

    vv.push_back(v);
    vv.push_back(std::vector<std::pair<int,int>>{{2,3}, {2,4}});
    
    for(auto& i : vv){
        for(auto& ivec : i)
            std::cout << "(" << ivec.first << "," << ivec.second << ")  ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
//slice - subvector
TEST(STLVECTOR, slice){
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int startpos=2, endpos=6;
    std::vector<int> v13(v.begin()+startpos, v.begin()+endpos);
    EXPECT_THAT(v13, ::testing::ContainerEq(std::vector<int>{3,4,5,6}));
}
//split
TEST(STLVECTOR, split) {
    std::vector<int> v{-1, -2, -3, -4, -5, 0, 7, 8, 9, 10};
    std::vector<int> negative{-1,-2,-3,-4,-5};
    std::vector<int> positive{7,8,9,10};
    auto pos = std::find(v.begin(), v.end(), 0);
    int d = std::distance(v.begin(), pos);
    EXPECT_THAT(negative, ::testing::ContainerEq(std::vector<int>(v.begin(), v.begin()+d)));
    EXPECT_THAT(positive, ::testing::ContainerEq(std::vector<int>(pos+1, v.end())));
}