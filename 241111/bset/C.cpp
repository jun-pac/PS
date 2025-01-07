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

ll r,c;
ll k;
int datas[808][808];
int cnt[640064];
// 나랑 같은 것의 개수를 전처리로 구한다... 그건 좀 어려울거같고 DP로 해야함

ll count_le(ll num){
    // num보다 작거나 같은 서로다른 element pair
    ll res=0;
    rng(i,0,r-1){
        fill(cnt,cnt+r*c,0);
        rng(ii,i-num,i+num){
            rng(jj,0,num){
                if(0<=ii && ii<r && 0<=jj && jj<c) cnt[datas[ii][jj]]++;
            }
        }
        rng(j,0,c-1){
            if(j!=0){
                int jj=j+num;
                if(0<=jj && jj<c){
                    rng(ii,i-num,i+num){
                        if(0<=ii && ii<r) cnt[datas[ii][jj]]++;
                    }
                }
                jj=j-num-1;
                if(0<=jj && jj<c){
                    rng(ii,i-num,i+num){
                        if(0<=ii && ii<r) cnt[datas[ii][jj]]++;
                    }
                }
            }
            res+=(min(r-1,i+num)-max(0LL,i-num)+1)*(min(c-1,j+num)-max(0LL,j-num)+1)-cnt[datas[i][j]];
        }
    }
    return res;
}

void Solve(int tt){
    cin>>r>>c>>k;
    rng(i,0,r-1){
        rng(j,0,c-1){
            cin>>datas[i][j];
            datas[i][j]--;
        }
    }
    int s=1, e=max(r,c)-1;
    while(s<e){
        int mid=(s+e)>>1;
        if(count_le(mid)>=k) e=mid;
        else s=mid+1;
    }
    cout<<"Case #"<<tt<<": "<<s<<'\n';   
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

