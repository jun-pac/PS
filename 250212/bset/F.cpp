
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

ll datas[3][N];
map<array<ll,3>,ll> mp;

ll f(array<ll, 3> idx){
    array<ll, 3> temp;
    rng(i,0,2) temp[i]=datas[i][idx[i]];
    return temp[0]*temp[1]+temp[2]*temp[1]+temp[2]*temp[0];
}

void Solve(){
    int n,k;
    cin>>n>>k;
    // mp.clear();
    rng(tt,0,2){
        rng(i,0,n-1) cin>>datas[tt][i];
        sort(datas[tt],datas[tt]+n);
        reverse(datas[tt],datas[tt]+n);
        // rng(i,0,n-1) cout<<datas[tt][i]<<' ';
        // cout<<'\n'; 
    }
    priority_queue<pair<ll,array<ll,3>>> pq;
    pq.push({f({0,0,0}),{0,0,0}});
    // non-neg pq;
    int cnt=0;
    while(!pq.empty()){
        pair<ll,array<ll,3>> temp=pq.top();
        pq.pop();
        // cout<<"cur :"<<temp.fi<<' '<<temp.se[0]<<' '<<temp.se[1]<<' '<<temp.se[2]<<'\n';
        cnt++;
        if(cnt==k){
            cout<<temp.fi<<'\n';
            return;
        }
        rng(tt,0,2){
            if(temp.se[tt]+1<n){
                temp.se[tt]++;
                if(mp[temp.se]==0){
                    pq.push({f(temp.se),temp.se});
                    mp[temp.se]=1;
                }
                temp.se[tt]--;
            }
        }
    }
    cout<<-1<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

