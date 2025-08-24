#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end()); // sort characters in string
        mp[key].push_back(s);        // group by sorted key
    }

    vector<vector<string>> result;
    for (auto& pair : mp) {
        result.push_back(pair.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    // Print result
    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << "\"" << ans[i][j] << "\"";
            if (j < ans[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < ans.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
