#ifndef AST_HEADER_FILE
#define AST_HEADER_FILE


namespace miracle {
	class AST {
	public:
		virtual ~AST() = default;
	};

	class Expression;
	class UnaryExpression;
	class Operand;
	class UnaryOperator;
	class BinaryOperator;
}


#endif