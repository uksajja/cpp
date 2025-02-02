#include<gmock/gmock.h>
#include<gtest/gtest.h>


TEST(CONST, const1){
    int x = 100;
    int y = 200;
    //x, y are variables and can take different valuyes at different times as needed

    const int *b = &x; // Contents of b are constant and CANNOT be changed directly, but, b can point to a different integer
    int const *c = &y; // Contents of c are constant and CANNOT be changed directly, but c can point to a different integer later
    // the above two statements represent two different ways for similar behavior
    // contents of b or c cannot be changed directly by de-reference operator(*)
    // However, b or c can point to different memory addresses at different times
    
    //*b = 10; // changing the contents of b directly is NOT allowed
    b = &y;    // b can be changed and can point to another int

    //*c = 50; // contents of c cannot be changed
    c = &x;    // c can be changed.


    const int a = 10; // value of a CANNOT be changed
    //a = 5;   // NOT allowed
    
    int *const d = new int(30); // d is a pointer that is constant. d always should point to the same memory
    *d = a;    // contents of d can be changed
    //d = &a;  //d cannot store another address - d cannotbe changed

    EXPECT_EQ(*b, 200);
    EXPECT_EQ(*c, 100);
    EXPECT_EQ(*d, 10);

}