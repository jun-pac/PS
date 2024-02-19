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

string datas[505];
char res[505][505];
int rows[505], cols[505];
int lcnt[505];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) cin>>datas[i];
        bool flag=true;
        for(int i=0; i<n; i++){
            int temp=0;
            for(int j=0; j<m; j++) if(datas[i][j]!='.') temp++;
            rows[i]=temp;
            if(temp%2!=0) flag=false;
        }
        for(int i=0; i<m; i++){
            int temp=0;
            for(int j=0; j<n; j++) if(datas[j][i]!='.') temp++;
            cols[i]=temp;
            if(temp%2!=0) flag=false;
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }

        int under_cnt;
        fill(lcnt,lcnt+m,0);
        for(int i=0; i<n; i++) fill(res[i],res[i]+m,'.');
        for(int i=0; i<n; i++){
            under_cnt=0;
            for(int j=0; j<m; j++){
                if(datas[i][j]=='L'){
                    lcnt[j]++;
                    if(lcnt[j]%2==0){
                        res[i][j]='B';
                        res[i][j+1]='W';
                    }
                    else{
                        res[i][j]='W';
                        res[i][j+1]='B';
                    }
                    j++;
                }
                else if(datas[i][j]=='U'){
                    under_cnt++;
                    if(under_cnt%2==0) res[i][j]='W', res[i+1][j]='B';
                    else res[i][j]='B', res[i+1][j]='W';
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cout<<res[i][j];
            cout<<endl;
        }
    }
    return 0;
}