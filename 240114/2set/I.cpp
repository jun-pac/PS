
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

int last_bit(int num){
    // 1011000 -> 3 return
    int res=0;
    while(num%2==0){
        res++;
        num/=2;
    }
    return res;
}

int bit_flip(int num, int idx){
    if(num&(1<<idx)){
        return num-(1<<idx);
    }
    return num+(1<<idx);
}

string prt(int n){
    string res;
    while(n!=0){
        res.pb((n%2)+'0');
        n/=2;
    }
    while(res.size()<5) res.pb('0');
    return res;
}

pii state[2020];

void Solve(){
    int n, cur, res=0;
    cin>>n;
    cin>>res;
    rng(i,0,n-1){
        cur=0;
        rng(j,1,(1<<(n-i))){
            if(j!=1){
                cin>>res;
                if(res==n) return;
            }
            state[j-1]={res,cur};
            //cout<<cur<<' '<<prt(cur)<<endl;
            if(j!=(1<<(n-i))){
                cout<<i+1<<' '<<i+1+last_bit(j)<<endl;
                cur=bit_flip(cur,last_bit(j));
            }

        }
        sort(state,state+(1<<(n-i)));
        int mx=state[(1<<(n-i))-1].fi;
        int mxstate=state[(1<<(n-i))-1].se;
        assert(mx>=i+1);
        //cout<<"check"<<i+1<<'a'<<mxstate<<'a'<<cur<<'a'<<mx<<endl;
        rng(j,0,(n-i-1)){
            if((cur&(1<<j))!=(mxstate&(1<<j))){
                cout<<i+1<<' '<<i+1+j<<endl;
                cin>>res;
                if(res==n) return;
            }
        }
        // cur가 여전히 마지막 state를 나타내고 있겠죠?   
    }
    cout<<"FUCK"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

