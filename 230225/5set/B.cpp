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

#define N 1000000
#define INF 100000007

bool col_one[N];
int right_one[N];
int mdivs[N];
int ans[N];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int num=n*m;
        string s;
        cin>>s;
        fill(ans,ans+num,0);
        fill(col_one,col_one+m,false);
        fill(right_one,right_one+num,0);
        fill(mdivs,mdivs+num,0);

        // cols
        int cur_num=0;
        for(int i=0; i<num; i++){
            if(s[i]=='1' && (!col_one[i%m])){
                cur_num++;
                col_one[i%m]=true;
            }
            ans[i]=cur_num;
        }

        // rows
        for(int i=num-1; i>=0; i--){
            if(i==num-1) right_one[i]=(s[i]=='1'?0:INF);
            else right_one[i]=(s[i]=='1'?0:right_one[i+1]+1);
        }
        /*
        if(m>=n){
            // use right_one
            //cout<<"bigm ";
            for(int i=0; i<num; i++){
                int temp=0;
                if((i+1)%m!=0){
                    if(right_one[0]<m) temp++;
                }
                for(int j=(i+1)%m; j<i+1; j+=m){
                    if(right_one[j]<m) temp++;
                }
                ans[i]+=temp;
                //cout<<temp<<' ';
            }
            //cout<<endl;
        }
        */
    
        for(int div=0; div<m; div++){
            if(div==0){
                mdivs[div*n+0]=(right_one[0]<m?1:0);
                for(int i=1; i<n; i++){
                    mdivs[div*n+i]=mdivs[div*n+i-1]+(right_one[i*m]<m?1:0);
                }
            }
            else{
                mdivs[div*n+0]=(right_one[0]<div?1:0);
                for(int i=1; i<n; i++){
                    mdivs[div*n+i]=mdivs[div*n+i-1]+(right_one[(i-1)*m+div]<m?1:0);
                }
            }
        }

        for(int i=0; i<num; i++){
            int divs=(i+1)%m;
            ans[i]+=mdivs[divs*n+(divs==0?(i+1)/m-1:(i+1)/m)];
            //cout<<mdivs[divs*n+(divs==0?(i+1)/m-1:(i+1)/m)]<<' ';
        }
        //cout<<endl;
        for(int i=0; i<num; i++) cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}