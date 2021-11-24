CFLAGS = -g -Wall

cshell: turtle.o cd.o pipe.o run_command.o redirec.o tokenize.o
	gcc -o cshell $(CFLAGS) turtle.o pipe.o cd.o run_command.o redirec.o tokenize.o 

clean:
	rm -f *.o cshell


turtle.o: turtle.c
	gcc $(CFLAGS) -c turtle.c

cd.o: cd.c cd.h
	gcc $(CFLAGS) -c cd.c	
	
run_command.o: run_command.c run_command.h
	gcc $(CFLAGS) -c run_command.c

redirec.o: redirec.c redirec.h
	gcc $(CFLAGS) -c redirec.c

tokenize.o: tokenize.c tokenize.h
	gcc $(CFLAGS) -c tokenize.c

pipe.o: pipe.c pipe.h
	gcc $(CFLAGS) -c pipe.c
