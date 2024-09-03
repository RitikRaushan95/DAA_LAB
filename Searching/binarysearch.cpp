#include<stdio.h>
#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> arr,int target){
    int i=0,j=arr.size()-1;
    int mid=(i+j)/2;
    while(i<=j){
        mid=(i+j)/2;
        if(arr[mid]==target)return true;
        if(arr[mid]>target){
            j=mid-1;
        }
        else i=mid+1;
    }
    return false;
}
int main(){
    int n,target;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter all the elements in array \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter your target \n";
    cin>>target;
    cout<<"Entered array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    if(binarySearch(arr,target))cout<<"\nTarget element found through binary search";
    else cout<<"\nTarget element not found";
    return 0;
}