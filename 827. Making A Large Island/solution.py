# Link : https://leetcode.com/problems/making-a-large-island/

from Queue import Queue

class Solution(object):
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        q = Queue()
        island_size = [0, 0]
        island_num = 2
        result = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 1:
                    continue
                size = 0
                q.put((i, j))
                while not q.empty():
                    xy = q.get()
                    x, y = xy[0], xy[1]
                    grid[x][y] = island_num
                    size += 1
                    if x > 0 and grid[x-1][y] == 1:
                        q.put((x-1, y))
                        grid[x-1][y] = island_num
                    if y > 0 and grid[x][y-1] == 1:
                        q.put((x, y-1))
                        grid[x][y-1] = island_num
                    if x < len(grid)-1 and grid[x+1][y] == 1:
                        q.put((x+1, y))
                        grid[x+1][y] = island_num
                    if y < len(grid)-1 and grid[x][y+1] == 1:
                        q.put((x, y+1))
                        grid[x][y+1] = island_num
                island_size.append(size)
                island_num += 1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] != 0:
                    continue
                touching = set()
                if i > 0:
                    touching.add(grid[i-1][j])
                if j > 0:
                    touching.add(grid[i][j-1])
                if i < len(grid)-1:
                    touching.add(grid[i+1][j])
                if j < len(grid)-1:
                    touching.add(grid[i][j+1])
                tot = 1
                for k in touching:
                    tot += island_size[k]
                result = max(result, tot)
        if result == 0:
            result = max(island_size)
        return result
