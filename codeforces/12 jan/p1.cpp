#include<iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int teamOf3 = n/3;
    int left3 = n%3;
    int teamOf2 = left3/2;
    int left2 = left3%2;
    int t2;
    if(left2 != 0){
        teamOf2++;
        t2 = ((teamOf2%2) *2)-1;
    }
    else{
        t2 = (teamOf2%2) *2;
    }

    int t3 = (teamOf3%2) *3;

    cout << abs(t3-t2) << "\n";

    
}

int main(){
    int t;
    cin >> t;
    while(t!=0){
        solve();
        t--;
    }
}