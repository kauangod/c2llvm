DIR := ./testes/
TXTFILES := $(wildcard $(DIR)*.txt)
LLFILES := $(TXTFILES:.txt=.ll)
BINARIES := $(LLFILES:.ll=)

# Regra principal: compilar tudo
all: tinycompiler $(BINARIES)

# Compilar o tinycompiler
tinycompiler: calc.c lex.yy.c parser.tab.c pilha.c ht.c
	gcc -o tinycompiler calc.c lex.yy.c parser.tab.c pilha.c ht.c -lfl

# Etapa 1: Compilar .txt para .ll
$(DIR)%.ll: $(DIR)%.txt tinycompiler
	./tinycompiler $< $@

# Etapa 2: Compilar .ll para executável
$(DIR)%: $(DIR)%.ll
	clang $< -o $@

# Limpeza
clean:
	rm -f $(LLFILES) $(BINARIES) tinycompiler
	rm -f *.o

# Limpeza completa (inclui arquivos gerados pelo flex/bison)
distclean: clean
	rm -f lex.yy.c parser.tab.c parser.tab.h

.PHONY: all clean distclean

