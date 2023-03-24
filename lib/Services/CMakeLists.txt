set(
	LIBRARY_SOURCES
	"SyntacticAnalyzer.cpp"
	"TokensParser.cpp"
	"JIT.cpp"
)

add_library(services ${LIBRARY_SOURCES})