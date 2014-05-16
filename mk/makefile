SUBMODS = gpio
SUBDIRS = $(addprefix ../, $(SUBMODS))


DIR_TOP = $(CURDIR)/..
DIR_OBJ = $(CURDIR)/obj


DIR_INC = $(addsuffix /include, $(SUBDIRS))
DIR_SRC = ..

SRC_TOP = $(wildcard ${DIR_SRC}/*.cpp)
OBJ_TOP = $(patsubst %.cpp,$(DIR_OBJ)/%.o,$(notdir $(SRC_TOP)))

LIB_FLAGS = $(addsuffix $(MOD_EXT), $(addprefix $(DIR_OBJ)/, $(SUBMODS)))

export DIR_TOP
export DIR_OBJ

TARGET = gpio_server 

include config.mak


.PHONY: all clean $(SUBDIRS)

all: $(TARGET)

$(TARGET): $(SUBDIRS) $(OBJ_TOP)
	$(CXX) $(OBJ_TOP) $(LIB_FLAGS) -o $@
	@echo $(DIR_TOP)

$(OBJ_TOP): $(DIR_OBJ)%.o: $(DIR_SRC)%.cpp
	$(CXX) $(CXX_FLAGS) -c  $< -o $@

clean: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

# all: $(TARGET)

# $(TARGET): $(OBJ_TOP)
# 	$(CXX) $(OBJ_TOP) -o $@








