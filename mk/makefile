SUBMODS = module
SUBDIRS = $(addprefix ../, $(SUBMODS))


DIR_TOP = $(CURDIR)/..
DIR_OBJ = $(CURDIR)/obj


DIR_INC = $(addsuffix /include, $(SUBDIRS))
DIR_SRC = ..

SRC_TOP_CPP = $(wildcard ${DIR_SRC}/*.cpp)
OBJ_TOP_CPP = $(patsubst %.cpp,$(DIR_OBJ)/%.o,$(notdir $(SRC_TOP_CPP)))

SRC_TOP_C = $(wildcard ${DIR_SRC}/*.c)
OBJ_TOP_C = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir $(SRC_TOP_C)))

LIB_FLAGS = $(addsuffix $(MOD_EXT), $(addprefix $(DIR_OBJ)/, $(SUBMODS)))

export DIR_TOP
export DIR_OBJ

TARGET = target

include config.mak


.PHONY: all clean $(SUBDIRS)

all: $(TARGET)

$(TARGET): $(SUBDIRS) $(OBJ_TOP_CPP) $(OBJ_TOP_C)
	$(CXX) $(OBJ_TOP_CPP) $(OBJ_TOP_C) $(LIB_FLAGS) -o $@
	@echo $(DIR_TOP)

$(OBJ_TOP_CPP): $(DIR_OBJ)%.o: $(DIR_SRC)%.cpp
	$(CXX) $(CXX_FLAGS) -c  $< -o $@

$(OBJ_TOP_C): $(DIR_OBJ)%.o: $(DIR_SRC)%.c
	$(CC) $(CC_FLAGS) -c  $< -o $@

clean: $(SUBDIRS)
	rm $(TARGET) $(OBJ_TOP_CPP) $(OBJ_TOP_C)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)









