# 2D-engine, A C++ library wrapping sfml, to be used for 2D games
# Copyright (C) 2014 firecoders
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
# IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
# TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

####################################################
#        Constants                                 #
####################################################
SRCDIR = src/
OBJDIR = bin/
CC = g++ -std=c++11 -Wall -I$(SRCDIR) -fdiagnostics-color=auto

LIBRARY = libengine.a

# Default target
default: $(LIBRARY)

####################################################
#        Other prerequisites / dependencies        #
####################################################

# events

engine/events/Broadcaster.hpp: \
	engine/events/interfaces/Receiver.h \
	engine/events/interfaces/Subscribable.h

engine/events/Lambda_node.hpp: \
	engine/events/Broadcaster.hpp

# gui

engine/gui/Window.h: \
	engine/gui/Draw_event.h
engine/gui/Window.o: \
	engine/gui/Window.h \
	engine/events/interfaces/Receiver.h

# engine/gui/Draw_event.h: none
engine/gui/Draw_event.o: \
	engine/gui/Draw_event.h

# engine/gui/Resource_manager.h: none
engine/gui/Resource_manager.o: \
	engine/gui/Resource_manager.h

# converters

engine/converters/Sfml_event_to_dict.h: \
	engine/types/Dict.h \
	engine/events/interfaces/Receiver.h \
	engine/converters/Sfml_enum_to_string.h
engine/converters/Sfml_event_to_dict.o: \
	engine/converters/Sfml_event_to_dict.h

# engine/converters/Sfml_enum_to_string.h: none
engine/converters/Sfml_enum_to_string.o: \
	engine/converters/Sfml_enum_to_string.h

engine/converters/Draw_event_to_dict.h: \
	engine/gui/Draw_event.h \
	engine/events/interfaces/Receiver.h \
	engine/types/Dict.h
engine/converters/Draw_event_to_dict.o: \
	engine/converters/Draw_event_to_dict.h

# types

# engine/types/Dict.h: none
engine/types/Dict.o: \
	engine/types/Dict.h

####################################################
#         Application definitions                  #
####################################################
OBJS = engine/gui/Resource_manager.o \
	engine/gui/Draw_event.o \
	engine/types/Dict.o \
	engine/converters/Draw_event_to_dict.o \
	engine/converters/Sfml_enum_to_string.o \
	engine/converters/Sfml_event_to_dict.o \
	engine/gui/Window.o

$(LIBRARY): make_dirs $(OBJS)
	ar rcs $@ $(addprefix $(OBJDIR), $(OBJS))
	@echo Done linking $@.

####################################################
#        Generated Variables                       #
####################################################
OBJDIRS = $(subst $(SRCDIR),$(OBJDIR),$(shell find $(SRCDIR) -type d))
TEST_OBJECTS = $(subst .cpp,.o,$(shell find $(TEST_DIR) -type f -regex .*.cpp))

####################################################
#          Googletest integration                  #
####################################################

GTEST_DIR = dep/gtest-1.7.0
GTEST_URL = https://googletest.googlecode.com/files/gtest-1.7.0.zip
TEST_DIR = tests
TEST_EXEC_NAME = test

$(TEST_EXEC_NAME): $(TEST_OBJECTS) libengine.a dep/bin/libgtest.a
	$(CC) -pthread $^ -o $@
	@echo Done linking $@

$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp libengine.a dep/bin/libgtest.a
	$(CC) -isystem $(GTEST_DIR)/include -Isrc -c $(filter %.cpp, $^) -o $@

$(GTEST_DIR)/%:
	@echo "Downloading googletest from $(GTEST_URL)"
	@mkdir -p dep/bin
	@curl $(GTEST_URL) > gtest.zip
	@unzip gtest.zip -d dep
	@rm gtest.zip
	@echo "Done downloading googletest"

dep/bin/gtest-all.o: $(GTEST_DIR)/src/gtest-all.cc
	$(CC) -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) \
		-pthread -c $^ -o $@

dep/bin/gtest_main.o: $(GTEST_DIR)/src/gtest_main.cc
	$(CC) -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) \
		-pthread -c $^ -o $@

dep/bin/libgtest.a: dep/bin/gtest-all.o dep/bin/gtest_main.o
	ar -rv $@ $^
	@echo Done linking $@

####################################################
#          Other targets                           #
####################################################
.PHONY : clean make_dirs all

%.h:
	@touch $(SRCDIR)$@

%.hpp:
	@touch $(SRCDIR)$@

%.o : %.cpp
	$(CC) -c $(filter %.cpp, $^) -o $(OBJDIR)$@

clean:
	-rm -r bin $(LIBRARY) $(TEST_OBJECTS) $(TEST_EXEC_NAME)

make_dirs:
	@mkdir -p $(OBJDIRS)

all: $(LIBRARY)


####################################################
#          vpath                                   #
####################################################
vpath %.cpp $(SRCDIR)
vpath %.o   $(OBJDIR)
vpath %.h   $(SRCDIR)
vpath %.hpp $(SRCDIR)

