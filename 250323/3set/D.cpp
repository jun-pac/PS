
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

// int datas[N];
int cnt[26][N];
string s;

void Solve(){
    cin>>s;
    int n=s.size();
    rng(k,0,25){
        rng(i,0,n-1) cnt[k][i]=(i==0?0:cnt[k][i-1])+(s[i]=='a'+k);
    }
    int l=-1,r=-1;
    rng(i,0,n/2-1){
        if(s[i]!=s[n-1-i]){
            l=i, r=n-1-i;
            break;
        }
    }
    if(l==-1){
        // cout<<"SAME\n";
        cout<<0<<'\n';
        return;
    }


    int x=(n-1)/2, y=(n)/2;
    // cout<<"XY: "<<x<<' '<<y<<'\n';
    while(x>=0 && s[x]==s[y]){
        x--, y++;
    }
    // cout<<l<<' '<<x<<' '<<y<<' '<<r<<'\n';
    assert(l<=x);
    // cout<<x-l+1<<'\n';

    bool flag=1;
    int mn=r-l+1;
    rng(i,x,(n-1)/2){
        flag=1;
        rng(k,0,25){
            if(cnt[k][i]-(l==0?0:cnt[k][l-1]) != cnt[k][r]-(n-1-i==0?0:cnt[k][n-1-i-1])){
                flag=0;
            }
        }
        if(flag){
            mn=min(mn,i-l+1);
        }
    }
    

    rng(i,(n/2),r-1){
        // [l,i]가 [i+1,r]의 content를 모두 포함.
        flag=1;
        rng(k,0,25){
            if(cnt[k][i]-(l==0?0:cnt[k][l-1]) < cnt[k][r]-(i+1==0?0:cnt[k][i])){
                flag=0;
            }
        }
        if(flag){
            mn=min(mn,i-l+1);
            // cout<<"ans: "<<l+1<<' '<<i+1<<'\n';
        }
    }

    rng(i,l+1,(n-1)/2){
        // [i,r]가 [l,i-1]의 content를 모두 포함.
        flag=1;
        rng(k,0,25){
            if(cnt[k][r]-(i==0?0:cnt[k][i-1]) < cnt[k][i-1]-(l==0?0:cnt[k][l-1])){
                flag=0;
            }
        }
        if(flag){
            mn=min(mn,r-i+1);
            // cout<<"ans: "<<i+1<<' '<<r+1<<'\n';
        }
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

