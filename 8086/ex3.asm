DATAS SEGMENT
    ;�˴��������ݶδ���
DATAS ENDS

STACKS SEGMENT
    ;�˴������ջ�δ���
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    ;����һ����ĸ
    mov ah,01h
    int 21h
    mov bl,al
    ;�����ӳ���
    call func
    ;���
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



