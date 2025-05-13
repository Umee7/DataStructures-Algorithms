#include<bits/stdc++.h>
using namespace std;

// My first Approach -
// void isSorted(int arr[], int size)
// {
//     for(int i = 0; i < size - 1; i++)
//     {
//         if(arr[i] > arr[i+1])
//         {
//             cout<<"false";
//             return;
//         }
//     }
//     cout<<"true";
// };

// Optimal Approach -
bool isSorted(int arr[], int size)
{
    // Edge case
    if(arr==nullptr || size < 0)
    {
        return false;
    }
    
    for(int i = 0;i<size-1;i++)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}


int main() 
{
    int arr[] = { 1, 2, 3, 4, 5};
    // isSorted(arr, 5);
    
    cout<<(isSorted(arr, 5) ? "true" : "false");
}