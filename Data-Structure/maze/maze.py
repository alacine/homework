# This program is used to find a way out in a maze

# define node
class node(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

sk = []
tmp = []

# get the map from input file
file = open("in.txt","r")
line1 = file.readline()
size = line1.split()
w = int(size[0])
h = int(size[1])
# print("%r\nw = %d\nh = %d\n" %(size, w, h))

# the next line shows how to init a two-demensional list
maze = [[0 for i in range(w)] for i in range(h)]
lines = file.readlines()
i = 0
for line in lines:
    j = 0
    for x in line.split():
        maze[i][j] = int(x)
        if int(x) == 3:
            op = node(i, j)
            maze[i][j] = 0
        if int(x) == 4:
            ed = node(i, j)
            maze[i][j] = 0
        j += 1
    # maze[i].append([int(x) for x in line.split()])
    i += 1

# check the next step is available or not
def check(nex):
    if(nex.x < w and nex.x >= 0 and
       nex.y < h and nex.y >= 0 and
       maze[nex.y][nex.x] == 0):
        return True
    return False

# check is there a way out or not
def path():
    cur = op
    sk.append(cur)
    while(len(sk) > 0):
        cur = sk.pop()
        sk.append(cur)
        if cur.x == ed.x and cur.y == ed.y:
            return True
        maze[cur.y][cur.x] = 6
        # go down
        nex = cur
        nex.y += 1
        if check(nex):
            cur = nex
            sk.append(cur)
            continue
        # go left
        nex = cur
        nex.x -= 1
        if check(nex):
            cur = nex
            sk.append(cur)
            continue
        # go up
        nex = cur
        nex.y -= 1
        if check(nex):
            sk.append(cur)
            continue
        # go right
        nex = cur
        nex.x += 1
        if ckeck(nex):
            sk.append(cur)
            continue
        sk.pop()
    return False

# to print the map
def pint_map():
    print("Or you can watch this map:")
    for m in maze:
        print(m)


# main
def main():
     