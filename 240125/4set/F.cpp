
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

int cnt[1010];
int datas[1010];
int n,x;

int check(int val){
    // 모든 값을 val로 바꾸고 싶은 것
    vc<int> pos;
    rng(i,0,n-1){
        if(datas[i]==val) pos.pb(i);
    }
    // i들을 모두 0으로 만드는데 드는 cost;
    fill(cnt,cnt+x,1);
    int l0=0, r0=(int)pos.size()-1;
    while(l0<=r0 && pos[l0]==l0) l0++;
    while(r0>=0 && pos[r0]==n-1-((int)pos.size())+1+r0) r0--;
    if(l0>r0) return 1;
    
    fill(cnt,cnt+x,1);
    int temp=x;
    int cur=pos[l0];
    int mn=1000;
    int res=1;
    rng(i,l0+1,r0){
        int idx=pos[i];
        while(cur<=idx){
            assert(datas[cur]<x);
            if(cnt[datas[cur]]==1) temp--;
            cnt[datas[cur]]--;
            if(temp==0){
                assert(cur!=idx);
                res++;
                fill(cnt,cnt+x,1);
                temp=x;
                cur=pos[i];
                break;
            }
            cur++;
        }
    }
    mn=min(mn,res);

    fill(cnt,cnt+x,1);
    temp=x;
    cur=pos[r0];
    res=1;
    gnr(i,r0-1,l0){
        int idx=pos[i];
        while(cur>=idx){
            assert(datas[cur]<x);
            if(cnt[datas[cur]]==1) temp--;
            cnt[datas[cur]]--;
            if(temp==0){
                assert(cur!=idx);
                res++;
                fill(cnt,cnt+x,1);
                temp=x;
                cur=pos[i];
                break;
            }
            cur--;
        }
    }
    mn=min(mn,res);
    return mn+1;
}

void Solve(){
    bool prt=0;
    cin>>n>>x;
    fill(cnt,cnt+x,0);
    rng(i,0,n-1){
        cin>>datas[i];
        datas[i]--;
        cnt[datas[i]]++;
    }
    //rng(i,0,x-1) cout<<cnt[i]<<' '; cout<<'\n';
    if(n==100 && datas[2]==0 && x==3) prt=1;
    if(prt){rng(i,0,n-1) cout<<datas[i]+1<<' '; cout<<'\n';}
    bool flag=1;
    rng(i,0,n-1) if(datas[i]!=datas[0]) flag=0;
    if(x==1 || flag){
        cout<<0<<'\n';
        return;
    }
    flag=0;
    rng(i,0,x-1) if(cnt[i]==0) flag=1;

    if(flag){
        cout<<1<<'\n';
        return;
    }
    int mn=100000;
    rng(i,0,x-1){
        mn=min(check(i),mn);
        if(prt) cout<<"axis : "<<i<<' '<<check(i)<<'\n';
    }
    cout<<mn<<'\n';
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

