
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

vc<int> datas[N];
int cnt;

void Solve(){
    int n;
    cin>>n;
    // 친구가 n명이면 끝
    // n=4
    // 1100 1010 
    // n=8
    // 11110000 11001100 10101010
    
    cnt=0;
    while(n>(1<<cnt)) cnt++;
    rng(i,0,cnt-1){
        int cur=(1<<i);
        rng(j,0,n-1){
            if(j&cur) datas[i].pb(j+1);
        }
    }
    

    cout<<cnt<<endl;
    rng(i,0,cnt-1){
        cout<<datas[i].size()<<' ';
        rng(j,0,(int)datas[i].size()-1){
            cout<<datas[i][j]<<' ';
        }
        cout<<endl;
    }
    
    int ans=0;
    string res;
    cin>>res;
    //res="101";
    rng(i,0,cnt-1){
        if(res[i]=='1') ans+=(1<<i);
    }
    assert(ans<n);
    cout<<ans+1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();
    }
    return 0;
}

