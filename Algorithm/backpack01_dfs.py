#!/usr/bin/env python
# coding: utf-8

# ### 深度搜索求解 01 背包

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


def dfs_bp(idx, sumv, sumw):
    global ANS
    if idx == n:
        if sumv <= v and sumw > ANS:
            ANS = sumw
        return
    dfs_bp(idx+1, sumv+vi[idx], sumw+wi[idx])
    dfs_bp(idx+1, sumv, sumw)


# In[4]:


if __name__ == '__main__':
    start = time.time()
    dfs_bp(0, 0, 0)
    end = time.time()
    print(ANS)
    print('It costs {}s.'.format(end-start))


# In[ ]:




