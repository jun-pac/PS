// 
//./C<test.txt

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

int datas[2][200000];
int down[2][200000];
int up[2][200000];
int do_mx[200000]; // 오른쪽 끝부터
int up_mx[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        int a;
        for(int i=0; i<m; i++){
            cin>>a;
            datas[0][i]=a+1;   
        }
        for(int i=0; i<m; i++) {
            cin>>a;
            datas[1][i]=a+1;
        }
        datas[0][0]=-1;
        down[0][0]=datas[0][0];
        for(int i=1; i<m; i++) down[0][i]=datas[0][i]-(m*2-i);
        for(int i=0; i<m; i++) down[1][i]=datas[1][i]-(i+1);
        for(int i=m-1; i>=0; i--){
            if(i==m-1) do_mx[i]=max(0,max(down[0][i],down[1][i]));
            else do_mx[i]=max(do_mx[i+1],max(down[0][i],down[1][i]));
        }
        for(int i=0; i<m; i++) up[0][i]=datas[0][i]-i;
        for(int i=0; i<m; i++) up[1][i]=datas[1][i]-(2*m-1-i);
        for(int i=m-1; i>=0; i--){
            if(i==m-1) up_mx[i]=max(0,max(up[0][i],up[1][i]));
            else up_mx[i]=max(up_mx[i+1],max(up[0][i],up[1][i]));
        }
        
        /*
        cout<<"down"<<endl;
        for(int i=0; i<m; i++) cout<<down[0][i]<<' ';
        cout<<endl;
        for(int i=0; i<m; i++) cout<<down[1][i]<<' ';
        cout<<endl;
        for(int i=0; i<m; i++) cout<<do_mx[i]<<' ';
        cout<<endl;
        cout<<"up"<<endl;
        for(int i=0; i<m; i++) cout<<up[0][i]<<' ';
        cout<<endl;
        for(int i=0; i<m; i++) cout<<up[1][i]<<' ';
        cout<<endl;
        for(int i=0; i<m; i++) cout<<up_mx[i]<<' ';
        cout<<endl;
        */

        ll res=100990000007;
        ll even_mx=0;
        ll odd_mx=0;
        for(int i=0; i<m; i++){
            ll cur_mx=0;
            //cout<<"debug "<<i<<endl;
            if(i%2==0){
                if(i!=0){
                    umax(even_mx,(ll)datas[0][i-2]-0-(2*i-4));
                    umax(even_mx,(ll)datas[1][i-2]-1-(2*i-4));
                    umax(even_mx,(ll)datas[1][i-1]-2-(2*i-4));
                    umax(even_mx,(ll)datas[0][i-1]-3-(2*i-4));
                    /*cout<<(ll)datas[0][i-2]-0-(2*i-4)<<' ';
                    cout<<(ll)datas[1][i-2]-1-(2*i-4)<<' ';
                    cout<<(ll)datas[1][i-1]-2-(2*i-4)<<' ';
                    cout<<(ll)datas[0][i-1]-3-(2*i-4)<<endl;*/
                }
                cur_mx=max(even_mx,(ll)up_mx[i]-i);
            }
            else{
                if(i==1){
                    umax(odd_mx,(ll)datas[0][i-1]-2-(2*i-4));
                    umax(odd_mx,(ll)datas[1][i-1]-3-(2*i-4));
                }
                if(i!=1){
                    umax(odd_mx,(ll)datas[1][i-2]-0-(2*i-4));
                    umax(odd_mx,(ll)datas[0][i-2]-1-(2*i-4));
                    umax(odd_mx,(ll)datas[0][i-1]-2-(2*i-4));
                    umax(odd_mx,(ll)datas[1][i-1]-3-(2*i-4));
                    /*cout<<(ll)datas[1][i-2]-0-(2*i-4)<<' ';
                    cout<<(ll)datas[0][i-2]-1-(2*i-4)<<' ';
                    cout<<(ll)datas[0][i-1]-2-(2*i-4)<<' ';
                    cout<<(ll)datas[1][i-1]-3-(2*i-4)<<endl;*/
                }
                cur_mx=max(odd_mx,(ll)do_mx[i]-(i-1));
            }
            //cout<<"cur_mx : "<<cur_mx<<endl;
            res=min(res,cur_mx);
        }
        cout<<res+2*m-1<<endl;
    }
    return 0;
}