// 
//./B<test.txt

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


#define N 200000

using namespace std;

int datas[N]; // color
int mx_e_val[N], mx_o_val[N]; // 각 color별로
int DP[N]; 
int color_max[N]; // 각 color에서 DP값의 max

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        for(int i=0; i<n; i++) datas[i]--;
        fill(mx_e_val,mx_e_val+n,0);
        fill(mx_o_val,mx_o_val+n,0);
        fill(color_max,color_max+n,0);
        for(int i=0; i<n; i++){
            int cur=datas[i];
            if(i%2==0){
                mx_e_val[cur]=max(mx_e_val[cur], mx_o_val[cur]+1);
            }
            else{
                mx_o_val[cur]=max(mx_o_val[cur], mx_e_val[cur]+1);
            }
        }
        for(int i=0; i<n; i++) cout<<max(mx_e_val[i],mx_o_val[i])<<' ';
        cout<<endl;
    }
    return 0;
}