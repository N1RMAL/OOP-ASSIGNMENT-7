#include <iostream>
#include <string.h>
using namespace std;

int maths, oop, se, ds;

class External1;
class Internal1
{
    public:
    
    int imaths, ioop, ise, ids;
    
    void inputInternal()
    {
        cout << "Enter the Internal marks:\n";
        cout << "MATHS: ";
        cin >> imaths;
        cout << "\nOOP: ";
        cin >> ioop;
        cout << "\nSE: ";
        cin >> ise;
        cout << "\nDS: ";
        cin >> ids;
    }
    friend void operator+(Internal1, External1);
};
    
class External1
{
    public:
    
    int tmaths, toop, tse, tds;
    
    void inputExternal()
    {
        cout << "\n\nEnter the External marks:\n";
        cout << "MATHS: ";
        cin >> tmaths;
        cout << "\nOOP: ";
        cin >> toop;
        cout << "\nSE: ";
        cin >> tse;
        cout << "\nDS: ";
        cin >> tds;
    }
    friend void operator+(Internal1, External1);
};

void operator +(Internal1 i, External1 e)
{
    maths = i.imaths + e.tmaths;
    oop = i.ioop + e.toop;
    se = i.ise + e.tse;
    ds = i.ids + e.tds;
    
    std::cout << "\n\nTotal marks of student\n\n";
    std::cout << "Maths: " << maths << endl << endl;
    std::cout << "OOP:  "<< oop << endl << endl;
    std::cout << "SE: " << se << endl << endl;
    std::cout << "DS: " << ds << endl << endl;
    
    if(maths<50)
    {
        cout << "You have failed in Maths\n";
    }
    else
    {
        cout << "You have passed in Maths\n";
    }
    
    if(oop<50)
    {
        cout << "You have failed in OOP\n";
    }
    else
    {
        cout << "You have passed in OOP\n";
    }
    
    if(se<50)
    {
        cout << "You have failed in SE\n";
    }
    else
    {
        cout << "You have passed in SE\n";
    }
    
    if(ds<50)
    {
        cout << "You have failed in DS\n";
    }
    else
    {
        cout << "You have passed in DS\n";
    }
    
    cout << "\n\nTOTAL MARKS: " << (maths+oop+ds+se) << endl << endl;
    
    if(oop>=50 && ds>=50 && maths>=50 && se>=50)
    {
        cout << "Percentage achieved: " << ((maths+oop+ds+se)/4) << "%";
    }
}

int main()
{
    Internal1 i;
    External1 e;
    i.inputInternal();
    e.inputExternal();
    i+e;
}
