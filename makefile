CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
PRSDIR = parse
SRCDIR = search
SRTDIR = sort

SRCS = main.cpp \
        $(PRSDIR)/parse.cpp \
        $(SRCDIR)/sequentialSearch.cpp \
        $(SRTDIR)/mergeSort.cpp

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean