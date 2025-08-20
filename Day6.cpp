#include <iostream>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    int n = arr.size();
    long long prefixSum = 0;
    unordered_map<long long, vector<int>> hashmap; 
    vector<pair<int, int>> result;

    // Prefix sum = 0 before array starts
    hashmap[0].push_back(-1);

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (hashmap.find(prefixSum) != hashmap.end()) {
            for (int startIndex : hashmap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        hashmap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};

    vector<pair<int, int>> res = findZeroSumSubarrays(arr);

    for (auto &p : res) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
