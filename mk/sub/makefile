
#MOD_NAME = $(subst $(DIR_TOP),aaa,$(CURDIR))
MOD_NAME = $(shell basename $(CURDIR))

DIR_INC = ./include
DIR_SRC = ./source

DIR_CUR_OBJ = $(DIR_OBJ)/$(MOD_NAME)

SRC_CPP = $(wildcard $(DIR_SRC)/*.cpp)
OBJ_CPP = $(patsubst %.cpp,$(DIR_CUR_OBJ)/%.o,$(notdir $(SRC_CPP)))

SRC_C = $(wildcard $(DIR_SRC)/*.c)
OBJ_C = $(patsubst %.c,$(DIR_CUR_OBJ)/%.o,$(notdir $(SRC_C)))


TARGET = $(DIR_OBJ)/$(MOD_NAME)$(MOD_EXT)

include $(DIR_TOP)/build/config.mak

.PHONY: $(DIR_CUR_OBJ) clean

all: $(DIR_CUR_OBJ) $(TARGET)

clean:
	rm $(TARGET) $(OBJ)

$(TARGET): $(OBJ_CPP) $(OBJ_C)
	$(AR) $(AR_FLAGS) $@ $(OBJ_CPP) $(OBJ_C) 

$(DIR_CUR_OBJ):
	$(MKDIR_P) $(DIR_CUR_OBJ)

$(OBJ_CPP): $(DIR_CUR_OBJ)%.o: $(DIR_SRC)%.cpp
	$(CXX) $(CXX_FLAGS) -c  $< -o $@

$(OBJ_C): $(DIR_CUR_OBJ)%.o: $(DIR_SRC)%.c
	$(CC) $(CC_FLAGS) -c  $< -o $@
