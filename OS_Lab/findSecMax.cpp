#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findKMax(vector<int> a, int k ){
    sort(a.begin(),a.end());
    return a[a.size()-k];
}
int main(){
    int n;
    cout<<"Enter the Size of the array\n";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n";
    cout<<"Entered array is\n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    int k;
    cout<<"\nEnter the max number you want\n";
    cin>>k;
    cout<<"\nThe "<<k<<"th "<< "largest value is"<< findKMax(arr,k);
    return 0;
}

