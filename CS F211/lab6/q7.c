#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int numStack[100]; int topNum=-1;
char strStack[100][100]; int strTop=-1;

void pushNum(int x){
    numStack[++topNum]=x;
}

int popNum(){
    return numStack[topNum--];
}

void pushStr(char *s){
    strcpy(strStack[++strTop], s);
}

void popStr(char *s){
    strcpy(s, strStack[strTop--]);
}

int main(){
    int n;
    scanf("%d", &n);

    char s[100];
    char curr[100]="";
    scanf("%s", &s);

    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            int num=0;
            while(isdigit(s[i])){
                num=(num*10)+(s[i]-'0');
                i++;
            }
            pushNum(num);
            i--;
        }

        else if(s[i]=='['){
            pushStr(curr);
            curr[0]='\0';
        }
        else if(s[i]==']'){
            char temp[100]=""; char prev[100];
            int k=popNum();
            popStr(prev);
            for(int j=0; j<k; j++){
                strcat(temp, curr);
            }
            strcpy(curr, prev);
            strcat(curr, temp);
        }
        else{
            int len=strlen(curr);
            curr[len]=s[i];
            curr[len+1]='\0';
        }
    }

    printf("%s", curr);
    return 0;

}