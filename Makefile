# Makefile racine
.PHONY: clean mrpoper doc

#DIRECTORIES
SRCDIR = src/
MAINDIR = main
SUBDIR = $(addprefix $(SRCDIR), histogram set image)

#COLORS
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: lib/libCCollections.a
	@for dir in $(SUBDIR) ; do make -s -C $$dir ; done
	@(make -s -C $(SRCDIR)$(MAINDIR))

lib/libCCollections.a :
	@make -s -C CCollections/
	@mv CCollections/bin/libCCollections.a lib/libCCollections.a
	@echo "Library $(CFILE)libCCollections.a$(CNONE) generated"

doc:
	@doxygen Doxyfile
	@echo "Documentation generated in $(CDIR)doc$(CNONE)"

clean:
	@for dir in $(SUBDIR) ; do make -s -C $$dir clean ; done
	@(cd $(SRCDIR)$(MAINDIR) && make -s clean)
	@rm -rf $(OBJDIR)*.o
	@rm -rf lib/*.a
	@echo "project cleaned"

mrproper: clean
	@(cd $(SRCDIR)$(MAINDIR) && make -s mrproper)
