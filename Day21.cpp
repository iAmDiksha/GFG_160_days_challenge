#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int low = 0;
        int mid =0;
        int high = arr.size()-1;
        while(mid <=high)
        {
            if(arr[mid] == 0)
            {
                swap(arr[mid],arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 2)
            {
                swap(arr[mid],arr[high]);
                high--;
            }
            else{
                mid++;
            }
        }
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends