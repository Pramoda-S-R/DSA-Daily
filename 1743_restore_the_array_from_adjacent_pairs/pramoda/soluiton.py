from collections import defaultdict

class Solution:
    def restoreArray(self, adjacentPairs: list[list[int]]) -> list[int]:
        graph = defaultdict(list)
        for u, v in adjacentPairs:
            graph[u].append(v)
            graph[v].append(u)

        for node in graph:
            if len(graph[node]) == 1:
                start = node
                break

        ans = [start]
        prev = None
        curr = start
        n = len(adjacentPairs) + 1
        while len(ans) < n:
            neighbors = graph[curr]
            next = neighbors[0] if neighbors[0] != prev else neighbors[1]
            ans.append(next)
            prev = curr
            curr = next

        return ans



s = Solution()
print(s.restoreArray([[2,1],[3,4],[3,2]]))