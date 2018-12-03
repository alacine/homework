def change_to_graph(f, S):
    graph = {}
    for elem in S:
        graph[elem] = []
    for elem in f:
        graph[elem[0]].append(f[(elem[0], elem[1])])
    return graph

def bfs(graph, s):
    pass

class Dfa(object):
    # dfa 类
    def __init__(self, S = [], sigma = [], f = {}, s0 = '', Z = []):
        # 五元组
        self.S = S # 有限状态集, 用list存储,每个元素表示一个状态
        self.sigma = sigma # 有穷输入字母表, 用list存储
        self.f = f # 单值映射, 用key为tuple的dictionary存储
        self.s0 = s0 # 初态集, 用单值存储
        self.Z = Z # 终态集, 用list存储

    def show(self):
        print('S:\n', self.S)
        print('sigma:\n', self.sigma)
        print('f:\n', self.f)
        print('s0:\n', self.s0)
        print('Z:\n', self.Z)

    def read(self):
        # 读入dfa
        S_input = input('输入状态集(每个状态之间用空格隔开):\n')
        self.S = S_input.split()
        sigma_input = input('输入字母表(每个字符之间用空格隔开):\n')
        self.sigma = sigma_input.split()

        print('输入映射集(每个映射都是一个三元组, 三元组元素用空格隔开)')
        print('例如(s0 a s1)表示s0状态输入a进入状态s1')
        for i in self.S:
            # 初始化一个状态转化矩阵
            for j in self.sigma:
                self.f[(i, j)] = []
        while True:
            f_input = input()
            if f_input == '':
                break
            f_tmp = f_input.split()
            if f_tmp[0] not in self.S or f_tmp[1] not in self.sigma or f_tmp[2] not in self.S:
                print('ERROR: 输入的状态不在有限状态集中或字母不在字母表中, 请检查输入')
            else:
                self.f[(f_tmp[0], f_tmp[1])].append(f_tmp[2])

        self.s0 = input('输入初始状态:\n')
        Z_input = input('输入终态集(每个状态之间用空格隔开):\n')
        self.Z = Z_input.split()

    def check(self):
        # 检查dfa的正确性: dfa的五元组是否正确
        for letter in self.sigma:
            if self.sigma.count(letter) > 1:
                print('ERROR: 字母表不能有重复的元素')
                return False

        for key in self.f:
            if len(self.f[key]) > 1:
                print('ERROR: 映射不全是单值映射')
                return False
        
        #if len(self.s0) > 1 or len(self.s0) == 0:
        #    print('ERROR: 初始状态有且仅有一个')
        #    return False
        if self.s0 not in self.S:
            print('ERROR: 初始状态不在状态集内')
            return False

        if len(self.Z) == 0:
            print('ERROR: 终态集不能为空')
            return False
        for status in self.Z:
            if status not in self.S or status == None:
                print('ERROR: 终态集不包含在状态集内')
                return False

        f_graph = change_to_graph(self.f, self.S)
        print(f_graph)
        #if not bfs(f_graph, self.s0[0]):
        #    return False

        return True

    def get_string(self, n):
        # 输入任意一个整数n, dfa列表显示其识别的所有长度小于等于n的字符串
        pass

    def demo(self, string):
        # dfa的规则字符串板顶: 输入一个字符串, 模拟dfa识别字符串的过程
        # 并判定该字符串是否是规则字符串
        pass

def main():
    a = Dfa()
    a.read()
    a.show()
    print(a.check())

if __name__ == '__main__':
    main()
