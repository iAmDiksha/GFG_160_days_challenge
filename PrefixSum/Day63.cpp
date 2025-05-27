// C++ program to find longest subarray with equal 
// number of 0's and 1's Using Hashmap and Prefix Sum
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
      int maxLen(vector<int> &arr) {
          unordered_map<int,int> mp;
          int psum =0, res =0;
          
          for(int i=0; i<arr.size(); i++)
          {
              psum += (arr[i]==0)?-1:1;
              if(psum == 0) res = i+1;
              if(mp.find(psum) != mp.end()) res = max(res,i-mp[psum]);
              else mp[psum]=i;
          } 
          return res;
      }
  };

int main() {
    Solution ob;
    vector<int> arr = {0, 1, 0, 1, 1, 0};
    int result = ob.maxLen(arr);
    cout << result << endl; // Output: 6 (subarray [0, 1, 0, 1, 1, 0])
    return 0;
}