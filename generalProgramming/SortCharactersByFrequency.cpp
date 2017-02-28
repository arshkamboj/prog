//sort characters by frequency
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (auto c : s) {
            ++freq[c];
        }
        
        vector<string> counts(s.size() + 1);
        for (auto a : freq) {
            counts[a.second]=a.first;
        }
        
        string result;
        for (int count = counts.size() - 1; count >= 0; --count) {
            for (auto c : counts[count]) {
                result += string(count, c);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    string ss=s.frequencySort("ttreee");
    cout<<ss;
    return 0;
}