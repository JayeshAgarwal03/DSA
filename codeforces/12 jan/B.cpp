#include<iostream>
using namespace std;

int state(int flips, int s, int k){
    int sandleft = s;
    for(int i=0; i<flips; i++){
        sandleft = s- max(sandleft-k, 0);
    }
    return sandleft;
}

void solve(){
    int s, k, m;
    cin >> s >> k >> m;
    int remaining = m%k;
    int flips = m/k;
    int t1;
    if(s<=k && k>m){
        t1 = s;
    }
    else{
        t1 = state(flips, s, k);
    }
    int t = max(t1-remaining,0);
    // int t = max(state(flips, s, k)-remaining,0);
    cout << t << "\n";
    
}

int main(){
    int t;
    cin >> t;
    while(t!=0){
        solve();
        t--;
    }
}