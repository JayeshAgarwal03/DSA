#include<stdio.h>
#include<string.h>

int main(){
    char str[50]; char result[50];
    printf("Enter String: ");
    scanf("%s", &str);
    int n = strlen(str);
    int j = 0;

    for(int i=0; i<n; i++){
        int count = 1;
        result[j] = str[i];
        while(i<n-1 && str[i] == str[i+1]){
            count++; i++;
        }
        result[j+1] = '0' + count;
        j += 2;
    }
    result[j] = '\0';

    if(n<strlen(result)){
        for(int i=0; i<n; i++){
            printf("%c", str[i]);
        }
    }
    else{
        for(int i=0; i<strlen(result); i++){
            printf("%c", result[i]);
        }
    }
    return 0;
}