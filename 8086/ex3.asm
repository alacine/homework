DATAS SEGMENT
    ;此处输入数据段代码
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    ;输入一个字母
    mov ah,01h
    int 21h
    mov bl,al
    ;调用子程序
    call func
    ;输出
    mov ah,02h
    int 21h
    
    MOV AH,4CH
    INT 21H
func proc near
    cmp bl,60h
    jl l1
    jg l2
l1: add bl,20h
    jmp l3
l2: sub bl,20h
    jmp l3
l3: mov dl,bl
    ret
func endp
    
CODES ENDS
    END START



