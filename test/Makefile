CPP   := g++ -Wall -g -fPIC
LIB   := -lpthread -lrt -lfskit
INC   := -I/usr/include -I. -I../
C_SRCS:= $(wildcard *.c)
CXSRCS:= $(wildcard *.cpp)
OBJ   := $(patsubst %.c,%.o,$(C_SRCS)) $(patsubst %.cpp,%.o,$(CXSRCS))
DEFS  := -D_REENTRANT -D_THREAD_SAFE -D__STDC_FORMAT_MACROS -D_FILE_OFFSET_BITS=64
LIBINC	:= -L../

COMMON := common.cpp
COMMON_O := common.o

TESTS := $(patsubst test-%.o,test-%,$(OBJ))

all: $(TESTS)

test-% : test-%.o $(COMMON_O)
	$(CPP) -o $@ $(INC) $(LIB) $(LIBINC) $(COMMON_O) $<

%.o : %.c
	$(CPP) -o $@ $(INC) -c $< $(DEFS)

%.o : %.cpp
	$(CPP) -o $@ $(INC) -c $< $(DEFS)

.PHONY: clean
clean:
	/bin/rm -f $(OBJ) $(TESTS)
