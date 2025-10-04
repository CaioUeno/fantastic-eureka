compile:
	gcc main.c src/app.c src/client.c -o httpserver

run: compile
	./httpserver
