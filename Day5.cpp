#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int j = n-2;
        
        for(j; j>=0; j--)
        {
            if(arr[j]<arr[j+1])
            {
                for(int i=n-1; i>j; i--)
                {
                    if(arr[i] > arr[j])
                    {
                        swap(arr[i],arr[j]);
                        break;
                    }
                }
                break;
            }
        }
        reverse(arr.begin()+j+1, arr.end());
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
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

