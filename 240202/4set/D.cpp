
#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define N 300030
#define INF 1000000007

priority_queue<array<int,3>> pq1,pq2; // {time_difference, time1_i, time2_j}
int time1[N], time2[N];
int conn12[N], conn21[N];
int mxconn12[N];

bool check(int n, int m, int num){ // For debug
    int cnt=0;
    rng(i,0,n-1) if(conn12[i]!=-1) cnt++;
    if(cnt!=num) return 0;
    
    cnt=0;
    rng(i,0,m-1) if(conn21[i]!=-1) cnt++;
    if(cnt!=num) return 0;
    
    rng(i,0,n-1) if(conn12[i]!=-1) if(i!=conn21[conn12[i]]) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m; // n: # of time1 events, m: # of time2 events
    cin>>n>>m;
    rng(i,0,n-1) cin>>time1[i]; sort(time1,time1+n);
    rng(i,0,m-1) cin>>time2[i]; sort(time2,time2+m);
    fill(conn12,conn12+n,-1); // conn12[i] indicate index in time2 in which time1_i currently connected
    fill(conn21,conn21+m,-1); // conn21[i] indicate index in time1 in which time2_i currently connected
    rng(i,0,n-1){
        rng(j,0,m-1) pq1.push({time2[j]-time1[i], i, j});
    }

    int cur, mxcur=0; // currently [cur, cur+6] time difference is allowed 
    int num=0; // current connected edges.
    int mx=-INF;
    while(!pq1.empty()){
        // add new edges (Which has maximum distance among unused edges)
        auto add_edge=pq1.top(); pq1.pop(); pq2.push(add_edge);
        cur=add_edge[0];
        int i=add_edge[1], j=add_edge[2]; 

        // Greedy scheme : always connect time1_i with front-most time2_j in [time1_i+cur, time2_i+cur+6]
        assert(conn12[i]!=j);
        if(conn12[i]!=-1){
            num--;
            conn21[conn12[i]]=-1;
            conn12[i]=-1;
        }
        if(conn21[j]!=-1){
            conn12[conn21[j]]=-1;
            conn21[j]=-1;
            num--;
        }
        conn12[i]=j, conn21[j]=i;
        num++;
        assert(check(n,m,num));

        if(num>mx){
            rng(k,0,n-1) mxconn12[k]=conn12[k];
            mx=num;
            mxcur=cur;
        }

        // delete edges that is greater or equal to cur+6
        while(!pq2.empty() && pq2.top()[0]>=cur+6){
            auto del_edge=pq2.top();
            if(conn12[del_edge[1]]==del_edge[2]){
                conn12[del_edge[1]]=-1;
                conn21[del_edge[2]]=-1;
                num--;
            }
            pq2.pop();
        }
    }
    cout<<"delta T : "<<mxcur+3<<'\n';
    cout<<"maximum # of pairs : "<<mx<<'\n';
    cout<<"connections\n";
    rng(i,0,n-1) if(mxconn12[i]!=-1) cout<<"("<<i+1<<' '<<mxconn12[i]+1<<") "; cout<<'\n';
    return 0;
}

