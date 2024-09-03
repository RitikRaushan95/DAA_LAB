#include<stdio.h>
#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

bool bubbleSort(vector<int> &arr){
   for(int i=0;i<arr.size();i++){
    for(int j=i;j<arr.size();j++){
        if(arr[i]>arr[j])swap(arr[i],arr[j]);
    }
   }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter all the elements in array \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Entered array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    bubbleSort(arr);
    cout<<"Sorted array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}