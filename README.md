Monty Scripting Language Overview
Monty 0.98 is a scripting language initially compiled into Monty byte codes, similar to Python. It utilizes a distinctive stack structure, employing specific instructions for stack manipulation. The primary objective of this project is to develop an interpreter for Monty ByteCodes files.

Monty Byte Code Files
Files containing Monty byte codes typically bear the .m extension. While widely adopted, adherence to this naming convention is not mandated by the language specification. Each line contains only one instruction, allowing for any number of spaces before or after the opcode and its argument:

opcodePush 0$
opcodePush 1$
opcodePush 2$
  opcodePush 3$
                   prntAll    $
opcodePush 4$
    opcodePush 5    $
      opcodePush    6        $
prntAll$

Monty byte code files may include blank lines (empty or composed solely of spaces), and any additional text following the opcode or its required argument is disregarded:
opcodePush 0 opcodePush 0 onto the stack$
opcodePush 1 opcodePush 1 onto the stack$
$
opcodePush 2$
  opcodePush 3$
                   prntAll    $
$
$
                           $
opcodePush 4$
$
    opcodePush 5    $
      opcodePush    6        $
$
prntAll This is the end of our program. Monty is awesome!$

Usage
To compile all files, use the following form:
gcc -Wall -Werror -Wextra -pedantic *.c -o monty

To execute the program:
./monty bytecode_file

Available operation codes:

Opcode	Description
opcodePush	Pushes an element onto the stack. e.g., (opcodePush 1 # pushes 1 into the stack)
prntAll	Prints all values on the stack, starting from the top.
topPrinter	Prints the value at the top of the stack.
remove_top	Removes the top element from the stack.
exchange	Swaps the top two elements of the stack.
sum	Adds the top two elements of the stack; result stored in the second node, and the first node is removed.
redundant	No operation; does not affect the stack.
subtrakt	Subtracts the second top element from the top element; result stored in the second node, and the first node is removed.
div	Divides the second top element by the top element; result stored in the second node, and the first node is removed.
multply	Multiplies the top two elements; result stored in the second node, and the first node is removed.
mod	Computes the remainder of the division of the second top element by the top element; result stored in the second node, and the first node is removed.
#	Lines beginning with # are treated as comments.
pchar	Prints the ASCII value representation of the integer at the top of the stack.
pstr	Prints ASCII values until 0, end of the stack, or a non-ASCII value is encountered.
rotl	Rotates the top of the stack to the bottom.
rotr	Rotates the bottom of the stack to the top.
stack	Sets the format of the data into a stack (LIFO).
queue	Sets the format of the data into a queue (FIFO).