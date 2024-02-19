
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
int cnt[4000][10];

void prt(int m){
    rng(i,0,2*m){
        int res=0;
        if(i%2==0) res+=datas[i/2]*datas[i/2];
        rng(j,0,i){
            if(j!=i-j) res+=datas[j]*datas[i-j];
        }
        cout<<res;
    }
    cout<<'\n';
    return;
}

void Solve(){
    int n,m;
    cin>>n;
    m=n/2;
    if(m==0){
        cout<<1<<'\n';
    }
    else if(m==1){
        cout<<169<<'\n'<<196<<'\n'<<961<<'\n';
    }
    else if(m==2){
        cout<<16384<<'\n'<<31684<<'\n'<<36481<<'\n'<<38416<<'\n'<<43681<<'\n';
    }
    else if(m==3){
        rng(i,1000,3162){
            int temp=i*i;
            fill(cnt[i],cnt[i]+10,0);
            rng(j,0,6){
                cnt[i][temp%10]++;
                temp/=10;
            }
            int nums=0;
            rng(j,1000,i){
                bool flag=1;
                rng(k,0,9){
                    if(cnt[j][k]!=cnt[i][k]){
                        flag=0;
                        break;
                    }
                }
                if(flag) nums++;
            }
            if(nums==n){
                rng(j,1000,i){
                    bool flag=1;
                    rng(k,0,9){
                        if(cnt[j][k]!=cnt[i][k]){
                            flag=0;
                            break;
                        }
                    }
                    if(flag){
                        cout<<j*j<<'\n';
                    }
                }
                return;
            }
        }
    }
    else{
        int cnt=0;
        rng(i,1,m){
            rng(j,i+1,m){
                if(j-i==i-0) continue;
                datas[0]=1, datas[i]=1, datas[j]=2;
                prt(m);
                datas[0]=0, datas[i]=0, datas[j]=0;
                cnt++;
                if(cnt==n) return;
                datas[0]=1, datas[i]=2, datas[j]=1;
                prt(m);
                datas[0]=0, datas[i]=0, datas[j]=0;
                cnt++;
                if(cnt==n) return;
                datas[0]=2, datas[i]=1, datas[j]=1;
                prt(m);
                datas[0]=0, datas[i]=0, datas[j]=0;
                cnt++;
                if(cnt==n) return;
            }
        }
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

