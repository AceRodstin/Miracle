# Grammar

## Notation

- | alternation
- () grouping
- [] option (0 or 1 times)
- {} repetition (0 to n times)
- a...b closed range (from a to b)

Non-terminals are in CamelCase. Terminals are enclosed in double quotes "".

## Expressions

```
Expression = UnaryExpression | Expression BinaryOperator Expression .
UnaryExpression = [ UnaryOperator ] PrimaryExpression .
PrimaryExpression = Operand .
Operand = Literal | "(" Expression ")" .
```

## Operators

```
BinaryOperator = AdditionGroupOperator | MultiplicationGroupOperator .
UnaryOperator = "+" | "-" .
AdditionGroupOperator = "+" | "-" .
MultiplicationGroupOperator = "*" | "/" .
```

## Literals

```
Literal = FloatLiteral .
FloatLiteral = DecimalFloatLiteral .
DecimalFloatLiteral = DecimalDigits  [ "." DecimalDigits ] .
```

## Characters

```
DecimalDigits = DecimalDigit { [ "_" ] DecimalDigit } .
DecimalDigit = "0" ... "9" .
```