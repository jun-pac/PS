// 
//./C<test.txt

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

int datas[100000];
pair<int,int> query[100000];
int ans[100000];
vector<pair<int,int>> edges[100000];
int cnt[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        //cout<<n<<' '<<q<<endl;
        int mx_idx;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            //cout<<datas[i]<<' ';
            if(datas[i]==n) mx_idx=i;
        }
        //cout<<endl;
        //cout<<"mx_idx "<<mx_idx<<endl;
        
        int mx_k=0,a,b;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<q; i++){
            cin>>a>>b; // as i, k
            mx_k=max(mx_k,b);
            query[i]={a-1,b};
            edges[min(n-1,b)].push_back({a-1,i});
        }

        fill(cnt,cnt+n,0);
        int cur_mx=datas[0];
        int cur_mx_idx=0;
        //cout<<"c "<<mx_k<<endl;
        for(int i=0; i<min(n-1,mx_k); i++){
            //cout<<"i "<<i<<endl;
            if(datas[i+1]>cur_mx){
                cur_mx=datas[i+1];
                cur_mx_idx=i+1;
                cnt[cur_mx_idx]++;
            }
            else{
                cnt[cur_mx_idx]++;
            }
            for(int j=0; j<edges[i+1].size(); j++){
                //cout<<"d "<<edges[i+1][j].se<<' '<<edges[i+1][j].fi<<endl;
                ans[edges[i+1][j].se]=cnt[edges[i+1][j].fi];
            }
        }
        
        for(int i=0; i<q; i++){
            if(query[i].fi==mx_idx && query[i].se>n-1){
                ans[i]+=query[i].se-(n-1);
            }
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}