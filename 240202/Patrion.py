N = 1010
MOD = 1000000007

datas = [0] * N
sum_arr = [0] * N
backval = [[0] * 19 for _ in range(N)]
DP = [[[0] * 19 for _ in range(19)] for _ in range(N)]
cnt = [[0] * 19 for _ in range(N)]

def solve():
    n = int(input())
    datas = list(map(int, input().split()))
    sum_arr[0] = datas[0]
    for i in range(1, n):
        sum_arr[i] = sum_arr[i - 1] + datas[i]
    
    if sum_arr[n - 1] % 2 == 1:
        print(0)
        return
    
    tar = sum_arr[n - 1] // 2
    
    for j in range(19):
        backval[n][j]=0
    for i in range(n - 1, -1, -1):
        for j in range(19):
            backval[i][j] = (0 if i == n - 1 else backval[i + 1][j]) + (datas[i] == j - 9)
    
    for i in range(n - 1, -1, -1):
        for j in range(19):
            for k in range(19):
                DP[i][j][k] = (0 if i == n - 1 else DP[i + 1][j][k]) + (backval[i + 1][k] if sum_arr[i] == tar + j - k else 0)
    
    res = 0
    
    # Case 1: Array divided outside idx of swapped elements
    for i in range(n - 1):
        if sum_arr[i] == tar:
            res += 1
            res += (i + 1) * i // 2 + (n - i - 1) * (n - i - 2) // 2
            for j in range(19):
                res -= cnt[i][j] * (cnt[i][j] - 1) // 2
                res -= (cnt[n - 1][j] - cnt[i][j]) * (cnt[n - 1][j] - cnt[i][j] - 1) // 2
    
    # Case 2: Array divided between swapped elements
    for i in range(n - 1):
        for val in range(-9, 10):
            if datas[i] == val:
                continue
            res += DP[i][datas[i] + 9][val + 9]
    
    print((res % MOD + MOD) % MOD)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()