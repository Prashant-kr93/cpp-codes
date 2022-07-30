#include<bits/stdc++.h>
using namespace std;

vector<int> peakArray(vector<int> &a){
    int n = a.size();
    auto it = minmax_element(a.begin() ,a.end());
    int max_idx = distance(a.begin() , it.second);
    int mx = a[max_idx];
    vector<int> temp;
    vector<int> op;
    for (int i = 0; i < max_idx; i++)
    {
        temp.push_back(a[i]);
    }
    sort(temp.begin(),temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
        op.push_back(temp[i]);
    }
    temp.clear();
    op.push_back(mx);
    for (int i = max_idx+1; i < n; i++)
    {
        temp.push_back(a[i]);
    }
    sort(temp.begin(), temp.end(), greater<int>());
    for (int i = 0; i < temp.size(); i++)
    {
        op.push_back(temp[i]);
    }
    temp.clear();
    return op;
    
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> op = peakArray(arr);
        // cout << candyDivision(arr) << endl;
        for(auto it: op){
            cout<<it<<" ";
        }
    }
}