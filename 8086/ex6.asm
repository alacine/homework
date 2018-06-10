DATAS SEGMENT
    ;此处输入数据段代码
    path db 'd:/ass_test/test.txt',0
    path1 db 'd:/ass_test/test1.txt',0
    path2 db 'd:/ass_test/test2.txt',0
    a db 100 dup (?),'$'
    b db 100 dup (?),'$'
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    ;打开文件TEST.TXT
    lea dx,path
    mov al,00h;用读模式打开文件
    mov ah,3dh
    int 21h
    ;读取文件内容，存入a
    lea dx,a

    mov bx,ax;将文件代号传给bx
    mov cx,100;暂定读入100个字节
    mov ah,3fh
    int 21h

    ;显示a中的内容
    mov cx,ax;保存实际读入的字节数，用于打印时的循环
    lea si,a
print:
    mov dl,[si]
    mov ah,02h
    int 21h
    inc si
    loop print
    ;关闭文件
    mov ah,3eh
    int 21h

read_file1:
    lea dx,path1
    mov al,00h
    mov ah,3dh
    int 21h
    lea dx,b
    mov bx,ax
    mov cx,100
    mov ah,3fh
    int 21h

    mov cx,ax
    lea si,b
printf:
    mov dl,[si]
    mov ah,02h
    int 21H
    inc si
    loop printf
    mov ah,3eh
    int 21h

write_file2:
    lea dx,path2
    mov al,01h
    mov ah,3dh
    int 21H

    lea dx,b
    mov bx,ax

    mov cx,100
    mov ah,40h
    int 21h

    mov ah,3eh
    int 21h

delete_file1:
    lea dx,path1
    mov ah,41h
    int 21h

    MOV AH,4CH  ;程序结束，返回到操作系统系统
    INT 21H
CODES ENDS
END START