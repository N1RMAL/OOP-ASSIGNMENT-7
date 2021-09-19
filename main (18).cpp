#include <iostream>
#include <string.h>
using namespace std;

int i, num, j;

class Computer
{
    public:
    
    int num;
    string doctor[100], area[100];
    
    void input()
    {
        cout << "Enter number of doctors: \n";
        cin >> num;
        cout << "Enter name and area of the doctor: \n";
        for(i=0;i<num;i++)
        {
            cin >> doctor[i];
            cin >> area[i];
        }
    }
    
    friend void operator<(Computer, Computer);
};

void operator<(Computer, Computer)
{
    char ch[100];
    char ch2[100];
    for(int i=0;i<num;++i)
    {
        for(j=0;j<(num-1);++j)
        {
            if(strcmp(Computer.area[j], Computer.area[j+1])>0)
            {
                strcpy(ch, Computer.area[j]);
                strcpy(Computer.area[j], Computer.area[j+1]);
                strcpy(Computer.area[j+1], ch);
                
                strcpy(ch2, Computer.doctor[j]);
                strcpy(Computer.doctor[j], Computer.doctor[j+1]);
                strcpy(Computer.doctor[j+1], ch2);
            }
        }
    }
    
    cout << "The doctors arranged alphabetically area-wise are:";
    for(i=0;i<num;i++)
    {
        cout << Computer.area[i] << "  " << Computer.doctor[i];
    }
}

int main()
{
    Computer c;
    c.input();
    c<c;
}
