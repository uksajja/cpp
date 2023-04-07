 
 #include <iostream>
 
 template <class T>
 T addNum(T a, T b){
   return a+b;
 }
 
 template <class T, class U>
 T addNum(T a, U b){ 
   return a+b;
 }

void test_template_function(){
   std::cout << "\n------------------------------------------------------------" << std::endl;
   std::cout << "    Test : Template Function example                         " << std::endl;
   std::cout << "------------------------------------------------------------" << std::endl;
   int    l = 10, m = 20;
   double x = 10.5, y = 20.5;
   
   std::cout << l << " + " << m << " = " << addNum(l, m) << std::endl;
   std::cout << x << " + " << y << " = " << addNum(x, y) << std::endl;
   std::cout << x << " + " << m << " = " << addNum(x, m) << std::endl;
}
