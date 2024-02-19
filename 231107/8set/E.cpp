#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
using namespace std;
 
#define N 300000
pair<int,pair<int,int>> a[300030], b[300030]; // {attack, {defence, idx}}
pair<int,int> sega[1<<20], segb[1<<20]; // defence, idx // attack은 중요하지 않음.
int nexta[300030], nextb[300030];
vector<int> redges[600060];
int visited[600060];
 
void build_sega(int idx, int l, int r){
    if(l==r){
        sega[idx]={a[l].se.fi,a[l].se.se};
        return;
    }
    int mid=(l+r)>>1;
    build_sega(2*idx,l,mid);
    build_sega(2*idx+1,mid+1,r);
    sega[idx]=max(sega[2*idx],sega[2*idx+1]); // Some other operation
}
 
void build_segb(int idx, int l, int r){
    if(l==r){
        segb[idx]={b[l].se.fi,b[l].se.se};
        return;
    }
    int mid=(l+r)>>1;
    build_segb(2*idx,l,mid);
    build_segb(2*idx+1,mid+1,r);
    segb[idx]=max(segb[2*idx],segb[2*idx+1]); // Some other operation
}
 
pair<int,int> find_sega(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return sega[idx];
    int mid=(l+r)>>1;
    pair<int,int> ans={-1,-20};
    if(t_l<=mid) ans=max(ans,find_sega(2*idx,l,mid,t_l,t_r));
    if(t_r>mid) ans=max(ans,find_sega(2*idx+1,mid+1,r,t_l,t_r));
    return ans;
}
 
pair<int,int> find_segb(int idx, int l, int r, int t_l, int t_r){
    if(t_l<=l && r<=t_r) return segb[idx];
    int mid=(l+r)>>1;
    pair<int,int> ans={-1,-20};
    if(t_l<=mid) ans=max(ans,find_segb(2*idx,l,mid,t_l,t_r));
    if(t_r>mid) ans=max(ans,find_segb(2*idx+1,mid+1,r,t_l,t_r));
    return ans;
}
 
void DFS(int idx, int mark){
    visited[idx]=mark;
    for(auto next : redges[idx]){
        DFS(next, mark);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n;
        for(int i=0; i<n; i++) cin>>a[i].fi;
        for(int i=0; i<n; i++) cin>>a[i].se.fi;
        for(int i=0; i<n; i++) a[i].se.se=i;
        cin>>m;
        for(int i=0; i<m; i++) cin>>b[i].fi;
        for(int i=0; i<m; i++) cin>>b[i].se.fi;
        for(int i=0; i<m; i++) b[i].se.se=i;
        sort(a,a+n);
        sort(b,b+m);
 
        // a[i]가 정해지면, a[i].se보다 strictly 큰 b[i].fi를 가진 b[i].se중에 최소값을 가지는 것.
        // 뭐 이것은 rmq같은 거네요
        // 만약에 b[i].se가 같으면 어쩌죠?
        // 그럼 뭐 앞에 있는거 주면 되는데
        build_sega(1,0,n-1);
        build_segb(1,0,m-1);
        for(int i=0; i<n; i++){
            int idx=a[i].se.se;
            if(b[m-1].fi<=a[i].se.fi) nexta[idx]=-1;
            else{
                int l=0, r=m-1;
                while(l!=r){
                    int mid=(l+r)>>1;
                    if(b[l].fi>a[i].se.fi) r=mid;
                    else l=mid+1;
                }
                nexta[idx]=find_segb(1,0,m-1,l,m-1).se;
            }
        }
        for(int i=0; i<m; i++){
            int idx=b[i].se.se;
            if(a[n-1].fi<=b[i].se.fi) nextb[idx]=-1;
            else{
                int l=0, r=n-1;
                while(l!=r){
                    int mid=(l+r)>>1;
                    if(a[l].fi>b[i].se.fi) r=mid;
                    else l=mid+1;
                }
                nextb[idx]=find_sega(1,0,n-1,l,n-1).se;
            }
        }
        
        for(int i=0; i<n; i++) if(nexta[i]!=-1) redges[nexta[i]+N].push_back(i);
        for(int i=0; i<m; i++) if(nextb[i]!=-1) redges[nextb[i]].push_back(i+N);
        fill(visited, visited+n, 0);
        fill(visited+N, visited+N+m, 0);
        int pre=0;
        for(int i=0; i<m; i++) if(nextb[i]==-1){
            DFS(i+N,2); // b wins!
        }
        //for(int i=0; i<n; i++) if(visited[i]==2) pre++;
        for(int i=0; i<n; i++) if(nexta[i]==-1){
            DFS(i,1); // a wins!
        }
        int cnt1=0, cnt2=0;
        for(int i=0; i<n; i++) if(visited[i]==1) cnt1++;
        for(int i=0; i<n; i++) if(visited[i]==2) cnt2++;
        //assert(pre==cnt2);
        cout<<cnt1<<' '<<n-cnt1-cnt2<<' '<<cnt2<<endl;
 
        for(int i=0; i<n; i++) redges[i].clear();
        for(int i=0; i<m; i++) redges[i+N].clear();
    }
    return 0;
}