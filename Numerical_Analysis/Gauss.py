# 高斯列主元消去法
import copy

# 输出列主元消去过程(取消17行和28行的注释)
def show_c(c):
    for i in c:
        for j in i:
            print("\t%g" % j, end = " ")
        print()
    print()

# 高斯列主元消去算法
def Guass(a, b, x):
    c = copy.deepcopy(a)
    for i in range(0, len(b)):
        c[i].append(b[i])
    # show_c(c)

    # 列主元消去
    for i in range(0, len(c)-1):
        # 排序，按照主元绝对值排序
        c[i:] = sorted(c[i:], key = lambda x: abs(x[i]), reverse = True)
        # 消元
        for j in range(i+1, len(c)):
            m = - c[j][i] / c[i][i]
            for k in range(0, len(c[j])):
                c[j][k] += m * c[i][k]
        # show_c(c)

    # 回带求值
    for i in range(0, len(c)-1):
        x.append(0)
    for i in range(len(c)-1, -1, -1):
        if i == len(c) - 1:
            x.append(c[i][len(c[i])-1] / c[i][i])
        else:
            x[i] = c[i][len(c[i])-1]
            for j in range(len(x)-1, i, -1):
                x[i] -= c[i][j] * x[j]
            x[i] /= c[i][j-1]
    # 返回答案列表
    return c

# 按要求格式化输出结果
def show_answer(c, x):
    print("A")
    for i in range(0, len(c)):
        for j in range(0, len(c[i])-1):
            print("\t%0.2lf" % c[i][j], end = "")
        print()
    print("b")
    for i in range(0, len(c)):
        print("\t%0.2lf" % c[i][len(c)-1], end = "")
    print("\nx")
    for i in range(0, len(x)):
        print("\t%0.2lf" % x[i], end = "")
    print("\n")

def main():
    A = [[1, 2, 1], [2, 2, 3], [-1, -3, 0]]
    b = [0, 3, 2]
    x = []
    c = Guass(A, b, x)
    show_answer(c, x)
    A1 = [[0, 2, 1], [1, 1, 0], [2, 3, 2]]
    b1 = [5, 3, 0]
    x1 = []
    c1 = Guass(A1, b1, x1)
    show_answer(c1, x1)
    A2 = [[2, 1, 0, 0], [1, 3, 1, 0], [0, 1, 1, 1], [0, 0, 2, 1]]
    b2 = [1, 2, 2, 0]
    x2 = []
    c2 = Guass(A2, b2, x2)
    show_answer(c2, x2)

if __name__ == "__main__":
    main()