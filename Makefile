skelet: main.c image.o
	gcc main.c image.o -o reflex -lGL -lGLU -lglut -lm -Wall
image.o: image.c image.h
	gcc image.c -o image.o -c -lGL -lGLU -lglut -lm -Wall
