# 高斯列主元消去法
import copy

# 输出列主元消去过程(取消20行和31行的注释)
def show_process(c):
    for i in c:
        for j in i:
            print('%10g' % j, end = ' ')
        print()
    print()

def merge(a, b):
    c = copy.deepcopy(a)
    for i in range(0, len(b)):
        c[i].append(b[i])
    return c

# 高斯列主元消去算法
def guass(c):
    # show_process(c)

    # 列主元消去
    for i in range(0, len(c)-1):
        # 排序，按照主元绝对值排序
        c[i:] = sorted(c[i:], key = lambda x: abs(x[i]), reverse = True)
        # 消元
        for j in range(i+1, len(c)):
            m = - c[j][i] / c[i][i]
            for k in range(0, len(c[j])):
                c[j][k] += m * c[i][k]
        # show_process(c)

    # 回带求值
    x = [0 for i in range(0, len(c)-1)]
    for i in range(len(c)-1, -1, -1):
        if i == len(c) - 1:
            x.append(c[i][len(c[i])-1] / c[i][i])
        else:
            x[i] = c[i][len(c[i])-1]
            for j in range(len(x)-1, i, -1):
                x[i] -= c[i][j] * x[j]
            x[i] /= c[i][j-1]
    # 返回解列表
    return x

# 按要求格式化输出结果
def show_answer(c, x):
    print('A')
    for i in range(0, len(c)):
        for j in range(0, len(c[i])-1):
            print('%10.3g' % c[i][j], end = '')
        print()
    print('b')
    for i in range(0, len(c)):
        print('%10.3g' % c[i][len(c[i])-1], end = '')
    print('\nx')
    for i in range(0, len(x)):
        print('%10.3g' % x[i], end = '')
    print('\n')

def main():
    A = [[1, 2, 1], [2, 2, 3], [-1, -3, 0]]
    b = [0, 3, 2]
    c = merge(A, b)
    x = guass(c)
    show_answer(c, x)

    A1 = [[0, 2, 1], [1, 1, 0], [2, 3, 2]]
    b1 = [5, 3, 0]
    c1 = merge(A1, b1)
    x1 = guass(c1)
    show_answer(c1, x1)

    A2 = [[2, 1, 0, 0], [1, 3, 1, 0], [0, 1, 1, 1], [0, 0, 2, 1]]
    b2 = [1, 2, 2, 0]
    c2 = merge(A2, b2)
    x2 = guass(c2)
    show_answer(c2, x2)

if __name__ == '__main__':
    main()