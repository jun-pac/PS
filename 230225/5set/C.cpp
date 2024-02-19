// 
//./C<test

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

int a[100000], b[100000];
int edge[100000];
vector<int> cycle_sz;
bool visited[100000];
int asn[100000];

int DFS(int idx){
    if(visited[idx]) return 0;
    //cout<<"cuue "<<idx<<endl;
    visited[idx]=true;
    return DFS(edge[idx])+1;   
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>x;
            a[i]=x-1;
        }
        for(int i=0; i<n; i++){
            cin>>x;
            b[i]=x-1;
        }
        for(int i=0; i<n; i++){
            edge[a[i]]=b[i];
            //cout<<a[i]<<' '<<b[i]<<endl;
        }
        fill(visited, visited+n, false);
        cycle_sz.clear();
        for(int i=0; i<n; i++){
            if(!visited[i]){
                //cout<<"GO "<<i<<endl;
                cycle_sz.push_back(DFS(i));
            }
        }
        //sort(cycle_sz.begin(), cycle_sz.end());
        //reverse(cycle_sz.begin(), cycle_sz.end());
        int i_num=1, f_num=n;
        ll res=0;
        // 의미상으로는 pq가 있어야 하는데, 실질적으로 계산은 pq없이도 할 수 있을 듯 합니다.
        priority_queue<int> pq;
        for(int i=0; i<cycle_sz.size(); i++){
            pq.push(cycle_sz[i]);
        }
        while(!pq.empty()){
            int temp=pq.top();
            pq.pop();
            if(temp>1){
                res+=2*(f_num-i_num);
                f_num--;
                i_num++;
            }
            else f_num--;
            if(temp>2) pq.push(temp-2);
        }
        cout<<res<<endl;
    }
    return 0;
}