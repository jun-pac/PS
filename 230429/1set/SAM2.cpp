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
        

        // n�� absolute maximum
        // ���� 2�辿 �þ�ٸ� => ��� ������ �Ѱ����� ���ϵǹǷ� �ᱹ ������ n���� ������ ��.
        // ���� ū ������ ������ ������ �� �� �ִ�.
        // 3�谡 �þ�� ������ ������ �׳��� 2�� �ؼ� �� ���� ó�� ����

        if(n==1){
            res=1;
        }
        else{
            // ������ ������ �༮�� �Ű� �� ������ ����.
            // mods�� 2,2,2,2,2,3,3,4,5,...�̷� �����̴�.
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