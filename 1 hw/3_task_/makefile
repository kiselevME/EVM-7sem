CC=g++
CFLAGS=-c -v -mtune=generic
SOURCES=3_task.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)