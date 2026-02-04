#include <stdio.h>
#include <stdlib.h>

struct Student{
    int marks ;
    int delay;
};

void sort(struct Student arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].marks<arr[j].marks || (arr[i].marks==arr[j].marks && arr[i].delay>arr[j].delay)){
                struct Student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

struct Student s[200];

for(int i=0;i<n;i++){
    scanf("%d" "%d", &s[i].marks,&s[i].delay);

}

sort(s,n);

for (int i = 0; i < n; i++)
        printf("%d %d\n", s[i].marks, s[i].delay);



    return 0;
}
