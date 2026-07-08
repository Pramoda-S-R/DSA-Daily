class Solution:
    def allPathsSourceTarget(self, graph: list[list[int]]) -> list[list[int]]:
        res: list[list[int]] = []

        target = len(graph) - 1
        
        def build(node_path: list[int]):
            last_node = node_path[-1]
            if last_node == target:
                res.append(node_path)
                return
            
            for node in graph[last_node]:
                build(node_path + [node])

        build([0])
        return res


s = Solution()
print(s.allPathsSourceTarget([[1,2], [3], [3], []]))