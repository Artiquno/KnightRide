SOURCES=main.cpp Board.cpp
CC=g++
CFLAGS=-c
LDFLAGS=-lsfml-system -lsfml-graphics -lsfml-window
OBJECTS=$(SOURCES:.cpp=.o)
EXEDIR=./bin/
EXECUTABLE=$(EXEDIR)knight-ride

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(EXEDIR)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

$(EXEDIR):
	mkdir $(EXEDIR)

clean:
	rm *.o

purge:
	rm -R *.o $(EXEDIR)
