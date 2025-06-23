# Lista de arquivos .txt e seus .ll correspondentes
TXTFILES := $(wildcard *.txt)
LLFILES := $(TXTFILES:.txt=.ll)
BINARIES := $(LLFILES:.ll=)

# Regra principal: compilar tudo
all: $(BINARIES)

# Etapa 1: Compilar .txt para .ll
%.ll: %.txt
	./tinycompiler $< $@

# Etapa 2: Compilar .ll para executável
%: %.ll
	clang $< -o $@

# Limpeza
clean:
	rm -f $(LLFILES) $(BINARIES)

