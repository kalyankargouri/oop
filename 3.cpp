#include<iostream>
using namespace std;
int main()
{
    int x,i;
    cout<<"enter number:";
    cin>>x;
    cout<<"the multification table is:"<<x;
    for(i=1;i<=10;i++)
    {
        cout<<"\n"<<x*i;
    }
}
