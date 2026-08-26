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
	@perl -MTime::HiRes=time -e ' \
		my $$start = time(); \
		my $$code = system(@ARGV); \
		printf("\nTempo de execução: %.4f s\n", time() - $$start); \
		exit($$code == -1 ? 127 : $$code >> 8); \
	' "./$(OUT)"

clean:
	@find . -name '*.out' -type f -delete
	@echo "Arquivos .out removidos"

$(SRC):
	@: 
