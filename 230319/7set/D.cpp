// 
//./C_test<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

#define N 200020
vector<int> datas[N];
pair<int,int> mx_ele[N];
int DP[N];

bool compare(pair<int,int> a, int b){
    return a.fi<b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,a;
        n=100000;
        for(int i=0; i<n; i++){
            m=();
            datas[i].clear();
            int mx=0;
            for(int j=0; j<m; j++){
                cin>>a;
                if(a>mx) datas[i].push_back(a);
                umax(mx,a);
            }
            mx_ele[i]={mx,i};
        }
        sort(mx_ele,mx_ele+n);
        for(int i=0; i<n; i++){
            int idx=mx_ele[i].se;
            int dp_temp=0; // DP의 후보 (cnt+DP[past])의 최대값
            int sz=datas[idx].size();
            for(int j=sz-1; j>=0; j--){
                int last_DP_idx = lower_bound(mx_ele,mx_ele+n,datas[idx][j],compare)-mx_ele;
                if(last_DP_idx==0) umax(dp_temp,sz-j);
                else umax(dp_temp,sz-j+DP[last_DP_idx-1]);
            }
            DP[i]=dp_temp;
            //cout<<"DP ["<<i<<"] "<<DP[i]<<endl;
        }
        cout<<DP[n-1]<<endl;
    }
    return 0;
}