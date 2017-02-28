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
        for (const auto& c : s) {
            ++freq[c];
        }
            
        vector<string> counts(s.size() + 1);
        for (const auto& kvp : freq) {
            counts[kvp.second].push_back(kvp.first);
        }
            
        string result;
        cout<<counts.size()<<endl;
        for (int count = counts.size() - 1; count >= 0; --count) {
            for (const auto& c : counts[count]) {
                cout<<string(count,c)<<endl;
                result += string(count, c);
            }
        }
        
        return result;
    }
};

int main(){
    Solution s;
    string ss=s.frequencySort("tree");
    cout<<ss;
    return 0;
}