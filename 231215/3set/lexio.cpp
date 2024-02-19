#include <bits/stdc++.h>
using namespace std;
 
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
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

#define N_ 201000
#define MOD 998244353
#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

int cnt[N_];
vc<int> subs[2];
vc<int> edges[N_];
vc<int> lists[N_];
int group[N_], gn; //gn은 group number
bool visited[N_];

void DFS(int idx){
    if(visited[idx]) return;
    visited[idx]=true;
    for(auto next : edges[idx]){
        if(!visited[next]) DFS(next);
    }
}


void Solve(){
	int n,x,fuck=0;
	cin>>n;
    gn=-1;
	rng(i,0,n-1){
		cin>>x;
		subs[cnt[x]%2].pb(x);
        if(fuck==0) gn++;
        group[i]=gn;
        if(cnt[x]%2==0) fuck++;
        else fuck--;
		cnt[x]++;
        lists[x].pb(i);
	}
    gn++;
	int ocnt=0;
	int ecnt=0;
	rng(i,0,N_-1){
		if(cnt[i]!=0 && cnt[i]%2==0) ecnt++;
		else if(cnt[i]!=0 && cnt[i]%2==1) ocnt++; 
	}
	if(ocnt>0){
		ll res=1;
		rng(i,0,ecnt+ocnt-2) res=res*2%MOD;
		cout<<(res%MOD+MOD)%MOD<<'\n';
		// 여기서 지금 red, blue가 lexio same이 나올 수가 없음.
	}
	else{
		// lexio same이 나오는 경우는 제거해줘야함.
		ll res=1;
		rng(i,0,ecnt-1) res=res*2%MOD;
		ll same=1;
		bool flag=true;
		rng(i,0,n/2-1){
			if(subs[0][i]!=subs[1][i]){
				flag=false;
				break;
			}
		}

		if(flag){
            rng(i,0,N_-1){
                rng(j,1,(int)lists[i].size()-1){
                    if(group[lists[i][0]]!=group[lists[i][j]]){
                        edges[group[lists[i][0]]].pb(group[lists[i][j]]);
                        edges[group[lists[i][j]]].pb(group[lists[i][0]]);
                    }
                }
            }
            int num=0;
            fill(visited,visited+gn,0);
            rng(i,0,gn-1){
                if(!visited[i]){
                    num++;
                    DFS(i);
                }
            }
            rep(i,num) same=(same*2)%MOD;
    	}
        else same=0;
		cout<<(((res-same)*ari_inv(2))%MOD+MOD)%MOD<<'\n';
	}
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int TC=1;
    while(TC--){
        Solve();
    }
}