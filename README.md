# Project on _printf Function
The _printf function prints out the user input to the terminal. It is an adaptation of the printf() function in the 'c' <stdio.h> library.
##### Prototype: ```int _printf(const char *format, ...);```

# Project Requirements
- All files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- A README.md file at the root of the folder of the project
- The code uses Betty coding style
-The header file "main.h" includes all function prototypes
## Authorized functions and macros
- ``` write (man 2 write) ```
- ``` malloc (man 3 malloc) ```
- ``` free (man 3 free) ```
- ``` va_start (man 3 va_start) ```
- ``` va_end (man 3 va_end) ```
- ``` va_copy (man 3 va_copy) ```
- ``` va_arg (man 3 va_arg) ```

## Examples
#### String
- Input - ```_printf("My name is %s\n", 'John Doe');```
- Output - ```My name is John Doe```

#### Character
- Input - ```_printf("Your grade is %c\n", 'A');```
- Output - ````Your grade is A```

#### Decimal
- Input - ```_printf("The cost of this item is %d dollars\n", 2500);```
- Output - ```The cost of this item is 2500 dollars```

#### Integer
- Input - ```_printf("This is item  number %i\n", 15);```
- Output - ```This is item number 15```
