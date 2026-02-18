#include <iostream>
#include <vector>
using namespace std;

bool solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    for(int i=1; i<=n/2; i++){
        if(v[i-1]>v[(2*i)-1]){
            int temp=v[i-1];
            v[i-1]=v[(2*i)-1];
            v[(2*i)-1]=temp;

            if(i%2==0){
                int j=i/2;
                while(j!=0){
                    if(v[j-1]>v[(2*j)-1]){
                        int temp1=v[j-1];
                        v[j-1]=v[(2*j)-1];
                        v[(2*j)-1]=temp1;
                    }
                    j/=2;
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(v[i-1]!=i){
            return false;
        }
    }
    
    return true;

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