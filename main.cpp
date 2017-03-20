#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

int naive_search_0(const std::vector<int>& v, int key) {

   for (int i = 0; i<v.size(); ++i) {
       if (v[i] == key) {
           return i;
       }
   }
   return -1;
}

int naive_search_1(std::vector<int>& v, int key) {
   v.push_back(key);
   int i =0;
   while (v[i] != key) {
        ++i;
   }
   v.pop_back();
   if (i!=v.size()) {
       return i;
   }
   return -1;
}

int binary_search_0(const std::vector<int>& A, int key, int first = -1, int last = -1) {

   if (first==-1) {
       first = 0;
   }
   if (last == -1) {
       last = A.size();
   }
   int i = (last + first)/2;

   for (; i< A.size(); ++i) {
       if (A[i]==key) {
           return i;
       }
       if (first == last)
       {
           cout<<"Element wasn't found"<<endl;
           return -1;
       }
       if(key < A[i]) {
         last = i-1;
        // cout<<"left "<<first<<",element: "<<A[i]<<", right = "<<last<<endl;

           return binary_search_0(A,  key, first, last);
       }
       if(key >A[i]) {
         first = i+1;
        // cout<<"left "<<first<<",element: "<<A[i]<<", right = "<<last<<endl;
         return  binary_search_0(A, key, first, last);
       }
   }
   return -1;
}

int binary_search_1(const std::vector<int>& v, size_t begin, size_t end, int key //, size_t depth=0
                    ) {
    //assert(depth <1000)
    assert(std::is_sorted(v.begin(), v.end()));
    if(begin<end){
        size_t m = begin+ (end-begin)/2;
        // [b, e) = [b,m) U[m] U [m+1,e)
        if (key <v [m]) {
         return  binary_search_1(v, begin, m, key);
        }
        else if (v[m] <key) {
             return  binary_search_1(v, m+1, end, key);
        }
         else {
            return m;
        }
    }
    return -1;
}

int binary_search_2(const std::vector<int>& v, int key) {
    assert(std::is_sorted(v.begin(), v.end()));
    size_t begin = 0;
    size_t end = v.size();
    while (begin<end) {
        size_t m = (begin+end)/2;
        // [b, e) = [b,m) U[m] U [m+1,e)
        if (key <v [m]) {
            end = m;
        }
        else if (v[m] <key) {
             begin = m+1;
        }
         else {
            return m;
        }
    }
    return -1;

}

template <class TFunc, class TResult, class TParam1, class TParam2>
void test(TResult expect, TFunc f, TParam1 param1,  TParam2 param2) {
    auto got= f(param1, param2);
    if (got != expect) {
        cerr<< "Failed:" <<" expected: " << expect<<", actual: " << got <<endl;
    }
    else {
        cout<<"Test passed!" <<endl;
    }
}


template <class TFunc, class TResult, class TParam1, class TParam2, class TParam3>
void test(TResult expect, TFunc f, TParam1 param1,  TParam2 param2, TParam3 param3, TParam3 param4) {
    auto got= f(param1, param2, param3, param4);
    if (got != expect) {
        cerr<< "Failed:" <<" expected: " << expect<<", actual: " << got <<endl;
    }
    else {
        cout<<"Test passed!" <<endl;
    }
}


int main(int argc, char *argv[])
{
//    check_tests<6>();



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

    typedef std::vector<int> Array;
       auto key = 8;
//    test(-1, naive_search_0, Array(), key);
//    test(-1, naive_search_0, Array({key-1}), key);
//    test(-1, naive_search_0, Array({key-1, key+1}), key);
//    test(-1, naive_search_0, Array({1, 2, 3, 4, 5, 7}), key);
//    test(-1, naive_search_0, Array({9, 10, 11, 12}), key);
//    test(-1, naive_search_0, Array({4, 1, 2, 7, 10}), key);


//    //key exists
//    test(0, naive_search_0, Array({key}), key);
//    test(0, naive_search_0, Array({key, key+1}), key);
//    test(1, naive_search_0, Array({key-1, key}), key);
//    test(7, naive_search_0, Array({0, 1, 2, 3, 4, 5, 7, key}), key);
//    test(0, naive_search_0, Array({key, 9, 10, 11, 12}), key);
//    test(2, naive_search_0, Array({4, 1, key, 2, 7, 10}), key);

//    test(0, naive_search_0, Array({key, 1, key, 10, 11, 12}), key);
//    test(2, naive_search_0, Array({4, 1, key, 2,key, 7, 10}), key);


//    test(-1, binary_search_1, Array(), 0, 0, key); // const std::vector<int>& v, size_t begin, size_t end, int key);

//    test(-1, binary_search_1, Array({1, 2, 3, 4, 5, 7}), 0, 6, key);
//    test(0, binary_search_1, Array({key}),0, 1, key);
//    test(0, binary_search_1, Array({8, 9, 18}), 0, 3, key);
//    test(1, binary_search_1, Array({1, 8, 10}), 0, 3, key);
//    test(2, binary_search_1, Array({1, 2, 8}), 0, 3, key);

//    test(-1, binary_search_1, Array({1, 2, 3}), 0, 3, key);
//    test(-1, binary_search_1, Array({10, 20, 30}), 0, 3, key);

//    test(0, binary_search_1, Array({key, 9, 10, 11, 12}), 0, 5, key);
//    test(2, binary_search_1, Array({4, 5, key, 11, 17, 20}), 0, 6, key);



    test(-1, binary_search_2, Array(),  key); // const std::vector<int>& v, size_t begin, size_t end, int key);

    test(-1, binary_search_2, Array({1, 2, 3, 4, 5, 7}),  key);
    test(-1, binary_search_2, Array({key-1}),key);

    test(0, binary_search_2, Array({key}), key);
    test(0, binary_search_2, Array({key, key+1}), key);
    test(1, binary_search_2, Array({key-1, key}), key);
    test(0, binary_search_2, Array({8, 9, 18}),  key);
    test(1, binary_search_2, Array({1, 8, 10}),  key);
    test(2, binary_search_2, Array({1, 2, 8}),key);

    test(-1, binary_search_2, Array({1, 2, 3}), key);
    test(-1, binary_search_2, Array({10, 20, 30}), key);

    test(0, binary_search_2, Array({key, 9, 10, 11, 12}),  key);
    test(2, binary_search_2, Array({4, 5, key, 11, 17, 20}), key);

    test(3, binary_search_2, Array({4, 5,  6, key, 20}), key);

    return 0;
}
