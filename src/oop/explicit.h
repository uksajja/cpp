// Example - Explicit keyword
#pragma once 

#include <iostream>
#include <string>


class Player{
    private:
        std::string m_Name;
        int  m_Id;
    public:
        Player (int Id): m_Id(Id) {}
        Player(const std::string& name) : m_Name(name) {}
};

class Team {
    private:
        std::string m_TeamName;
        int  m_TeamId;
    public:
        explicit Team (int Id): m_TeamId(Id) {}
        explicit Team(const std::string& name) : m_TeamName(name) {}
};

void test_explicit_keyword();