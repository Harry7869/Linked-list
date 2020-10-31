#include<iostream>
using namespace std;

class A
{
    public :
        int x=20;
};
class B
{
    public :
        int x=10;
};

int main()
{
    A obj1;
    B obj2;
    obj1 = obj2;
    cout<< obj1.x;
    cout<<endl;
    return 0;
}
