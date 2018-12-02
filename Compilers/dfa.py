graph = {
    ('a', 'b'): 1,
    ('a', 'b'): 2,
    ('b', 'c'): 2,
    ('c', 'd'): 3,
}

class Dfa(object):
    # dfa 类
    def __init__(self, S, sigma, f, s0, Z):
        # 五元组
        self.S = S # 有限状态集, 用list存储,每个元素表示一个状态
        self.sigma = sigma # 有穷输入字母表, 用list存储
        self.f = f # 单值映射, 用key为tuple的dictionary存储
        self.s0 = s0 # 初态集, 用list存储
        self.Z = Z # 终态集, 用list存储

    def check(self):
        # 检查dfa的正确性: dfa的五元组是否正确
        for letter in self.sigma:
            if self.sigma.count(letter) > 1:
                return False

        if self.s0 not in self.S:
            return False

        if self.Z not in self.S:
            return False

        return True

    def get_string(self, n):
        # 输入任意一个整数n, dfa列表显示其识别的所有长度小于等于n的字符串
        pass

    def demo(self, string):
        # dfa的规则字符串板顶: 输入一个字符串, 模拟dfa识别字符串的过程
        # 并判定该字符串是否是规则字符串
        pass

def main():
    print(len(graph))
    S = [0, 1, 2, 3, 4]
    sigma = ['a', 'b', 'c']
    f = {
        (0, 'a'): 1,
        (0, 'b'): 2,
        (0, 'c'): 3,
    }
    s0 = [0]
    Z = [4]
    a = Dfa(S, sigma, f, s0, Z)
    print(a.S, a.sigma, a.f, a.s0, a.Z)
    print(a.check())

if __name__ == '__main__':
    main()
