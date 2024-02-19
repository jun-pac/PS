// 
//./C<test

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

int cnt[200200];
vector<int> bs[200200];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) bs[i].clear();
        for(int i=0; i<n; i++){
            int k;
            cin>>k;
            int x;
            bs[i].reserve(k);
            for(int j=0; j<k; j++){
                cin>>x;
                bs[i].push_back(x);
                cnt[x]=0;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<bs[i].size(); j++){
                cnt[bs[i][j]]++;
            }
        }
        bool flag=false;
        for(int i=0; i<n; i++){
            bool temp=true;
            for(int j=0; j<bs[i].size(); j++){
                if(cnt[bs[i][j]]<=1){
                    temp=false;
                    break;
                }
            }
            if(temp){
                flag=true;
                break;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}