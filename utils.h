//When utils.h is included anywhere, everything in between the #ifndef and the #endif will be ignored
//if UTILS_H has been defined, which will happen on the first time it is included in the compilation unit.
//Header files aren’t passed to the compiler. Instead, they are included from source files.
//"if not defined" demek aslında. yani, "(zaten) tanımlanmamışsa" anlamına geliyor.
//header file'larin birkac kere include edildiginde olusabilecek problemleri ortadan kaldirmak icin

//Preprocessor Directive ifndef

#ifndef UTILS_H
#define UTILS_H
//directive
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <utility>
#include <mutex>
#include <stdexcept>
#include <deque>
#include <set>
#include <stack>
#include <queue>
#include <cmath>

//------------------------------------------------------------------>
//Preprocessors -> complier -> linker -> executable
//Preprocessors are programs that process our source code before compilation.
//Before the C++ compiler starts compiling a source code file, the file is processed by a preprocessor.
//This is a separate program (normally called "cpp", for "C preprocessor"),
//#include. This is used to access function definitions defined outside of a source code file. For instance:
//    #include <iostream>
//causes the preprocessor to paste the contents of <iostream> into your source code file.

//Linker
//Like the preprocessor, the linker is a separate program called ld. Also like the preprocessor,
//the linker is invoked automatically for you when you use the compiler.
//The normal way of using the linker is as follows:

//    g++ -Wall main.o -o oop

//This line tells the compiler to link together object files (main.o, etc) into a binary executable file

//------------------------------------------------------------------>
//Namespace - isim alanı
//C++ dilinde tüm blokların dışında kalan alan global isim alanı olarak adlandırılır.
//Global isim alanı, programı oluşturan tüm dosyaları dolayısıyla bütün alanları kapsar.
//Bu alanda bildirilen tüm varlıklar global bilinirlik alanının içindedir.
//namespace namespace_adı {
//... // bildirimler, tanımlamalar
//}
//namespace:İsim alanı tanımlaması namespace anahtar kelimesiyle başlar.
//namespace_adı:İsim alanının adıdır ve isimlendirme kurallarına uygun olarak programcı tarafından belirlenir.
//küme parantezleri:Küme parantezleri isim alnında kendi içinde tanımlanan varlıkları kapsayan bir alan tanımlar. Noktalı virgülle sonlanmaz.
// normalde direk bu şekilde kullanılması önerilmez, başka kütüphanedeki olabilecek isim çakışması sebebiyle
//C++ standard library.
using namespace std;

//------------------------------------------------------------------>

// any source file that includes this will be able to use "global_x"
extern int global_x;
// Declare the global variable using extern
extern int globalVariable;

// Template Metaprogramming
// Templates are expanded at compiler time. This is like macros.
// The difference is, the compiler does type checking before template expansion.
// The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.
// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
// Container classes (vector, list, map) are all templated.
// complier internaly generates and adds true type

template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

// funStruct yapısı, bilinen herhangi bir n (veya sabit n) için 2^n'yi hesaplamak için kullanılabilir.
template<int n> struct funStruct
{
    enum { val = 2*funStruct<n-1>::val };
};

template<> struct funStruct<0>
{
    enum { val = 1 };
};

void test_templates()
{
    cout << "\nTesting templates : \n" << endl;
    cout << "Call myMax for int 3 , 7 : " << myMax<int>(3, 7) << endl; // Call myMax for int
    cout << "Call myMax for double 3.0 , 7.0 : " << myMax<double>(3.0, 7.0) << endl; // Call myMax for double
    cout << "Call myMax for char : 'g', 'e' : " << myMax<char>('g', 'e') << endl; // Call myMax for char
    cout << "2 nin sekizinci kuvveti : " << funStruct<8>::val << endl;
}

// Satır içi (inline) Fonksiyonu

// inline belirtecini fonksiyonun geri dönüş tipinin önüne yerleştirmek derleyiciye; o fonksiyon derleyiciye fonksiyonun çağrısı yerine,
// fonksiyonun kullanıldığı yerde yaratılmasını “tavsiye eder”.

// İnline belirteci sadece küçük ve sık kullanılan fonksiyonlar için kullanılmalıdır.
// Nedeni; inline fonksiyonun kullanıldığı yere kopyalanmasını sağladığı için programın boyutunu artırır ve yavaşlamasına neden olur.


// is explicit inline
inline int fonk_inline(int a, int b)
{
    return (a + b)*(a + b) ;
}

#define MULT(x, y) ((x)+(y)) * ((x)+(y))


// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

//There are different preprocessor directives that perform different tasks. You can categorize these Preprocessor Directives as follows:

//Inclusion Directives:
//#include: specifies the files to be included, especially header-files
//Macro Definition Directives:
//#define: define a macro substitution
//#undef: It is used for undefining a macro
//Conditional Compilation Directives:
//#if: It tests a compile-time condition
//#elif
//#endif: It specifies the end of #if
//#ifdef: It is used to test for macro definition
//#ifndef: It tests whether a macro is not defined
//#else: It provides an alternative option when #if fails
//Other Directives:
//#error
//#line: Supplies a line number for compiler messages
//#pragma: It specifies implementation-defined instructions to the compiler

//pre-increment and post-increment.  a  =b++;   means first assign  b  to  a , then increment value of  b  by  1 .  a=++b;  means first increment  b  by  1 , then assign the result to  a .
#endif // UTILS_H
