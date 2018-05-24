# 计算差商 difference quotient
def get_diff_quo(k, x, fx, c):
    for i in range(0, k):
        c.append([])
        c[i].append(fx[i])
    for j in range(1, k):
        for i in range(j, k):
            c[i].append((c[i-1][j-1] - c[i][j-1]) / (x[i-j] - x[i]))
            #        开始于首节点的次阶差商 - 结束于尾节点的次阶差商
            # 差商 = --------------------------------------------
            #                      首节点 - 尾节点

# 计算牛顿插值多项式的值
def newton(k, x, fx, x1, c, nt):
    nt.append(c[0][0])
    for i in range(1, k):
        tmp = c[i][i]
        for j in range(i - 1, -1, -1):
            tmp *= (x1 - x[j])
        nt.append(nt[i - 1] + tmp)

# 输出差商表和牛顿插值多项式的值
def show(k, c, nt, x1):
    for i in range(0, k):
        for j in range(0, i + 1):
            print('c[%d][%d]=%0.5lf' %(i, j, c[i][j]), end = ' ')
        print()
    print()
    for i in range(0, k):
        print('N_%d<%g>=%0.5lf' %(i, x1, nt[i]))

def main():
    c, nt = [], []
    x = [0.4, 0.55, 0.65, 0.80, 0.90]
    fx = [0.41075, 0.57815, 0.69675, 0.88811, 1.02652]
    x1 = 0.596
    k = len(x)
    get_diff_quo(k, x, fx, c)
    newton(k, x, fx, x1, c, nt)
    show(k, c, nt, x1)

if __name__ == '__main__':
    main()