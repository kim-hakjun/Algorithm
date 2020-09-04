n = int(input())
m = [list(map(int, input().split())) for i in range(n)]

dp = [[[0 for d in range(3)] for c in range(n)] for r in range(n)]

dp[0][1][0] = 1
for r in range(0, n):
    for c in range(0, n):
        if m[r][c] == 0:
            # 가로
            if c > 0 and m[r][c - 1] == 0:
                dp[r][c][0] += (dp[r][c - 1][0] + dp[r][c - 1][2])
            # 세로
            if r > 0 and m[r - 1][c] == 0:
                dp[r][c][1] += (dp[r - 1][c][1] + dp[r - 1][c][2])
            # 대각
            if r > 0 and c > 0 and m[r][c - 1] == 0 and m[r - 1][c] == 0:
                dp[r][c][2] += (dp[r - 1][c - 1][0] + dp[r - 1][c - 1][1] + dp[r - 1][c - 1][2])

print(dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2])