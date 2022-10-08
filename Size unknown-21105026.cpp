#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;


//function for linear search

int linearsearch(int arr[], int x)
{
    for (int k = 0;; k++) 
    {
        if (arr[k] == x)
        {
            return k;
        }
    }
}


//function for binary search

int binarysearch_code(int arr[],int l,int r,int x)
{
    int mid = (l+r) / 2;
    while(l<=r)
    {
        if(arr[mid]>x)
        {
            r = mid - 1;
            mid = (l+r) / 2;
        }
        else if(arr[mid]<x)
        {
            l = mid+1;
            mid = (l+r) / 2;
        }
        else
        {
            return mid;
        }
    }

}

//increasing the range of our search exponentially by 2 

int binarysearch(int arr[], int x)
{
    int low = 0;
    int high = 1;

    while (arr[high] < x)
    {
        low = high;
        high = 2 * high;}

    return binarysearch_code(arr,low,high,x);
}



int main()
{
    
    int *arr = new int[1000];
    int n;
    cout << "number of elements in array : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter element to search for : ";
    cin >> x;
    cout << endl;

    cout << "Index of " << x << " from linear search is : " << linearsearch(arr, x) << endl;
    cout << "Index of " << x << " from binary search is : " << binarysearch(arr, x) << endl;
    delete[] arr;
}