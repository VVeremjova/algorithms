#include <iostream>
#include <vector>

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

//int binary_search(const std::vector<int>& A, int key, int first = -1, int last = -1) {

//   if (first==-1) {
//       first = 0;
//   }
//   if (last = -1) {
//       last = size;
//   }

//   int i = (last - first)/2 +1;
//      cout<<"i ="<<i<<endl;
//   for (; i< A.size; ++i) {
//       if (A[i]==key) {
////           cout<<"Stop here \n";
//           return i;
//       }
//       if (first == last)
//       {
//           cout<<"Element wasn't found"<<endl;
//           return -1;
//       }
//       if(key < A[i]) {

//           last = i;
//           cout<<"left "<<first<<",element: "<<A[i]<<", right = "<<last<<endl;

//           return binary_search(A, i, key, first, last);
//       }
//       if(key >A[i]) {

//         first = i+1;
//          cout<<"left "<<first<<",element: "<<A[i]<<", right = "<<last<<endl;
//         return  binary_search(A, size, key, first, last);
//       }
//   }
//   return -1;
//}

//void test_suit1() {

//    int A[]={2,4,6,7,8,11,24,56,78,80};
//    //cout<<naive_search(A,10,24)<<'\n';
//    cout<<binary_search(A,10,24)<<'\n';
//}

//void test_suit4() {

//    int A[]={2,4,6};
//    //cout<<naive_search(A,10,24)<<'\n';
//    cout<<binary_search(A,3,2)<<'\n';
//}

//void test(expect, f, params) {
//    auto got(f(params));
//    if (got ~= expect) {
//        cerr<< "Failed: expected" << expect<<" != actual" << got <<endl;
//    }
//}

template <class T>
ostream & operator << (ostream&o ,const  vector<T>&v) {
    o<<"[";
    for (auto& x:v) {
        o<< x<< ", " ;
    }
}

template <class TFunc, class TResult, class TParam1>
void test(TResult expect, TFunc f, TParam1 params) {
    auto got= f(params);
    if (got != expect) {
        cerr<< "Failed: f(" << params<< "," << expect<<" != actual" << got <<endl;
    }
}

//template <class TFunc, class TResult, class TParam1, class TParam2>
//void test(TResult expect, TFunc f, TParam1 params, TParam2 p2) {
//    auto got= f(params);
//    if (got ~= expect) {
//        cerr<< "Failed: expected" << expect<<" != actual" << got <<endl;
//    }
//}

void test_search() {
    typedef vector<int> Arr;
    test (8, naive_search_1, Arr({0,1,2,3,4,5,7,8}));
}

void test_suit5() {

//    int A[]={2,4,6};
    //cout<<naive_search(A,10,24)<<'\n';
//    cout<<binary_search(A,3,4)<<'\n';
    std::vector<int> A;
    A.push_back(2);
    A.push_back(4);
    A.push_back(6);
    cout<<naive_search_0(A,4)<<'\n';
}



//void test_suit6() {

//    int A[]={2,4,6};
//    //cout<<naive_search(A,10,24)<<'\n';
//    cout<<binary_search(A,3,6)<<'\n';
//}
int main(int argc, char *argv[])
{
//    cout << "1st test" << endl;
//     test_suit1();
//     cout <<"2nd test:" << endl;
//    test_suit2();
//    cout <<"3rd test:" << endl;
//     test_suit3();

    cout << "1st test" << endl;
//     test_suit4();
     cout <<"2nd test:" << endl;
    test_suit5();
    cout <<"3rd test:" << endl;
//     test_suit6();
    return 0;
}
