#include "bits/stdc++.h"
using namespace std;

int main(){
    set<int> st;
    st.insert(1); // {1}
    st.insert(10); // {1, 10}
    st.insert(8);  // {1, 8, 10}
    st.insert(1);  // {1, 8, 10}
    auto it1 = st.begin(); // points to the first element
    auto it2 = st.find(8); // points to 8
    auto it3 = st.find(2); // points to st.end()
    cout << *it1 << "\n";
    cout << *it2 << "\n";
    cout << *it3 << "\n";


}