
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

int datas[1000];
int lcnt[10], cnt[10];

void Solve(){
    int n;
    cin>>n;
    int step=0, ltar, tar;
    while(true){
        fill(cnt,cnt+10,0);
        rng(i,0,n-1){
            cin>>datas[i];
            datas[i]--;
            cnt[datas[i]]++;
        }
        if(step==0){
            rng(i,0,9) lcnt[i]=cnt[i];
            cout<<"- 0"<<endl;
        }
        else if(step==1){
            rng(i,0,9){
                if(cnt[i]<lcnt[i]){
                    ltar=i;
                    break;
                }
            }
            cout<<"- 0"<<endl;
        }
        else if(step==2){
            bool flag=0;
            rng(i,0,9){
                if(cnt[i]>lcnt[i]){
                    tar=i;
                    flag=1;
                    break;
                }
            }
            if(!flag) tar=ltar; 
            cout<<"- "<<n-cnt[tar]<<endl;
            rng(i,0,n-1) if(datas[i]!=tar) cout<<i+1<<' ';
            cout<<endl;
            n=cnt[tar];
        }
        else if(step==3){
            if(n==1){
                cout<<"! 1"<<endl;
                return;
            }
            rng(i,0,n-1){
                if(datas[i]!=tar){
                    cout<<"! "<<i+1<<endl;
                    return;
                }
            }
            cout<<"- 0"<<endl;
        }
        else if(step==4){
            //cout<<"why tar "<<tar<<endl;
            rng(i,0,n-1){
                if(datas[i]!=tar){
                    cout<<"! "<<i+1<<endl;
                    return;
                }
            }
            assert(false);
        }
        step++;
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

