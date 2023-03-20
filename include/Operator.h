#ifndef OPERATOR_HEADER_FILE
#define OPERATOR_HEADER_FILE


#include <map>

using namespace std;

namespace miracle {
	enum class Operator {
		add,
		substruct,
		multiply,
		divide
	};

	map<Operator, char> operators {
		{ Operator::add, '+' },
		{ Operator::substruct, '-' },
		{ Operator::multiply, '*' },
		{ Operator::divide, '/' }
	};

	map<Operator, int> operatorsPrecedence {
		{ Operator::add, 10 },
		{ Operator::substruct, 10 },
		{ Operator::multiply, 20 },
		{ Operator::divide, 20 }
	};
}


#endif