# This is generated with help from StackOverflow:
# http://stackoverflow.com/questions/231229/how-to-generate-a-makefile-with-source-in-sub-directories-using-just-one-makefil


CC = gcc
CPP = g++

LD = g++
CFLAGS = -ggdb
LDFLAGS = -lSDL

DIRS = src

INCLUDE_DIR = include
SRC_DIR = src
BUILD_DIR = build

CPPSRC = $(foreach sdir, $(SRC_DIR), $(wildcard $(sdir)/*.cpp))
CSRC = $(foreach sdir, $(SRC_DIR), $(wildcard $(sdir)/*.c))
CPPOBJ = $(patsubst src/%.cpp, build/%.o, $(CPPSRC))
COBJ = $(patsubst src/%.c, build/%.o, $(CSRC))
INCLUDES = $(addprefix -I,$(INCLUDE_DIR))

vpath %.cpp $(SRC_DIR)
vpath %.c $(SRC_DIR)

define make-cmd
$1/%.o: %.cpp
	$(CPP) $(INCLUDES) -c $$< -o $$@
$1/%.o: %.c
	$(CC) $(INCLUDES) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs build/main

build/main: $(CPPOBJ) $(COBJ)
	$(LD) $(CFLAGS) $^ -o $@ $(LDFLAGS)

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)

$(foreach bdir, $(BUILD_DIR), $(eval $(call make-cmd, $(bdir))))
