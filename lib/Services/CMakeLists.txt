set(
	LIBRARY_SOURCES
	"Executor.cpp"
	"SyntacticAnalyzer.cpp"
	"TokensParser.cpp"
)

add_library(services ${LIBRARY_SOURCES})