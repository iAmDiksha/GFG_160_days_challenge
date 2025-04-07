#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        bool visited[n]={false};
        
        for(auto ele : arr)
        {
            if(ele > 0 && ele <=n)
            {
                visited[ele-1] = true;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(visited[i] == false)
            {
                return i+1;
            }
        }
        return n+1;
    }
};

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
