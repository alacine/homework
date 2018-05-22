# 高斯列主元消去法
import copy

def show_c(c):
    for i in c:
        for j in i:
            print("%10.3lf" % j, end = " ")
        print()
    print()

def Guass(a, b, x):
    c = copy.deepcopy(a)
    for i in range(0, len(b)):
        c[i].append(b[i])
    show_c(c)

    for i in range(0, len(c)-1):
        c.sort(key = lambda x: abs(x[i in range(0, len(c))]), reverse = True)
        for j in range(i+1, len(c)):
            m = - c[j][i] / c[i][i]
            for k in range(0, len(c[j])):
                c[j][k] += m * c[i][k]    
        show_c(c)
    show_c(c)

    for i in range(len(c)-1, -1, -1):
        if i == len(c) - 1:
            x.append(c[i][len(c[i])-1] / c[i][i])
        else:
            x.insert(0, c[i][len(c[i])-1])
            for j in range(len(x)-1, 0, -1):
                x[0] -= c[i][i+j] * x[j]
            x[0] /= c[i][j]
    print(x)

def show(a, b, x):
    print("A")
    for i in range(0, len(a)):
        for j in range(0, len(a[i])):
            print("\t", a[i][j], end = "")
        print()
    print("b")
    for i in range(0, len(b)):
        print("%g\t" % b[i], end = "")
    print("\nx")
    for i in range(0, len(x)):
        print("%g\t" % x[i], end = "")
    print()

def main():
    A = [[1, 2, 1], [2, 2, 3], [-1, -3, 0]]
    b = [0, 3, 2]
    x = []
    A1 = [[0, 2, 1], [1, 1, 0], [2, 3, 2]]
    b1 = [5, 3, 0]
    x1 = []
    A2 = [[2, 1, 0, 0], [1, 3, 1, 0], [0, 1, 1, 1], [0, 0, 2, 1]]
    b2 = [1, 2, 2, 0]
    x2 = []
    Guass(A, b, x)
    show(A, b, x)
    Guass(A1, b1, x1)
    show(A1, b1, x1)
    Guass(A2, b2, x2)
    show(A2, b2, x2)

if __name__ == "__main__":
    main()