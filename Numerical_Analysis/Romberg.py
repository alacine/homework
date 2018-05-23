import math

EPS = 1e-5

def f1(x):
    return math.exp(x) * math.cos(x)

def f2(x):
    return 4 / (1 + x * x)

# 用于输出外推结果表格
def show(T):
    print('区间数\t', end = ' ')
    for i in range (0, len(T)):
        print('%d次外推\t' %i, end = ' ')
    print()
    for i in range(0, len(T)):
        print('----------------', end = '')
    print()
    for i in range(0, len(T)):
        print(2**i, end = '\t')
        for j in range(0, i+1):
            print('%0.6lf\t' %T[i][j], end = '')
        print()

# 龙贝格算法的实现
def romberg(f, a, b, T):
    T.append([])
    h = b - a # 步长
    i, err, n = 0, 999.0, 1 # n为区间数量
    T[0].append((f(a) + f(b)) * h / 2)

    while err >= EPS: # 当误差足够小，即小于预定的误差时结束计算，否则区间数量翻倍
        s = 0
        i += 1
        for j in range(0, n):
            s += f(a + (j+0.5) * h)
        T.append([0.5 * T[i-1][0] + h / 2 * s])
        for j in range(1, i + 1):
            T[i].append((4**j * T[i][j-1] - T[i-1][j-1]) / (4**j-1)) # 龙贝格迭代公式
        err = abs(T[i][i-1] - T[i-1][i-1])
        h /= 2 # 步长减半
        n *= 2 # 区间数量翻倍

    print('#interval=%d, err=%e, res=%0.6lf\n' %(n, err, T[i][i]))

def main():
    T, W = [], []
    romberg(f1, 0, math.pi, T)
    show(T)
    print()
    romberg(f2, 0, 1, W)
    show(W)

if __name__ == '__main__':
    main()