#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    vector<string> name = {"Muddasir","Ali"};

    //To show each character of vector of type string
    /*for(string i:name)
    {
        for(char c:i)
        cout<<c<<endl;
    }*/

    /*for(string i:name)
    {
        for(int j=0;j<i.length();j++)
        cout<<i[j]<<endl;
    }*/

    //Get character at spacific index
    /*for (char c : name[1])
    {
        cout << c << endl;
    }*/

    //Get length of total vector
    /*
    int total = 0;
    for(string s:name)
    {
        total += s.length();
    }
    cout<<"Total length = "<<total<<endl;*/

    //Get length of spacific index
    /*int toa = 0;
    for(char s:name[1])
    {
        toa++;
    }
    cout<<toa<<endl;*/

    cout<<name.front()<<endl;
    cout<<name.back()<<endl;
    name.push_back("Muzamil");
    cout<<name.back()<<endl;
    cout<<name.size()<<endl;
    cout<<name.at(2);

}