set(
	LIBRARY_SOURCES
	"SyntacticAnalyzer.cpp"
	"TokensParser.cpp"
	"JIT.cpp"
	"CodeGenerator.cpp"
	"Calculator.cpp"
)

add_library(services ${LIBRARY_SOURCES})