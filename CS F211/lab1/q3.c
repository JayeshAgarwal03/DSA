#include<stdio.h>
#include<string.h>

int main(){
    char str[50];
    printf("Input: ");
    scanf("%[^\n]s", &str);
    int wordCount = 0;
    int vowelCount = 0;
    int n = strlen(str);
    char revStr[n];

    if(n!=0){
        wordCount = 1;
        for(int i=0; i<n; i++){
            if(str[i] == ' '){
                wordCount++;
            }
            if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'
            || str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                vowelCount++;
            }

            revStr[i] = str[n-i-1];
        }
    }

    printf("Words: %d \n", wordCount);
    printf("Vowels: %d \n", vowelCount);
    printf("Reversed: %s \n", revStr);

    return 0;
}