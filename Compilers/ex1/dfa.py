from sys import argv

def f_to_graph(f, S):
    # 传入dfa的映射f和状态集S
    # 返回dfa的映射转化成的图(dictionary), 用于后续bfs, 返回值为
    graph = {}
    for status in S:
        graph[status] = []
    for key in f:
        if not f[(key[0], key[1])]:
            continue
        graph[key[0]].append(f[(key[0], key[1])][0])
    return graph

def bfs(graph, s0):
    # 传入图和起始状态s0
    # bfs 返回搜索到的所有状态(list)
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
        # 用于输出dfa
        print('f:')
        for elem in self.f:
            if not self.f[elem]:
                continue
            print('\t', elem[0], '+', elem[1], '->', self.f[elem][0])
        return "S:\n\t{}\nsigma:\n\t{}\ns0:\n\t{}\nZ:\n\t{}\n".format(self.S, self.sigma, self.s0, self.Z)

    def print_to_dot(self, outputfile):
        # 把当前dfa输出到dot文件中, 用于dot生成图片
        fe = open(outputfile, 'w')
        fe.write('digraph dfa {\nrankdir = LR\n')
        fe.write('start -> ' + self.s0 + '\n')
        for elem in self.f:
            if not self.f[elem]:
                continue
            fe.write(elem[0] + ' -> ' + self.f[elem][0] + ' [label = \"' + elem[1] + '\"]\n')
        fe.write('start [shape = box]\n')
        for status in self.S:
            fe.write(status + ' [shape = circle]\n')
        for status in self.Z:
            fe.write(status + ' [shape = doublecircle]\n')
        fe.write('\n')
        fe.close()

    def read(self):
        # 读入dfa
        S_input = input('输入状态集(每个状态之间用空格隔开):\n')
        self.S = S_input.split()
        sigma_input = input('输入字母表(每个字符之间用空格隔开):\n')
        self.sigma = sigma_input.split()

        print('输入映射集(每个映射都是一个三元组, 三元组元素用空格隔开, 空行表示结束)')
        print('例如(s0 a s1)表示s0状态输入a进入状态s1')
        for status in self.S:
            # 初始化一个状态转化矩阵
            for letter in self.sigma:
                self.f[(status, letter)] = []
        while True:
            f_input = input()
            if not f_input:
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
        
        if self.s0 not in self.S:
            print('ERROR: 初始状态不在状态集内')
            return False

        if not self.Z:
            print('ERROR: 终态集不能为空')
            return False
        for status in self.Z:
            if status not in self.S or status == None:
                print('ERROR: 终态集不包含在状态集内')
                return False

        # 把映射转换为图
        f_graph = f_to_graph(self.f, self.S)
        # 通过bfs找到所有能够从初始状态出发到达的状态
        step = bfs(f_graph, self.s0)
        if len(step) < len(self.S):
            return False

        return True

    def get_string(self, cur_status, n, string = ''):
        # 输入任意一个整数n, dfa列表显示其识别的所有长度小于等于n的字符串
        # 三个参数分别是当前状态cur_status, 最大长度n, 字符串string(默认是空字符串)
        # 如果string不为空, 那么查找到的字符串是以传入的字符串开头的且符合要求的字符串(这条与本实验无关)
        if len(string) < n:
            if cur_status in self.Z:
                print(string)
        else:
            if cur_status in self.Z:
                print(string)
            return

        for letter in self.sigma:
            # 采用递归的方式查找, 当找到一个可以继续下去的状态就进入下一个状态
            # 找不到就回退一步, 类似与dfs
            if self.f[(cur_status, letter)]:
                string += letter
                self.get_string(self.f[(cur_status, letter)][0], n, string)
                string = string[:-1]

    def demo(self, string, outputfile):
        # dfa的规则字符串判定: 模拟dfa识别字符串的过程
        # string表示要匹配的字符串, display表示是否输出过程返回是否匹配成功
        # 匹配的过程会输出在屏幕上, 同时会保存在dot文件中
        cur_status = self.s0
        cnt = 1
        fe = open(outputfile, 'a')
        fe.write('start -> ' + self.s0 + ' [label = 0, fontcolor = red, color = "red"]\n')

        for letter in string:
            if not self.f[(cur_status, letter)]:
                fe.write('}\n')
                fe.close()
                return False
            print(cur_status, letter, end=' ')
            fe.write(cur_status + ' -> ' + self.f[(cur_status, letter)][0] +
                    ' [label = ' + str(cnt) + ', fontcolor = red, color = "red"]\n')

            cur_status = self.f[(cur_status, letter)][0]

            cnt += 1
            print(cur_status)

        if cur_status in self.Z:
            fe.write('}\n')
            fe.close()
            return True
        else:
            fe.write('}\n')
            fe.close()
            return False

def main():
    # 命令行获取一个额外的参数(要生成的dot文件名)
    script, outputfile = argv

    # 初始化一个Dfa类型的a, 并读入a的数据
    a = Dfa()
    a.read()
    print(a)

    # 检查a的正确性, 只有正确才能继续其他的操作
    if a.check():
        # 把a的信息输出到dot文件中
        a.print_to_dot(outputfile)
        # 匹配输入的字符串是否是规则字符串
        string = input('输入你想尝试匹配的字符串: \n')
        if a.demo(string, outputfile):
            print('匹配成功')
        else:
            print('匹配失败')
        # 输出a能识别的所有长度小于n的字符串
        n = int(input('输入最大长度: \n'))
        a.get_string(a.s0, n)

    else:
        print('ERROR: 输入的dfa不规范')

if __name__ == '__main__':
    main()
