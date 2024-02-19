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

vector<int> datas[50000];
int last_visit[50050];
int lens[50000];
int ans[50000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        int mx_part=0;
        for(int i=0; i<n; i++){
            cin>>lens[i];
            datas[i].clear();
            datas[i].reserve(lens[i]);
            for(int j=0; j<lens[i]; j++){
                cin>>a;
                a--;
                datas[i].push_back(a);
                last_visit[a]=i;
            }
        }
        bool flag=true;
        fill(ans,ans+n,-1);
        for(int i=0; i<n; i++){
            for(int j=0; j<lens[i]; j++){
                int cur=datas[i][j];
                if(last_visit[cur]==i){
                    ans[i]=cur+1;
                    break;
                }
            }
            if(ans[i]==-1){
                flag=false;
                break;
            }
        }
        if(flag) for(int i=0; i<n; i++) cout<<ans[i]<<' ';
        else cout<<-1;
        cout<<endl; 
    }
    return 0;
}