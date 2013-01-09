# This is generated with help from StackOverflow:
# http://stackoverflow.com/questions/231229/how-to-generate-a-makefile-with-source-in-sub-directories-using-just-one-makefil

CC = g++
LD = g++
CFLAGS = 
LDFLAGS = -lSDL

DIRS = src

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

SRC = $(foreach sdir, $(SRC_DIR), $(wildcard $(sdir)/*.cpp))
OBJ = $(patsubst src/%.cpp, build/%.o, $(SRC))
INCLUDES = $(addprefix -I,$(INCLUDE_DIR))

vpath %.cpp $(SRC_DIR)

define make-cmd
$1/%.o: %.cpp
	$(CC) $(INCLUDES) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs build/main

build/main: $(OBJ)
	$(LD) $^ -o $@ $(LDFLAGS)

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

$(foreach bdir, $(BUILD_DIR), $(eval $(call make-cmd, $(bdir))))
