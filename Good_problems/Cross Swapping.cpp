


#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_bacidx
#define eb emplace_bacidx
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

#define N 1030
#define MOD 998244353
#define INF 1000000007 

int datas[N][N];
int cols[N][N];
int conn[N]; // 없으면 -1. 언제나 component당 연결이 1개인 상황을 유지하는 것
int state[N];
int parent[N];

int find(int idx){
	if(idx==parent[idx]) return idx;
	return parent[idx]=find(parent[idx]);
}
void c_union(int a, int b){
	a=find(a), b=find(b);
	parent[b]=a;
}

int n;
void swapcol(int idx){
    rng(j,0,n-1) datas[idx][j]=cols[idx][j];
    rng(j,0,n-1) datas[j][idx]=cols[j][idx];
    rng(j,0,n-1) cols[idx][j]=datas[j][idx];
    rng(j,0,n-1) cols[j][idx]=datas[idx][j];
}

void Solve(){
    cin>>n;
    rng(i,0,n-1){
        rng(j,0,n-1) cin>>datas[i][j];
    }
    rng(i,0,n-1){
        rng(j,0,n-1) cols[i][j]=datas[j][i];
    }

    //** always maintain 'pair-connection' condition is crucial
    fill(conn,conn+n,-1);
    rng(i,0,n-1) parent[i]=i;
    rng(i,0,n-2){
        rng(j,i+1,n-1){
            // (i,j) -> swap (i,i) or swap(j,j)
            if(datas[i][j]<datas[j][i]){
                // i,j need to reside in same component
                int ri=find(i), rj=find(j);
                if(ri!=rj){
                    // if they are already in opposite position?
                    if(conn[ri]==rj){
                        assert(conn[rj]==ri);
                        continue;
                    }
                    int cri=conn[ri], crj=conn[rj];
                    // Union operation for 'opposite side'
                    if(cri==-1 && crj==-1) c_union(ri,rj);
                    else if(cri!=-1 && crj!=-1) c_union(ri,rj), c_union(cri,crj);
                    else if(cri!=-1) c_union(ri,rj);
                    else c_union(rj,ri);
                }
            }
            else if(datas[i][j]>datas[j][i]){
                // swappedness of i,j should be different
                int ri=find(i), rj=find(j);
                int cri=conn[ri], crj=conn[rj]; // ri -- cri, rj -- crj
                if(ri==rj) continue;
                if(conn[ri]!=-1 && conn[rj]!=-1){
                    assert(conn[cri]==ri);
                    assert(conn[crj]==rj);
                    c_union(conn[ri],rj);
                    c_union(conn[rj],ri);
                    conn[cri]=crj;
                    conn[crj]=cri;
                }
                else if(conn[ri]!=-1) c_union(conn[ri],rj);
                else if(conn[rj]!=-1) c_union(conn[rj],ri);
                if(conn[ri]==-1 && conn[rj]==-1){
                    conn[ri]=rj;
                    conn[rj]=ri;
                }
            }
        }
        // 그리고 마지막에 찾으려면 그냥 정상적인 그래프가 낫지않
    }
    fill(state,state+n,-1);
    rng(i,0,n-1){
        if(state[find(i)]==-1){
            state[find(i)]=0;
            if(conn[find(i)]!=-1){
                assert(state[conn[find(i)]]==-1);
                state[conn[find(i)]]=1;
            }
        }
        state[i]=state[find(i)];
    }
    rng(i,0,n-1){
        if(state[i]==1) swapcol(i);
    }
    int a=(state[0]?:1);
    //cout<<'\n';
    rng(i,0,n-1){
        rng(j,0,n-1) cout<<datas[i][j]<<' '; cout<<'\n';
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

