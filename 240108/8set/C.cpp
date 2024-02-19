
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

int datas[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    int ori=0;
    rng(i,0,n-2) if(datas[i]<datas[i+1]) ori++;
    if(ori<=1){
        cout<<0<<'\n';
        return;
    }   
    stack<int> a,b;
    a.push(INF), b.push(INF);
    int res=0;
    rng(i,0,n-1){
        int at=a.top(), bt=b.top();
        if(datas[i]>max(at,bt)){
            if(at>bt) b.push(datas[i]);
            else a.push(datas[i]);
            res++;
        }
        else if(datas[i]==at || datas[i]==bt){
            continue;
        }
        else if(datas[i]<max(at,bt) && datas[i]>min(at,bt)){
            if(at>bt) a.push(datas[i]);
            else b.push(datas[i]);
        }
        else{
            if(at>bt) b.push(datas[i]);
            else a.push(datas[i]);
        }
    }
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

