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

int mx_dist[200020]; // 각 [l,r]에 내가 있었을 때 도달가능한 최대 x
pair<int,int> outer[200020]; // [l,r]
pair<int,int> inner[200020]; // [a,b]
pair<int,int> lsort[200020]; // [l,idx];
pair<int,int> bsort[200020]; // [b,idx];
vector<pair<int,int>> ans; // 기준이 되는 {l,b}즉 x가 l이상이면 b까지는 보장이 된다는 것
int n, last_l;

int DFS(int idx){;
    int mx_b=inner[idx].se, mx_idx=-1;
    while(last_l<n && lsort[last_l].fi<=inner[idx].se){
        if(inner[lsort[last_l].se].se>mx_b){
            mx_b=inner[lsort[last_l].se].se;
            mx_idx=lsort[last_l].se;
        }
        last_l++;
    }
    if(mx_idx!=-1) mx_b=DFS(mx_idx);
    return mx_b;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ans.clear();
        cin>>n;
        for(int i=0; i<n; i++) cin>>outer[i].fi>>outer[i].se>>inner[i].fi>>inner[i].se;
        for(int i=0; i<n; i++){
            lsort[i]={outer[i].fi,i};
            bsort[i]={inner[i].se,i};
        }
        sort(lsort,lsort+n);
        sort(bsort,bsort+n);
        last_l=0;

        int ii=0;
        while(ii<n){
            int idx=bsort[ii].se;
            int mx_b=DFS(idx);
            int mn_l=outer[idx].fi;
            while(ii<n && bsort[ii].fi<=mx_b){
                mn_l=min(mn_l,outer[bsort[ii].se].fi);
                ii++;
            }
            ans.push_back({mn_l,mx_b});
        }
        sort(ans.begin(), ans.end());
        
        int q;
        cin>>q;
        for(int i=0; i<q; i++){
            int x;
            cin>>x;
            if(x<ans[0].fi) cout<<x<<' ';
            else{
                int l=0, r=(int)ans.size()-1;
                while(l<r){
                    int mid=(l+r+1)/2;
                    if(ans[mid].fi>x) r=mid-1;
                    else l=mid;
                }
                cout<<max(x,ans[l].se)<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}