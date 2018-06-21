## 第八章习题  

### 8.1  
**假设我们将模式 $r \left( A, B, C, D, E \right)$ 分解为**  
$r_1 \left( A, B, C \right)$  
$r_2 \left( A, D, E \right)$  
**证明该分解是无损分解，如果如下函数依赖集F成立：**  
$A \to BC, CD \to E, B \to D, E \to A$  

$\because r_1 \cap r_2 = A, A \to BC$  
$\therefore r_1 \cap r_2 \to ABC$  
$\therefore r_1 \cap r_2$ 是$r_1$的超码  
$\therefore$该分解是无损分解。

### 8.6  
**计算关于模式 $r \left( A, B, C, D, E \right)$ 的如下函数依赖集F的闭包。**  
$A \to BC$  
$CD \to E$  
$B \to D$  
$E \to A$  
**列出R的候选码**  

$\because A \to BC$  
$\therefore A \to B, A \to C$  
$\because B \to D$  
$\therefore A \to D$  
$\therefore A \to CD$  
又$\because CD \to E$  
$\therefore A \to E$  
$\therefore A \to ABCDE$  

$\because E \to A$  
$\therefore E \to ABCDE$  

$\because CD \to E$  
$\therefore CD \to ABCDE$  

$\because B \to D, BC \to CD$  
$\therefore BC \to ABCDE$  

$\therefore$ R的候选码有$A, BC, CD, E$。  

### 8.7  
**计算8.6的正则覆盖$F_c$**  

$\because F$左侧都是唯一的，且不含无关属性  
$\therefore F_c = F$。  

### 8.19  
**给出8.1中R的BCNF分解**  

分解为  
$r_1 = \left( A, B, C, D \right)$  
$r_2 = \left( A, B, E \right)$  

### 8.20  
**给出8.1中R的3NF分解**

### 8.29  
**考虑如下关系模式 $r \left( A, B, C, D, E, F \right)$上的函数依赖F:**  
$A \to BCD$  
$BC \to DE$  
$B \to D$  
$D \to A$  

*a. 计算 $B^+$*  
$\because B \to D, D \to A$  
$\therefore B \to A$  
$\because A \to BCD$  
$\therefore B \to BCD$  
$\therefore B \to BC$  
又$\because BC \to DE$  
$\therefore B \to DE$  
综上，$B^+ = ABCDE$  

*b. (使用Armstrong公理)证明AF是超码*  
由a得：$B \to ABCDE$，且$B \to A$  
因此 $A \to ABCED$  
$\therefore AF \to ABCDEF$；  
$\therefore AF$是超码。  

*c. 计算上述函数依赖F的正则覆盖*  
1. $A \to BCD$
2. $BC \to DE$
3. $B \to D$
4. $D \to A$  

$\because B \to D$  
$\therefore$ 2式中 $D$是无关的  
显然1式中 $D$ 也是无关的  
$\therefore$ 
1. $A \to BC$  
2. $BC \to E$  
3. $B \to D$  
4. $D \to A$  

$\because B \to D\to A \to BC$  
$\therefore$ 2式和3式合并为 $B \to DE$  
$\therefore$  
1. $A \to BC$  
2. $B \to DE$  
3. $D \to A$  

此时，不再有任何函数依赖含有无关属性，且左半部都是唯一的。  
$F_c = \lbrace A \to BC, B \to DE, D \to A \rbrace$。

*d. 基于正则覆盖，给出一个3NF分解*  
由c得：  
1. $A \to BC$  
2. $B \to DE$  
3. $D \to A$  

$\therefore R \left( ABC, BDE, AD \right)$  
添加候选码B得： $R \left( ABC, BDE, AD, BF \right)$  
删除冗余，得3NF范式为： $\left( ABC, BDE, AD, BF \right)$

*e.f*  
 不会