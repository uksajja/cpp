// Operators
#pragma once 

#include <iostream>
#include <string>

class PosVector {
    public :
        float m_X, m_Y, m_Z;
    public:
        PosVector():m_X(0.0f), m_Y(0.0f), m_Z(0.0f){}
        PosVector(float x, float y, float z): m_X(x), m_Y(y), m_Z(z) {}
        PosVector operator+(const PosVector& other) const {
            return PosVector(m_X + other.m_X,  m_Y + other.m_Y, m_Z + other.m_Z);
        }
        PosVector operator-(const PosVector& other) const {
            return PosVector(m_X - other.m_X,  m_Y - other.m_Y, m_Z - other.m_Z);
        }
        PosVector operator*(const PosVector& other) const {
           return PosVector(m_X * other.m_X,  m_Y * other.m_Y, m_Z * other.m_Z);
        }
        void Print() {
            std::cout << "(x, y, z): " << "(" <<m_X << "," << m_Y << ","<< m_Z << ")" << std::endl;
        }
        bool operator==(const PosVector& other) const {
            return (m_X == other.m_X && m_Y == other.m_Y && m_Z == other.m_Z);
        }
        //Assignment operator
        //Usage: Object is already constructed elsewhere. Just the contents are copied with the use of assignement operator
        PosVector& operator=(const PosVector& other) {
            if(this != &other){
                m_X = other.m_X;
                m_Y = other.m_Y;
                m_Z = other.m_Z;
            }
            return *this;           
        } //return (PosVector(other.m_X, other.m_Y, other.m_Z)); This is wrong here - WHY? object should not be constructed.
};
std::ostream& operator<<(std::ostream& stream, const PosVector& A);

void test_operator_overloading();