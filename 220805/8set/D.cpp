// 
//./D<test

#include <bits/stdc++.h>
#define endl '\n'
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

#define INF 10007
#define N 101

vector<int> edges[N];
int flow[N][N]; // Use map if N is larger than 20000
int capa[N][N];
int levels[N];
bool visited[N];
int work[N];
int rest[N][N];

void add_edge(int a, int b, int c){ // edge a->b (c)
    // this is NOT bidirectional!
	edges[a].push_back(b); flow[a][b]=0; capa[a][b]=c;
	edges[b].push_back(a); flow[b][a]=0; capa[b][a]=c;
	// If capa accumulate, 
    //edges[a].push_back(b); flow[a][b]=0; capa[a][b]=c;
	//edges[b].push_back(a); flow[b][a]=0; capa[b][a]=0;
}
 
void level_BFS(int s){
	fill(visited,visited+N,false);
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		int idx=q.front().first;
		int level=q.front().second;
		q.pop();
		if(visited[idx]) continue;
		levels[idx]=level;
		visited[idx]=true;
		for(int i=0; i<edges[idx].size(); i++){
			int next=edges[idx][i];
			if(!visited[next] && capa[idx][next]>flow[idx][next]){
				q.push({next,level+1});
			}
		}
	}
}
 
int main_DFS(int idx, int f, int t){
	visited[idx]=true;
	if(idx==t || f==0) return f;
	for(int &i=work[idx]; i<edges[idx].size(); i++){
		int next=edges[idx][i];
		if(!visited[next] && levels[next]==levels[idx]+1 && capa[idx][next]>flow[idx][next]){
			int f_temp=main_DFS(next,min(f,capa[idx][next]-flow[idx][next]),t);
			if(f_temp==0) continue;
			flow[idx][next]+=f_temp;
			flow[next][idx]-=f_temp;
			return f_temp;
		}
	}
	return 0;
}
 
int DINIC(int s, int t){
	int result=0;
	while(true){
		levels[t]=-1;
		level_BFS(s);
		if(levels[t]==-1) break;
 
		fill(work,work+N,0);
		while(true){
			fill(visited,visited+N,false);
			int f_temp=main_DFS(s,INF,t);
			if(f_temp==0) break;
			result+=f_temp;
		}
	}
	return result;
}
 
// 유량이 남은 모든 정점을 탐색
void cut_DFS(int idx){
	if(visited[idx]) return;
	visited[idx]=true;
	for(int i=0; i<edges[idx].size(); i++){
		int next=edges[idx][i];
		if(!visited[next] && capa[idx][next]>flow[idx][next]) cut_DFS(next);
	}
}

vector<string> ans;
vector<int> ans_num;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b,c;
    for(int i=0; i<n; i++){
        fill(capa[i],capa[i]+n,0);
        fill(flow[i],flow[i]+n,0);
        fill(rest[i],rest[i]+n,1000000007);
    }
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        a--, b--;
        add_edge(a,b,1);
        rest[a][b]=c;
        rest[b][a]=c;
    }
    bool inf_flag=false;
    ll tot=0;
    int last_f=0;
    while(true){
        int ff=DINIC(0,n-1);
        ff+=last_f;
        if(ff==0){
            inf_flag=true;
            break;
        }
        if(ff>=INF) break;
        fill(visited,visited+n,false);
        cut_DFS(0);
        int rest_mn=1000000007;
        for(int i=0; i<n; i++){
            if(!visited[i]) continue;
            for(auto next:edges[i]){
                if(visited[i]!=visited[next]) rest_mn=min(rest[i][next], rest_mn);
            }                
        }
        tot=tot+rest_mn;
        for(int i=0; i<n; i++){
            if(!visited[i]) continue;
            for(auto next:edges[i]){
                if(visited[i]!=visited[next]){
                    rest[i][next]-=rest_mn;
                    rest[next][i]-=rest_mn;
                    if(rest[i][next]==0) capa[i][next]=capa[next][i]=INF;
                }
            }                
        }
        /*
        for(int i=0; i<n; i++){
            fill(flow[i],flow[i]+n,0);
        }
        */
        last_f=ff;
        string s;
        for(int i=0; i<n; i++){
            if(visited[i]) s.push_back('1');
            else s.push_back('0');
        }
        ans.push_back(s);
        ans_num.push_back(rest_mn);
    }
    if(inf_flag) cout<<"inf"<<endl;
    else{
        cout<<tot<<' '<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<' '<<ans_num[i]<<endl;
        }
    }
    return 0;
}