CC = g++ 	# this is the compiler we are using

CFLAGS = -c -Wall -Wextra	# Compiles with all errors and warnings

TARGET = deque	# assigning deque as our target

all: $(TARGET)		# Target for building all

$(TARGET): main.o deque.o				#target for linking all .o files and creating binary $(TARGET)
	$(CC) main.o deque.o -o $(TARGET)

main.o: main.cpp		     # Compiles main.o from source (main.cpp)
	$(CC) $(CFLAGS) main.cpp

deque.o: deque.cpp deque.h	 	# Compiles deque.o from source (deque.cpp)
	$(CC) $(CFLAGS) deque.cpp

clean:						 # Removes all objects, emacs backups, and target
	$(RM) $(TARGET) *.o *~