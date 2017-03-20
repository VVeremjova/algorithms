#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;


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
