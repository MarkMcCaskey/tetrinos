#--------------------------------------------------------------------	
#Provisional Makefile, not yet tested
#--------------------------------------------------------------------	

CC   = g++
OPTS = -std=c++11 -Wall -O3

SRCS= src/logic.cpp src/main.cpp src/board.cpp src/graphics.cpp
SUBDIRS = . inc/
INCLUDE = $(addprefix -I,$(SUBDIRS)) 
OBJS=${SRCS:.cpp=.o}
LIB = inc/
CFLAGS   = $(OPTS) $(INCLUDE)
TARGET = bin/game

SRCS_TEST = src/logic.cpp src/board.cpp test/logicTest.cpp
OBJS_TEST=${SRCS_TEST:.cpp=.o}
TARGET_TEST = bin/test

all: $(TARGET) $(TARGETi)

#--------------------------------------------------------------------	
objs: ${OBJS}
objs_test: ${OBJS_TEST}
#--------------------------------------------------------------------

$(TARGET): objs 
	${CC} ${CFLAGS} -o $@ $(OBJS) $(LIB)

$(TARGET_TEST): objs_test
	${CC} ${CFLAGS} -o $@ $(OBJSi) $(LIB)

clean:
	rm -f *.d $(OBJS) 
	rm -f *.d $(OBJS_TEST)

#--------------------------------------------------------------------
.SUFFIXES: .c

.cpp.o:
	${CC} ${CFLAGS} -c $< -o $@
