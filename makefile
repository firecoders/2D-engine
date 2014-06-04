####################################################
#        Constants                                 #
####################################################
CC = g++ -std=c++11 -Wall
SRCDIR = src/
OBJDIR = bin/

EXECUTABLES = executable

# Default target
default: executable

####################################################
#        Other prerequisites / dependencies        #
####################################################

####################################################
#         Application definitions                  #
####################################################
OBJS = main.o
executable: make_dirs $(OBJS)
	$(CC) $(addprefix $(OBJDIR), $(OBJS)) -o $@
	@echo Done linking $@.

####################################################
#        Generated Variables                       #
####################################################
OBJDIRS = $(subst $(SRCDIR),$(OBJDIR),$(shell find $(SRCDIR) -type d))
HEADER = $(subst .o,.h, $(subst $(OBJDIR), $(SRCDIR), $@))

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
vpath %.h   $(SRCDIR)

