#include "bits/stdc++.h"
using namespace std;

int main(){
    cout << "DSA" << "\n";
    cout << "Enter Que no.";
    string s;
    int x;
    cin >> x;
    cout << "Question no. is" << x << "\n";
    cout << "type string: " << "\n";
    cin >> ws;      //to skip the leading whitespace or newline left in the input buffer by cin << x
    getline(cin, s);
    cout << "You typed: " << s;

    return 0;
}
