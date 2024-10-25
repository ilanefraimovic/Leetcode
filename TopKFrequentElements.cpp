#include "includes.h"
/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
using namespace std;
class Solution {
private:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    vector<int> sortAndCompile(map<int, int> freq, int k){
        vector<pair<int, int>> freqVector;
        vector<int> out;
        for (auto& it : freq) {
            freqVector.push_back(it);
        }
        std::sort(freqVector.begin(),freqVector.end(),cmp);
        int counter = 0;
        for (auto& it : freqVector) {
            if (counter == k) {
                return out;
            }
            out.push_back(it.first);
            counter++;
        }
        return out;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> myMap;
        for (int i = 0; i < nums.size();i++) {
            myMap[nums[i]]++;
        }
        return sortAndCompile(myMap, k);

    }
};