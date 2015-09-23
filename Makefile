# Use 'make V=1' to see the full commands
CC = gcc
CXX = g++
AS = as
AR = ar

INCLUDE := -I/usr/local/include
LIBS := -L/usr/lib64 -L/usr/local/lib -lpthread -lleveldb
CFLAGS := 
CPPFLAGS = -std=c++11

CFILES := $(wildcard *.c)
CPPFILES := $(wildcard *.cpp)
OBJECTS := $(addsuffix .o,$(basename $(CPPFILES)) $(basename $(CFILES)))
TARGETS := $(basename $(OBJECTS))

ifeq ("$(origin V)", "command line")
   BUILD_VERBOSE = $(V)
endif

ifndef BUILD_VERBOSE
   BUILD_VERBOSE = 0
endif

ifeq ($(BUILD_VERBOSE),0)
	QUIET_CC        = @echo '   ' CC $@;
	QUIET_CXX       = @echo '   ' CXX $@;
endif

all:$(TARGETS)
	@echo "--------------------------make successful----------------------------------------------------------"

$(TARGETS):$(OBJECTS)
	$(QUIET_CXX)$(CXX) -o $@ $(addsuffix .o,$@) $(LIBS) 

%.o:%.c
	$(QUIET_CC)$(CC) $(INCLUDE) -c $<

%.o:%.cc
	$(QUIET_CXX)$(CXX) $(CPPFLAGS) $(INCLUDE) -c $<

%.o:%.cpp
	$(QUIET_CXX)$(CXX) $(CPPFLAGS) $(INCLUDE) -c $<

.PHONY:clean show help
clean:
	-rm -Rf $(TARGETS) $(OBJECTS)
	@echo "--------------------------make clean----------------------------------------------------------"

show:
	@echo $(CPPFILES)
	@echo "-----------------------"
	@echo $(CFILES)
	@echo "-----------------------"
	@echo $(OBJECTS)
	@echo "-----------------------"
	@echo $(TARGETS)
	@echo "-----------------------"

help:
	@echo 'clean            -Remove generated files '
	@echo 'show             -Show target files' 
	@echo 'make V=1         -enable verbose output'
