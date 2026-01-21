#include "bits/stdc++.h"
using namespace std;


void printP1(char s, int n){
    for(int i=0; i<n; i++){
        for(int j=n-i; j>0; j--){
            cout << s;
        }

        cout << "\n";
    }
}

void printP2(char s, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << s;
        }
        cout << "\n";
    }
}

void printP3(){
    for(int i=0; i<5; i++){
        for(int j=1; j<=i+1; j++){
            cout << j;
        }
        cout << "\n";
    }
}

void printP4(){
    for(int i=0; i<5; i++){
        for(int j=0; j<=i; j++){
            cout << i+1;
        }
        cout << "\n";
    }
}

void printP5(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5-i; j++){
            cout << j+1;
        }
        cout << "\n";
    }
}

void printP6(char s, int n){
    int p = (2*n)-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=p; j++){
            if(j>((p+1)/2-i) && j<((p+1)/2+i)){
                cout << s;
            }
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void printP7(char s, int n){
    int p = (2*n)-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=p; j++){
            if(j>=((p+1)/2-(n-i)) && j<=((p+1)/2+(n-i))){
                cout << s;
            }
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int main(){
    char s;
    cout << "type char: " << "\n";
    cin >> s;
    int n = 10;
    printP6(s, n);
}