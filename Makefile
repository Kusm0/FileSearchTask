CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic
LIB_PATH = ../file_search_lib
LIB_NAME = libfile_search.a

all: app

lib:
	$(CC) $(CFLAGS) -c $(LIB_PATH)/file_search_lib.cpp -o $(LIB_NAME)

app: lib
	$(CC) $(CFLAGS) main.cpp $(LIB_NAME) -o file_search_app -lpthread

clean:
	rm -f $(LIB_NAME) file_search_app
