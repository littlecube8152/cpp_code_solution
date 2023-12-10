T = int(input())
for _ in range(T):
	raw = input().split()
	n, k = int(raw[0]), int(raw[1])
	s = input()
	big = int(10 ** ((n + k) // (k + 1) + 4))
	rgs = []
	rgs.append([0])
	for t in range(k):
		mid = n * (t + 1) // (k + 1)
		rg = []
		for d in range(-3, 4):
			if 1 <= d + mid and d + mid < n:
				rg.append(d + mid)
		rgs.append(rg)
	rgs.append([n])

	lazy = {}
	dp = [[big for j in range(len(rgs[i]))] for i in range(k + 2)]

	
	dp[0][0] = 0;
	for i in range(1, k + 2):
		for b, l in enumerate(rgs[i - 1]):
			cost = int('0' + s[l:max(l, rgs[i][0] - 1)])
			for a, r in enumerate(rgs[i]):
				if l < r:
					cost = cost * 10 + int(s[r - 1]);
					dp[i][a] = min(dp[i][a], dp[i - 1][b] + cost);
					
	print(dp[k + 1][0])
