// 
//./E<test

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

bool A_visit[200000], B_visit[200000];
vector<int> edges[200000];
int d;

class node{
public:
    node(){
        A_eng=false, B_eng=false;
        A_path=B_path=0;
        A_depth=B_depth=-1;
    }
    bool A_eng, B_eng;
    ll A_path, B_path; // path if eng==true, else minimum dist
    ll A_depth, B_depth; // farmost
};
node DP[200000];

ll DP_DFS(int idx, int p){
    node res;
    res.A_eng=false|A_visit[idx];
    res.B_eng=false|B_visit[idx];
    res.A_depth=(A_visit[idx]?0:-1);
    res.B_depth=(B_visit[idx]?0:-1);
    res.A_path=0;
    res.B_path=0;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(next==p) continue;
        DP_DFS(next,idx);
        node temp=DP[next];
        res.A_eng=res.A_eng|temp.A_eng;
        res.B_eng=res.B_eng|temp.B_eng;
        if(temp.A_depth!=-1) res.A_depth=max(res.A_depth,temp.A_depth+1);
        if(temp.B_depth!=-1) res.B_depth=max(res.B_depth,temp.B_depth+1);
        if(temp.A_eng) res.A_path=res.A_path+temp.A_path+2;
        if(temp.B_eng) res.B_path=res.B_path+temp.B_path+2;
    }
    if(!res.A_eng && res.B_depth>=d){
        res.A_eng=true;
    }
    if(!res.B_eng && res.A_depth>=d){
        res.B_eng=true;
    }
    DP[idx]=res;
    return res.A_path+res.B_path;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,a,b;
    int m1,m2;
    cin>>n>>d;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    fill(A_visit,A_visit+n,false);
    fill(B_visit,B_visit+n,false);
    
    cin>>m1;
    for(int i=0; i<m1; i++){
        cin>>a;
        a--;
        A_visit[a]=true;
    }
    cin>>m2;
    for(int i=0; i<m2; i++){
        cin>>a;
        a--;
        B_visit[a]=true;
    }
    ll res=DP_DFS(0,-1);
    cout<<res<<endl;
    return 0;
}