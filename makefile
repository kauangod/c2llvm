all:
	bison -d parser.y -o parser.tab.c
	flex lexer.l
	gcc -lfl *.c -o tinycompiler -g

# -Wcounterexamples
clean:
	rm -f tiny.tab.c lex.yy.c tinycompiler saida saida.txt saida.ll parser.tab.c
