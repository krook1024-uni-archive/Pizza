appname := pizza

CXX := g++
CXXFLAGS := -std=c++17

srcfiles := $(shell find . -name "*.cpp")
objects  := $(patsubst %.C, %.o, $(srcfiles))

all: $(appname)

$(appname): $(objects)
		$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(appname) $(objects) $(LDLIBS)

depend: .depend

.depend: $(srcfiles)
		rm -f ./.depend
		$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

dist-clean: clean
		rm -f *~ .depend

include .depend
