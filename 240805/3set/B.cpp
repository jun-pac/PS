#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    int ans = 1000000;
    for (int i = 0; i < n - 1; i++) {
        for(int j=i+1; j<n; j++){
            if (A[i] * A[j] >= 0) {
                ans = min(ans, A[i] * A[j]);
            }
        }
    }
    return ans;
}


/*
#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
    int n = A.size();
    int ans = 1000000;
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 1; i++) {
        if (A[i] * A[i + 1] >= 0) {
            ans = min(ans, A[i] * A[i + 1]);
        }
    }
    return ans;
}
*/