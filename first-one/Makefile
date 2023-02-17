CFLAGS=-Wall -g

# This is the target that compiles our executable
# All other targets are "prerequisites" of this target
# The @ symbol tells make to not display the command
# that it is about to execute
# The - symbol tells make to ignore errors
# The $^ symbol is a macro that expands to all the
# prerequisites of the target (in this case, program1.o)
# The $@ symbol is a macro that expands to the name
# of the target (in this case, program1)
# The $< symbol is a macro that expands to the name
# of the first prerequisite (in this case, program1.c)
# The $* symbol is a macro that expands to the stem
# shared by target and prerequisites (in this case, program1)
# The $? symbol is a macro that expands to the names
# of all prerequisites that are newer than the target
# (in this case, program1.o)
# The $+ symbol is a macro that expands to the names
# of all prerequisites, with spaces between them
# (in this case, program1.o)
# The $| symbol is a macro that expands to the names
# of all order-only prerequisites
# (in this case, program1.o)
# The $% symbol is a macro that expands to the member
# name when the target is an archive member
# (in this case, program1.o)
all: program1
	clang -o program1 program1.o

# This is the target that compiles program1.c to create
# the object file program1.o
# All other targets are "prerequisites" of this target
program1.o: program1.c
	clang -c program1.c

# This is the target that removes all generated files
# so that we can start over
clean:
	rm -f program1 program1.o
