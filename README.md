# elementary-vm
The purpose of this project is to create a simple virtual machine that can interpret programs written in a basic assembly language.

As for any assembly language, the language of Elementary VM is composed of a series of instructions, with one instruction per line.
However, Elementary VM’s assembly language has a limited type system, which is a major difference from other real world assembly languages.

<b>Comments</b>:

    Comments start with a ’#’ and finish with a newline.
    A comment can be either at the start of a line, or after an instruction.

<b>put</b>:

    Pushes the value v at the top of the stack. The value v must have one of the following form:
      ◦ int8(n): Creates an 8-bit integer with value n.
      ◦ int16(n): Creates a 16-bit integer with value n.
      ◦ int32(n): Creates a 32-bit integer with value n.
      ◦ float32(z): Creates a 32-bit float with value z.
      ◦ float64(z): Creates a 64-bit float with value z.
      ◦ int64(n): Creates a 64-bit integer with value n.
      ◦ int128(n): Creates a 128-bit integer with value n.
      
<b>pop</b>:

    Remove the value from the top of the stack. If the stack is empty, the program execution must stop with an error.
    
<b>trace</b>:

    Displays each value of the stack, from the most recent one to the oldest one WITHOUT CHANGING the stack.
    Each value is separated from the next one by a newline.
  
<b>assert</b>:

    Asserts that the value at the top of the stack is equal to the one passed as parameter for this instruction.
    If it is not the case, the program execution must stop with an error.
    The value v has the same form that those passed as parameters to the instruction put.

<b>add</b>:

    Unstacks the first two values on the stack, adds them together and stacks the result.
    If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.
 
<b>sub</b>:

    Unstacks the first two values on the stack, subtracts them, then stacks the result.
    If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.
   
<b>mul</b>:

    Unstacks the first two values on the stack, multiplies them, then stacks the result.
    If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.

<b>div</b>:

    Unstacks the first two values on the stack, divides them, then stacks the result.
    If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.
    Moreover, if the divisor is equal to 0, the program execution must stop with an error too.
    
<b>mod</b>:

    Unstacks the first two values on the stack, calculates the modulus, then stacks the result.
    If the number of values on the stack is strictly inferior to 2, the program execution must stop with an error.
    Moreover, if the divisor is equal to 0, the program execution must stop with an error too.
 
<b>print</b>:

    Asserts that the value at the top of the stack is an 8-bit integer (If not, see the instruction assert).
    Then interprets it as an ASCII value and displays the corresponding character on the standard output.
    
<b>end</b>:

    Terminate the execution of the current program.
    If this instruction does not appears while all others instruction has been processed, the execution must stop with an error.
  
