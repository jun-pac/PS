
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
vc<int> rec[30];
vc<int> cc;

void Solve(){
    int n;
    char trc,x; // trump
    cin>>n;
    cin>>trc;    
    int tr=trc-'A';
    rng(i,0,3) rec[cc[i]].clear();
    rng(i,0,2*n-1){
        cin>>s;
        rec[s[1]-'A'].pb(s[0]-'0');
    }
    int odd=0;
    rng(i,0,3) if(((int)rec[cc[i]].size())%2==1) odd++;
    rng(i,0,3) sort(all(rec[cc[i]]));
    assert(odd%2==0);

    if(odd==4){
        if((int)rec[tr].size()>=3){
            rng(i,0,3){
                if(cc[i]!=tr){
                    cout<<rec[cc[i]].back()<<(char)(cc[i]+'A')<<' '<<rec[tr].back()<<(char)(tr+'A')<<'\n';
                    rec[tr].pop_back();
                }
            }
            rng(i,0,3){
                rng(j,0,(int)rec[cc[i]].size()-1){
                    if(j%2==1) cout<<rec[cc[i]][j-1]<<(char)(cc[i]+'A')<<' '<<rec[cc[i]][j]<<(char)(cc[i]+'A')<<'\n';
                }
            }
        }
        else{
            cout<<"IMPOSSIBLE\n";
        }
    }
    else if(odd==2 && rec[tr].size()%2==0){
        if(rec[tr].size()>=2){
            rng(i,0,3){
                if(cc[i]!=tr && (int)rec[cc[i]].size()%2==1){
                    cout<<rec[cc[i]].back()<<(char)(cc[i]+'A')<<' '<<rec[tr].back()<<(char)(tr+'A')<<'\n';
                    rec[tr].pop_back();
                }
            }
            rng(i,0,3){
                rng(j,0,(int)rec[cc[i]].size()-1){
                    if(j%2==1) cout<<rec[cc[i]][j-1]<<(char)(cc[i]+'A')<<' '<<rec[cc[i]][j]<<(char)(cc[i]+'A')<<'\n';
                }
            }
        }
        else cout<<"IMPOSSIBLE\n";
    }
    else{
        rng(i,0,3){
            rng(j,0,(int)rec[cc[i]].size()-1){
                if(j%2==1) cout<<rec[cc[i]][j-1]<<(char)(cc[i]+'A')<<' '<<rec[cc[i]][j]<<(char)(cc[i]+'A')<<'\n';
            }
        }
        if(odd==2){
            bool flag=0;
            rng(i,0,3) if(cc[i]!=tr && rec[cc[i]].size()%2==1){
                assert(!flag);
                cout<<rec[cc[i]].back()<<(char)(cc[i]+'A')<<' '<<rec[tr].back()<<(char)(tr+'A')<<'\n';
                flag=1;
            }
            assert(flag);
        }
    }
}   

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    cc.pb('C'-'A');
    cc.pb('D'-'A');
    cc.pb('H'-'A');
    cc.pb('S'-'A');
    while(t--){
        Solve();
    }
    return 0;
}

