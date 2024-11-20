#include<iostream>
#include<vector>
using namespace std;

void mergeSort(vector<int> &arr, int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    vector<int> arr1(n1);
    vector<int> arr2(n2);

    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[m+i+1];
    }
    
    int i=0,j=0,k=l;
    while(i< arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    while(i< arr1.size()){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j< arr2.size()){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}

void merge(vector<int> &arr,int l,int r){
    if(l<r){
        int m=(l+r)/2;
        merge(arr,l,m);
        merge(arr,m+1,r);
        mergeSort(arr,l,m,r);
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
    merge(arr,0,n-1);
    cout<<"\nSorted array is \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
