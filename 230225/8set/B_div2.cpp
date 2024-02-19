// 
//./F<test

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

int datas[200000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        sort(datas,datas+n);
        // 음수인 애들만 모았다면? 모든 음수 가능
        // 0이 있다면? 0이하의 모든 수 가능
        // 양수 k가 있다면 k hop씩 뛰면서 찾아야 하는데, greedy하게 잡으면 되긴 함. 그럼 이제 n^2이니까 문제죠
        // 양수 k가 선택되었다는 것은 k뽑고 그 아래로는 바로 0 이하로 추락.
        // 그니까 0 이하인애들 전부 뽑는것보다 최대 1 증가시켜 줌
        int m_cnt=0;
        while(m_cnt<n && datas[m_cnt]<=0) m_cnt++;
        if(m_cnt==n) cout<<m_cnt<<endl;
        else if(m_cnt==0){
            cout<<1<<endl;
        }
        else{
            int mn_diff=1000000007;
            for(int i=0; i<m_cnt-1; i++) mn_diff=min(mn_diff,datas[i+1]-datas[i]);
            if(datas[m_cnt]<=mn_diff) cout<<m_cnt+1<<endl;
            else cout<<m_cnt<<endl;
        }
    }
    return 0;
}