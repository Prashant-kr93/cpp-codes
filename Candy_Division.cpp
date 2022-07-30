#include<bits/stdc++.h>
using namespace std;

int candyDivision(vector<int> &a){
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    if (sum %2 == 0)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<candyDivision(arr)<<endl;
    }
    
}