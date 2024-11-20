#include<iostream>
#include<vector>
using namespace std;

void makeArray(vector<int> &a, int n) {
    for(int i=0;i<n;i++)
        cin >>a[i];
}

int linearSearch(vector<int> a, int i, int target) {
    if (i>=a.size()) {
      return -1;
    }
    if (a[i]==target){
      return i + 1;
    }
    return linearSearch(a, i + 1, target);
}

int main() {
    vector<int> help(5);
    makeArray(help, 5);
    int target;
    cout << "Enter the Target: ";
    cin >> target;

    int result = linearSearch(help, 0, target);
    if(result != -1)
        cout << "Element is found at: " << result << endl;
    else
        cout << "Element is not found" << endl;
    return 0;
}
