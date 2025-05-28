#include<bits/stdc++.h>
using namespace std;
// C++ program to find product of array except self
// Using Two Passes and Handling Zeroes
class Solution {
    public:
      vector<int> productExceptSelf(vector<int>& arr) {
          vector<int> v;
          int prod = 1;
          int zeroes =0;
          for(int i=0; i<arr.size();i++){
              if(arr[i]!=0) prod *= arr[i];
              else zeroes++;
          }
           
               if(zeroes >= 2) {
                   for(int i=0; i<arr.size();i++)
                   v.push_back(0);
               }
               
               else if(zeroes == 1){
                  for(int i=0; i<arr.size();i++)
                   {
                       if(arr[i] !=0){
                       v.push_back(0);
                   }
                   else{
                       v.push_back(prod);
                   }
                   }
               }
               else {
                   for(int i=0; i<arr.size();i++)
                   v.push_back(prod/arr[i]);
               }
              
           
           return v;
      }
  };
  
int main() {
    Solution ob;
    vector<int> arr = {1, 2, 3, 4};
    vector<int> result = ob.productExceptSelf(arr);
    for(int i : result) {
        cout << i << " "; // Output: 24 12 8 6
    }
    cout << endl;
    return 0;
}