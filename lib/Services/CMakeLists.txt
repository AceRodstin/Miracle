set(
	LIBRARY_SOURCES
	"Executor.cpp"
	"SyntacticAnalyzer.cpp"
	"TokensParser.cpp"
	"Calculator.cpp"
	"JIT.cpp"
)

add_library(services ${LIBRARY_SOURCES})