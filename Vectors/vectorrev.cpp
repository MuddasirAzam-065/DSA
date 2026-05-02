#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reverse(vector<string> &name)
{

    for (int i = 0; i < name.size(); i++)
    {
        int start = 0;
        int end = name[i].length() - 1;

        while (start < end)
        {
            char temp = name[i][start];
            name[i][start] = name[i][end];
            name[i][end] = temp;

            start++;
            end--;
        }
    }

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