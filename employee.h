#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
    public:
        string name;
        string Position;
        int Age;

        Employee (string na, string pos, int ag )
        {
            name = na;
            Position = pos;
            Age = ag;
        }

        Employee ()
        {
            name = "unknow";
            Position = "cat";
            Age = 0;
        }

        ~Employee ()
        {
        }


       friend ostream& operator << (ostream& o, const Employee& e)
        {
            o << "Name: " << e.name << endl;
            o << "Position: " << e.Position << endl;
            o << "Age: " << e.Age << endl;
      return o;
        }

};
