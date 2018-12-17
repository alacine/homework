class Grammar:
    # 文法四元组
    def __init__(self, vt = [], vn = [], s = '', xi = {}):
        self.vt = vt # 终结符集合
        self.vn = vn # 非终结符集合
        self.s = s # 文法开始符
        self.xi = xi # 产生式非空有限集
        self.firstvt = {} # 所有非终结符的firstvt集合
        self.lastvt = {} # 所有非终结符的lastvt集合
        self.table = {} # 算符优先关系

    def __str__(self):
        print('---------Grammar----------')
        print('Vt: ', self.vt)
        print('Vn: ', self.vn)
        print('S: ', self.s)
        print('xi: ')
        for key in self.xi:
            print('\t', key, '->', self.xi[key])
        print('firstvt: ')
        for key in self.firstvt:
            print('\t', key, ':', self.firstvt[key])
        print('lastvt: ')
        for key in self.lastvt:
            print('\t', key, ':', self.lastvt[key])
        print('table: ')
        for key in self.table:
            print('\t', key, ':', self.table[key])
        return '--------------------------'

    def read(self):
        self.vt = list(input('输入终结符集合(要求: 1.小写字母 2.不要有空格和|)\n'))
        self.vn = list(input('输入非终结符集合, 第一个默认作为文法开始符(要求: 1.大写字母 2.不能有空格)\n'))
        self.s = self.vn[0]
        print('输入产生式, 每行一个, 例如(S ET E)表示S->ET|E (左部右部均不允许重复)')
        while True:
            in_xi = input()
            if not in_xi:
                break
            self.xi[in_xi[0]] = in_xi[1:]
        for key in self.xi:
            self.xi[key] = self.xi[key].split()

        for vi in self.vn:
            self.firstvt[vi] = []
        for vi in self.vn:
            self.lastvt[vi] = []
        vt = self.vt
        vt.append('#')
        for vi in vt:
            for vj in vt:
                self.table[(vi, vj)] = ' '

    def is_opg(self):
        # Operator Precedence Grammar
        # 判断是否为算符优先文法
        for key in self.xi:
            for exp in self.xi[key]:
                for i in range(len(exp)-1):
                    if exp[i].isupper() and exp[i+1].isupper():
                        return False
        return True

    def get_firstvt(self, vt):
        # 获取某个终结符的firstvt集
        if not self.firstvt[vt]:
            for rexp in self.xi[vt]:
                # rexp: 产生式右部的每一项
                # 若产生式P->a...或P->Qa..., 则a属于firstvt(P)
                if rexp[0] in self.vt:
                    self.firstvt[vt].append(rexp[0])
                else:
                    if len(rexp) > 1 and rexp[1] in self.vt:
                        self.firstvt[vt].append(rexp[1])
                    if rexp[0] != vt:
                        # 若a属于firstvt(Q), 且有P->Q..., 则a属于firstvt(P)
                        self.get_firstvt(rexp[0])
                        for vi in self.firstvt[rexp[0]]:
                            if vi not in self.firstvt[vt]:
                                self.firstvt[vt].append(vi)

    def get_lastvt(self, vt):
        # 获取某个终结符的firstvt集
        if not self.lastvt[vt]:
            for rexp in self.xi[vt]:
                # rexp: 产生式右部的每一项
                # 若产生式P->...a或P->...aQ, 则a属于lastvt(P)
                if rexp[-1] in self.vt:
                    self.lastvt[vt].append(rexp[-1])
                else:
                    if len(rexp) > 1 and rexp[-2] in self.vt:
                        self.lastvt[vt].append(rexp[-2])
                    if rexp[-1] != vt:
                        # 若a属于lastvt(Q), 且有P->...Q, 则a属于lastvt(P)
                        self.get_lastvt(rexp[-1])
                        for vi in self.lastvt[rexp[-1]]:
                            if vi not in self.lastvt[vt]:
                                self.lastvt[vt].append(vi)

    def make_table(self):
        # 构造算符优先表
        for vi in self.vn:
            self.get_firstvt(vi)
            self.get_lastvt(vi)

def main():
    # cal = Grammar('i', 'ETF', 'E', {'E':['E+T', 'T'], 'T':['T*F', 'F'], 'F':['(E)', 'i']})
    cal = Grammar()
    cal.read()
    if cal.is_opg():
        print('是算符优先文法')
        cal.make_table()
        print(cal)
    else:
        print('不是算符优先文法')
    # g = Grammar()
    # g.read()
    # print(g)

if __name__ == '__main__':
    main()
