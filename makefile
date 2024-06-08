.DEFAULT_GOAL := binfo # make

CFLAGS = -Wall -Wextra -pedantic -std=c++17

SRCDIR = src
INCDIR = include
BUILDDIR = build
LIBDIR = lib
LIBNAME = libbinfo
EXE = binfo

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	g++ $(CFLAGS) -I$(INCDIR) -c -o $@ $<

test: $(OBJS) tests/test.cpp
	g++ $(CFLAGS) -g -I$(INCDIR) -L. -o test $^

d: $(OBJS)
	g++ $(CFLAGS) -g -I$(INCDIR) -o $(EXE) $(OBJS)

$(LIBDIR)/$(LIBNAME).a: $(OBJS)
	ar rcs $(LIBDIR)/$(LIBNAME).a $^

lib: $(OBJS)
	ar rcs $(LIBDIR)/$(LIBNAME).a $^

old_binfo: $(OBJS)
	g++ $(CFLAGS) -I$(INCDIR) -o $(EXE) $(OBJS) main.cpp
# with lib: g++ -Iinclude main.cpp -Llib -lbinfo -o main
binfo: $(OBJS) $(LIBDIR)/$(LIBNAME).a
	g++ $(CFLAGS) -I$(INCDIR) main.cpp -L$(LIBDIR) -lbinfo -o $(EXE)

clean:
	rm -rf $(BUILDDIR)/* $(LIBDIR)/* test.exe test binfo.exe binfo
