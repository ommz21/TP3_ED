# == VARIAVEIS ===
# ================
CC=g++ 
CFLAGS=-g -Wall -Wextra
EXEC=./tp3
TMPOUT=tp3.testresult
MEM_LEAK=valgrind --leak-check=full --track-origins=yes --show-reachable=yes 

# === REGRAS =====
# ================
$(EXEC): main.cc arvore.o
	$(CC) $(CFLAGS) main.cc arvore.o -o $(EXEC)

arvore.o: headers/arvore.o
	$(CC) $(CFLAGS) -c headers/arvore.cc -o arvore.o

all: $(EXEC)
	$(EXEC)
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)
memcheck: $(EXEC) #Execucao usando valgrind para verificar se o codigo possui algum leak de memoria
	$(MEM_LEAK)$(EXEC)
clean: #remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf tp3 arvore.o headers/arvore.o