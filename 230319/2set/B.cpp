// 
//./B<test

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

int datas[1000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int mx, mx_idx, nx, nx_idx;
        bool all_same=true;
        bool is_one=false;
        for(int i=0; i<n; i++){
            if(datas[i]==1) is_one=true;
            if(datas[i]!=datas[0]) all_same=false;
        }
        if(all_same){
            cout<<0<<endl;
            continue;
        }
        if(is_one){
            cout<<-1<<endl;
            continue;
        }
        
        vector<pair<int,int>> ans;
        while(!all_same){
            all_same=true;
            mx=0, nx=0;
            for(int i=0; i<n; i++){
                if(datas[i]>mx) mx=datas[i], mx_idx=i;
                if(datas[i]!=datas[0]) all_same=false;
            }
            //cout<<"d "<<all_same<<endl;
            if(all_same) break;
            for(int i=0; i<n; i++){
                if(datas[i]>nx && datas[i]<mx) nx=datas[i], nx_idx=i;
            }
            //cout<<"dsa "<<endl;
            ans.push_back({mx_idx,nx_idx});
            datas[mx_idx]=(datas[mx_idx]%datas[nx_idx]==0?datas[mx_idx]/datas[nx_idx]:datas[mx_idx]/datas[nx_idx]+1);
        }
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i].fi+1<<' '<<ans[i].se+1<<endl;
        }
    }
    return 0;
}