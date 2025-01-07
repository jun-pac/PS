
#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)

using namespace std;

typedef long long ll;
#define INF 1000000007
int datas[50][50];
int face[5][50][50]; // 동, 서, 남, 북, 윗
int times[50][50]; // 사용이 불가능한 첫 번째 시간 (처음부터 불이나 물이 있었으면 0)
pair<int,int> dir[4]; // 
vector<int> edges[2002];
int dist[2002];

int mnt_BFS(int s, int t, int n){
    queue<pair<int,int>> q;
    fill(dist, dist+n, -1);
    q.push({s,0});
    while(!q.empty()){
        int idx=q.front().fi;
        int d=q.front().se;
        q.pop();
        if(dist[idx]!=-1) continue;
        dist[idx]=d;
        
        for(auto next : edges[idx]){
            if(dist[next]==-1) q.push({next,d+1});
        }
    }
    return dist[t];
}

int BFS(int s, int t, int n, int init_t){
    queue<pair<int,int>> q;
    fill(dist, dist+n*n, -1);
    q.push({s,init_t});
    while(!q.empty()){
        int idx=q.front().fi;
        int d=q.front().se;
        q.pop();
        if(dist[idx]!=-1) continue;
        dist[idx]=d;
        
        for(auto next : edges[idx]){
            if(dist[next]==-1 && d+1<times[next/n][next%n]) q.push({next,d+1});
        }
    }
    return dist[t];
}

void Solve(int tt){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1){
        rng(j,0,n-1){
            cin>>datas[i][j];
        }
    }
    rng(i,0,n-1) fill(times[i],times[i]+n,INF);
    pair<int,int> mnt={-1,-1};
    pair<int,int> entry={-1,-1};
    rng(i,0,n-1){
        rng(j,0,n-1){
            if(datas[i][j]==3){
                mnt={i,j};
                break;
            }
        }
        if(mnt.first!=-1) break;
    }
    rng(i,0,n-1){
        rng(j,0,n-1){
            if(datas[i][j]==1) times[i][j]=0;
        }
    }
    

    // Solving mountin problem
    int start=-1;
    rng(i,0,m*m*5) edges[i].clear();
    rng(k,0,4){
        rng(i,0,m-1){
            rng(j,0,m-1){
                int idx=k*m*m+i*m+j;
                cin>>face[k][i][j];
                if(face[k][i][j]==2){
                    start=idx;
                }
            }
        }
    }
    int k;
    cin>>k;
    rng(i,0,k-1){
        int a,b,d,v;
        cin>>a>>b>>d>>v;
        //cout<<a<<' '<<b<<' '<<d<<' '<<v<<'\n';
        int ni=a, nj=b;
        int val=0;
        while(0<=ni && ni<n && 0<=nj && nj<n){
            if(datas[ni][nj]!=0) break;
            times[ni][nj]=min(val,times[ni][nj]);
            val+=v;
            //cout<<ni<<' '<<nj<<' '<<val<<'\n';
            ni+=dir[d].fi;
            nj+=dir[d].se;
        }
    }
    // cout<<"TIMES\n";
    // rng(i,0,n-1){
    //     rng(j,0,n-1){
    //         cout<<(times[i][j]==INF?9:times[i][j])<<' ';
    //     }
    //     cout<<'\n';
    // }

    rng(f,0,4){
        rng(i,0,m-1){
            rng(j,0,m-1){
                int idx=f*m*m+i*m+j;
                if(face[f][i][j]!=1){
                    rng(k,0,3){
                        int ni=i+dir[k].first, nj=j+dir[k].second;
                        int idx2=f*m*m+ni*m+nj;
                        if(0<=ni && ni<m && 0<=nj && nj<m){
                            if(face[f][ni][nj]!=1) edges[idx].pb(idx2);
                        }
                    }
                }
            }
        }
    }
    int f=4;
    int i=0;
    rng(j,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=3, ni=0, nj=m-1-j;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    i=m-1;
    rng(j,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=2, ni=0, nj=j;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    int j=0;
    rng(i,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=1, ni=0, nj=i;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    j=m-1;
    rng(i,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=0, ni=0, nj=m-1-i;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    f=0;
    j=0;
    rng(i,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=2, ni=i, nj=m-1;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    f=1;
    j=0;
    rng(i,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=3, ni=i, nj=m-1;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    f=2;
    j=0;
    rng(i,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=1, ni=i, nj=m-1;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    f=3;
    j=0;
    rng(i,0,m-1){
        int idx=f*m*m+i*m+j;
        if(face[f][i][j]!=1){
            int nf=0, ni=i, nj=m-1;
            int idx2=nf*m*m+ni*m+nj;
            if(face[nf][ni][nj]!=1){
                edges[idx].pb(idx2);
                edges[idx2].pb(idx);
            }
        }
    }
    int mnt_end=5*m*m;
    
    rng(i,0,m-1){
        rng(j,0,m-1){
            rng(k,0,3){
                int ni=mnt.first+i+dir[k].first, nj=mnt.second+j+dir[k].second;
                if(0<=ni && ni<n && 0<=nj && nj<n && datas[ni][nj]==0){
                    f=k;
                    entry={ni,nj};
                    if(f==0){
                        int idx=f*m*m+(m-1)*m+(m-1-i);
                        //cout<<"conn: "<<idx<<' '<<f<<endl;
                        edges[idx].pb(mnt_end);
                        edges[mnt_end].pb(idx);
                    }
                    if(f==1){
                        int idx=f*m*m+(m-1)*m+(i);
                        edges[idx].pb(mnt_end);
                        edges[mnt_end].pb(idx);
                    }
                    if(f==2){
                        int idx=f*m*m+(m-1)*m+(j);
                        edges[idx].pb(mnt_end);
                        edges[mnt_end].pb(idx);
                    }
                    if(f==3){
                        int idx=f*m*m+(m-1)*m+(m-i-j);
                        edges[idx].pb(mnt_end);
                        edges[mnt_end].pb(idx);
                    }
                }
            }
        }
    }
    // cout<<"entry: "<<entry.fi<<' '<<entry.se<<'\n';

    mnt_BFS(start,mnt_end,5*m*m+1);
    // rng(k,0,4){
    //     cout<<"FACE "<<k<<'\n';
    //     rng(i,0,m-1){
    //         rng(j,0,m-1){
    //             cout<<dist[k*m*m+i*m+j]<<' ';
    //         }
    //         cout<<'\n';
    //     }
    // }
    
    // cout<<"final: "<<dist[mnt_end]<<' '<<times[entry.fi][entry.se]<<'\n';
    if(dist[mnt_end]==-1 || dist[mnt_end]>=times[entry.fi][entry.se]){
        cout<<"#"<<tt<<" "<<-1<<'\n';
        return;
    }
    // cout<<"entry : "<<dist[mnt_end]<<'\n';


    // Solving fire problem
    rng(i,0,n*n) edges[i].clear();
    start=n*entry.fi+entry.se;
    int end=-1;
    rng(i,0,n-1){
        rng(j,0,n-1){
            if(datas[i][j]==4) end=i*n+j;
        }
    }
    // graph construction
    rng(i,0,n-1){
        rng(j,0,n-1){
            if(datas[i][j]==0 || datas[i][j]==4){
                rng(k,0,3){
                    int ni=i+dir[k].first, nj=j+dir[k].second;
                    if(0<=ni && ni<n && 0<=nj && nj<n && (datas[ni][nj]==0 || datas[ni][nj]==4)){
                        edges[i*n+j].pb(ni*n+nj);
                    }
                }
            }
        }
    }
    BFS(start, end, n, dist[mnt_end]);
    cout<<"#"<<tt<<" "<<dist[end]<<'\n';

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    dir[0]={0,1};
    dir[1]={0,-1};
    dir[2]={1,0};
    dir[3]={-1,0};
    for(int tt=1; tt<=t; tt++){
        Solve(tt);
    }
    
}