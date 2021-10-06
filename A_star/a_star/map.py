import sys
import numpy as np


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.cost = sys.maxsize
        self.parent = None


class Map:
    def __init__(self, size=10):
        self.size = size  # 大小
        self.start = Point(0, 0)  # 起点
        self.end = Point(self.size-1, self.size-1)  # 终点
        self.obstacle_point = []  # 障碍
        self.setObstacle()  # 设置障碍

    def setStart(self, x, y):
        if x == -1 and y == -1:
            x = np.random.randint(0, self.size//2)
            y = np.random.randint(0, self.size)
        if not self.isValidPoint(Point(x, y)):
            return
        self.start.x = x
        self.start.y = y

    def setEnd(self, x, y):
        if x == -1 and y == -1:
            x = np.random.randint(self.size//2, self.size)
            y = np.random.randint(0, self.size)
        if not self.isValidPoint(Point(x, y)):
            return
        self.end.x = x
        self.end.y = y

    # 生成障碍
    def setObstacle(self):
        self.obstacle_point.append(Point(self.size//2, self.size//2))
        self.obstacle_point.append(Point(self.size//2, self.size//2-1))

        for i in range(self.size // 2 - 4, self.size // 2):
            self.obstacle_point.append(Point(i, self.size - i))
            self.obstacle_point.append(Point(i, self.size - i - 1))
            self.obstacle_point.append(Point(self.size - i, i))
            self.obstacle_point.append(Point(self.size - i, i - 1))

        for i in range(8):
            x = np.random.randint(0, self.size)
            y = np.random.randint(0, self.size)
            self.obstacle_point.append(Point(x, y))

            if np.random.rand() > 0.5:
                for i in range(self.size // 4):
                    self.obstacle_point.append(Point(x, y + i))
                    pass
            else:
                for i in range(self.size // 4):
                    self.obstacle_point.append(Point(x + i, y))
                    pass

    def isStart(self, p):
        return p.x == self.start.x and p.y == self.start.y

    def isEnd(self, p):
        return p.x == self.end.x and p.y == self.end.y

    def isObstacle(self, p):
        for pp in self.obstacle_point:
            if p.x == pp.x and p.y == pp.y:
                return True
        return False

    # 是否有效点
    def isValidPoint(self, p):
        if p.x < 0 or p.y < 0:
            return False
        if p.x >= self.size or p.y >= self.size:
            return False
        if self.isObstacle(p):
            return False
        return True
