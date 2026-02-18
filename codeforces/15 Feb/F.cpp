#include <iostream>
#include <vector>
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<vector<int>> v(n);

    for(int i=0; i<n; i++){
        vector<int> v_i(3);
        for(int j=0; j<3; j++){
            cin >> v_i[j];
        }
        v[i] = v_i;
    }

    vector<int> y(n);

    for(int i=0; i<n; i++){
        // y[i]=(-(v[i][1]/v[i][0]));
        y[i]=(((4*v[i][0]*v[i][2])-(v[i][1]*v[i][1]))/(4*v[i][0]));
    }
    vector<vector<int>> ans(n);

    for(int i=0; i<n; i++){
        vector<int> ans_i;
        for(int j=0; j<n; j++){
            if(i==j){
                continue;
            }
            
            
        }
    }

}

int main(){
    int t;
    cin >> t;

    while(t!=0){
        bool b = solve();
        if(b==true){
            cout << "Yes";
            cout << endl;
        }
        else{
            cout << "No";
            cout << endl;
        }
        
        t--;
    }
}
