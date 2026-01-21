#include "bits/stdc++.h"
using namespace std;

void vectorSpace(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    int *i = v.data();
    cout << *i << "\n";
    i++;i++;
    cout << *i << "\n";
}

int main(){
    int a = 0;
    int *p = &a;
    auto q = &p;
    
    cout << a << "\n";  //0
    cout << p << "\n";  //6135752732
    cout << q << "\n";  //6135752720
    cout << "\n";
    cout << *p <<"\n";    //0
    cout << *q << "\n";   //6135752732
    cout << **q << "\n";  //0

    vectorSpace();
}

