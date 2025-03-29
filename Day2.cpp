#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int low = -1;
        int high;
        
     for(int i=0; i<arr.size(); i++)
     {
         if(arr[i] == 0)
         {
             low = i;
             break;
         }
     }
     if(low == -1)
     {
         return;
     }
     high = low+1;
     
     while(high <arr.size())
     {
         if(arr[high] != 0)
         {
             swap(arr[low],arr[high]);
             low++;
         }
         high++;
     }
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.pushZerosToEnd(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
