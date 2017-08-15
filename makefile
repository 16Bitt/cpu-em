SOURCES	= $(patsubst %.cpp,%.o,$(wildcard *.cpp))
CPPFLAGS	= -Werror -g -std=c++11
TARGET	= cpu-em
CPP		= g++

all: $(SOURCES)
	$(CPP) $(CPPFLAGS) $(SOURCES) -o $(TARGET)

clean:
	-rm $(SOURCES)
	-rm $(TARGET)
