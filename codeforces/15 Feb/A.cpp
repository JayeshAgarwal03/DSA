#include <iostream>
#include <vector>
using namespace std;

string solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int x=0;
    int y=0;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(v[i]==67){
            x=v[i];
        }
        else if(v[i]==1){
            y=v[i];
        }
    }

    if((x!=0 && y!=0) || (x!=0)){
        return "YES";
    }
    else{
        return "NO";
    }

}

int main(){
    int t;
    cin >> t;

    while(t!=0){
        string s = solve();
        cout << s;
        cout << endl;
        t--;
    }
}