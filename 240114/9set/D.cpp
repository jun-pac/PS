
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

pii datas[N];
int ans[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi;
    rng(i,0,n-1) datas[i].se=i;
    sort(datas,datas+n);

    int l=0, r=n-1;
    int cnt=n;
    int offset=0;
    bool flag=1;
    while(l<=r){
        // datas[l]이 작은 것, datas[r]이 큰 것
        if(datas[r].fi-offset==cnt && datas[l].fi-offset==0){
            flag=0;
            break;
        }
        else if(datas[r].fi-offset==cnt){
            ans[datas[r].se]=cnt;
            //cout<<datas[r].se<<' '<<cnt<<'\n';
            offset++;
            cnt--;
            r--;
        }
        else if(datas[l].fi-offset==0){
            ans[datas[l].se]=-cnt;
            //cout<<datas[l].se<<' '<<cnt<<'\n';
            cnt--;
            l++;
        }
        else{
            flag=0;
            break;
        }
    }    
    if(flag){
        cout<<"YES\n";
        rng(i,0,n-1) cout<<ans[i]<<' '; cout<<'\n';
    }
    else{
        cout<<"NO\n";
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

