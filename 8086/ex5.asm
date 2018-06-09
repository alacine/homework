DATAS SEGMENT
    ;此处输入数据段代码
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    xor ax,ax
    xor bx,bx
    
input:mov ah,01h
    int 21h
    cmp al, 0dh
    je sum
    sub al,30h
    xor ah,ah
    add bx,ax
    jmp input
    
sum:mov ax,bx
    daa
    mov bx,ax
    
    mov dl,0ah
    mov ah,02h
    int 21h
    
    mov ax,bx
    mov dl,ah
    mov ah,02h
    int 21h
    
    mov ax,bx
    mov dl,al
    mov ah,02h
    int 21h

    MOV AH,4CH
    INT 21H
CODES ENDS
    END START





