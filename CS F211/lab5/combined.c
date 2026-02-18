//q1
#include<stdio.h>
#include<stdlib.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[100][100]={{0}};
    int prefix[100][100]={{0}};

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int a1, b1, a2, b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            prefix[i][j]= arr[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            printf("%d ", prefix[i][j]);
        }
        printf("\n");
    }

    int sum=prefix[a2][b2]-prefix[a1-1][b2]-prefix[a2][b1-1]+prefix[a1-1][b1-1];
    printf("%d\n", sum);
    return 0;
}


//q2

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *a = malloc(n*sizeof(*a));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int i=0;
    int j=1;
    int diff=a[j]-a[i];

    int ans_i=0;
    int ans_j=1;
    int ans_len=2;

    // while(i<n-1 && i<j){
    //     for(j=i+1; j<n-1; j++){
    //         if(a[j+1]-a[j]!=diff){
    //             diff=a[j+1]-a[j];
    //             if(ans<j-i){
    //                 ans_i=i;
    //                 ans_j=j;
    //                 ans=j-i;
    //             }
    //         }
    //     }
    //     i++;
    // }

    for(j=2; j<n; j++){
        if(a[j]-a[j-1]!=diff){
            diff=a[j]-a[j-1];
            i=j-1;
        }

        if(j-i+1>ans_len){
            ans_i=i;
            ans_j=j;
            ans_len=j-i+1;
        }
    }

    printf("%d %d", ans_i+1, ans_j+1);


    free(a);
    return 0;
}


//q3

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int a[N+1];
    int total = 0;

    for(int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
        total ^= a[i];
    }

    int left = 0;
    for(int i = 2; i <= N-1; i++) {
        left ^= a[i-1];
        int right = total ^ left ^ a[i];
        if(left == right)
            printf("%d ", i);
    }
    return 0;
}



//q4

#include<stdio.h>
#include<stdlib.h>

int canPlace(int *a, int n, int k, int max){
    int count=1;
    int last=a[0];

    for(int i=1; i<n; i++){
        if(a[i]-last>=max){
            count++;
            last=a[i];
        }
    }
    return count>=k;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = malloc(n*sizeof(*a));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }


    int low=0;
    int high=a[n-1];
    int ans;

    while(low<=high){
        int mid=(low+high)/2;
        
        if(canPlace(a, n, k, mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    printf("%d\n", ans);
    free(a);
    return 0;
}


//q5

#include<stdio.h>
#include<stdlib.h>

int divisors(int x){
    int c=0;
    for(int i=1; i*i<=x; i++){
        if(x%i==0){
            c++;
            if(i*i!=x){
                c++;
            }
        }
    }
    return c;
}

int main(){
    int n;
    scanf("%d", &n);

    int *a = malloc(n*sizeof(*a));
    int *d=malloc(n*sizeof(*d));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        d[i]=divisors(a[i]);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((d[i]>d[j]) || (d[i]==d[j] && a[i]<a[j])){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=d[i];
                d[i]=d[j];
                d[j]=temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    free(d);
    return 0;
}


//q6

#include<stdio.h>
#include<stdlib.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[100][100]={{0}};

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int layers;
    
    if(m<n){
        layers=m/2;
    }
    else{
        layers=n/2;
    }
    
    

    for(int l=0; l<layers; l++){
        
        int k=0; int temp[100];
        for(int j=l; j<n-l; j++){
            temp[k]=arr[l][j];
            k++;
        }

        for(int i=l+1; i<m-l-1; i++){
            temp[k]=arr[i][n-l-1];
            k++;
        }

        for(int j=n-l-1; j>=l; j--){
            temp[k]=arr[m-l-1][j];
            k++;
        }

        for(int i=m-l-2; i>l; i--){
            temp[k]=arr[i][l];
            k++;
        }
        
        int rotate;
        int id=0;

        if(l%2==0){
        rotate=k-1;
        }
        else{
            rotate=1;
        }
        
        for(int j=l; j<n-l; j++){
            arr[l][j]=temp[(id+rotate)%k];
            id++;
        }

        for(int i=l+1; i<m-l-1; i++){
            arr[i][n-l-1]=temp[(id+rotate)%k];
            id++;
        }

        for(int j=n-l-1; j>=l; j--){
            arr[m-l-1][j]=temp[(id+rotate)%k];
            id++;
        }

        for(int i=m-l-2; i>l; i--){
            arr[i][l]=temp[(id+rotate)%k];
            id++;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}



//q7

#include<stdio.h>
#include<stdlib.h>

int partition(int *arr, int l, int r){
    int p=arr[r]; int i=l;
    for(int j=l; j<r; j++){
        if(arr[j]>p){
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
        }
    }
    int temp=arr[i];
    arr[i]=arr[r];
    arr[r]=temp;
    return i;
}


int quickSelect(int *arr, int l, int r, int k){
    if(l<=r){
        int p=partition(arr, l, r);
        if(p==k){
            return arr[p];
        }
        else if(p>k){
            return quickSelect(arr, l, p-1, k);
        }
        else{
            return quickSelect(arr, p+1, r, k);
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    int ans=quickSelect(arr, 0, n-1, k-1);
    printf("%d", ans);
    free(arr);
    return 0;
}


//q8

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int intervals[100][2];

    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(intervals[i][0]>intervals[j][0]){
                int temp1=intervals[i][0]; int temp2=intervals[i][1];
                intervals[i][0]=intervals[j][0]; intervals[i][1]=intervals[j][1];
                intervals[j][0]=temp1; intervals[j][0]=temp2; 
            }
        }
    }

    int s=intervals[0][0]; int e=intervals[0][1];

    for(int i=1; i<n; i++){
        if(intervals[i][0]<=e){
            if(intervals[i][1]>e){
                e=intervals[i][1];
            }
        }
        else{
                printf("%d %d\n", s, e);
                s=intervals[i][0];
                e=intervals[i][1];
            }
    }
    printf("%d %d\n", s, e);
    return 0;
}


//q9

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *a = malloc(n*sizeof(*a));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }


    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    int found=0;

    for(int i=0; i<n-2; i++){
        if(i>0 && a[i]==a[i-1]){
            continue;
        }

        int left=i+1;
        int right=n-1;

        while(left<right){
            int sum=a[i]+a[left]+a[right];

            if(sum==0){
                printf("%d %d %d\n", a[i], a[left], a[right]);
                found=1;
                
                while((left<right) && a[left]==a[left+1]){
                    left++;
                }

                while((left<right) && a[right]==a[right-1]){
                    right--;
                }

                left++;
                right--;
            }

            else if(sum<0){
                left++;
            }

            else{
                right--;
            }
        }
    }

    if(!found){
        printf("No triplets found\n");
    }

    free(a);
    return 0;
}


//q10

#include<stdio.h>
#include<stdlib.h>

int max(int *a, int n){
    int max=a[0];
    for(int i=1; i<n; i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}

void countSort(int *a, int n, int exp){
    int out[100]={0}; int c[10]={0};

    for(int i=0; i<n; i++){
        c[(a[i]/exp)%10]++;
    }

    for(int i=1; i<10; i++){
        c[i]+=c[i-1];
    }

    for(int i=n-1; i>=0; i--){
        out[c[(a[i]/exp)%10]-1]=a[i];
        c[(a[i]/exp)%10]--;
    }

    for(int i=0; i<n; i++){
        a[i]=out[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *a = malloc(n*sizeof(*a));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int m=max(a, n);
    for(int exp=1; m/exp>0; exp*=10){
        countSort(a, n, exp);
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    free(a);
    return 0;
}