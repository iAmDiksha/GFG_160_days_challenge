#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int cnt = 0;
        for(int i=0; i<arr.size(); i++)
        {
            int left = i+1;
            int right = arr.size()-1;
            
            while(left<right)
            {
                int sum = arr[left]+arr[right]+arr[i];
                
                if(sum == target)
                {
                    int ele1 = arr[left], ele2 = arr[right];
                    int cnt1 = 0, cnt2 =0;
                    while(left<=right && arr[left] == ele1)
                    {
                        left++;
                        cnt1++;
                    }
                    while(left<=right && arr[right] == ele2)
                    {
                        right--;
                        cnt2++;
                    }
                    if(ele1 == ele2)
                    {
                        cnt += (cnt1*(cnt1-1))/2;
                    }
                    else{
                        cnt += cnt1*cnt2;
                    }
                }
                else if(sum < target)
                {
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends