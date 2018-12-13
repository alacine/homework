class Grammar:
    # 文法四元组
    def __init__(self, vt = [], vn = [], s = '', xi = {}):
        self.vt = vt # 终结符集合
        self.vn = vn # 非终结符集合
        self.s = s # 文法开始符
        self.xi = xi # 产生式非空有限集

    def __str__(self):
        print('---------Grammar----------')
        print('Vt: ', self.vt)
        print('Vn: ', self.vn)
        print('S: ', self.s)
        print('xi: ')
        for key in self.xi:
            print('\t', key, '->', self.xi[key])
        return '--------------------------'

    def read(self):
        self.vt = list(input('输入终结符集合(要求: 1.小写字母或数字或符号 2.不要有空格和|)\n'))
        self.vn = list(input('输入非终结符集合, 第一个默认作为文法开始符(要求: 1.大写字母 2.不能有空格)\n'))
        self.s = self.vn[0]
        print('输入产生式, 每行一个, 例如(S ET)表示S->ET')
        while True:
            in_xi = input().split()
            if not in_xi:
                break
            if in_xi[0] in self.xi:
                self.xi[in_xi[0]] += (' ' + in_xi[1])
            else:
                self.xi[in_xi[0]] = in_xi[1]
        for key in self.xi:
            self.xi[key] = self.xi[key].split()

    def demo(self, string):
        return True

def main():
    cal = Grammar('i', 'ETF', 'E', {'E':['E+T', 'T'], 'T':['T*F', 'F'], 'F':['(E)', 'i']})
    print(cal)
    cal.demo('i+i*i')
    #g.read()
    #print(g)

if __name__ == '__main__':
    main()
