#include<iostream>
using namespace std;
int fibonacci(int a){
    if(a<=1) return a;
    else return fibonacci(a-2)+fibonacci(a-1);

}
int main(){
    int n;
    cout<<"Enter the number n for  nth fibonacci: ";
    cin>>n;
    cout<<fibonacci(n);
}