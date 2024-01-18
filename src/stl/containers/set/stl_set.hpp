#pragma once

#include <iostream>
#include <set>


struct compare_object{
    bool operator()(int a, int b) const{
        return (a%10 == 0 && b%10 == 0 && a<b);
    }
};
class Point {
    public:
        Point(int x, int y): mX(x), mY(y){}
        int getX() { return mX; }
        int getY() { return mY; }
        bool operator<(Point p) const {
            return (mX < p.mX)? true : (mX==p.mX)? (mY<p.mY) : false;
        }
        bool operator>(Point p) const {
            return (mX > p.mX)? true : (mX==p.mX)? (mY>p.mY) : false;
        }
        
    private:
        int mX, mY;
};

std::ostream& operator<<(std::ostream& stream, Point A);
std::ostream& operator<<(std::ostream& stream, std::pair<int,int> A);

void show_auto(const std::set<int>& s);
void show_auto(const std::set<int, std::greater<int>>& s);
void show_auto(const std::set<int, compare_object>& s);
template< class T>
void show(T& s){
    if(s.empty()){
        std::cout << " The set is empty " << std::endl;
        return;
    }
    std::cout << "Set has " << s.size() << "elements." << std::endl;
    std::cout << "The elements in the set are (auto): " << std::endl;
    for(auto& it : s){
        std::cout << it << "  " ;

    }
    std::cout << std::endl;
}
//iterator based methods
void show1(const std::set<int>& s);
void show2(const std::set<int>& s);
void show3(const std::set<int>& s);
void show4(const std::set<int>& s);

std::ostream& operator<<(std::ostream& os, std::set<char>& u);