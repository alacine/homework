#!/usr/bin/env python
# coding: utf-8

# ### 广度优先求解 01 背包

# In[1]:


from collections import deque
import time


# In[2]:


with open('backpack.txt') as bp_file:
    n, v = map(int, bp_file.readline().split())
    vi = [0 for i in range(n)]
    wi = [0 for i in range(n)]
    for i in range(0, n):
        vi[i], wi[i] = map(int, bp_file.readline().split())
ANS = 0


# In[3]:


def bfs():
    global ANS
    que = deque()
    que.append(0)
    cur = 0
    while que:
        cur = que.popleft()
        left = 2 * cur + 1
        right = 2 * cur + 2
        if left > 1<<n or right > 1<<n:
            continue
        left_tmpv = left_tmpw = right_tmpv = right_tmpw = 0
        for i in range(n):
            left_tmpv += ((left >> i) & 1) * vi[i]
            left_tmpw += ((left >> i) & 1) * wi[i]
            right_tmpv += ((right >> i) & 1) * vi[i]
            right_tmpw += ((right >> i) & 1) * wi[i]
        if left_tmpv <= v:
            ANS = max(ANS, left_tmpw)
        que.append(left)
        if right_tmpv <= v:
            ANS = max(ANS, right_tmpw)
        que.append(right)


# In[4]:


if __name__ == '__main__':
    start = time.time()
    bfs()
    end = time.time()
    print(ANS)
    print('It costs {}s.'.format(end-start))


# In[ ]:




