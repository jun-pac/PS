
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)


map<int,int> mp;


bool factorize(ll temp){
    // cout<<"FACT "<<temp<<'\n';
    int last=1;
    while(temp!=1){
        // cout<<temp<<endl;
        ll end=sqrt(temp)+1;
        bool flag=false;
        for(int i=last+1; i<=end; i++){
            if(temp%i==0){
                // cout<<i<<' ';
                if(mp[i]) return true;
                mp[i]=1;
                while(temp%i==0){
                    temp=temp/i;
                    // cout<<temp<<' '<<i<<' '<<endl;
                }
                last=i;
                flag=true;
                break;
            }
        }
        if(!flag){
            // cout<<"? "<<temp<<' ';
            if(mp[temp]) return true;
            mp[temp]=1;
            
            break;
        }
    }
    // cout<<'\n';
    return false;
}

bool unfactorize(ll temp){
    int last=1;
    while(temp!=1){
        ll end=sqrt(temp)+1;
        bool flag=false;
        for(int i=last+1; i<=end; i++){
            if(temp%i==0){
                mp.erase(i);
                while(temp%i==0) temp=temp/i;
                flag=true;
                last=i;
                break;
            }
        }
        if(!flag){
            mp.erase(temp);
            break;
        }
    }
    return false;
}


int as[N], bs[N];

bool check(int n){ // if multiple exist
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
    int evencnt=0;
    rng(i,0,n-1) if(as[i]%2==0) evencnt++;
    if(evencnt>=2 || check(n)){
        cout<<0<<'\n';
        return;
    }
    if(evencnt==1){
        cout<<1<<'\n';
        // one even
        // int mn=INF;
        // int mincost_odd=INF;
        // rng(i,0,n-1) if(as[i]%2==1) mincost_odd=min(mincost_odd,bs[i]);
        // // mincost_odd candidate ans
        
    }
    else{
        // all odd
        int mn=2;
        rng(i,0,n-1){

            unfactorize(as[i]);
            if(factorize(as[i]+1)){
                cout<<1<<'\n';
                return;
            }
            unfactorize(as[i]+1);
            factorize(as[i]);
        }
        cout<<2<<'\n';

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

