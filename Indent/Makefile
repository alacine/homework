#This is Makefile
indent.out: Del.o headfile_indent.o Clean.o Allman.o indent.o Lisp.o Ratliff.o Whitesmiths.o GNU.o Horstmann.o KR.o Pico.o  
	gcc Del.o headfile_indent.o Clean.o Allman.o Lisp.o Ratliff.o Whitesmiths.o GNU.o Horstmann.o KR.o Pico.o indent.c -o indent.out
Del.o:
	gcc -c Del.c
headfile_indent.o:
	gcc -c headfile_indent.c
Clean.o:
	gcc -c Clean.c
Allman.o:
	gcc -c Allman.c
Lisp.o:
	gcc -c Lisp.c
Ratliff.o:
	gcc -c Ratliff.c
Whitesmiths.o:
	gcc -c Whitesmiths.c
GNU.o:
	gcc -c GNU.c
Horstmann.o:
	gcc -c Horstmann.c
KR.o:
	gcc -c KR.c
Pico.o:
	gcc -c Pico.c

clean: Allman.o Del.o headfile_indent.o indent.o Lisp.o Ratliff.o  Whitesmiths.o Clean.o GNU.o Horstmann.o KR.o Pico.o indent.out
	rm Allman.o Del.o headfile_indent.o indent.o Lisp.o Ratliff.o  Whitesmiths.o Clean.o GNU.o Horstmann.o KR.o Pico.o indent.out
