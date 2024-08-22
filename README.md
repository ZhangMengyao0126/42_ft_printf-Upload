# ft_printf
## The **objective** of this project
1.The function signature of "printf": int printf(const char *format, ...);
（1）The return value is the number of characters successfully output, or negative when there is an error.
（2）const char *format:
A.constant char: To ensure the string cannot be motified through the pointer, cause it is the users' input.
B.*format: In fact, it is indeed a pointer to a char, which is used to represent strings in C. Since it includes the format specifiers, so it is called "format".

## The **solution** of this project
1.the main function: 
printfint ft_printf(const char *format,...) , used to declare the variable argument list and specify the specific variable to use;
2.Subfunction for ft_printf:
static int ft_check_format(const char *format, va_list ap, int len), used to check '%format' and print other normal characters.
3.Subfunction for ft_check_format:
static int ft_check_specifier(char spec, va_list ap)


## Useful Knowledge
### About variadic function
*Variadic function: They are indeed a group of macros defined in the head file <stdarg.h>.
*Macro:  A macro is a fragment of code that is given a name. Whenever the name is used, it is going to be replaced by the content of the macro before compilation.
1.va_start(arg, last_param):
Purpose: Initializes the variable argument list and sets the pointer to the first argument.
Note: This only initializes the variable argument list and does not retrieve the value of arg (value retrieval is done using va_arg).
2.va_arg(arg, type):
Purpose: Retrieves the current argument value and interprets it as the specified type.
Note:
If the type does not match, it will result in undefined behavior.
If there is no next argument, the behavior is also undefined.
3.va_end(arg):
Purpose: Ends the traversal of the variable argument list and cleans up any resources.
Note: Although va_end may do nothing in some implementations, it is required by the standard to be called.

### About lib.a
1.The file extension of an archive, which is a file that encapsulates all of the compiled object files (.o). Archives are used for the modularity of a program. Each archive can be treated as a module of the whole project.
2.ar -rc *the name of the archive(.a)* *the object files the archive is going to encapsulate(.o)*
3.gcc main.o lib.a -o *the name of the executable*

### About different excutable files
1.'a.out' is the default name of the executable on Unix-like systems. Note that .out is just part of the name, not a file extension. In fact, there is no specific file extension for executables on Unix-like systems.
2.'.exe' is the file extension of the executable on Windows.Note the reason you get both of the test and the test.exe is that maybe your development environment is set up for cross-compilation.

### About Makefile
#### Complication Process
1. Preprocess.  
The compiler will process the preprocessor directives, such as #include and #define. After that, the original source file is expanded with all the headers and macro definitions. This means that the preprocessor will replace the directives with their corresponding content.
2. Compilation
The preprocessed code is then translated into assembly code, which acts as an intermediary between syntax code and machine code. Notice that syntax code cannot be directly transferred into machine code.
3. Assembly
The assembly code will be converted into machine code by the assembler, resulting in a binary **object** file(.o). This file contains the machine code and the related metadata, such as the symbol table.
4. Linking
The linker will combine multiple object files and libraries to produce the final executable file (.out/.exe).

#### What is Makefile
1.Makefile is a build automation tool. It defines a set of rules and dependencies that dictate how to compile and link the program.
2.Makefile will check the timestamps of all the targets and the dependencies to make sure that the output is the newest version. With Makefile, we don't have to recompile all the programs when there are changes in the original code.

#### Makefile syntax
target: dependencies // target is created from dependencies
(tab) the command for using dependencies to produce the target

$(variable's name) // reference a defined variable
$(variable's name:.c=.o) // references a defined variable, but replaces all '.c' with '.o'"
$<// reference the first dependency
$^// reference all the dependencies
$@// reference the target

%.o:%.c// match each of the object files and its corresponding source files

OBJS // objects
CC // c compiler
RM // rm -f（default value）

gcc // c compiler
-c // specifically for compiling. When use without -c, gcc is for linking
-o // specify the name of the output file(the default name should be a.out/a.exe)
-Wall -Wextra -Werror // warning messages flags, warn all, extra warnings, warnings as errors

rm // remove
-r // -recursive, remove the directory and all of its content
-f // -force

* // wildcard, all files with the specified file extension

ar // archive
-r // replace: replace or add files in the archive. If the archive doesn't exist, then create one.
-c // create: create the archive, if it doesn't exist. Seems redundant with the -r, but could suppress some error warnings.



### About **markdone language**
//.md：1.markdone language, which is a markup language commonly used to format README files.
//file extensions: 1.A declaration to the operating system (OS) and to applications about how the file should be interpreted and handled.
///////////////////2.Changing it won't lead to changes in the content.
///////////////////3.Some file extensions are compatible, so even if you change them, you can still open the file with the same editor. For example, .md and .txt are both for plain text files, so you can open both of them with a text editor.

Headers: 1. # for H1(Be aware of the space after #); # for H2 etc...  
         2. Headers can have up to six levels.
new paragraph: space and double enter
new line: double space and enter
#text: Headers; # for H1; ## for H2; ### for H3.
*text*/_text_: Be italic.
**text**/__text__: Be bold.
***text***:Be both italic and bold.
~text~: Strikethrough.
***/___/- - - between two paragraphs: divider.