from a_star.map import *
from a_star.a_star import AStar


def main():
    m = Map(30)  # 设置地图大小
    # 参数为-1时是随机起终点
    m.setStart(-1, -1)  # 起点
    m.setEnd(-1, -1)  # 终点
    a = AStar(m)
    a.aStar()
    a.print()


if __name__ == '__main__':
    main()
    input()
