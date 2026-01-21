#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0;
        int hash[26] = {0};
        hash[s[0]-'a']++;
        int freq = 1;

        for(int r=0; r<s.length();){
            int cnt = 0;
            for(int i=0; i<26; i++){
                if(hash[i]==1){
                    cnt++;
                }
            }
            if(cnt == r-l+1){
                if(r!=s.size()-1){
                    hash[s[r+1]-'a']++;
                    freq = max(r-l+1, freq);
                    r++;
                }
                else{
                    freq = max(r-l+1, freq);
                    break;
                }
            }
            else{
                hash[s[l]-'a']--;
                l++;
            }
        }
        return freq;
    }
};

int main(){
    Solution sol;

    cout << sol.lengthOfLongestSubstring("abcabcbb");
}