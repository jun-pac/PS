
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

string s;
int n;
bool used[1000100];

void Solve(){
    cin>>s;
    n=s.size();
    int l=n/2,r=n/2;
    int cnt=0;
    used[l]=1;
    l--, r++;
    cnt++;
    while(l>=0 && r<n){
        if(s[l]==s[r]){
            used[l]=used[r]=1;
            l--, r++;
            cnt+=2;
        }
        else if(l!=0 && s[l-1]==s[r]){
            used[l-1]=used[r]=1;
            l-=2, r++;
            cnt+=2;
        }
        else if(r!=n-1 && s[l]==s[r+1]){
            used[l]=used[r+1]=1;
            l--, r+=2;
            cnt+=2;
        }
        else if(l!=0 && r!=n-1 && s[l-1]==s[r+1]){
            used[l-1]=used[r+1]=1;
            l-=2, r+=2;
            cnt+=2;
        }
        else break;
    }
    if(cnt<n/2){
        l=n/2-1,r=n/2-1;
        fill(used,used+n,0);
        cnt=0;
        used[l]=1;
        l--, r++;
        cnt++;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                used[l]=used[r]=1;
                l--, r++;
                cnt+=2;
            }
            else if(l!=0 && s[l-1]==s[r]){
                used[l-1]=used[r]=1;
                l-=2, r++;
                cnt+=2;
            }
            else if(r!=n-1 && s[l]==s[r+1]){
                used[l]=used[r+1]=1;
                l--, r+=2;
                cnt+=2;
            }
            else if(l!=0 && r!=n-1 && s[l-1]==s[r+1]){
                used[l-1]=used[r+1]=1;
                l-=2, r+=2;
                cnt+=2;
            }
            else break;
        }
    }
    assert(cnt>=n/2);
    rng(i,0,n-1) if(used[i]) cout<<s[i];
    cout<<'\n';
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

