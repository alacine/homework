def print_name(func):
    # 打印函数名
    def wrapper(*args):
        print(func.__name__, '\t', *args)
        return func(*args)
    return wrapper

class Rdp(object):
    # recursive descent parser 递归下降分析器
    def __init__(self, exp = '', f = {}):
        self.exp = exp
        self.f = f

    def __str__(self):
        return self.exp

    def read(self, exp = ''):
        if not exp:
            exp = input('请输入一个表达式, 包含+-*/(p)和小写字母, 每个字母都是一个终结符\n')
            if not exp:
                return False

        self.exp = exp
        exp += '#'

    def check(self):
        exp = self.exp + '#'

        # @print_name
        def plus_minus(p):
            # 判断是不是+或-
            (err, p) = multiply_divide(p)
            if exp[p] == '+' or exp[p] == '-':
                p += 1
                show(p)
                (err, p) = plus_minus(p)
            return (err, p)

        # @print_name
        def multiply_divide(p):
            # 判断是否为*或/
            (err, p) = brackets_letter(p)
            if exp[p] == '*' or exp[p] == '/':
                p += 1
                show(p)
                (err, p) = multiply_divide(p)
            return (err, p)

        # @print_name
        def brackets_letter(p):
            # 字母和括号的判断
            err = False
            if exp[p].isalpha():
                p += 1
                show(p)
                return (err, p)
            elif exp[p] == '(':
                p += 1
                show(p)
                p = plus_minus(p)[1]
                if exp[p] == ')':
                    p += 1
                    show(p)
                else:
                    err = True
            else:
                err = True

            return (err, p)

        # @print_name
        def show(p):
            blank = ''
            for i in range(p):
                blank += ' '
            if p < len(exp):
                print(blank, end = '')
                print(exp[p:])

        print('开始匹配')
        p = 0
        err = False
        show(p)
        while p < len(exp)-1 and not err:
            (err, p) = plus_minus(p) # 子程序判断表达式是否正确
        if err:
            return False
        else:
            return True

def main():
    a = Rdp()
    a.read()
    if a.check():
        print(a, '表达式正确')
    else:
        print('表达式错误')

if __name__ == '__main__':
    main()
