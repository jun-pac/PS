
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
ll lsum[N], rsum[N];
int visited[N];
ll cnt, lcnt, rcnt;

void Solve(){
    cnt++;
    int n,m; // m is # of seats
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) if(datas[i]>0) datas[i]--;
    vc<int> pos;
    lcnt=rcnt=0;
    rng(i,0,n-1){
        if(datas[i]==-1) lcnt++;
        else if(datas[i]==-2) rcnt++;
        else if(cnt!=visited[datas[i]]){
            visited[datas[i]]=cnt;
            pos.pb(datas[i]);
        }
        
    }
    sort(all(pos));
    ll num=pos.size();
    //cout<<"pos : "<<num<<'\n';
    //cout<<"ch "<<lcnt<<' '<<rcnt<<'\n';
    ll mx=0;
    if(rcnt>0){
        // 맨 왼쪽에서 시작
        ll temp=((num>0 && pos[0]==0)?num-1:num)+min(((num>0 && pos[0]==0)?m-num:m-num-1),rcnt-1)+1;
        mx=max(mx,temp);
    }
    if(lcnt>0){
        // 맨 오른쪽에서 시작
        ll temp=((num>0 && pos[num-1]==m-1)?num-1:num)+min(((num>0 && pos[num-1]==m-1)?m-num:m-num-1),lcnt-1)+1;
        //cout<<"st "<<temp<<'\n';
        mx=max(mx,temp);
    }
    rng(i,0,(int)pos.size()-1){
        ll st=pos[i];
        // st의 왼쪽의 빈 공간
        ll temp=min(st-i,lcnt)+min(m-st-(num-i),rcnt);
        mx=max(mx,temp+num); 
    }
    cout<<mx<<'\n';

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

