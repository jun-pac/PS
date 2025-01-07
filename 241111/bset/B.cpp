// 7z x name.zip
// ./A < name.txt > output

#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define pb push_back
#define all(x) x.bg,x.ed
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 

ll powt[19];

ll numd(ll num){
    ll cnt=0;
    while(num!=0){
        cnt++;
        num/=10;
    }
    return cnt;
}

ll aa, bb, mm, bnum;

void rec(int lastl, int lastr, int k, ll val, ll &res){ // k는 남은 digit수
    if(k==0){
        if(val%mm==0 && aa<=val && val<=bb) res++;
        return;
    }
    for(ll jl=1; jl<=lastl; jl++){
        for(ll jr=1; jr<=lastr; jr++){
            rec(jl,jr,k-1,val+jl*powt[k-1]+jr*powt[bnum-k],res);
        }
        
    }
}

ll count_num(ll a, ll b, ll m){
    ll res=0;
    ll bitnum=numd(a);
    if(bitnum%2==0) return 0;
    if(bitnum==1 && a<=1 && m==1) res++; // 1 in the middle

    rng(i,2,9){
        aa=a;
        bb=b;
        mm=m;
        bnum=bitnum;
        rec(i-1,i-1,bitnum/2,i*powt[bitnum/2],res);
    }
    //cout<<a<<' '<<b<<' '<<m<<' '<<res<<'\n';
    return res;
}

void Solve(int tt){
    rng(i,0,18) powt[i]=(i==0?1:powt[i-1]*10);
    ll a,b,m;
    cin>>a>>b>>m;
    //cout<<a<<' '<<b<<' '<<m<<'\n';
    ll res=0;
    if(a==0){
        a++;
        b=max(b,1LL);   
    }
    while(numd(a)!=numd(b)){
        res+=count_num(a,powt[numd(a)]-1,m);
        a=powt[numd(a)];
    }
    res+=count_num(a,b,m);
    
    cout<<"Case #"<<tt<<": "<<res<<'\n';   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(tt,0,t-1){
        Solve(tt+1);
    }
    return 0;
}

