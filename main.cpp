#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>


#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
template <class Iter, class ParamType>

Iter lower_bound_1(Iter first, Iter last, const ParamType &key) {
    while (first<last) {
        Iter m = first + (last-first)/2;
        if ( *m <key ) {
            first = m+1;
        }
        else {
            last = m;
        }
    }
    return first;
}

template <class Iter, class ParamType>

Iter upper_bound_1(Iter first, Iter last, const ParamType &key) {
    // [a,b) = [a,m)U[m]U(m,b)
    while (first<last) {
        Iter m = first + (last-first)/2;
        if ( key >= *m ) { //  or (!(key<m))
            //[a, m+1)U[m+1,key,last)
            first = m+1;
        }
        else {
            last = m;
        }
    }
    return last;
}

template <class Iter, class ParamType>

Iter binary_search_3(Iter first, Iter last, const ParamType &key) {
    Iter v = lower_bound_1(first, last, key);
    return (v!=last) && !(key < *v ) ? v : last;
}

template <class Iter, class ParamType>

Iter binary_search_4(Iter first, Iter last, const ParamType &key) {
    Iter v = upper_bound_1(first, last, key);
    return (v!=last) && !(key >= *v ) ? v : last-1;
}

template <class TFunc, class TResult, class TParam1,  class TParam2 >

void test(TResult expect, TFunc f, TParam1 param1,  TParam2 param2) {

    auto got= f(param1, param2);

    if (got != expect) {

        cerr<< "Failed:" <<" expected: " << expect<<", actual: " << got <<endl;

    }

    else {

        cout<<"Test passed!" <<endl;

    }

}

int main()
{
    typedef std::vector<int> Array;
    auto search = [](const vector<int>&v, int key) {
        auto r = binary_search_3(v.begin(),v.end(),key);
        return r!= v.end()? r-v.begin() :-1;
    };

    auto search2 = [](const vector<int>&v, int key) {
        auto r = binary_search_4(v.begin(),v.end(),key);
        return r!= v.end()? r-v.begin() : -1;
    };

    auto key = 8;
  //  Array a ({key-1});
   // Array::iterator i =  upper_bound_1(a.begin(), a.end(), key);
   // cout<< i-a.begin() <<endl;

    //Array::iterator i2 =  binary_search_3(a.begin(), a.end(), key);
   //  cout<< i2-a.begin() <<endl;
    // test cases:
    /*key exists
     * degenerate - not exists
     * trivial
     * trivial-2
     * general
     *
     * key not exists
     * degenerate
     * trivial
     * trivial-2
     * general
     */

   // test(-1, search, Array(), key);
    //key exists

    test(0, search, Array({key}), key);
    test(0, search, Array({key, key+1}), key);
    test(1, search, Array({key-1, key}), key);
    test(2, search, Array({key-2, key-1,key}), key);
    test(8, search, Array({0,1,2,3,4,5,6,7,key}), key);
    test(0, search, Array({key, 9, 10, 11, 12}), key);
    test(2, search, Array({2,4, key, 11, 12}), key);
    test(0, search, Array({key, key, key+1, key+2}), key);
    test(2, search, Array({key-2, key-1, key, key+2}), key);
    test(2, search, Array({1, 7, key, key}), key);

    // key not exists
    cout<<"==== key not exists"<<endl;
    test(-1, search, Array(), key);
    test(-1, search, Array({key-1}), key);
    test(-1, search, Array({key+1}), key);
    test(-1, search, Array({key-2, key-1}), key);
    test(-1, search, Array({key+1, key+2}), key);
    test(-1, search, Array({key-1, key+1}), key);
    test(-1, search, Array({1,2,3,4,5,6,7}), key);
    test(-1, search, Array({9,10,11,12}), key);

//    // key not exists

    cout<<"==== key not exists - for upperbound search"<<endl;
    test(-1, search2, Array(), key);
    test(0, search2, Array({key-1}), key);
    test(0, search2, Array({key+1}), key);
    test(1, search2, Array({key-2, key-1}), key);
    test(0, search2, Array({key+1, key+2}), key);
    test(1, search2, Array({key-1, key+1}), key);
    test(6, search2, Array({1,2,3,4,5,6,7}), key);
    test(0, search2, Array({9,10,11,12}), key);

    //key exists

    cout<<"==== key exists - for upperbound search"<<endl;
    test(0, search2, Array({key}), key);
    test(1, search2, Array({key, key+1}), key);
    test(1, search2, Array({key-1, key}), key);
    test(2, search2, Array({key-2, key-1,key}), key);
    test(8, search2, Array({0,1,2,3,4,5,6,7,key}), key);
    test(1, search2, Array({key, 9, 10, 11, 12}), key);
    test(3, search2, Array({2,4, key, 11, 12}), key);
    test(2, search2, Array({key, key, key+1, key+2}), key);
    test(3, search2, Array({key-2, key-1, key, key+2}), key);
    test(3, search2, Array({1, 7, key, key}), key);
    test(4, search2, Array({1, 7, key, key, 10}), key);

    return 0;

}
