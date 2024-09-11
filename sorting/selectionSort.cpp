#include<stdio.h>
#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr){
   for(int i=0;i<arr.size()-1;i++){
    int y=i;
    for(int j=i+1;j<arr.size();j++){
        if(arr[y]>arr[j])
        y=j;
    }
    if(y!=i){
        int temp=arr[y];
        arr[y]=arr[i];
        arr[i]=temp;
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
    selectionSort(arr);
    cout<<"Sorted array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}