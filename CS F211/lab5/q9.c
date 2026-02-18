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