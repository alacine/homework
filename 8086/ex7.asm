DATAS SEGMENT
    a db 'Give me a letter, and I will give you a tower!$' 
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    ;提示语
    lea dx,a
    mov ah,09h
    int 21h
    mov dl,0ah
    mov ah,02h
    int 21h
    mov dl,0dh
    mov ah,02h
    int 21h
    
    ;输入
input:
    mov ah,01h
    int 21h
    mov bl,al
    
    mov dl,0ah
    mov ah,02h
    int 21h
    mov dl,0dh
    mov ah,02h
    int 21h
    
    mov ah,02h
    int 21h
    jmp output
    
output:
    mov ah,02h
    int 21h
    dec dl
    cmp dl,40h
    jz exit
    jmp output

    MOV AH,4CH
    INT 21H
    
CODES ENDS
    END START




