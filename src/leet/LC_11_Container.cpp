#include<iostream>
#include<vector>

class LeetProb11 {
public:
    int maxArea(std::vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;
        int area=0, max = 0;
        while(i<j){      
            if(height[i]<height[j]){
                area = height[i]*(j-i);
                i++;
            }else {
                area = height[j]*(j-i);
                j--;
            }
            if(max<area) max = area;
        }
        return max;
    }

};

void test_leet_prob11(){
    LeetProb11 p = LeetProb11();
    std::vector<int> height = {1,2,1};
    std::cout << p.maxArea(height) << std::endl;
    std::vector<int> h= {1,8,6,2,5,4,8,3,7};
    std::cout << p.maxArea(h) << std::endl;
}