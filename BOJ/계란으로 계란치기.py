def dfs(idx, cnt):
    global N, ans, info

    if idx == N:
        if cnt > ans:
            ans = cnt
        return

    temp_cnt = cnt
    used = False
    for i in range(N):
        if info[idx][0] <= 0:
            break
        elif i != idx and info[i][0] > 0:
            used = True

            info[i][0] -= info[idx][1]
            info[idx][0] -= info[i][1]

            if info[i][0] <= 0:
                cnt += 1
            if info[idx][0] <= 0:
                cnt += 1

            dfs(idx + 1, cnt)

            info[i][0] += info[idx][1]
            info[idx][0] += info[i][1]
            cnt = temp_cnt

    if not used:
        dfs(idx + 1, cnt)


ans = 0
N = int(input())
info = [list(map(int, input().split())) for i in range(N)]

dfs(0, 0)

print(ans)