set(
	LIBRARY_SOURCES
	"BinaryOperator.cpp"
	"Expression.cpp"
	"Operand.cpp"
	"UnaryExpression.cpp"
	"UnaryOperator.cpp"
)

add_library(ast ${LIBRARY_SOURCES})