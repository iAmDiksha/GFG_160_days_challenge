#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
      int maxWater(vector<int> &arr) {
         int l=0, r=arr.size()-1;
         int res =0;
         while(l<r)
         {
             int water = min(arr[l],arr[r])*(r-l);
             res = max(res,water);
             
             if(arr[l]<arr[r]){
                 l++;
             }
             else{
                 r--;
             }
         }
         return res;
      }
  };

int main() {
    Solution ob;
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = ob.maxWater(arr);
    cout << result << endl; // Output: 49
    return 0;
}