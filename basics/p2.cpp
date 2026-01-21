#include "bits/stdc++.h"
using namespace std;

int main(){
    int x;
    cin >> x;
    if(x>10 && x<20){
        cout << "TeenAge";
    }
    else if(x>=20){
        cout << "Adult";
    }
    else{
        cout << "Child";
    }
}