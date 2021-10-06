from .map import *
import numpy


class AStar:
    def __init__(self, map):
        self.map = map
        self.open_set = []
        self.close_set = []
        self.path = []

    # 总代价(这里代价计算用的是对角距离)
    def TotalCost(self, p):
        # 基本代价(距离起点的代价)
        dis_x = abs(p.x - self.map.start.x)
        dis_y = abs(p.y - self.map.start.y)
        base_cost = dis_x + dis_y + (numpy.sqrt(2) - 2) * min(dis_x, dis_y)
        # 启发函数(距离终点的预计代价)
        dis_x = abs(p.x - self.map.end.x)
        dis_y = abs(p.y - self.map.end.y)
        heuristic_cost = dis_x + dis_y + (numpy.sqrt(2) - 2) * min(dis_x, dis_y)
        return base_cost + heuristic_cost

    @staticmethod
    def isInPointList(p, plist):
        for pp in plist:
            if p.x == pp.x and p.y == pp.y:
                return True
        return False

    # 是否在open set
    def isInOpenSet(self, p):
        return self.isInPointList(p, self.open_set)

    # 是否在close set
    def isInCloseSet(self, p):
        return self.isInPointList(p, self.close_set)

    # 是否是路径
    def isInPath(self, p):
        return self.isInPointList(p, self.path)

    # 返回周围的点
    @staticmethod
    def findAroundPoint(p):
        return [
            Point(p.x-1, p.y+1), Point(p.x, p.y+1), Point(p.x+1, p.y+1),
            Point(p.x-1, p.y),                      Point(p.x+1, p.y),
            Point(p.x-1, p.y-1), Point(p.x, p.y-1), Point(p.x+1, p.y-1),
        ]

    # 遍历周围节点
    def processPoint(self, parent):
        for p in self.findAroundPoint(parent):
            if not self.map.isValidPoint(p):
                continue
            if self.isInCloseSet(p):
                continue
            # 未遍历过的点计算代价并加入到open set
            if not self.isInOpenSet(p):
                p.parent = parent
                p.cost = self.TotalCost(p)
                self.open_set.append(p)

    # 从open set选代价最小的点
    def selectPoint(self):
        if len(self.open_set) == 0:
            return None
        min_cost = sys.maxsize
        min_cost_p = self.open_set[0]
        for p in self.open_set:
            if p.cost < min_cost:
                min_cost = p.cost
                min_cost_p = p
        return min_cost_p

    # 建立路径
    def buildPath(self, p):
        path = [p]
        while True:
            if self.map.isStart(p):
                break
            path.append(p.parent)
            p = p.parent
        self.path = path

    def print(self):
        for i in range(self.map.size+2):
            print('-', end=' ')
        print()
        for y in range(self.map.size):
            print('|', end=' ')
            for x in range(self.map.size):
                p = Point(x, y)
                if self.map.isStart(p):
                    print('S', end=' ')
                elif self.map.isEnd(p):
                    print('E', end=' ')
                elif self.isInPath(p):
                    print('>', end=' ')
                elif not self.map.isValidPoint(p):
                    print('#', end=' ')  # 障碍
                # elif self.isInCloseSet(p):
                #     print('o', end=' ' )  # 遍历过的点
                else:
                    print(' ', end=' ')
            print('|', end='\n')
        for i in range(self.map.size + 2):
            print('-', end=' ')
        print()

    # 算法运行
    def aStar(self):
        self.map.start.cost = 0  # 设置起点代价最小
        self.open_set.append(self.map.start)  # 起点加入open set
        while True:
            p = self.selectPoint()  # 选代价最小的点
            if p is None:
                return  #
            if self.map.isEnd(p):  # 终点回溯
                self.buildPath(p)  # 生成路径
                return
            else:
                self.open_set.remove(p)  # 从待遍历集合删除
                self.close_set.append(p)  # 加入已遍历集合
                self.processPoint(p)  # 遍历周围的点
