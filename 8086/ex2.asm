DATAS SEGMENT
    a db 0ah,'end$'
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
    ;���̿���loopѭ�������д��ĸ
    mov dl,40h
    mov cx,100
s1: add dl,1
    ;��������д��ĸ�ķ�Χʱ���˳�
    cmp dl,5ah
    jg s2
    mov ah,02h
    int 21h
    loop s1
    
s2: lea dx,a
    mov ah,09h
    int 21h
    jmp s3
    
s3: MOV AH,4CH
    INT 21H
    
CODES ENDS
    END START



