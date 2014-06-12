# rpg-engine, An rpg engine written in C++
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
CC = g++ -std=c++11 -Wall -I$(SRCDIR)

EXECUTABLES = executable

# Default target
default: executable

####################################################
#        Other prerequisites / dependencies        #
####################################################

engine/events/interfaces/Hub.h: engine/events/interfaces/Listener.h \
	engine/events/interfaces/Filter.h
engine/events/Central_hub.hpp: engine/events/interfaces/Hub.h
engine/events/Lambda_listener.hpp: engine/events/interfaces/Listener.h
engine/events/Lambda_filter.hpp: engine/events/interfaces/Filter.h

engine/gui/Window.o: engine/gui/Window.h
engine/gui/Draw_event.o: engine/gui/Draw_event.h
engine/gui/Resource_manager.o: engine/gui/Resource_manager.h

engine/types/Dict.o: engine/types/Dict.h

main.o: engine/events/Central_hub.hpp engine/events/Lambda_filter.hpp \
	engine/events/Lambda_listener.hpp engine/gui/Window.o \
	engine/gui/Draw_event.o engine/gui/Resource_manager.o

####################################################
#         Application definitions                  #
####################################################
OBJS = main.o engine/gui/Window.o engine/gui/Draw_event.o \
	   engine/gui/Resource_manager.o engine/types/Dict.o

executable: make_dirs $(OBJS)
	$(CC) -lsfml-graphics -lsfml-window -lsfml-system $(addprefix $(OBJDIR), $(OBJS)) -o $@
	@echo Done linking $@.

####################################################
#        Generated Variables                       #
####################################################
OBJDIRS = $(subst $(SRCDIR),$(OBJDIR),$(shell find $(SRCDIR) -type d))

####################################################
#          Other targets                           #
####################################################
.PHONY : clean make_dirs all

%.o : %.cpp
	$(CC) -c $(filter %.cpp, $^) -o $(OBJDIR)$@

clean:
	@-rm -r bin $(EXECUTABLES)

make_dirs:
	@mkdir -p $(OBJDIRS)

all: $(EXECUTABLES)


####################################################
#          vpath                                   #
####################################################
vpath %.cpp $(SRCDIR)
vpath %.o   $(OBJDIR)
vpath %.h   $(SRCDIR)
vpath %.hpp $(SRCDIR)

