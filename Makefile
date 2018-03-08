

CC=g++
SRCDIR := src
TESTDIR := test
CPPFLAGS=-Iheader
BUILDDIR := build
DIRECTORIES := build bin

all: directories $(BUILDDIR)/Socket.o $(BUILDDIR)/ServerSocket.o $(BUILDDIR)/SocketException.o
	$(CC) $(CPPFLAGS) $(BUILDDIR)/*.o $(TESTDIR)/example1.cpp -o bin/example1
	$(CC) $(CPPFLAGS) $(BUILDDIR)/*.o $(TESTDIR)/example2.cpp -o bin/example2

lib: directories $(BUILDDIR)/Socket.o

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp directories
	$(CC) $(CPPFLAGS) -c -o $@ $<


.PHONY: clean directories

directories:
	mkdir -p $(DIRECTORIES)

clean:
	$(RM) -r build bin

