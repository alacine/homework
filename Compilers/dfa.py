from sys import argv

def f_to_graph(f, S):
    graph = {}
    for elem in S:
        graph[elem] = []
    for elem in f:
        if not f[(elem[0], elem[1])]:
            continue
        graph[elem[0]].append(f[(elem[0], elem[1])][0])
    return graph

def bfs(graph, s0):
    queue = []
    seen = set()
    queue.append(s0)
    seen.add(s0)
    parent = {s0: None}
    while len(queue) > 0:
        vertex = queue.pop(0)
        nodes = graph[vertex]
        for i in nodes:
            if i not in seen:
                queue.append(i)
                seen.add(i)
                parent[i] = vertex
        #print(vertex)
    #print('parent', parent, len(parent))
    return parent

class Dfa(object):
    # dfa 类
    def __init__(self, S = [], sigma = [], f = {}, s0 = '', Z = []):
        # 五元组
        self.S = S # 有限状态集, 用list存储,每个元素表示一个状态
        self.sigma = sigma # 有穷输入字母表, 用list存储
        self.f = f # 单值映射, 用key为tuple的dictionary存储
        self.s0 = s0 # 初态集, 用单值存储
        self.Z = Z # 终态集, 用list存储

    def __str__(self):
        print('f:')
        for elem in self.f:
            if not self.f[elem]:
                continue
            print('\t', elem[0], '+', elem[1], '->', self.f[elem][0])
        return "S:\n\t{}\nsigma:\n\t{}\ns0:\n\t{}\nZ:\n\t{}\n".format(self.S, self.sigma, self.s0, self.Z)

    def print_to_dot(self, outputfile):
        # 把当前dfa输出当dot文件中, 用于dot生成图片
        fe = open(outputfile, 'w')
        fe.write('digraph dfa {\nrankdir = LR\n')
        fe.write('start -> ' + self.s0 + '\n')
        for elem in self.f:
            if not self.f[elem]:
                continue
            fe.write(elem[0] + ' -> ' + self.f[elem][0] + ' [label = \"' + elem[1] + '\"]\n')
        fe.write('start [shape = box]\n')
        for i in self.S:
            fe.write(i + ' [shape = circle]\n')
        for i in self.Z:
            fe.write(i + ' [shape = doublecircle]\n')
        fe.write('}\n')
        fe.close()

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

        self.s0 = input('输入初始状态(有且只有一个):\n')
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

        f_graph = f_to_graph(self.f, self.S)
        step = bfs(f_graph, self.s0)
        if len(step) < len(self.S):
            return False
        #if not bfs(f_graph, self.s0[0]):
        #    return False

        return True

    def get_string(self, n):
        # 输入任意一个整数n, dfa列表显示其识别的所有长度小于等于n的字符串
        pass

    def demo(self, string):
        cur_status = self.s0
        for letter in string:
            if not self.f[(cur_status, letter)]:
                print('匹配失败')
                return False
            print(cur_status, letter, end=' ')
            cur_status = self.f[(cur_status, letter)][0]
            print(cur_status)
        if cur_status in self.Z:
            print('匹配成功')
            return True
        else:
            print('匹配失败')
            return False
        # dfa的规则字符串板顶: 输入一个字符串, 模拟dfa识别字符串的过程
        # 并判定该字符串是否是规则字符串

def main():
    script, outputfile = argv
    a = Dfa()
    a.read()
    if a.check():
        print(a)
        a.demo('babababababaab')
        a.print_to_dot(outputfile)
    else:
        print('ERROR: 输入的dfa不规范')

if __name__ == '__main__':
    main()
