QT -= gui

CONFIG += c++14 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    utils.h


#sudo apt-get install qt5-default

#C++ source code files are always compiled into binary code by a program called a "compiler" and then executed.
#A .o object file file (also .obj on Windows) contains compiled object code
#(that is, machine code produced by your C or C++ compiler),
#together with the names of the functions and other objects the file contains.
#Object files are processed by the linker to produce the final executable.
#If your build process has not produced these files,
#there is probably something wrong with your makefile/project files.
#object files are assembled to binary code in a format that is relocatable.
#This is a form which allows the assembled code
#to be loaded anywhere into memory for use with other programs by a linker.


#The different kinds of files
#Compiling C++ programs requires you to work with four kinds of files:

#Regular source code files.
#These files contain function definitions, and have names which end in ".cc" by convention (although sometimes you will see source code filenames which end in ".cpp" or ".C").

#Header files.
#These files contain class declarations, function declarations (also known as function prototypes) and various preprocessor statements (see below). They are used to allow source code files to access externally-defined classes and functions. Header files end in ".hh" or ".h" by convention.

#Object files.
#These files are produced as the output of the compiler. They consist of function definitions in binary form, but they are not executable by themselves. Object files end in ".o" by convention, although on some operating systems (Windows, MS-DOS), they often end in ".obj".

#Binary executables.
#These are produced as the output of a program called a "linker". The linker links together a number of object files to produce a binary file which can be directly executed. Binary executables have no special suffix on Unix operating systems, although they generally end in ".exe" on Windows.

#There are other kinds of files as well, notably libraries (".a" files) and shared libraries (".so" files),
#but you won't normally need to deal with them directly.

#The preprocessor

#Before the C++ compiler starts compiling a source code file, the file is processed by a preprocessor.
#This is a separate program (normally called "cpp", for "C preprocessor"),
#but it is invoked automatically by the compiler before compilation proper begins.
#Preprocessor commands start with the pound sign ("#"). There is really only one preprocessor command you need to know for this track:
##include. This is used to access function definitions defined outside of a source code file. For instance:
#    #include <iostream>
#causes the preprocessor to paste the contents of <iostream> into your source code file.
#include is almost always used to include header files. In this case, we use #include in order to be able to use the cin and cout objects (input/output streams),
#whose declarations are located in the file iostream.h. C++ compilers do not allow you to use a class, function or global object unless it has previously been declared or defined in that file; #include statements are thus the way to re-use previously-written code in your C++ programs. Note that, unlike C, you do not have to include the file extension of the header file in the #include statement.
#There are a number of other preprocessor commands as well, but we won't be needing them.
#In particular, C programmers should note that you should never use #define to define a constant! Instead, use const:
#    const int BIGNUM = 1000000;
#This is much safer, since the compiler can use the type information to check that BIGNUM is being used correctly.
#It's good to do this in C code as well.
