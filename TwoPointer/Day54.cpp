#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int res = 0;
        int n = arr.size();
        int left = 0, right = n -1;
        while(left<right)
        {
            int sum = arr[left]+arr[right];
            if(sum < target)
            {
                left++;
            }
            else if(sum > target)
            {
                right--;
            }
            else{
                int cnt1 = 0, cnt2 = 0;
                int ele1 = arr[left], ele2 = arr[right];
                while(left<=right && arr[left] == ele1)
                {
                    left++;
                    cnt1++;
                }
                while(left<=right && arr[right]==ele2)
                {
                    right--;
                    cnt2++;
                }
                if(ele1 == ele2)
                {
                    res += (cnt1*(cnt1-1))/2;
                }
                else{
                    res += (cnt1*cnt2);
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends