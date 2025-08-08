# C2LLVM - Projeto de compilador do subset da linguagem C para C2LLVM

## BNF

program:
    declarations commands
;

declarations:
      %empty
    | declarations declaration
;

declaration:
      INTtype ID
    | FLOATtype ID
    | BOOLEANtype ID
    | CHARtype ID
;

commands:
      %empty
    | commands command
;

command:
      if_command
    | atrib
    | read_command
    | write_command
    | return_command
    | while_command
;

while_command:
    WHILE LEFT logical_expr RIGHT  B_LEFT commands  B_RIGHT

return_command:
    returnCommand expr

read_command:
    readCommand LEFT ID RIGHT
;

write_command:
    writeCommand LEFT write_value RIGHT
;

write_value:
      STRING COMMA write_formats
    | STRING
;

write_formats:
        expr

atrib:
      ID EQUALS expr
;

if_command:
    IF LEFT logical_expr RIGHT  B_LEFT commands  B_RIGHT  else_command
;

else_command:
      ELSE  B_LEFT commands B_RIGHT
    | %empty
;

logical_expr:
    logical_operations
;

expr:
      expr PLUS term
    | expr MINUS term
    | term
;

term:
      term TIMES factor
    | term DIVIDE factor
    | factor
;

factor:
      DOUBLE
    | INT
    | CHARACTER
    | ID
    | LEFT expr RIGHT
;

logical_operations:
      logical_operations AND logical_operations
    | logical_operations OR logical_operations
    | logical_operations GT expr
    | logical_operations GE expr
    | logical_operations LT expr
    | logical_operations LE expr
    | logical_operations DIF expr
    | logical_operations l_EQUALS expr
    | NOT logical_operations
    | NOT LEFT logical_operations RIGHT
    | expr
;

## Apresentação

[Arquivo .pptx com a apresentação](/assets/C2LLVM.pptx)

## Docs

[Artigo-relatório](/assets/artigo_relatorio_c2llvm.pdf)

[Repositório GitHub](https://github.com/kauangod/c2llvm)

# Estrutura do Projeto

```
├── calc.c              # Funções auxiliares para geração de código
├── calc.h              # Header das funções auxiliares
├── ht.c                # Implementação da tabela hash para tabela de símbolos
├── ht.h                # Header da tabela hash
├── lex.yy.c            # Arquivo gerado pelo flex (lexer)
├── lexer.l             # Especificação do lexer (flex)
├── Makefile            # Script de compilação do projeto
├── parser.tab.c        # Arquivo gerado pelo bison (parser)
├── parser.tab.h        # Header gerado pelo bison
├── parser.y            # Especificação da gramática (bison)
├── stack.c             # Implementação da stack para controle de branches
├── stack.h             # Header da stack
├── utils.h             # Utilitários gerais
├── LeiameKauanGodoyMuriloMontalvão.md  # Este arquivo de documentação
└── testes/             # Diretório com arquivos de teste
    ├── celsius_para_fahrenheit.txt
    ├── fatorial.txt
    ├── ifs_aninhados.txt
    ├── loop_aninhado.txt
    ├── par_impar.txt
    └── teste.txt
```

# Descrição dos Arquivos

## Arquivos Principais
- **lexer.l**: Especificação do analisador léxico usando Flex
- **parser.y**: Especificação da gramática usando Bison
- **Makefile**: Script de compilação e build do projeto

## Arquivos Gerados
- **lex.yy.c**: Código fonte do lexer gerado pelo Flex
- **parser.tab.c**: Código fonte do parser gerado pelo Bison
- **parser.tab.h**: Header do parser gerado pelo Bison

## Bibliotecas Auxiliares
- **ht.c/h**: Implementação de tabela hash para gerenciamento da tabela de símbolos
- **calc.c/h**: Funções auxiliares para geração de código LLVM
- **stack.c/h**: Implementação de stack para controle de nomenclatura em branches
- **utils.h**: Utilitários gerais do projeto

## Testes
O diretório `testes/` contém diversos arquivos de teste com diferentes cenários:
- Conversão de temperatura (celsius para fahrenheit)
- Cálculo de fatorial
- Estruturas condicionais aninhadas
- Loops aninhados
- Verificação de paridade
- Testes gerais
