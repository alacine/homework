#!/usr/bin/python3

# 解决 01 背包问题
import sys
from random import randint
from collections import namedtuple


def print_name(func):
    """打印调用的函数名"""
    def wrapper(*args):
        print('{}:'.format(func.__name__))
        return func(*args)
    return wrapper


class BackPack01:
    def __init__(self, capability, staffs=None):
        """初始化一个背包
        args:
            capability: 背包的承重
            staffs: 尝试装入的各个物品(二维列表)的重量和价值
        """
        staff = namedtuple('staff', 'w, v')
        self.staffs = [staff._make(i) for i in staffs]
        self.capability = capability
        self._inbag = [staff(v=1, w=2), staff(v=2, w=3)]
        self._weight = 0
        self._value = 0

    def __str__(self):
        """展示背包中装入的物品"""
        string = []
        for staff in self._inbag:
            string.append(str(staff)+'\n')
        return ''.join(string)

    @property
    def weight(self):
        """返回背包内物品的总重量"""
        for staff in self._inbag:
            self._weight += staff.w
        return self._weight

    @property
    def value(self):
        """返回背包内物品的总价值"""
        for staff in self._inbag:
            self._value += staff.v
        return self._value


@print_name
def test_backpack():
    """单元测试"""
    v = randint(1, 100)
    staffs = [[randint(2, 10), randint(2, 10)] for i in range(10)]
    test_bp = BackPack01(v, staffs)
    print(test_bp)
    print(test_bp.weight)
    print(test_bp.value)


def main():
    print('输入物品的个数背包体积, 用空格分开')
    line = sys.stdin.readline().split()
    n, v = list(map(int, line))
    staffs = []
    for i in range(n):
        line = sys.stdin.readline().split()
        vi, wi = list(map(int, line))
        staffs.append([vi, wi])
    print(staffs)
    test_backpack(n, v, staffs)


if __name__ == '__main__':
    main()
