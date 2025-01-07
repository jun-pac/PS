
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)

#define N 100010
int visited[N];

int solution(vector<int> &T, vector<int> &A){
    // T: parent, T[root]=root
    int num=T.size();
    fill(visited,visited+num,0);
    for(auto idx:A){
        if(!visited[idx]){
            int cur=idx;
            while(!visited[cur]){
                visited[cur]=1;
                cur=T[cur];
            }
        }
    }
    int res=0;
    for(int i=0; i<num; i++) if(visited[i]) res++;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> T, A;
    rng(i,0,n-1){
        int a;
        cin>>a;
        T.push_back(a);
    }
    rng(i,0,m-1){
        int a;
        cin>>a;
        A.push_back(a);
    }

    int num=T.size();
    fill(visited,visited+num,0);
    for(auto idx:A){
        if(!visited[idx]){
            int cur=idx;
            while(!visited[cur]){
                visited[cur]=1;
                cur=T[cur];
            }
        }
    }
    int res=0;
    for(int i=0; i<num; i++) if(visited[i]) res++;    cout<<res<<'\n';

    return 0;
}

