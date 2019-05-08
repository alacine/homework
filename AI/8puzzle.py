# pylint: disable-msg = missing-docstring, invalid-name
from copy import deepcopy
from typing import List


def cantor() -> list:
    """阶乘"""
    fac = [1 for i in range(10)]
    for i in range(1, 10):
        fac[i] = fac[i - 1] * i
    return fac


FAC = cantor()


def cantor_hash(lista: list) -> list:
    """对每个状态做哈希变换"""
    ans = 0
    for i in range(9):
        num = 0
        for j in range(i + 1, 9):
            if lista[j] < lista[i]:
                num += 1
        ans += num * FAC[9 - i - 1]
    return ans + 1


class Node:
    """每个状态节点的数据结构"""
    def __init__(self, layout=None):
        """
        layout: 二维数组, 8 个数码的位置
        loc: 0 的位置
        status: hash 值
        path: 路径
        """
        self.layout = layout
        self.loc = layout.index(0)
        self.status = cantor_hash(self.layout)
        self.path = []

    def __str__(self) -> str:
        return '{}\n{}\n{}'.format(
            self.layout[:3],
            self.layout[3:6],
            self.layout[6:9],
        )


def bfs(target: Node) -> list:
    """搜索出所有从终态可以到达的状态"""
    visit = [False for i in range(FAC[9] + 10)]
    path = [None for i in range(FAC[9] + 10)]
    mov = [[-1, 0], [1, 0], [0, -1], [0, 1]]  # u, d, l, r
    dirction = "durl"  # 由于是反着搜索这里的方向和mov刚好相反
    cur = deepcopy(target)
    queue = []
    queue.append(cur)
    path[target.status] = []

    while queue:
        cur = queue.pop(0)
        for i in range(4):
            tx = cur.loc // 3 + mov[i][0]
            ty = cur.loc % 3 + mov[i][1]
            if tx < 0 or tx > 2 or ty < 0 or ty > 2:
                continue
            nex = deepcopy(cur)
            # 移动
            nex.loc = tx * 3 + ty
            nex.layout[cur.loc] = nex.layout[nex.loc]
            nex.layout[nex.loc] = 0
            nex.status = cantor_hash(nex.layout)
            if not visit[nex.status]:
                visit[nex.status] = True
                nex.path.append(dirction[i])
                queue.append(nex)
                path[nex.status] = nex.path[::-1]
            del nex

    return path


def travel(node: Node, path: List[str]) -> None:
    """打印移动过程"""
    print(node)
    for direction in path:
        loc = node.loc
        print('-->')
        if direction == 'u':
            loc -= 3
        elif direction == 'd':
            loc += 3
        elif direction == 'l':
            loc -= 1
        elif direction == 'r':
            loc += 1
        else:
            pass
        node.layout[node.loc] = node.layout[loc]
        node.layout[loc] = 0
        node.loc = loc
        print(node)


def test():
    """测试用例"""
    # test_list = list(map(int, input('输入0-8共九个数码\n').split()))
    # start = [0, 1, 2, 3, 4, 5, 6, 7, 8]

    start = [2, 3, 4, 1, 5, 0, 7, 6, 8]
    target = [1, 2, 3, 4, 5, 6, 7, 8, 0]
    target_node = Node(target)
    start_node = Node(start)
    path = bfs(target_node)
    if path[start_node.status]:
        print('共需要 {} 步'.format(len(path[start_node.status])))
        print(''.join(path[start_node.status]))
        travel(start_node, path[start_node.status])
    else:
        print('unsolvable')


if __name__ == '__main__':
    test()
