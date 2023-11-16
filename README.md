# Monty

Monty 0.98 is a scripting language akin to Python, initially compiled into Monty byte codes. It operates on a distinctive stack, employing specific instructions for stack manipulation. The primary objective of this project is to develop an interpreter for Monty ByteCodes files.

Monty Byte Code Files
Monty byte code files commonly bear the .m extension, a standard adopted by most of the industry, although not mandated by the language specification. Each line in these files contains at most one instruction. The opcode and its argument can be accompanied by any number of spaces before or after, allowing for flexible formatting.

```
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$

```

# Usage

All the files are compiled in the following form:

```
 gcc -Wall -Werror -Wextra -pedantic *.c -o monty.

```

To run the program:

```
 ./monty bytecode_file
```

Available operation codes:

| Opcode | Description |
<<::================ :: ============>>
:rotl   : Rotates the top of the stack to the bottom of the stack.:
:rotr   : Rotates the bottom of the stack to the top of the stack.:
:stack  : This is the default behavior. Sets the format of the data into a stack (LIFO).:
:queue  : Sets the format of the data into a queue (FIFO).:
::push == Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack):
::pall == Prints all the values on the stack, starting from the to of the stack.:
::pint == Prints the value at the top of the stack.:
::pop  == Removes the to element of the stack. :
::div    : Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.:
::mul | Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.:
::mod    : Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.:
:#      : When the first non-space of a line is a # the line will be trated as a comment.:
:pchar  : Prints the integer stored in the top of the stack as its ascii value representation.:
:pstr   : Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.:
::swap == Swaps the top to elements of the stack.:
::add  == Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.
::nop    : This opcode does not do anything.:
::sub    : Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.:

