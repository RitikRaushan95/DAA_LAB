#include <iostream>
using namespace std;
static int x=0;
void TOH(int n, char a, char b, char c) {
    
    if (n == 1) {
        x++;
        return;
    }
    TOH(n - 1, a, c, b);
    x++;
    TOH(n - 1, c, b, a);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    TOH(n, 'A', 'C', 'B');
    cout<<"\nNumber of time function called "<<x;
    return 0;
}
