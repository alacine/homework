#!/usr/bin/env python
# coding: utf-8

# ### 暴力枚举法求解 01 背包

# In[1]:


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


def brute_force():
    global ANS
    idx = 0
    while idx < 1<<(n+1):
        tmpv = tmpw = 0
        for i in range(n):
            tmpv += ((idx >> i) & 1) * vi[i]
            tmpw += ((idx >> i) & 1) * wi[i]
        if tmpv <= v:
            ANS = max(ANS, tmpw)
        idx += 1


# In[4]:


if __name__ == '__main__':
    start = time.time()
    brute_force()
    end = time.time()
    print(ANS)
    print('It costs {}s.'.format(end-start))


# In[ ]:




