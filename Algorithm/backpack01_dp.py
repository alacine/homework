#!/usr/bin/env python
# coding: utf-8

# ### 动态规划法求解 01 背包

# In[1]:


import time


# In[2]:


with open('backpack.txt') as bp_file:
    n, v = map(int, bp_file.readline().split())
    vi = [0 for i in range(n+1)]
    wi = [0 for i in range(n+1)]
    for i in range(1, n+1):
        vi[i], wi[i] = map(int, bp_file.readline().split())
ANS = [[0 for i in range(v+1)] for j in range(n+1)]


# In[3]:


def dp_solve():
    for i in range(1, n+1):
        for j in range(1, v+1):
            if j >= vi[i]:
                ANS[i][j] = max(ANS[i-1][j], ANS[i-1][j-vi[i]] + wi[i])
            else:
                ANS[i][j] = ANS[i-1][j]


# In[4]:


if __name__ == '__main__':
    start = time.time()
    dp_solve()
    end = time.time()
    print(ANS[n][v])
    print('It costs {}s.'.format(end-start))


# In[ ]:




