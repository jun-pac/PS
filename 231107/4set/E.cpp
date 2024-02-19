// 
//./E<test

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

#define INF 20000100
pair<ll,ll> a[200020];
ll b[22];
int mv[22][200020]; // [j][i]는 i에서 시작해서 j를 먹기 위한 최소의 지점
int DP[1<<20]; // 어디서 처음 만족하는지
pair<int,int> pred[1<<20];
vector<int> ans[1<<20];
pair<int,int> mark[22];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m; // n:프로그래머, m:project
    for(int i=0; i<n; i++) cin>>a[i].fi;
    for(int j=0; j<m; j++) cin>>b[j];
    for(int i=0; i<n; i++) a[i].se=i;
    if(n<m){
        cout<<"NO"<<endl;
        return 0;
    }
    sort(a,a+n);
    reverse(a,a+n);

    // mv채우기
    for(int j=0; j<m; j++){
        // 아마 two pointer로 조져야 하지 않을까
        //cout<<"J : "<<j<<' '<<b[j]<<endl;
        ll last=-1;
        ll cur=0;
        for(ll i=0; i<n; i++){
            while(last<=i && (i-last)*a[i].fi>=b[j]){
                last++;
            }
            if(last!=-1) last--;
            //cout<<"last : "<<last<<endl;
            if((i-last)*a[i].fi>=b[j]){
                while(cur<=last+1){
                    mv[j][cur++]=i;
                }
            }
        }
        while(cur<n) mv[j][cur++]=-1;
        //for(int i=0; i<n; i++) cout<<mv[j][i]<<' ';
        //cout<<endl;
    }

    // DP채우기
    fill(DP,DP+(1<<m),INF); // 최소의 idx임
    //fill(pred,pred+(1<<m)); // 최소의 idx임
    DP[0]=-1;
    for(int i=0; i<(1<<m)-1; i++){
        for(int j=0; j<m; j++){
            if(DP[i]<INF && !(i&(1<<j))){
                if(DP[i]!=n-1 && mv[j][DP[i]+1]!=-1){
                    if(DP[i|(1<<j)]>mv[j][DP[i]+1]){
                        DP[i|(1<<j)]=mv[j][DP[i]+1];
                        pred[i|(1<<j)]={i,j};
                    }
                }
            }
        }
    }
    //cout<<DP[(1<<m)-1]<<endl;
    if(DP[(1<<m)-1]>=INF) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        int cur=(1<<m)-1;
        while(DP[cur]!=-1){
            mark[pred[cur].se]={DP[cur],pred[cur].se};
            cur=pred[cur].fi;
        }
        sort(mark,mark+m);
        cur=0;
        for(int i=0; i<m; i++){
            while(cur<=mark[i].fi){
                ans[mark[i].se].push_back(a[cur++].se);
            }
        }
        for(int i=0; i<m; i++){
            cout<<ans[i].size()<<' ';
            for(auto ele:ans[i]) cout<<ele+1<<' ';
            cout<<endl;
        }
    } 
    return 0;
}