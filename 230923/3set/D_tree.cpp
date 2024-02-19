// 
//./D<test
// 원래 CPH문제일 것 같은데,
// 근데 DP를 한쪽에 몰아서 비트를 바꾸는 경우로 풀었다. 이건 좀 이상하다. 한쪽에 몰아서 존재할 필요는 없지 않나
// 아니면 이걸 두 개를 빼서, 뭔가 중간의 영역을 이분탐색으로 구한다거나,,?
// 어떤 a값에 대해서 어떤 비율로 가져갈지를 모르는 상태에서 어떻게 DP를 짬?


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

string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int ori0=0, ori1=0;
        int k0=0, k1=0;
        cin>>s;
        char last=s[0];
        int lidx=0;
        for(int i=0; i<n; i++){
            if(last!=s[i]){
                if(last=='0') ori0=max(ori0,i-lidx);
                else ori1=max(ori1,i-lidx);
                last=s[i];
                lidx=i;
            }
        }
        if(last=='0') ori0=max(ori0,n-lidx);
        else ori1=max(ori1,n-lidx);

        
    }
    return 0;
}