
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

ll as[N], ds[N];
int dead[N];
priority_queue<array<ll,4>> pq; // {a_l+a_r-d_i,i,l,r};
int nc[N], pv[N];
int n;
vc<int> dnow;
int step;

inline void pq_clear(){
    while(!pq.empty()){
        int l=pq.top()[2], r=pq.top()[3], idx=pq.top()[1];
        if((l!=-1 && (dead[l]!=0 && dead[l]!=step)) || (r!=n && (dead[r]!=0 && dead[r]!=step)) || (dead[idx])) pq.pop();
        else break;
    }
}

void Solve(){
    cin>>n;
    while(!pq.empty()) pq.pop();
    fill(dead,dead+n,0);
    rng(i,0,n-1) cin>>as[i];
    rng(i,0,n-1) cin>>ds[i];
    rng(i,0,n-1){
        nc[i]=i+1;
        pv[i]=i-1;
        pq.push({-ds[i]+(i-1==-1?0:as[i-1])+(i+1==n?0:as[i+1]),i,i-1,i+1});
    }
    step=1;
    while(step<=n){
        int cnt=0;
        dnow.clear();
        //cout<<"STEP : "<<step<<'\n';
        
        while(!pq.empty()){
            pq_clear();
            if(!pq.empty() && pq.top()[0]>0){
                auto temp=pq.top(); // 여기서의 l,r은 여전히 valid함
                int l=temp[2], r=temp[3], idx=temp[1];
                //assert(!dead[idx] && (l==-1 || !dead[l]) && (r==n || !dead[r]));
                assert(!((l!=-1 && (dead[l]!=0 && dead[l]!=step)) || (r!=n && (dead[r]!=0 && dead[r]!=step)) || (dead[idx])));
                assert(!(step==n));
                pq.pop();
                if(l!=-1) dnow.pb(l);
                if(r!=n) dnow.pb(r);
                dead[idx]=step;
                //cout<<"DEAD "<<idx<<'\n';
                cnt++;
            }
            else break;
        }
        // deadnow처리
        sort(all(dnow));
        int last=-1;
        for(auto idx : dnow){
            if(dead[idx] || idx==last) continue;
            last=idx;
            int l=pv[idx], r=nc[idx];
            while(l!=-1 && dead[l]) l=pv[l];
            while(r!=n && dead[r]) r=nc[r];
            pv[idx]=l;
            nc[idx]=r;
            pq.push({-ds[idx]+(l==-1?0:as[l])+(r==n?0:as[r]),idx,l,r});
        }
        cout<<cnt<<' ';
        step++;
    }
    cout<<'\n';
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

