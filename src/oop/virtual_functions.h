// virtual functions - example

#pragma once 

// C++ includes
#include<iostream>
#include<string>

class Book{
    protected:
        std::string m_Title;
        std::string m_Author;
    public:
        Book() {}
        Book(const std::string& title): m_Title(title), m_Author("Unknown") {}
        Book(const std::string& title, const std::string& author): m_Title(title), m_Author(author) {}
        
        virtual std::string GetType() const { return "Book";}
        std::string getTitle() const { return m_Title; }
        std::string getAuthor() const { return m_Author; }
        
        void PrintBookDetails()  const {
            std::cout << "------------------------------------------------------------" << std::endl;
            std::cout << GetType() << std::endl;
            std::cout << "Title: " << m_Title << std::endl;
            std::cout << "Author: " << m_Author<< std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;
        }
};
class TextBook : public Book{
    protected:
        std::string m_Course;
    public:
        TextBook(const std::string& title, const std::string& author) {
        m_Title = title;
        m_Author = author;
        }
    std::string GetType() const override { return "TextBook";}
    std::string getCourse() const { return m_Course;}
};

void test_virtual_functions();