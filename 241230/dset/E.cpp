
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
ll n,k;
ll mx, mn;
stack<array<ll,3>> st; 

void DFS(ll n1, ll p1, ll c1){
    // st.reserve(1000000);
    st.push({n1,p1,c1});
    ll num, pos, cur;
    while(!st.empty()){
        array<ll,3> a=st.top();
        st.pop();
        num=a[0];
        pos=a[1];
        cur=a[2];
        if(num==1){
            rng(i,pos,n-num){
                mx=max(mx,cur^datas[i]);
            }
        }
        else{
            rng(i,pos,n-num){
                st.push({num-1, i+1, cur^datas[i]});
            }
        }
    }
}

ll offset;

void DFS2(ll n1, ll p1, ll c1){
    st.push({n1,p1,c1});
    ll num, pos, cur;
    while(!st.empty()){
        array<ll,3> a=st.top();
        st.pop();
        num=a[0];
        pos=a[1];
        cur=a[2];
        if(num==1){
            rng(i,pos,n-num){
                mx=max(mx,offset^(cur^datas[i]));
            }
        }
        else{
            rng(i,pos,n-num){
                st.push({num-1, i+1, cur^datas[i]});
            }
        }
    }
}

void Solve(){
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    if(k==0){
        cout<<0<<'\n';
    }
    else if(k==n){
        offset=0;
        rng(i,0,n-1) offset=offset^datas[i];
        cout<<offset<<'\n';
    }
    else if(k>=n/2){
        mx=0;
        offset=0;
        rng(i,0,n-1) offset=offset^datas[i];
        DFS2(n-k, 0, 0);
        cout<<mx<<'\n';
    }
    else{
        mx=0;
        DFS(k, 0, 0);
        cout<<mx<<'\n';
    }
    
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

