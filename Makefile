CXX := clang++
SRC := $(filter %.cpp,$(MAKECMDGOALS))
OUT := $(SRC:.cpp=.out)

.PHONY: run clean $(SRC)

run:
	@if [ -z "$(SRC)" ]; then \
		echo "Uso: make run <arquivo.cpp>"; \
		echo "Exemplo: make run atividade-2/q1.cpp"; \
		exit 1; \
	fi
	$(CXX) "$(SRC)" -o "$(OUT)"
	@RUN_CMD="./$(OUT)" perl -MTime::HiRes=time -e 'my $$s=time(); my $$c=system($$ENV{RUN_CMD}); printf("\nTempo de execução: %.4f s\n", time()-$$s); exit($$c==-1?127:$$c>>8)'

clean:
	@find . -name '*.out' -type f -delete
	@echo "Arquivos .out removidos"

$(SRC):
	@: 
