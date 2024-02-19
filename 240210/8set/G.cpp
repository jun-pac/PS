
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
map<int,int> mp;
vc<int> pos[N];
int n,k;

int get_mn(int val){
    assert(pos[val].size()>=k);
    int res=k; // k를 모두 넘기는 방법
    int sz=pos[val].size();
    rng(i,0,sz-k){
        res=min(res,pos[val][i+k-1]-pos[val][i]-(k-1));
    }
    rng(i,1,k-1){ // 뒤에서 i개를 앞으로 넘기는 일이다.
        res=min(res,i+i+pos[val][k-1-i]-(k-1));
    }
    return res;
}

void Solve(){
    cin>>n>>k;
    mp.clear();
    int mx=0;
    rng(i,0,n-1){
        cin>>datas[i];
        mp[datas[i]]++;
        if(mp[datas[i]]==1){
            pos[datas[i]].clear();
        }
        pos[datas[i]].pb(i);
        mx=max(mx,mp[datas[i]]);
    }
    if(mx<k){
        cout<<-1<<'\n';
        return;
    } 
    int res=INF;
    rng(i,0,n-1){
        if(mp[datas[i]]>=k){
            //cout<<datas[i]<<' '<<get_mn(datas[i])<<'\n';
            res=min(res,get_mn(datas[i]));
            mp[datas[i]]=0; // 재방문 방지 
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

