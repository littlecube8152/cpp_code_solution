import math

raw = input().split()
k = int(raw[0])
n = int(raw[1])

def solve(b, c):
	d = b * b - 4 * c
	sd = math.isqrt(d)
	if sd * sd != d:
		return 0
	p = -b + sd
	if p % 2 != 0:
		return 0
	return p // 2

def find(a, b):
	return solve(-k * (a + b), a * a + b * b - k * a * b - 1)

sols = [[0, 1, k]]
vis = {0: True}
ans = []

i = 0
while i < len(sols):
	if len(ans) == n:
		break
	a, b, c = sols[i]
	if (a not in vis) and (b not in vis) and (c not in vis):
		ans.append([a, b, c])
		vis[a] = True
		vis[b] = True
		vis[c] = True
	if find(b, c) > a:
		sols.append([find(b, c), b, c])
	if find(a, c) > b:
		sols.append([find(a, c), a, c])
	if find(a, b) > c:
		sols.append([find(a, b), a, b])
	i = i + 1


for a, b, c in ans:
	print(a, b, c)
