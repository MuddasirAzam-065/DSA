#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reverse(vector<string> &name)
{
    int start = 0;
    int end = name.size()-1;
    while(start < end)
    {
        string temp = name[start];
        name[start] = name[end];
        name[end] = temp;
        start++;
        end--;
    }

    for(string n:name)
    {
       cout<<n<<endl;
    }
}

int main()
{
    vector<string> name = {"Muddasir","Ali"};

    reverse(name);

}