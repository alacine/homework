maxn = 1000
nex = []
num = 1

for i in range(0, maxn):
    nex.append(0)

# s = "abcgabchabc"
# p = "abc"
file = open('in.txt', 'r')
lines = file.readlines()
word1 = lines[0].split()
word2 = lines[1].split()
s = word1[0]
p = word2[0]
file.close()

def get_next(lp):
    nex[0] = -1
    j = 0
    i = 1
    while(i < lp):
        # print(p[i], p[j])
        if ((j == -1) or (p[i] == p[j])):
            i += 1
            j += 1
            nex[i] = j
        else:
            j = nex[j]

def kmp(ls, lp):
    i = 0
    j = 0
    num = 1
    while(i < ls):
        if (j == -1) or (j < len(p) and (s[i] == p[j])):
            # print("\ns[%d]=%r p[%d]=%r Yes" %(i, s[i], j, p[j]))
            i += 1
            j += 1
        else:
            # print("\ns[%d]=%r p[%d]=%r No" %(i, s[i], j, p[j]))
            j = nex[j]
        
        if j == lp:
            print("%d:%d" %(num, i-j+1))
            num += 1

def main():
    ls = len(s)
    lp = len(p)
    get_next(lp)
    kmp(ls, lp)

main()
