#include<bits/stdc++.h>
using namespace std;

int cyclicString(string a, string b) {
    // Write your code here.
    int n = a.length();
    for (int i = 0; i < n; i++)
    {
        int dif = abs(b[i] - a[i]);
        if (dif % 2 != 0)
        {
            return 0;
        }
        
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        string a,b;
        cin>>a>>b;
        cout<<cyclicString(a,b)<<endl;
    }
    
}