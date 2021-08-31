#include <iostream>
#include <vector>

using namespace std;

// Create metafunction
template <class T>
struct TypeDecider
{
    using inType = T;
    using outType = string;
};

template <>
struct TypeDecider<int>
{
    using inType = int;
    using outType = string;
};

template <>
struct TypeDecider<double>
{
    using inType = double;
    using outType = char;
};
// end of metafunction

// A class example created using meta function TypeDecider
template <class T>
class App
{
public:
    typename TypeDecider<T>::outType m;
};

// A function example using the metafunction, TypeDecider.
// We also, use if constexpr() to decide types within function body.
template <class T>
void f(vector<T> v)
{
    typename TypeDecider<T>::outType x;
    cout << x.size()<<"\n";

    // deciding the type and do stuff
    // Note this is a compile-time if,
    // so if a condition is not met, the
    // subsequent lines won't be in the 
    // compiled program.
    if constexpr (is_same<T, int>::value)
        cout << "type is int\n";
}

int main()
{
    App<double> app1; // has member => char m
    App<int> app2; // has member => string m

    vector<int> v1; // has local variable => string x
    f(v1);

    vector<double> v2;
    //f(v2); this will give error because char doesn't have function size().

}
