// 
//./E<test.txt

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

bool datas[100][100];

// i,j n-1-j,i j,n-1-j n-1-i,n-1-j

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        for(int i=0; i<n; i++){
            cin>>s;
            for(int j=0; j<n; j++) datas[i][j]=(s[j]=='1'?true:false);
        }
        int cnt=0;
        for(int i=0; i<n; i++) for(int j=0; j<n; j++){
            int t_cnt=datas[i][j]+datas[n-1-j][i]+datas[j][n-1-i]+datas[n-1-i][n-1-j];
            cnt+=min(t_cnt,4-t_cnt);
        }        
        cout<<cnt/4<<endl;
    }
    return 0;
}