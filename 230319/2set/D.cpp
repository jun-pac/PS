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

const ll INF=1000000000000000;
ll DP[5999]; // 
ll cold[5999], hot[5999]; // hot<cold
int datas[5999];
ll straight;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        ll ans;
        
        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>datas[i];
            datas[i]--;
        }
        for(int i=0; i<m; i++) cin>>cold[i];
        for(int i=0; i<m; i++) cin>>hot[i];
        straight=cold[datas[0]];
        fill(DP,DP+m,INF);
        ll last_prog=datas[0];

        for(int i=1; i<n; i++){
            // last_prog와 datas[i]가 같은 경우
            //cout<<i<<" th"<<endl;
            if(datas[i]==last_prog){
                for(int j=0; j<m; j++){
                    if(j!=last_prog) DP[j]=DP[j]+hot[last_prog];
                }
                straight+=hot[datas[i]];
                continue;
            }
            

            // 반대쪽에 올리는 경우
            DP[last_prog]=min(DP[last_prog],straight+cold[datas[i]]);
            for(int j=0; j<m; j++){
                if(j!=last_prog && j!=datas[i]){
                    //cout<<"ds "<<j<<' '<<DP[j]<<' '<<cold[datas[i]]<<endl;
                    DP[last_prog]=min(DP[last_prog],DP[j]+cold[datas[i]]);
                }
                if(j==datas[i]) DP[last_prog]=min(DP[last_prog],DP[j]+hot[datas[i]]);
            }
            
            // 같은 쪽에 올리는 경우
            for(int j=0; j<m; j++){
                if(j!=datas[i] && j!=last_prog) DP[j]=DP[j]+cold[datas[i]];
            }

            DP[datas[i]]=INF;
            last_prog=datas[i];
            straight+=cold[datas[i]];
            
            ans=INF;
            for(int j=0; j<m; j++) ans=min(ans,DP[j]);
            
            //cout<<min(straight,ans)<<endl;
            //cout<<"DP : ";
            //for(int j=0; j<m; j++) cout<<(DP[j]>=INF?100:DP[j])<<' ';
            //cout<<endl;
        }
        ans=INF;
        for(int i=0; i<m; i++) ans=min(ans,DP[i]);
        cout<<min(straight,ans)<<endl;
    }
    return 0;
}