#!/usr/bin/env python
# coding: utf-8

# ### 随机法求解 01 背包

# In[1]:


import time
import random


# In[2]:


with open('backpack.txt') as bp_file:
    n, v = map(int, bp_file.readline().split())
    vi = [0 for i in range(n)]
    wi = [0 for i in range(n)]
    for i in range(0, n):
        vi[i], wi[i] = map(int, bp_file.readline().split())
ANS = 0


# In[3]:


def my_random():
    global ANS
    attempt, attempts = 0, 2e6
    while attempt < attempts:
        tmpv = tmpw = 0
        idx = random.randint(0, 1<<(n+1))
        for i in range(n):
            tmpv += ((idx >> i) & 1) * vi[i]
            tmpw += ((idx >> i) & 1) * wi[i]
        if tmpv <= v:
            ANS = max(ANS, tmpw)
        attempt += 1


# In[4]:


if __name__ == '__main__':
    start = time.time()
    my_random()
    end = time.time()
    print(ANS)
    print('It costs {}s.'.format(end-start))


# In[ ]:




