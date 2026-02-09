#include<iostream>
using namespace std;
class rectangle
{
    float length;
    float width;
    float area;
    float perimeter;
public:
    void input()
    {
        cout<<"Enter the length"<<endl;
        cin>>length;
        cout<<"Enter the width"<<endl;
        cin>>width;
        area=length*width;
        perimeter=2*(length+width);
    }
    void output()
    {
        cout<<"The area is:"<<endl;
        cout<<area<<endl;
        cout<<"The perimeter is:"<<endl;
        cout<<perimeter;
    }
};
int main()
{
    int n;
    rectangle r[n];
    cout<<"Enter the value of N"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        r[i].input();
    }
    for(int i=0;i<n;i++)
    {
        r[i].output();
    }
}
