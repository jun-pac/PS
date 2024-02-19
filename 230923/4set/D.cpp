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

string datas[3003];
int sum[3003][3003]; // 위 방향으로 바뀐 수의 sum을 구한 것이다. 
int check[3003][3003]; // 이건 그냥 바뀌면 1.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        //fill(sum[0],sum[0]+n,0);
        for(int i=0; i<n; i++) cin>>datas[i];
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp=0;
                if(i>0 && j>0) temp+=sum[i-1][j-1];
                if(i>0 && j<n-1) temp+=sum[i-1][j+1];
                if(i>1 && j>0 && j<n-1) temp-=sum[i-2][j];
                if(i>0) temp+=check[i-1][j];
                if((temp%2==0 && datas[i][j]=='1') ||(temp%2==1 && datas[i][j]=='0')){
                    check[i][j]=1;
                    temp++;
                    cnt++;
                }
                else check[i][j]=0;
                sum[i][j]=temp;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}