// 
//./E<test

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

int datas[5050];
//int mex[5050][5050]; // [i,j]에서의 mex값
bool DP[5050][5050];
int cnt[5050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n+2; i++) DP[0][i]=false;
        DP[0][0]=DP[0][(datas[0]==0?1:0)]=true;
        //for(int i=0; i<n-1; i++) cout<<DP[0][i]<<' '; cout<<endl;
        for(int i=1; i<n; i++){
            for(int j=0; j<n+2; j++) DP[i][j]=DP[i-1][j];
            fill(cnt,cnt+n+1,0);
            int cur_mex=0;
            for(int j=i; j>=0; j--){
                // original 할 경우에만 stop을 한다.
                cnt[datas[j]]++;
                while(cur_mex<n+1 && cnt[cur_mex]!=0) cur_mex++;
                if(cnt[datas[i]]>1) break;
                if(cnt[datas[j]]==1 && cur_mex>datas[i] && cur_mex>datas[j]){
                    if(j==0) DP[i][cur_mex]=true;
                    else for(int k=0; k<n+2; k++) if(DP[j-1][k]) DP[i][cur_mex^k]=true;
                }
            }
            //for(int j=0; j<n+1; j++) cout<<DP[i][j]<<' '; cout<<endl;
        }
        int mx=0;
        for(int i=0; i<n+2; i++) if(DP[n-1][i]) mx=i;
        cout<<mx<<endl;
    }
    return 0;
}