#include<iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    map<long long, int> prefix;
    int ans=0;
    int prefixSum=0;

    for(int i=0; i<n; i++){
        prefixSum+=arr[i];

        if(prefixSum==0){
            ans=max(ans, i+1);
        }

        else if(prefix.find(prefixSum)!=prefix.end()){
            ans=max(ans, i-prefix[prefixSum]);
        }

        if(prefix.find(prefixSum)==prefix.end()){
            prefix[prefixSum]=i;
        }
    }

    cout << ans;
}








//following code works but has time complexity of O(n^2)
// #include<stdio.h>
// #include<stdlib.h>

// int main(){
//     int n;
//     scanf("%d", &n);
//     int ans=-1;

//     int *arr=malloc(n*sizeof(*arr));
//     int *map=malloc(n*sizeof(*map));

//     for(int i=0; i<n; i++){
//         scanf("%d", &arr[i]);
//     }

//     int prefixSum=0;
//     for(int i=0; i<n; i++){
//         prefixSum+=arr[i];
//         printf("%d\n", prefixSum);
//         if(prefixSum==0){
//             if(ans<i+1){
//                 ans=i+1;
//             }
//         }
//         else{
//             for(int j=0; j<i; j++){
//                 if(map[j]==prefixSum){
//                     if(ans<i-j){
//                         ans=i-j;
//                     }
//                     break;
//                 }
//             }
//         }


        
//         map[i]=prefixSum;
//     }
//     for(int i=0; i<n; i++){
//         printf("%d ", map[i]);
//     }
    
//     printf("\n%d", ans);
//     free(map);
//     free(arr);
//     return 0;
// }