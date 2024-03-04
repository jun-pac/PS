
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define N 300030
#define INF 1000000007 

array<int,3> calc(int a2, int b2, int c2, int a3, int b3, int c3){
    int abc=max(0,min(14,min(a2+7,a3+7))-max(7,max(a2,a3)))*max(0,min(14,min(b2+7,b3+7))-max(7,max(b2,b3)))*max(0,min(14,min(c2+7,c3+7))-max(7,max(c2,c3)));   
    int bc=max(0,min(a2+7,a3+7)-max(a2,a3))*max(0,min(b2+7,b3+7)-max(b2,b3))*max(0,min(c2+7,c3+7)-max(c2,c3));
    int ab=max(0,min(a2+7,7+7)-max(a2,7))*max(0,min(b2+7,7+7)-max(b2,7))*max(0,min(c2+7,7+7)-max(c2,7));
    int ca=max(0,min(7+7,a3+7)-max(7,a3))*max(0,min(7+7,b3+7)-max(7,b3))*max(0,min(7+7,c3+7)-max(7,c3));
    int sum=ab+bc+ca;
    array<int,3> res={343*3-2*sum+3*abc,sum-3*abc,abc};
    return res;
}

void Solve(){
    int v1, v2, v3;
    cin>>v1>>v2>>v3;
    rng(a,0,14){
        rng(b,a,14){
            rng(c,b,14){
                rng(aa,0,14){
                    rng(bb,0,14){
                        rng(cc,0,14){
                            array<int,3> vs=calc(a,b,c,aa,bb,cc);
                            if(vs[0]==v1 && vs[1]==v2 && vs[2]==v3){
                                cout<<"Yes\n";
                                cout<<7<<' '<<7<<' '<<7<<' '<<a<<' '<<b<<' '<<c<<' '<<aa<<' '<<bb<<' '<<cc<<'\n';
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"No\n";
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

