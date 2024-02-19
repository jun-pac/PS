// 
//./A<test.txt

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

string datas[100][100];
vector<pair<int,int>> mid_k[100];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        for(int i=0; i<n; i++) mid_k[i].clear();
        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-1; j++){
                cin>>datas[i][j];
                for(int k=0; k<n; k++){
                    if(datas[i][j][k]==1) mid_k[k].push_back({i,i+j+1});
                }
            }
        }
        
    }

    return 0;
}