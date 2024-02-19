// 
//./B<test

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

vector<int> datas[30000];
ll mns[30000];
ll mn2s[30000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) datas[i].clear();
        for(int i=0; i<n; i++){
            int m,x;
            cin>>m;
            datas[i].reserve(m);
            for(int j=0; j<m; j++){
                cin>>x;
                datas[i].push_back(x);
            }
            int mn=1000000007, mn_idx;
            for(int j=0; j<m; j++){
                if(datas[i][j]<mn){
                    mn_idx=j;
                    mn=datas[i][j];
                }
            }
            int mn2=1000000007, mn2_idx;
            for(int j=0; j<m; j++){
                if(datas[i][j]<mn2 && j!=mn_idx){
                    mn2_idx=j;
                    mn2=datas[i][j];
                }
            }
            mns[i]=mn;
            mn2s[i]=mn2;
        }
        ll mn2sum=0, mntot=1000000007;
        for(int i=0; i<n; i++){
            mntot=min(mntot,mns[i]);
            mn2sum+=mn2s[i];
        }
        ll res=0;
        for(int i=0; i<n; i++){
            ll temp=mntot+mn2sum-mn2s[i];
            res=max(res,temp);

        }
        cout<<res<<endl;
    }
    return 0;
}