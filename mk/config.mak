
CXX =  g++
CXX_FLAGS +=  -std=c++0x -Wall -I${DIR_INC}

CC = gcc
CC_FLAGS +=  -std=c99 -Wall -I${DIR_INC}

AR = ar
AR_FLAGS = cr

MKDIR_P = @mkdir -p

MOD_EXT = .a
