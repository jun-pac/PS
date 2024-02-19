// 
//./SAM1<test

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

ll vals[100];
ll mods[100];
bool visited[100];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        ll res=0;
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>vals[i];
        for(int i=0; i<n-1; i++) mods[i]=vals[i+1]/vals[i];
        

        // n은 absolute maximum
        // 전부 2배씩 늘어난다면 => 모든 동전이 한개씩만 리턴되므로 결국 방정식 n개를 만들어야 함.
        // 가장 큰 동전은 언제나 꽁으로 알 수 있다.
        // 3배가 늘어나는 구간이 있으면 그놈은 2배 해서 한 번에 처리 가능

        if(n==1){
            res=1;
        }
        else{
            // 이제는 마지막 녀석은 신경 쓸 이유가 없다.
            // mods는 2,2,2,2,2,3,3,4,5,...이런 느낌이다.
            sort(mods,mods+n-1);
            cout<<"MODS : ";
            for(int i=0; i<n-1; i++) cout<<mods[i]<<' ';
            cout<<endl;

            fill(visited,visited+n,0);
            int left=n-1;
            while(left>0){
                int temp=0;
                for(int i=0; i<n-1; i++){
                    if(!visited[i] && mods[i]>temp+1){
                        visited[i]=true;
                        temp++;
                    }
                }
                left-=temp;
                cout<<"CNT_DEL : "<<temp<<endl;
                res++;
            }
        }
        cout<<'#'<<tt<<' '<<res<<endl;
    }
    return 0;
}