// 
//./D<test

#include <bits/stdc++.h>
//#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}


int ans[100010];

vector<int> edges[100010];
int mx_dist[100010];
int subdepth[100010];

int sub_DFS(int idx, int p){
    int mx=0;
    for(auto next : edges[idx]){
        if(next!=p){
            umax(mx,sub_DFS(next,idx));
        }
    }
    return subdepth[idx]=mx+1;
}

void update_DFS(int idx, int p, int mx_depth){
    mx_dist[idx]=mx_depth;
    for(auto next : edges[idx]){
        if(next!=p){
            update_DFS(next, idx, mx_depth+1);
        }
    }
}

void sz_DFS(int idx, int p, int mx_depth=0){
    int init_mx=mx_depth;
    int mx_idx=-1;
    for(auto next : edges[idx]){
        if(next==p) continue;
        if(subdepth[next]>mx_depth){
            mx_depth=subdepth[next];
            mx_idx=next;
        }
    }
    mx_dist[idx]=mx_depth;
    
    for(auto next:edges[idx]){
        if(next!=p && next!=mx_idx){
            update_DFS(next,idx,mx_depth+1);
        }
    }

    if(mx_idx!=-1){
        for(auto next:edges[idx]){
            if(next!=p && next!=mx_idx){
                init_mx=max(init_mx,subdepth[next]);
            }
        }
        sz_DFS(mx_idx, idx, init_mx+1);
    }
}
/*
int find(int idx){
    return parent[idx]=(parent[idx]==idx?idx:find(parent[idx]));
}
void c_union(int a, int b){
    parent[find(a)]=find(b);
}
*/
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        int n;
        cin>>n;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        //for(int i=0; i<n; i++) parent[i]=i;
        sub_DFS(0,-1);
        //cout<<"Subdepth : ";
        //for(int i=0; i<n; i++) cout<<subdepth[i]<<' ';
        //cout<<endl;
        sz_DFS(0,-1,0);
        for(int i=0; i<n; i++) cout<<mx_dist[i]<<' ';
        cout<<endl;
        sort(mx_dist,mx_dist+n);
        reverse(mx_dist,mx_dist+n);
        int cnt=0;
        for(int i=n; i>0; i--){
            while(cnt<n && mx_dist[cnt]>=i) cnt++;
            ans[i-1]=n-cnt+1;
        }
        for(int i=0; i<n; i++) cout<<min(ans[i],n)<<' ';
        cout<<endl;
    return 0;
}