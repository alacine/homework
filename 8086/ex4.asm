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
    ;��ʾ��
    lea dx, pa
    mov ah, 09h
    int 21h
    lea dx, a
    mov ah, 09h
    int 21h
    lea dx, pb
    mov ah, 09h
    int 21h
    ;ԭ��b���е�����
    mov ax,ext
    mov ds,ax
    lea dx, b
    mov ah, 09h
    int 21h
    
    ;���¸��ε�ַ
    mov ax,datas
    mov ds,ax
    ;��ʼ���Ʋ���
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



