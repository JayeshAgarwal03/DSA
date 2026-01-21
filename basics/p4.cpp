#include "bits/stdc++.h"
using namespace std;

int calculateFactorial(int n){
    int f = n;
    if(f <= 0 || f == 1){
        return 1;
    }
    else{
        return f*calculateFactorial(f-1);
    }
}

int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    int f = calculateFactorial(n);
    cout << f;
}