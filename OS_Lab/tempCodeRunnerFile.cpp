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
    cin>>n;
    cout<<"Enter the Size of the array";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n";
    cout<<"Entered array is";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    int k;
    cout<<"Enter the max number you want";
    cin>>k;
    cout<<"The "<<k<<"th "<< "largest value is"<< findKMax(arr,k);
    return 0;
}

