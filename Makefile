CXX := clang++
SRC := $(filter %.cpp,$(MAKECMDGOALS))
OUT := $(SRC:.cpp=.out)

.PHONY: run $(SRC)

run:
	@if [ -z "$(SRC)" ]; then \
		echo "Uso: make run <arquivo.cpp>"; \
		echo "Exemplo: make run atividade-2/q1.cpp"; \
		exit 1; \
	fi
	$(CXX) "$(SRC)" -o "$(OUT)" && "./$(OUT)"

$(SRC):
	@:
