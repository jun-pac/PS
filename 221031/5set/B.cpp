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


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll sum_a=0, na=0; //evem
        ll sum_b=0, nb=0;
        bool a_even=true, b_even=false;
        int n,q;
        cin>>n>>q;
        int u,x;
        for(int i=0; i<n; i++){
            cin>>x;
            if(x%2==0) sum_a+=x, na++;
            else sum_b+=x, nb++;
        }
        for(int i=0; i<q; i++){
            cin>>u>>x;
            if(u==0){
                if(a_even){
                    sum_a+=na*x;
                    if(x%2==1) a_even=!a_even;
                }
                if(b_even){
                    sum_b+=nb*x;
                    if(x%2==1) b_even=!b_even;
                }
            }
            else{
                if(!a_even){
                    sum_a+=na*x;
                    if(x%2==1) a_even=!a_even;
                }
                if(!b_even){
                    sum_b+=nb*x;
                    if(x%2==1) b_even=!b_even;
                }
            }
            cout<<sum_a+sum_b<<endl;
        }
    }
    return 0;
}