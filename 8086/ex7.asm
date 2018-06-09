DATAS SEGMENT
    ask_for_game_info db 0ah,'Do you like van game?(y/n)$'
    error_info db 0ah,'Sorry, I can not understand what you are saying... Tell me again please.(y/n)$'
    ask_others_info db 0ah,'Then what do you like? poems, computer games, songs, sleep?(p/c/s/e)$'
    like_nothing_info db 0ah,'It seems that you like nothing, I will just leave',0ah,'$'
    start_info db 0ah,'I am thinking of an ASCII character, guess what it is',0ah,'$'

    poem_title_info db 0ah,'Rain',0ah,'$'
    poem_info1 db 'Rain is falling all around,',0ah,'$'
    poem_info2 db 'It falls on field and tree,',0ah,'$'
    poem_info3 db 'It rains on the umbrella here,',0ah,'$'
    poem_info4 db 'And on the ships at sea.',0ah,'$'

    songs_title_info db 0ah,'I can only sing Twinkle...',0ah,'$'
    songs_info db '~Twinkle, twinkle, little star~',0ah,'~How I wonder what you are~',0ah,'$'
    songs_end_info db 'but I do not think you like it...$'
DATAS ENDS

STACKS SEGMENT
    ;此处输入堆栈段代码
STACKS ENDS

CODES SEGMENT
    ASSUME CS:CODES,DS:DATAS,SS:STACKS
START:
    MOV AX,DATAS
    MOV DS,AX
    
ask_for_game:
    ;询问是否要van游戏
    lea dx,ask_for_game_info
    mov ah,09h
    int 21h
    
    mov ah,01h
    int 21h
    cmp al,'y'
    je game_start
    cmp al,'n'
    je ask_others
    lea dx,error_info
    mov ah,09h
    int 21h
    jmp ask_for_game

ask_others:
    ;问点别的
    lea dx,ask_others_info
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h
    cmp al,'p'
    je read_poem
    cmp al,'c'
    je computer_game
    cmp al,'s'
    je sing_songs
    cmp al,'e'
    je sleep
    lea dx,like_nothing_info
    mov ah,09h
    int 21h
    jmp exit


game_start:
    ;输出游戏开始信息
    lea dx,start_info
    mov ah,09h
    int 21h

    jmp exit
    
read_poem:
    lea dx,poem_title_info
    mov ah,09h
    int 21h
    lea dx,poem_info1
    mov ah,09h
    int 21h
    lea dx,poem_info2
    mov ah,09h
    int 21h
    lea dx,poem_info3
    mov ah,09h
    int 21h
    lea dx,poem_info4
    mov ah,09h
    int 21h

    jmp exit
    
sing_songs:
    lea dx,songs_title_info
    mov ah,09h
    int 21h
    lea dx,songs_info
    mov ah,09h
    int 21h
    lea dx,songs_end_info
    mov ah,09h
    int 21h

    jmp exit

computer_game:
    jmp exit
sleep:
    jmp exit
exit:
    MOV AH,4CH
    INT 21h
CODES ENDS
    END START
