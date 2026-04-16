#include<iostream>
#include<vector>
#include<string>
#include <climits> 
using namespace std;

int reverse(vector<int> &name)
{
    int cSum = 0;
    int maxSum = INT_MIN;
    for(int value : name)
    {
        cSum += value;
        maxSum = max(cSum,maxSum);

        if(cSum < 0)
            cSum = 0;
    }

    return maxSum;
}

int main()
{
    vector<int> name = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<"Max Sum is :" <<reverse(name);

}