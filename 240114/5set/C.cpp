
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

map<int,int> mp;
vc<int> val[N];
int datas[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n) val[i].clear();
    mp.clear();
    int cnt=1;
    rng(i,0,n-1){
        cin>>datas[i];
        //cout<<"c"<<datas[i]<<'\n'; 
        if(mp[datas[i]]!=0) val[mp[datas[i]]-1].pb(i);
        else{
            mp[datas[i]]=cnt++;
            val[mp[datas[i]]-1].pb(i);
        }
    }

    // rng(i,0,cnt-2){
    //     cout<<"i "<<i<<'\n';
    //     for(auto ii:val[i]){
    //         cout<<ii<<' ';
    //     }
    //     cout<<endl;
    // } 
    int last=0;
    while(last<=n && mp[last]!=0) last++;
    last--;
    if(last==n-1) cout<<"NO\n";
    else{
        int idx=mp[last+2]-1; // idxÀ» ½á¾ß.
        if(idx==-1) cout<<"YES\n";
        else{
            int l,r;
            l=val[idx][0];
            r=*prev(val[idx].end());
            //cout<<"lr "<<l<<' '<<r<<' '<<last+1<<'\n';
            bool flag=1;
            rng(i,l,r) datas[i]=last+1;
            mp.clear();
            rng(i,0,n-1) mp[datas[i]]++;
            int res=0;
            while(res<n && mp[res]!=0){
                res++;
            }
            //cout<<res<<'\n';
            if(res==last+2) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
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

