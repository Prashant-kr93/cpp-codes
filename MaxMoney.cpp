#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n){
    if (n == 0)
    {
        return false;
    }
    return (ceil(log2(n)) == floor(log2(n)));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}


int knapSack(int W, vector<int> &wt, vector<int> &val, int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}



//Dp optimized space complexity
//S.C : O(W)//W is maxm weight capacity of knapsack
// int knapsack_DP_OpS(int wt[],int val[], int n, int mw){
int knapsack_DP_OpS(int mw, vector<int> &wt, vector<int> &val, int n){
    int **DP = new int*[2];
    for (int i = 0; i < 2; i++)
    {
        DP[i]= new int[mw + 1];
        for (int j = 0; j < mw + 1; j++)
        {
            DP[i][j] = 0;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= mw; j++)
        {
            if (wt[i] > j)
            {
                DP[i%2][j] = DP[(i+1) %2][j];
            }
            else{
                int a = val[i] + DP[(i+1) %2][j-wt[i]];
                int b = DP[(i+1) % 2][j];
                DP[i%2][j] = max(a,b);
            }
        }
    }
    return (n%2 == 0) ? DP[1][mw] : DP[0][mw];

}

//function

int maximizingMoney(int n, int m, vector<int> &b, vector<int> &c) {
    // Write your code here.
    vector<int> money(n);
    for (int i = 0; i < n; i++)
    {
        int sq = floor(sqrt(b[i]));
        if (isPowerOfTwo(b[i]))
        {
            money[i] = floor(log2(b[i]));
        }
        else{
            money[i] = sq + 1;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<money[i]<<" ";
    // }

    int sum = knapsack_DP_OpS(m,c,money,n);
    
    // typedef pair< float,pair<int,int>> pi;
    // priority_queue<pi> pq;
    // for (int i = 0; i < n; i++)
    // {
    //     pair<int,int> temp;
    //     temp.first = money[i];
    //     temp.second = c[i];
    //     float m = money[i]/c[i];
    //     pq.push(make_pair(m,make_pair(money[i],c[i])));

    // }

    // int sum = 0;
    // while (m != 0 && !pq.empty())
    // {
    //     int diff = m - pq.top().second.second;
    //     if (diff> 0)
    //     {
    //         sum += pq.top().second.first;
    //         m = diff;
    //         // pq.pop();
    //     }
    //     pq.pop();
    // }
    
    return sum;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];
        }
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin>>c[i];
        }
        cout<<maximizingMoney(n,m,b,c)<<endl;
    }
    
}