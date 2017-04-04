
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <iterator>

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
Iter upper_bound_2(Iter first, Iter last, const ParamType &key) {
    while (first<last) {
        Iter m = first + (last-first)/2;
        if ( key <*m) {
             last = m;

        }
        else {
            first = m+1;
        }
    }
    return first;
}

template <class Iter, class ParamType>

Iter binary_search_3(Iter first, Iter last, const ParamType &key) {
    Iter v = lower_bound_1(first, last, key);
    return (v!=last) && !(key < *v ) ? v : last;
}

template <class Iter, class ParamType>
Iter binary_search_4(Iter first, Iter last, const ParamType &key) {
    Iter v = upper_bound_2(first, last, key);
    return (v!=last) && !(key >= *v ) ? v : last-1;
}

template <class TFunc, class TResult, class TParam1 >
void test(TResult expect, TFunc f, TParam1 param1) {
    auto got= f(param1);
    if (got != expect) {
        cerr<< "Failed! \n"; //<<" expected: " << expect<<", actual: " << got <<endl;
    }
    else {
        cout<<"Test passed!" <<endl;
    }
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

template <class TFunc, class TResult, class TParam1>
void test1(TResult expect, TFunc f, TParam1 param1) {
    auto got= f(param1);
    if (got != expect) {
        cerr<< "Failed:" <<" expected: " << expect<<", actual: " << got <<endl;
    }
    else {
        cout<<"Test passed!" <<endl;
    }
}

namespace   {

template <class ParamType>
ParamType min_element1(ParamType b, ParamType e) {
    auto result = b;
    while (b < e) {
        if (*b < *result ) {
            result =b;
        }
        ++b;
    }
   return result;
}

}

template <class TIter>
void naive_sort(TIter b, TIter e) {
    for (auto i=b; i<e; ++i) {
        assert(is_sorted(b,i));
        // [sorted) U [unsorted) = [b,i)U  [i,e)
        for (auto j = i+1; j<e; ++j) {
            // [unsorted) = [i] U [i+1,j) U [j, e)
            assert(min_element1(i,j) == i);
            if (*j<*i)
                swap(*i,*j);
            assert(min_element1(i,j) == i);
        }
        assert(is_sorted(b,i+1));
    }
}

template <class TIter>
void selection_sort(TIter b, TIter e) {
    for (auto i=b; i<e; ++i) {
        // [sorted) U [unsorted) = [b,i)U  [i,e)
        assert(is_sorted(b,i));
        swap( *i, *min_element1(i,e));
        assert(is_sorted(b,i+1));
    }
}

template <class TIter>
void bubble_sort(TIter b, TIter e) {
//    for (auto i=b; i<e; ++i) {
//     // [unsorted) U [sorted) = [b,i)U  [i,e)
//        auto sorted_begin = e-(i-b)-1;
//        assert(sorted_begin<e);
//        assert (is_sorted(sorted_begin,e));
//        for (auto j = b; j<sorted_begin; ++j) {
//            //assert(max_element(b,j) == j);
//            if (*(j+1)<*j)
//                std::iter_swap(j+1,j);
////            assert(max_element(b,j) == j);
//        }
//    }

    if (b==e) {
        return;
    }
    auto sorted_begin = e-1;
    while (b<sorted_begin) {
        assert(sorted_begin<e);
        assert (is_sorted(sorted_begin,e));

        auto j = b;
        while (j<sorted_begin) {
            if (*(j+1)<*j)
                std::iter_swap(j+1,j);
             ++j;
        }

        --sorted_begin;
        assert(is_sorted(sorted_begin,e));
    }
}


//template <class TIter>
//void insert_search(TIter b, TIter e) {
//    if (b==e) {
//        return;
//    }

//    auto pivot =b+1;
//    while(pivot<e) {
//        // [sorted) U [unsorted) = [b, pivot) U [pivot) U [pivot, unsorted)
//        assert(is_sorted(b,pivot));
//        auto i =pivot;
//        while (b<i && *(i)<*(i-1)) {
//            assert(is_sorted(b,i));
//            assert(is_sorted(i, pivot));

//            std::iter_swap(i,i-1);
//            --i;
//            assert(is_sorted(b,i));
//            assert(is_sorted(i, pivot));
//        }

//        pivot++;
//        assert(is_sorted(b,pivot));

//    }
//}

template <class TIter>
void merge(TIter b, TIter m, TIter e, TIter buff)  {
    const auto size = e-b;
    const auto old = buff;
    const auto e1 = m;
    while(b<e1 && m<e) {
        //[sorted) U [sorted)
        *buff++ = *b<*m ? *b++ : *m++;
    }
    buff = copy(b,e1,buff);
    buff = copy(m,e,buff);
    assert(buff-old ==size);
}

template <class TIter>
void merge_sort_outer(TIter b, TIter e, TIter buff)  {

    auto size = e-b;
    if (size >1) {
        auto m = b+(e-b)/2;
        merge_sort_outer(b,m,buff);
        merge_sort_outer(m,e,buff+(size)/2);
        copy(buff,buff+size,b);
        merge(b, m, e, buff);
    } else {
        copy(b,e,buff);
    }
}

template <class TIter>
void merge_sort_wrapper(TIter b, TIter e)  {
   auto size = e-b;
   vector<int> buff(size);
   merge_sort_outer<TIter>(b,e,buff.begin());
   copy(buff.begin(), buff.end(), b);
}

template <class TIter>
TIter partition1(TIter b, TIter p, TIter e)  {
    assert(b<e);
    auto pivot= *p;

    swap(*(e-1), *p);
    auto ub = b;
    auto ue = e-1;

    //assert [b ub)<[ub, eb] < (ue, e]

    while (ub <ue) {
        if (*ub <pivot) {
            ++ub;
        }
        else {
            --ue;
            swap(*ub,*ue);
        }
    }
    swap(*ub,*(e-1));
    return ub;
}

template <class TIter>
TIter partition2(TIter b, TIter p, TIter e)  {
    assert(b<e);
    auto pivot= *p;
    iter_swap(e-1,p);
    auto b2 = b;
    auto e2 = b;

    //assert [b b2) [b2, e2)  [(]e2, e)
    //assert [<p) [p <= )  ( unpr)

    while (e2+1 <e) {
        if (*e2 <pivot) {
            swap(*b2, *e2);
            ++b2;
        }
        ++e2;
    }
    iter_swap(e-1,b2);
    return b2;
}

template <class TIter>
TIter pivot_strategy(TIter b, TIter e)  {
    assert(b<e);
    auto m = b+(e-b)/2;
    auto last =e-1;

    if (*m <*b ) swap(b,m);
    if (*last <*m ) swap(last,m);
    if (*m <*b ) swap(b,m);
    cout<<*m<<endl;
    return m;

}

template <class TIter>
void quick_sort(TIter b, TIter e)  {
  if (e-b <2) {
      return;
  }
  //auto p = select_pivot();
  auto p = partition2(b,pivot_strategy(b, e),e);
  //assert(*max(b,p) <= *p && p < *min(p+1,e));
  quick_sort(b,p);
  quick_sort(p+1,e);
}

int main()
{
    typedef std::vector<int> Array;
        auto sort = [](vector<int>&v) {
            quick_sort(v.begin(),v.end());

            for (vector<int>::iterator i=v.begin(); i<v.end(); i++) {
                cout<< *i<<" ";
            }
            cout<<endl;
            return v;
        };

//      test(Array(), sort, Array());
      test(Array({1}), sort, Array({1}));
      test(Array({1,2}), sort, Array({1,2}));
      test(Array({1,2}), sort, Array({2,1}));
      test(Array({1,1}), sort, Array({1,1}));

      test(Array({1,1, 1}), sort, Array({1,1,1}));
      test(Array({1,2, 3}), sort, Array({1,2,3}));
      test(Array({1,2, 3}), sort, Array({1,3,2}));
      test(Array({1,2, 3}), sort, Array({3,2,1}));
      test(Array({1,2, 3}), sort, Array({2,3,1}));

      test(Array({3,4,5,5}), sort, Array({5,4,3,5}));

      test(Array({0,1,3,5,8}), sort, Array({3,1,8,5,0}));
      test(Array({1,4,5,6,7,8}), sort, Array({5,7,8,1,6,4}));

      test(Array({1,2, 3, 4, 5,6,7,8}), sort, Array({8,6,5,2,1,4,3,7}));

    return 0;

}

