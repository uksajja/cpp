#pragma once 

#include<iostream>
#include<string>

class Sport{
    // private members are local to the class - Cannot be accessed by derived classes or by direct reference
    // protected members - can be accessed by derived classes but NOT by direct reference
    // public members can be accessed by derived classes and also by direct refrence 
    protected:
        //Data members
        std::string m_Name;
        int m_TeamSize;
    public:   
        //Constructor
        Sport(): m_Name("Sport"), m_TeamSize(0){}
        
        //Methods
        const std::string GetName() const {
            return m_Name;
        }
        int GetTeamSize() const {
            return m_TeamSize;
        }
        void PrintDetails() const{
            std::cout << "----------------------------"<< std::endl;
            std::cout << "Name:" << m_Name << std::endl;
            std::cout << "TeamSize:" << m_TeamSize << std::endl;
        }
        
        //Destructor
        virtual ~Sport(){}  // virtual Destructor - ensures the derived destructor is called when base pointer points to a derived object
};

class Cricket : public Sport {
    public:
        //Constructor 
        Cricket(){
            m_Name = "Cricket";
            m_TeamSize = 11;
        }
        //The following constructor definition does not work for derived classes -- Why? These are NOT members of this class
        //Cricket() : m_Name("Cricket"), m_TeamSize(11){}

        void PrintDetails() const{
            Sport::PrintDetails();
            std::cout << "Additional Details:" << std::endl;
            std::cout << "Batsmen " << "Bowlers " << "Fielders " << std::endl;
            std::cout << "Overs:(20/50)" << std::endl;
        }
};

class Soccer : public Sport {
    public:
        //Constructor 
        Soccer(){
            m_Name = "Soccer";
            m_TeamSize = 11;
        }
        //The following constructor definition does not work for derived classes -- Why?
        //Soccer(): m_Name("Soccer"), m_TeamSize(11){}

        void PrintDetails() const{
            Sport::PrintDetails();
            std::cout << "Additional Details:" << std::endl;
            std::cout << "Offense " << "Defense " << "MidField " << "GoalKeeper" << std::endl;
            std::cout << "Duration:(45 min + 45 min)" << std::endl;
        }
};

class Baseball : public Sport {
    public:
        //Constructormicrosoft
        Baseball(){
            m_Name = "Baseball";
            m_TeamSize = 9;
        }
        void PrintDetails() const{
            Sport::PrintDetails();
            std::cout << "Additional Details:" << std::endl;
            std::cout << "BattingTeam " << "FieldingTeam " << "Pitchers " << std::endl;
        }
};
class Basketball : public Sport {
    public:
        //Constructor
        Basketball(){
            m_Name = "Basketball";
            m_TeamSize = 5;
        }
        void PrintDetails() const{
            Sport::PrintDetails();
            std::cout << "Additional Details:" << std::endl;
            std::cout << "Hoop " << "Dribble " << "SlamDunk " << std::endl;
        }
};

void PrintSportInfo(const Sport& s);
void PrintSportInfo(Sport* sptr);

void test_inheritance();
void test_inheritance_ptr();
void test_inheritance_ref();

