#include<stdio.h>
#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;
bool linearSearch(vector<int> arr,int target){
    for(auto a:arr){
        if(a==target)return true;
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
    cout<<"Entered array is ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    if(linearSearch(arr,target))cout<<"\nTarget element found through linear search";
    else cout<<"\nTarget element not found";
    return 0;
}