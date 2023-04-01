// Employee Class

#pragma once

#include<iostream>
#include<string>


class Employee {
    private:       
        std::string m_Name;
        int m_ID;
        double m_Salary;
    public:
        Employee(const std::string& name) : m_Name(name), m_ID(-1), m_Salary(-1.0) {}

        Employee(int Id) : m_Name("Unknown"), m_ID(Id), m_Salary(-1.0) {}
        
        Employee(const std::string& name, int Id ) : m_Name(name), m_ID(Id), m_Salary(-1.0) {}
           
        Employee(const std::string& name, int Id, double salary)  : m_Name(name), m_ID(Id), m_Salary(salary) {}
            
        void setID(int id) {
            m_ID = id;
        }
        void setSalary(double salary) {
            m_Salary = salary;
        }
        //const keyword on the right side of function name - the contents of the class cannot be modified by this function
        int getID() const{
            return m_ID;
        }
        std::string getName() const {
            return m_Name;
        }
        double getSalary() const {
            return m_Salary;
        }
        ~Employee(){}
};