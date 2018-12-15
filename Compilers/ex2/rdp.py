def print_name(func):
    def wrapper(*args):
        print(func.__name__)
        print('\t', *args)
        return func(*args)
    return wrapper

class Rdp(object):
    # recursive descent parser 递归下降分析器
    def __init__(self, exp = '', f = {}):
        self.exp = exp
        self.f = f

    def __str__(self):
        return self.exp

    def readexp_and_check(self, exp = ''):
        if not exp:
            self.exp = input('请输入一个表达式, 包含+-*/(p)和小写字母, 每个字母都是一个终结符\n')
            if not self.exp:
                return False
        else:
            self.exp = exp

        @print_name
        def plus_minus(p):
            # 判断是不是+或-
            flag = False
            (err, p) = multiply_divide(p)
            if exp[p] == '+' or exp[p] == '-':
                flag = True
            if flag:
                p += 1
                show(p)
                (err, p) = plus_minus(p)
            return (err, p)

        @print_name
        def multiply_divide(p):
            # 判断是否为*或/
            flag = False
            (err, p) = brackets_letter(p)
            if exp[p] == '*' or exp[p] == '/':
                flag = True
            if flag:
                p += 1
                show(p)
                p = multiply_divide(p)[1]
            return (err, p)

        @print_name
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

        @print_name
        def show(p):
            blank = ''
            for i in range(p):
                blank += ' '
            if p < len(exp):
                print(blank, end = '')
                print(exp[p:])

        p = 0
        err = False
        for letter in exp:
            if err:
                break
            (err, p) = plus_minus(p) # 子程序判断表达式是否正确
        if err:
            return False
        else:
            return True

    def readf_and_check(self, f = ''):
        pass

def main():
    a = Rdp()
    if a.readexp_and_check('a+b-(c-d)/a*b'):
        print(a, '表达式正确')
    else:
        print('表达式错误')

if __name__ == '__main__':
    main()
