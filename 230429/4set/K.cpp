// 
//./F<test

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

int cost[200020];
vector<int> edges[200020]; // idx, cost
int in[200020], out[200020]; // time을 기록
int p[200020];
int cyc_start;
int min_idx; 
int min_val;

void DFS(int idx, int cnt){
    //cout<<"DFS "<<idx<<endl;
    in[idx]=cnt++;
    for(auto next : edges[idx]){
        if(cyc_start==-1 && in[next]!=0 && in[idx]%2==in[next]%2){
            cyc_start=next;
            min_idx=idx;
        }
        else if(in[next]==0){
            DFS(next,cnt);
        }
    }
    
    if(cyc_start!=-1 && out[cyc_start]==0){
        // 아직 cycle속에 존재
        //cout<<"comp : "<<cyc_start<<' '<<idx<<' '<<cost[idx]<<' '<<out[cyc_start]<<endl;    
        if(cost[min_idx]>cost[idx]) min_idx=idx;
    }
    out[idx]=cnt;
}

void DFS2(int idx, int cnt, bool flag){
    if(flag) cnt++;
    in[idx]=cnt++;
    for(auto next : edges[idx]){
        if(in[next]<1000000){
            if((next==p[min_idx] && idx==min_idx) || (next==min_idx && idx==p[min_idx])) DFS2(next,cnt,true);
            else DFS2(next,cnt,false);
        }
    }
    if(flag) cnt--;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        ll a,b;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n; i++){
            cin>>a;
            a--;
            p[i]=a;
            edges[i].push_back(a);
            edges[a].push_back(i);
        }

        ll sum=0;
        for(int i=0; i<n; i++){
            cin>>cost[i];
            sum+=cost[i];
        }
        if(k==1){
            cout<<sum<<endl;
            for(int i=0; i<n; i++) cout<<1<<' ';
            cout<<endl;
        }
        else if(k>2){
            cout<<0<<endl;
            ll res=0;
            fill(in,in+n,0);
            fill(out,out+n,0);
            for(int i=0; i<n; i++){
                if(in[i]==0){
                    cyc_start=-1;
                    min_idx=-1;
                    DFS(i,1);
                    if(min_idx!=-1) in[cyc_start]+=1000000;
                }
            }
            for(int i=0; i<n; i++){
                cout<<(in[i]>=1000000?3:in[i]%2+1)<<' ';
            }
            cout<<endl;
        }
        else{
            ll res=0;
            fill(in,in+n,0);
            fill(out,out+n,0);
            for(int i=0; i<n; i++){
                if(in[i]==0){
                    cyc_start=-1;
                    min_idx=-1;
                    //cout<<"DFS strart : "<<i<<endl;
                    DFS(i,1);
                    if(cyc_start!=-1){
                        res+=cost[min_idx];
                        min_val=cost[min_idx];
                        DFS2(cyc_start,1000001,false);
                    }
                }
            }
            cout<<res<<endl;
            for(int i=0; i<n; i++) cout<<(in[i]%2+1)<<' ';
            cout<<endl;
        }
    }
    return 0;
}