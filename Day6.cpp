#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;
        for(int ele : arr)
        {
            if(ele == ele1){
                cnt1++;
            }
            else if(ele == ele2)
            {
                cnt2++;
            }
            else if(cnt1 == 0)
            {
                ele1 = ele;
                cnt1++;
            }
            else if(cnt2 == 0)
            {
                ele2 = ele;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0;
        cnt2 = 0;
        for(int ele: arr)
        {
            if(ele == ele1) cnt1++;
            else if(ele == ele2) cnt2++;
        }
        vector<int> res;
        if(cnt1 > n/3) res.push_back(ele1);
        if(cnt2 > n/3) res.push_back(ele2);
        
        if(res.size()==2 && res[0]>res[1])
        {
            swap(res[0],res[1]);
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
