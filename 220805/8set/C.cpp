// 
//./C<test

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

int datas[200020];
priority_queue<int> pqs[200020];
int DP[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) while(!pqs[i].empty()) pqs[i].pop();
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) datas[i]--;

        DP[0]=0;
        pqs[datas[0]].push(n);
        int res=0;
        for(int i=1; i<n; i++){
            DP[i]=DP[i-1];
            int mx=(pqs[datas[i]].empty()?n-1-i:pqs[datas[i]].top());
            DP[i]=max(DP[i],mx-(n-1-i));
            pqs[datas[i]].push(DP[i-1]+n-i);
        }
        //for(int i=0; i<n; i++) cout<<DP[i]<<' ';
        //cout<<endl;
        cout<<DP[n-1]<<endl;
    }
    return 0;
}