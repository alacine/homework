## 一、实验项目 
编程实现一个串处理任务。  

## 二、编程环境 
* 操作系统：windows7 32位
* 软件：masm for windows

## 三、调试数据与结果  
![photo1](ex4_1.png)

## 四、实验源程序  
实现串的复制  
```
DATAS SEGMENT
    a db 'aaaaaaa',0ah,0dh,'$'
	pa db 'This is a: $'
	pb db 'This is b: $'
DATAS ENDS

EXT SEGMENT
    b db 'bbbbbbb',0ah,0dh,'$', 24 dup(?)
EXT ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,es:ext
START:
    MOV AX,DATAS
    MOV DS,AX
    ;提示语
    lea dx, pa
    mov ah, 09h
    int 21h
    lea dx, a
    mov ah, 09h
    int 21h
    lea dx, pb
    mov ah, 09h
    int 21h
    ;原来b串中的内容
    mov ax,ext
    mov ds,ax
    lea dx, b
    mov ah, 09h
    int 21h
    
    ;重新赋段地址
    mov ax,datas
    mov ds,ax
    lea dx,pb
    mov ah,09h
    int 21h
    ;开始复制操作
    mov ax, ext
    mov es, ax
    lea si, a
    lea di, b
    mov cx, 11
    cld
    rep movsb
    mov bx, es
    mov ds, bx
    lea dx, b
    mov ah, 09h
    int 21h
    
    MOV AH,4CH
    INT 21H
CODES ENDS
    END START
```

## 五、体会
更好地掌握了串操作指令。