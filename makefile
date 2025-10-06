compile:
	gcc main.c src/app/app.c src/client/client.c src/router/router.c src/handlers/handlers.c -o httpserver

run: compile
	./httpserver
