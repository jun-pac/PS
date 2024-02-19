// 
//./F<test.txt

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

int datas[200000];
ll p_cnt[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        p_cnt[0]=(datas[0]<1?1:0);
        for(int i=1; i<n; i++) p_cnt[i]=p_cnt[i-1]+(datas[i]<i+1?1:0);
        ll res=0;
        //for(int i=0; i<n; i++) cout<<p_cnt[i]<<' ';
        //cout<<endl;
        for(int j=1; j<n; j++) if(datas[j]<j+1 && datas[j]>1) res+=p_cnt[datas[j]-2];
        cout<<res<<endl;
    }
    return 0;
}