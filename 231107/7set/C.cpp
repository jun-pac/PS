// 
//./C<test

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

int datas[500050];
pair<int, pair<int,int>> qs[500050]; // 조건이 아주 가혹하다.
vector<pair<int,int>> st; // {t,value}꼴로 t에서 시작하는 segment를 담음
vector<pair<int,int>> en; // {t,value}꼴로 t에서 끝나는 segment를 담음
int ans[500050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n;
        for(int i=0; i<n; i++) cin>>datas[i];
        int l,r,x;
        cin>>q;
        st.clear();
        en.clear();
        st.reserve(q);
        en.reserve(q);
        for(int i=0; i<q; i++){
            cin>>l>>r>>x;
            l--, r--;
            st.push_back({l,x});
            en.push_back({r,x});
            //qs[i]={x,{l,r}};
        }
        sort(st.begin(), st.end());
        sort(en.begin(), en.end());

        for(int i=0; i<n; i++){
            // 전에 끝난 것 빼주기
            // 여기서 시작하는 것 더해주기
            // 
        }
        
        // 한 자리에 대해서 O(n)보다 빠르게 후보를 찾을 수는 없음.
        // 다 같을 수도 있잖아?
        // a[0], ..., a[i-1]은 반드시 뭐가 돼야 한다~ 이런거는 될지도
        // 그럼 그 후보들을 어떻게 담을 수가 있나?
        // 음 priority queue를 쓸 수 있나
        // 이게 근데 다 scan하는 방식은 곤란함.
        // 뭔가 가능성이 있는것만 pq를 이용해서 남기고, 그 사이의 변화를 jump로 처리해야 할 것 같은데
        // 더해지는 값을 다 저장하는 건 안될거고
        // 변하는 구조 자체가 인접하면 비슷하다. 
        // 그게 다른 경우를 합쳐봐야 O(n)스케일
        // 사실 그럼 가로방향 sweeping하는 문제라 보는게 합당하네요


    }
    return 0;
}