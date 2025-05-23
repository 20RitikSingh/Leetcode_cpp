from typing import List

class Solution:
    def __init__(self):
        self.res = 0
        self.adj = []
        self.values = []
        self.k = 0
    @cache
    def dfs(self, curr: int, prev: int) -> int:
        total = 0
        for neighbor in self.adj[curr]:
            if neighbor == prev:
                continue
            x = self.dfs(neighbor, curr)
            if x % self.k == 0:
                self.res += 1
            else:
                total += x
        return total + self.values[curr]

    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], v: List[int], ki: int) -> int:
        self.adj = [[] for _ in range(n)]
        self.values = v
        self.k = ki

        for u, v in edges:
            self.adj[u].append(v)
            self.adj[v].append(u)

        ans = 0
        for i in range(n):
            self.res = 0
            x = self.dfs(i, i)
            if x % self.k == 0:
                self.res += 1
            ans = max(ans, self.res)
        return ans
