
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

ll datas[N];
map<ll,ll> mp;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    // 홀수번 나누는 소인수가 있음.
    // 그 홀수번의 소인수들을 매칭해서 이게 완전히 같으면 되는건데..
    // (1) 이게 시간안에 가능? (2) 어떻게 완전히 같은지 확인?
    // 완전히 같은지는 hashing해서 map에다 넣자 그냥 -- 이걸 다 곱하면 유일하니까
    ll res=0;
    ll num0=0;
    rng(i,0,n-1) num0+=(datas[i]==0);
    rng(i,0,n-1){
        if(datas[i]==0) continue;
        //cout<<"ori "<<datas[i]<<'\n';
        for(int val=2; val<=sqrt(datas[i]); val++){
            while(datas[i]%(val*val)==0){
                datas[i]/=(val*val);
            }
        }
        //cout<<"reduced "<<datas[i]<<'\n';
        res+=mp[datas[i]];
        mp[datas[i]]++;
    }
    cout<<res+(num0)*(n-num0)+(num0*(num0-1))/2<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

