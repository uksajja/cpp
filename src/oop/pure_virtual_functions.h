// Interfaces or Pure Virtual functions
// class objects cannot be instantiated unless all the pure virtual functions are implemented by a derived class
#pragma once 

#include<iostream>


class Shape{
    protected:
        std::string m_Name;
        unsigned int m_Vertices;
        unsigned int m_Sides;
        double m_Area;
    public:
        // Constructor 
        // This Shape class is purely an interface
        // Instantiation - Not allowed due to the pure virtual function

        //Interface functions or pure virtual functions
        virtual void calculate_area() = 0;
        
        double getArea() const{
            return m_Area;
        }
        void PrintDetails() const {
            std::cout << "Shape: "  << m_Name << std::endl;
            std::cout << "Vertices: " << m_Vertices << " Sides: " << m_Sides << std::endl;
            std::cout << "Area: " << getArea() << std::endl;
        }

        //Destructor
        //virtual Destructor - ensures the derived destructor is called when base pointer points to a derived object
        virtual ~Shape(){}
};

class Triangle : public Shape{
    private:
        double m_Base;
        double m_Height;
    public: 
        Triangle() {
            std::cout << "\nTriangle Object is being Constructed!" <<std::endl;
            m_Name = "Triangle";
            m_Vertices = 3;
            m_Sides = 3;
            std::cout << "Enter the base of the triangle: " << std::endl;
            std::cin >> m_Base;
            std::cout << "Enter the height of the triangle: " << std::endl;
            std::cin >> m_Height;
        }
        Triangle(double base, double height) {
            
            m_Name = "Triangle";
            m_Vertices = 3;
            m_Sides = 3;
            std::cout << "\nTriangle Object is being Constructed with base : " << base << "Height: " << height <<std::endl;
            m_Base = base;
            m_Height = height;
        }
        void calculate_area() override {
            m_Area = 0.5*m_Base*m_Height;;
        }  
};

class Square: public Shape {
    private:
        double m_Side;
    public:
        Square() {
            std::cout << "\nSquare Object is being Constructed!" <<std::endl;
            m_Name = "Square";
            m_Vertices = 4;
            m_Sides = 4;
            std::cout << " Enter length of the side : " << std::endl;
            std::cin >> m_Side;
        }
        Square (double side){            
            m_Name = "Square";
            m_Side = side;
            m_Vertices = 4;
            m_Sides = 4;
            std::cout << "\nSquare Object is being Constructed with Side: " << side <<std::endl;
        }
        void calculate_area() {
            m_Area =  m_Side*m_Side;
        }
};

class Rectangle : public Shape {
    private:
        double m_Length;
        double m_Width;
    public:
        Rectangle () {
            std::cout << "\nRectangle Object is being Constructed!" <<std::endl;
            m_Name = "Rectangle";
            std::cout << " Enter the length of a Rectangle: " << std::endl;
            std::cin >>m_Length;
            std::cout << " Enter the width of a Rectangle: " << std::endl;
            std::cin >>m_Width;
            m_Vertices = 4;
            m_Sides = 4;
        }
        Rectangle(double length, double width) {
            std::cout << "\nRectangle Object is being Constructed!" <<std::endl;
            m_Name = "Rectangle";
            m_Length = length;
            m_Width = width;
            m_Vertices = 4;
            m_Sides = 4;
        }
};
void test_pure_virtual_functions();