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

char datas[1020][1020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int cnt=0; // one cnt
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>datas[i][j];
                if(datas[i][j]=='1') cnt++;
            }
        }
        
        if(n%2==0 && (k%2!=cnt%2)){
            cout<<"NO"<<endl;
            continue;
        }
        int diff_cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(datas[i][j]!=datas[n-1-i][n-1-j]) diff_cnt++;
            }
        }
        diff_cnt/=2;
        if(k>=diff_cnt) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}