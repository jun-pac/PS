// 
//./D<test.txt

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

vector<pair<int,int>> edges[200000];
pair<int,int> e_ls[200020];
bool visited[200000];
int parent[200000];
int f0,f1,f2,f3;
int root(int idx){
    return parent[idx]=(parent[idx]==idx?idx:root(parent[idx]));
}
void c_union(int a, int b){
    parent[root(a)]=root(b);
}
bool DFS(int idx){
    if(visited[idx]) return false;
    visited[idx]=true;
    if(idx==f0) return true;
    if(idx==f1||idx==f2||idx==f3) return false;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i].fi;
        if(!visited[next] && DFS(next)) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        for(int i=0;i<n;i++) edges[i].clear();
        for(int i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            edges[a].push_back({b,i});
            edges[b].push_back({a,i});
            e_ls[i]={a,b};
        }
        for(int i=0; i<n; i++) parent[i]=i;
        if(m<=n+1){
            for(int i=0; i<m; i++){
                int a=e_ls[i].fi, b=e_ls[i].se;
                if(root(a)!=root(b)){
                    c_union(a,b);
                    cout<<0;
                }
                else cout<<1;
            }
            cout<<endl;
        }
        else{
            // More complicated.
            int tri[3];
            int nums[6];
            int cnt=0;
            for(int i=0; i<m; i++){
                int a=e_ls[i].fi, b=e_ls[i].se;
                if(root(a)!=root(b)){
                    c_union(a,b);
                }
                else{
                    nums[2*cnt]=a;
                    nums[2*cnt+1]=b;
                    tri[cnt++]=i;
                }
            }
            sort(nums, nums+6);
            if(nums[0]==nums[1] && nums[2]==nums[3] && nums[4]==nums[5]){
                bool flag=false;
                int st=e_ls[tri[0]].fi;
                f0=e_ls[tri[0]].se;
                fill(visited,visited+n,false);
                visited[st]=true;
                f1=nums[0], f2=nums[2], f3=nums[4];
                for(int i=0; i<edges[st].size(); i++){
                    int b=edges[st][i].fi;
                    if(b!=nums[0] && b!=nums[2] && b!=nums[4] && DFS(b)){
                        // st,b연결하는 edges찾기
                        tri[0]=edges[st][i].se;
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    st=e_ls[tri[1]].fi;
                    f0=e_ls[tri[1]].se;
                    fill(visited,visited+n,false);
                    visited[st]=true;
                    for(int i=0; i<edges[st].size(); i++){
                        int b=edges[st][i].fi;
                        if(b!=nums[0] && b!=nums[2] && b!=nums[4] && DFS(b)){
                            tri[1]=edges[st][i].se;
                            flag=true;
                            break;
                        }
                    }
                }
                if(!flag){
                    st=e_ls[tri[2]].fi;
                    f0=e_ls[tri[2]].se;
                    fill(visited,visited+n,false);
                    visited[st]=true;
                    for(int i=0; i<edges[st].size(); i++){
                        int b=edges[st][i].fi;
                        if(b!=nums[0] && b!=nums[2] && b!=nums[4] && DFS(b)){
                            tri[2]=edges[st][i].se;
                            flag=true;
                            break;
                        }
                    }
                }
            }
            for(int i=0; i<m; i++){
                if(i==tri[0] || i==tri[1] || i==tri[2]) cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
    }
    return 0;
}