
MOD_NAME = $(subst $(DIR_TOP),aaa,$(CURDIR))

DIR_INC = ./include
DIR_SRC = ./source

DIR_CUR_OBJ = $(DIR_OBJ)/$(MOD_NAME)

SRC = $(wildcard $(DIR_SRC)/*.cpp)
OBJ = $(patsubst %.cpp,$(DIR_CUR_OBJ)/%.o,$(notdir $(SRC)))


TARGET = $(DIR_OBJ)/$(MOD_NAME)$(MOD_EXT)

include $(DIR_TOP)/build/config.mak

.PHONY: $(DIR_CUR_OBJ)

all: $(DIR_CUR_OBJ) $(TARGET)

$(TARGET): $(OBJ)
	# $(MKDIR_P) $(@D)
	$(AR) $(AR_FLAGS) $@ $(OBJ)

$(DIR_CUR_OBJ):
	$(MKDIR_P) $(DIR_CUR_OBJ)

$(OBJ): $(DIR_CUR_OBJ)%.o: $(DIR_SRC)%.cpp
	$(CXX) $(CXX_FLAGS) -c  $< -o $@
