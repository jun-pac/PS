
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
#define INF 100000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)


map<ll,ll> mp;


bool factorize(ll temp){
    ll last=1;
    bool res=0;
    while(temp!=1){
        ll end=sqrt(temp)+1;
        bool flag=false;
        for(ll i=last+1; i<=end; i++){
            if(temp%i==0){
                if(mp[i]) res=true;
                mp[i]++;
                while(temp%i==0) temp=temp/i;
                last=i;
                flag=true;
                break;
            }
        }
        if(!flag){
            if(mp[temp]) res=true;
            mp[temp]++;
            
            break;
        }
    }
    return res;
}

void unfactorize(ll temp){
    ll last=1;
    while(temp!=1){
        ll end=sqrt(temp)+1;
        bool flag=false;
        for(ll i=last+1; i<=end; i++){
            if(temp%i==0){
                mp[i]--;
                while(temp%i==0) temp=temp/i;
                flag=true;
                last=i;
                break;
            }
        }
        if(!flag){
            mp[temp]--;
            break;
        }
    }
}


ll as[N], bs[N];

bool check(ll n){ // if multiple exist
    mp.clear();
    rng(i,0,n-1){
        bool temp=factorize(as[i]);
        if(temp) return true;
    }
    return false;
}


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>as[i];
    rng(i,0,n-1) cin>>bs[i];
    ll evencnt=0;
    rng(i,0,n-1) if(as[i]%2==0) evencnt++;
    if(evencnt>=2 || check(n)){
        cout<<0<<'\n';
        return;
    }
    if(evencnt==1){
        // one even
        ll mincost_odd=INF;
        rng(i,0,n-1) if(as[i]%2==1) mincost_odd=min(mincost_odd,bs[i]);
        // mincost_odd candidate ans
        ll evenidx, ecost;
        rng(i,0,n-1) if(as[i]%2==0) evenidx=i;
        ecost=bs[evenidx];
        ll k=1;
        while(ecost*k<mincost_odd){
            unfactorize(as[evenidx]);
            if(factorize(as[evenidx]+k)){
                cout<<ecost*k<<'\n';
                return;
            }
            unfactorize(as[evenidx]+k);
            factorize(as[evenidx]);
            k++;
        }
        cout<<mincost_odd<<'\n';
    }
    else{
        // all odd
        ll mn1=INF, mn2=INF, mn1idx, mn2idx;
        rng(i,0,n-1){
            if(bs[i]<mn1){
                mn2=mn1;
                mn2idx=mn1idx;
                mn1=bs[i];
                mn1idx=i;
            }
            else if(bs[i]<mn2){
                mn2=bs[i];
                mn2idx=i;
            }
        }

        ll mn=mn1+mn2;

        rng(i,0,n-1){
            ll k=1;
            while(bs[i]*k<mn){
                unfactorize(as[i]);
                if(factorize(as[i]+k)){
                    mn=min(mn,bs[i]*k);
                }
                unfactorize(as[i]+k);
                factorize(as[i]);
                k++;
            }
        }
        cout<<mn<<'\n';

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

