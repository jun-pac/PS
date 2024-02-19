
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

// 이게 뭔가 diversity가 별로 유지가 안됨

map<int,int> mp[2];
int datas[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    mp[0].clear();
    rng(i,0,n-1) mp[0][datas[i]]++;
    rng(i,0,n-2){
        mp[(i+1)%2].clear();
        auto it=mp[i%2].begin();
        while(it!=mp[i%2].end()){
            // if(it->se==0){
            //     it=next(it);
            //     continue;
            // }
            pii temp=*it;
            if(temp.se!=1) mp[(i+1)%2][0]+=temp.se-1;
            it=next(it);
            if(it!=mp[i%2].end()) mp[(i+1)%2][(it->fi)-temp.fi]++;
        }
        //mp[(i+1)%2] <- mp[i%2];
        // for(auto hey : mp[(i+1)%2]){
        //     cout<<"("<<hey.fi<<' '<<hey.se<<") ";
        // }
        // cout<<endl;
    }
    cout<<(mp[(n-1)%2].begin()->fi)<<'\n';
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

