#include <iostream>
#include <string>

using namespace std;

int hash_main[26] = {0};
int hash_sub[26] = {0};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1 > l2) return false;
        if(l1 == 0) return true;
        bool flag;
        for(int i = 0; i < l1; i++) {
            hash_main[(int)s1[i] - 'a'] += 1;
        }
        for(int i = 0; i < l1; i++) {
            hash_sub[(int)s2[i] - 'a'] += 1;
        }
        for(int i = 0; i + l1 - 1 < l2; i++) {
            if(i != 0) {
                hash_sub[(int)s2[i-1] - 'a'] -= 1;
                hash_sub[(int)s2[i+l1-1] - 'a'] += 1;
            }
            flag = true;
            for(int j = 0; j < 26; j++) {
                if(hash_main[j] != hash_sub[j]) flag = false;
            }
            if(flag) return true;
        }
        return false;
    }
};