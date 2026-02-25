#include<iostream>
#include<vector>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int count=0;
    for(int i=0; i<n; i++){
        if(i==0 && (v[i]+v[i+1]==7||v[i]==v[i+1])){
            for(int j=1; j<=6; j++){
                if(j!=v[i] && j!=7-v[i+1]){
                    v[i]=j;
                    break;
                }
            }
            count++;
        }
        else if(i==n-1 && (v[i]+v[i-1]==7||v[i]==v[i-1])){
            for(int j=1; j<=6; j++){
                if(j!=v[i] && j!=7-v[i-1]){
                    v[i]=j;
                    break;
                }
            }
            count++;
        }
        else if((i!=0 && i!=n-1) && (v[i]+v[i-1]==7||v[i]==v[i-1]) || (v[i]+v[i+1]==7||v[i]==v[i+1])){
            for(int j=1; j<=6; j++){
                if(j!=7-v[i-1] && j!=v[i] && j!=7-v[i+1]){
                    v[i]=j;
                    break;
                }
            }
            count++;
        }
    }
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }

    cout << "\n";
    cout << count << "\n";
}





int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}