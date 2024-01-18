
#include<gmock/gmock.h>
#include<gtest/gtest.h>
#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include<algorithm>

template< class T>
void show(const T& s){
    if(s.empty()){
        std::cout << "The set is empty. "  << std::endl;
        return;
    }
    std::cout << "The elements in the set are :" << std::endl;
    for(auto& it : s) {
        std::cout << it << "  ";
    }
    std::cout << std::endl;
}

void traverse(const std::unordered_set<std::string>& us){
    if(us.empty()){
        std::cout << "The set is empty. "  << std::endl;
        return;
    }
    std::cout << "The elements in the set are :" << std::endl;
    for(std::unordered_set<std::string>::const_iterator it=us.begin(); it!=us.end(); ++it) {
        std::cout << (*it) << "  ";
    }
    std::cout << std::endl;
}

TEST(UNORDEREDSET, initialization1) {
    std::unordered_set<int> us{1,4,2,5,3,2};
    show(us);
}
TEST(UNORDEREDSET, initialization2) {
    std::unordered_set<int> us({1,4,2,5,3,2});
    show(us);
}
TEST(UNORDEREDSET, initialization3) {
    std::unordered_set<int> us = {1,4,2,5,3,2};
    show(us);
}
TEST(UNORDEREDSET, initialization4) {
    int arr[] = {10, 4, 2, 1, 5};
    std::unordered_set<int> us(arr, arr+sizeof(arr)/sizeof(arr[0]));;
    show(us);
}
TEST(UNORDEREDSET, initialization5) {
    std::unordered_set<int> s = {1,3,2,4};
    std::unordered_set<int> us(s);
    show(us);
}
TEST(UNORDEREDSET, insert1) {
    std::unordered_set<int> us;
    std::unordered_set<int> res({1,4,5,2,1,3});
    us.insert(1);
    us.insert(4);
    us.insert(5);
    us.insert(2);
    us.insert(1);
    us.insert(3);
    EXPECT_TRUE(us==res);
    EXPECT_THAT(us, ::testing::ContainerEq(res));
}
TEST(UNORDEREDSET, insert2) {
    int arr[] = {10, 4, 2, 1, 5};
    std::unordered_set<int> us;
    us.insert(arr, arr+sizeof(arr)/sizeof(arr[0]));
    show(us);
}
TEST(UNORDEREDSET, insert3) {
    std::set<int> s = {1,3,2,4};
    std::unordered_set<int> us;
    us.insert(s.begin(), s.end());
    show(us);
}
TEST(UNORDEREDSET, insert4) {
    std::vector<int> v = {1,3,2,4};
    std::unordered_set<int> us;
    us.insert(v.begin(), v.end());
    show(us);
}

TEST(UNORDEREDSET, erase1){ //by value
    std::unordered_set<std::string> ustr{"c++", "python", "java", "fortran"};
    ustr.erase("python");
    traverse(ustr);
}
TEST(UNORDEREDSET, erase2){ //by position
    std::unordered_set<std::string> ustr{"c++", "python", "java", "fortran"};
    std::unordered_set<std::string>::iterator it = ustr.find("python");
    ustr.erase(it);
    traverse(ustr);
}
TEST(UNORDEREDSET, erase3){ //by position
    std::unordered_set<std::string> ustr{"c++", "python", "java", "fortran"};
    std::unordered_set<std::string>::iterator it = ustr.begin();
    ustr.erase(std::next(it,1), std::next(it,2));
    traverse(ustr);
}

TEST(UNORDEREDSET, bucket1){
    std::unordered_set<std::string> ustr{"c++", "python", "java", "fortran"};//items are stored in NO specific order
    show(ustr);//items are displayed in NO specific order
    std::cout << "bucket_count()    : " << ustr.bucket_count() << std::endl;
    std::cout << "max_bucket_count(): " << ustr.max_bucket_count() << std::endl;
    std::cout << "load_factor()     : " << ustr.load_factor() << std::endl;
    std::cout << "max_load_factor() : " << ustr.max_load_factor() << std::endl;
    int n = ustr.bucket("java");
    std::cout << "bucket number (\"java\"): " << ustr.bucket("java") << std::endl;
    std::cout << "bucket size  (\"java\") : " << ustr.bucket_size(ustr.bucket("java")) << std::endl;
    std::cout << " The elements  in the bucket that contains \"java\" are :" <<std::endl;
    for(auto it=ustr.begin(n); it!=ustr.end(n); it++){
        std::cout << *it << std::endl;
    }
}
TEST(UNORDEREDSET, bucket2){
    std::unordered_set<std::string> ustr{"c++", "python", "java", "fortran"};
    traverse(ustr);
    std::cout << "bucket_count()    : " << ustr.bucket_count() << std::endl;
    for(auto i:ustr) {
        std::cout << "bucket number of " << i << " is : " << ustr.bucket(i) << std::endl;
        std::cout << "bucket size of " << ustr.bucket(i) << " is :" << ustr.bucket_size(ustr.bucket(i)) << std::endl;
        std::cout << " The elements  in the bucket " << ustr.bucket(i) << " are : " <<std::endl;
        for(auto it = ustr.begin(ustr.bucket(i)); it!=ustr.end(ustr.bucket(i)); it++){
            std::cout << *it << "  ";
        }
        std::cout << std::endl;
    }
}

TEST(UNORDEREDSET, HashFunction){
    std::unordered_set<std::string> ustr{"c++", "python", "java", "fortran"};
    std::hash<std::string> h = ustr.hash_function();
    std::unordered_set<std::string>::hasher hs = ustr.hash_function();
    std::cout<< h("c++") <<std::endl;
    std::cout<< hs("c++") <<std::endl;
    ustr.insert("php");
    std::cout<< h("php") <<std::endl;
    h = ustr.hash_function();
    std::cout<< h("c++") <<std::endl;
    std::cout<< h("java") <<std::endl;
    std::cout<< h("script") <<std::endl;
    ustr.insert("script");
    std::cout<< hs("script") <<std::endl;
}




