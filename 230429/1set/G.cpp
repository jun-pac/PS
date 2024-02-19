// 
//./G<test

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

ll cc[200030];
bool visited[200020];
bool temp[200020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>cc[i];
        sort(cc,cc+n);
        //cout<<cc[n-1]<<endl;
        fill(visited,visited+cc[n-1]+1,0);
        // ������ ���� �ͺ��� ���� �� �־�� �Ѵ�.
        // ��� cc[i] (i!=0)�� ���ؼ�, ���� ���ҵ��� ������ select�ؼ� ���Ҹ� ���� �� �ִ��� �����غ���...
        // ���� �� �ִ� ������ check�س��� �����?
        // �ٵ� �̰� O(n^2)�� ���ɼ��� �ִ�.
        if(n==1){
            cout<<(cc[0]==1?"YES":"NO")<<endl;
        }
        else{
            visited[1]=1;
            bool flag=true;
            
            for(int i=1; i<n; i++){
                //cout<<"CD "<<i<<' '<<cc[i]<<' '<<visited[i]<<endl;
                if(!visited[cc[i]]){
                    flag=false;
                    break;
                }
                for(int i=0; i<=cc[n-1]; i++) temp[i]=visited[i];
                for(int j=cc[i]+1; j<=cc[n-1]; j++){
                    //cout<<j-cc[i]<<' '<<visited[j-cc[i]]<<endl;
                    if(visited[j-cc[i]]) temp[j]=1;
                }
                for(int i=0; i<=cc[n-1]; i++) visited[i]=temp[i];
            }
            cout<<(flag?"YES":"NO")<<endl;
        }
    }
    return 0;
}