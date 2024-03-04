
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

string datas[7];
vc<int> odd_cent, even_cent; // 중심의 B와 거기에 연동된 애들을 bit로 표시
pii dir[4];

int get_num(int num){
    // 1개수 세어주는 것
    int res=0;
    while(num!=0){
        res+=(num%2);
        num/=2;
    }
    return res;
}

void Solve(){
    rng(i,0,6) cin>>datas[i];
    odd_cent.clear();
    even_cent.clear();
    rng(i,1,5){
        rng(j,1,5){
            bool flag=1;
            if(datas[i][j]!='B') flag=0;
            rng(k,0,3) if(datas[i+dir[k].fi][j+dir[k].se]!='B') flag=0;
            if(!flag) continue;
            int val=0;
            int num=((i-1)*5+j-1)/2;
            val+=(1<<num);
            rng(k,0,3){
                if(1<=i+dir[k].fi && i+dir[k].fi<=5 && 1<=j+dir[k].se && j+dir[k].se<=5){
                    num=((i+dir[k].fi-1)*5+j+dir[k].se-1)/2;
                    val+=(1<<num);
                }
            }
            if((i+j)%2==0) even_cent.pb(val);
            else odd_cent.pb(val);
        }
    }

    int even_res=100;
    rng(i,0,(1<<13)-1){
        bool flag=1;
        rng(j,0,(int)even_cent.size()-1){
            if(!(even_cent[j]&i)) flag=0;
        }
        if(flag) even_res=min(even_res,get_num(i));
    }

    int odd_res=100;
    rng(i,0,(1<<12)-1){
        bool flag=1;
        rng(j,0,(int)odd_cent.size()-1){
            if(!(odd_cent[j]&i)) flag=0;
        }
        if(flag) odd_res=min(odd_res,get_num(i));
    }
    cout<<even_res+odd_res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    dir[0]={-1,-1};
    dir[1]={1,-1};
    dir[2]={-1,1};
    dir[3]={1,1};
    while(t--){
        Solve();
    }
    return 0;
}

