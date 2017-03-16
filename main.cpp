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

int binary_search_1(const std::vector<int>& v, size_t begin, size_t end, int key) {
    assert(std::is_sorted(v.begin(), v.end()));

    if (begin == end) return -1;
    if ((end - begin) == 1) {
        if (v[begin] == key)
            return begin;
        else
            return -1;
    }

    size_t b = 0;
    size_t m = (begin+end)/2;
    // [b, e) = [b,m) U [m,e)

    if (key <v [m]) {
     return rl = binary_search_1(v, begin, m, key);
    }
    else if (v[m] <key) {
         return  binary_search_1(v, m, end, key);
    }
     else {
        return m;
    }

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


template <int N>
void test_suit();


//template <>
//void test_suit<0>() {

//    // Not exists
//    typedef vector<int> Array;
//    auto key = 8;
//    //degenerate
//    test(-1, naive_search_0, Array(), key);
//    test(-1, naive_search_0, Array({key-1}), key);
//    test(-1, naive_search_0, Array({key-1, key+1}), key);
//    test(-1, naive_search_0, Array({1, 2, 3, 4, ,5, 7}), key);
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

//}
//template <>
//void test_suit<0>() {

//    //degenerate
//    std::vector<int> A={2,4,6,7,8,11,24,56,78,80};
//    test(3, naive_search_0, A, 7);
//    test(3, binary_search_0, A, 7, -1, -1);
//}

template <>
void test_suit<1>() {
    //trivial
    std::vector<int> A={2,4,6,7,8,11,24,56,78,80};
    test(6, naive_search_0, A, 24);
    test(6, binary_search_0, A, 24, -1, -1);
}


template <>
void test_suit<2>() {
    //trivial-2
    std::vector<int> A ={2,4,6};
    test(0, naive_search_0, A, 2);
    test(0, binary_search_0, A, 2, -1, -1);
}

template <>
void test_suit<3>() {
    //general
    std::vector<int> A = {2, 4, 6};
    test(1, naive_search_0, A, 4);
    test(1, binary_search_0, A, 4, -1, -1);
}



template <>
void test_suit<4>() {
    std::vector<int> A ={2,4,6};
    test(2, naive_search_0, A, 6);
    test(2, binary_search_0, A, 6, -1, -1);
}


template <>
void test_suit<5>() {
    std::vector<int> A ={2,4};
    test(1, naive_search_0, A, 4);
    test(1, binary_search_0, A, 4, -1, -1);
}



template <>
void test_suit<6>() {
    std::vector<int> A ={2,4};
    test(-1, naive_search_0, A, 3);
    test(-1, binary_search_0, A, 3, -1, -1);
}


//template <int N>
//void check_tests();

//template <>
//void check_tests<0>()
//{
//    cout<<"Test #0"<<endl;
//    test_suit<0>();
//}

//template <int N>
//void check_tests()
//{
//  cout<<"Test #"<<N<<endl;
//  test_suit<N>();
//  check_tests<N - 1>();
//};

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
    test(-1, naive_search_0, Array(), key);
    test(-1, naive_search_0, Array({key-1}), key);
    test(-1, naive_search_0, Array({key-1, key+1}), key);
    test(-1, naive_search_0, Array({1, 2, 3, 4, 5, 7}), key);
    test(-1, naive_search_0, Array({9, 10, 11, 12}), key);
    test(-1, naive_search_0, Array({4, 1, 2, 7, 10}), key);


    //key exists
    test(0, naive_search_0, Array({key}), key);
    test(0, naive_search_0, Array({key, key+1}), key);
    test(1, naive_search_0, Array({key-1, key}), key);
    test(7, naive_search_0, Array({0, 1, 2, 3, 4, 5, 7, key}), key);
    test(0, naive_search_0, Array({key, 9, 10, 11, 12}), key);
    test(2, naive_search_0, Array({4, 1, key, 2, 7, 10}), key);

    test(0, naive_search_0, Array({key, 1, key, 10, 11, 12}), key);
    test(2, naive_search_0, Array({4, 1, key, 2,key, 7, 10}), key);
    return 0;
}
