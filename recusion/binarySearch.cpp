#include<iostream>
#include<vector>
using namespace std;

void makeArray(vector<int> &a, int n) {
    for(int i=0;i<n;i++)
        cin >>a[i];
}

int binarSearch(vector<int> a, int i, int j,int target){
    if(i>j)return -1;
    int mid=(i+j)/2;
    if(a[mid]==target){
        return mid+1;
    }
    if(a[mid]<target)return binarSearch(a, mid + 1, j, target);
    else return binarSearch(a,i,mid-1,target);
}

int main() {
    vector<int> help(5);
    makeArray(help, 5);
    int target;
    cout << "Enter the Target: ";
    cin >> target;

    int result = binarSearch(help, 0, 4, target);
    if(result != -1)
        cout << "Element is found at: " << result << endl;
    else
        cout << "Element is not found" << endl;
    return 0;
}