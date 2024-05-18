.DEFAULT_GOAL := binfo # make

CFLAGS = -Wall -Wextra -pedantic -std=c++17

SRCDIR = src
INCDIR = include
BUILDDIR = build
LIBDIR = lib
LIBNAME = libbinfo.a
EXE = binfo

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	g++ $(CFLAGS) -I$(INCDIR) -c -o $@ $<

test: $(OBJS) tests/test.cpp
	g++ $(CFLAGS) -g -I$(INCDIR) -L. -o test $^

d: $(OBJS)
	g++ $(CFLAGS) -g -I$(INCDIR) -o $(EXE) $(OBJS)

lib: $(OBJS)
	ar rcs $(LIBDIR)/$(LIBNAME) $^

binfo: $(OBJS)
	g++ $(CFLAGS) -I$(INCDIR) -o $(EXE) $(OBJS) main.cpp
# with lib: g++ -Iinclude main.cpp -Llib -lbinfo -o main
clean:
	rm -rf $(BUILDDIR)/*.o $(LIBDIR)/* test.exe test binfo.exe binfo
