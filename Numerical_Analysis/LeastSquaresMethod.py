# 数据拟合的最小二乘方法的实现 (Least Squares Method)
from Gauss import guass, merge, show_process

# 内积
def dot_product(old_list, n):
    new_list = [i**n for i in old_list]
    return new_list

# 向量相乘
def product(la, lb):
    p = sum([i*j for i, j in zip(la, lb)])
    return p

# 根据所求多项式次数转化为相应大小的矩阵
def transform(x, y, n):
    c = [[] for i in range(0, n+1)]
    for i in range(0, n+1):
        c[i] = [product(dot_product(x, i), dot_product(x, j)) for j in range(0, n+1)]
        c[i].append(product(dot_product(x, i), y))
    return c

# 输出得到的多项式
def show_least_squares(x, n):
    print('p%d(x)=%g' % (n ,x[0]), end = '')
    for i in range(1, len(x)):
        if x[i] >= 0:
            print('+', end = '')
        print('%gx' % x[i], end = '')
        if i >= 2:
            print('^%d' % i, end = '')
    print('\n')

def main():
    x = [0, 0.15, 0.31, 0.5, 0.6, 0.75]
    y = [1.0, 1.004, 1.031, 1.117, 1.223, 1.422]
    c = transform(x, y, 1)
    show_process(c)
    # guaa(c) 用高斯列主元消去法解方程
    show_least_squares(guass(c), 1)
    d = transform(x, y, 2)
    show_process(d)
    show_least_squares(guass(d), 2)

if __name__ == '__main__':
    main()