DATAS SEGMENT
    ;�˴��������ݶδ���
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    ;����
    xor ax,ax
    xor bx,bx
    xor cx,cx
    ;����һ��һλ��
input:mov ah,01h
    int 21h
    cmp al,0dh;����Ϊ�س�ʱ��������
    je sum
    sub al,30h
    mov cl,al
    mov ax,bx
    add ax,cx
    daa
    adc ah,0
    mov bx,ax
    jmp input
    
sum:;�����һ������
    mov dl,0ah
    mov ah,02h
    int 21h
    ;�����λ
    mov ax,bx
    and ax,0f00h
    mov dl,ah
    add dl,30h
    mov ah,02h
    int 21h
    ;���ʮλ
    mov ax,bx
    and ax,00f0h
    mov cl,4
    shr ax,cl
    mov dl,al
    add dl,30h
    mov ah,02h
    int 21h
    ;�����λ
    mov ax,bx
    and ax,000fh
    mov dl,al
    add dl,30h
    mov ah,02h
    int 21h

    MOV AH,4CH
    INT 21H
CODES ENDS
    END START






