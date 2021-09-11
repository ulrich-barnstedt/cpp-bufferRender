#pragma once
#include <string>
#include <ostream>
#include <iostream>

namespace strLib::internal {
    inline std::string __NO_DEF__GLOBAL__("__STR/NO-DEF__GLOBALVAR");
    inline std::string __EMPTY__(" ");

    class DataObj {
        public:
            DataObj () : l1(&__NO_DEF__GLOBAL__), l2(&__NO_DEF__GLOBAL__) {};
            DataObj (const DataObj &cpy) : l1(cpy.l1), l2(cpy.l2) {};
            ~DataObj () {
                tryDel(l1);
                tryDel(l2);
            }
            void update (std::string *next) {
                tryDel(l2);

                l2 = l1;
                l1 = next;
            }
            [[nodiscard]] bool diff () const { return *l1 != *l2; } // std::cout << "\"" << *l1 << "\"vs\"" << *l2 << "\"";
            [[nodiscard]] std::string *val () { return l1 != &__NO_DEF__GLOBAL__ ? l1 : &__EMPTY__; }

            friend std::ostream &operator<<(std::ostream &os, const DataObj &obj) {
                os << "{<DataObj> :: " << "l1: \"" << *obj.l1 << "\", l2: \"" << *obj.l2 << "\"}";
                return os;
            }

        private:
            void tryDel(std::string *ptr) {
                if (ptr == &__EMPTY__ || ptr == &__NO_DEF__GLOBAL__) return;
                delete ptr;
            }
            std::string *l1;
            std::string *l2;
    };

    template <typename T> class vector2 : public std::vector<T> {
        public:
            /*using internalType = T;

            void forEach (const std::function<void(T&, int)> &fn) {
                for (int i = 0; i < this->size(); i++)
                    fn(this[i], i);
            }*/

            /*template <typename R> void d2forEach (const std::function<void(R&, int, int)> &fn) {
                for (int i = 0; i < this->size(); i++)
                    for (int j = 0; j < this[i].size(); j++)
                        fn(this[i][j], i, j);
            }*/

            /*template <typename R> void d2forEach (const std::function<void(R&, int, int)> &fn) {
                forEach([fn](T& ref, int i){
                    ref.forEach([fn, i](R& ref2, int j){
                        fn(static_cast<R>(ref2), i, j);
                    });
                });
            }*/

            /*template <typename R> void d2forEach (const std::function<void(R&, int, int)> &fn) {
                for(auto& row:this){
                    for(auto& col:row){
                        fn(row);
                    }
                }
            }*/

            friend std::ostream &operator<<(std::ostream &os, const vector2 &vec) {
                os << "<" << typeid(T).name() << ">[";
                for (int i = 0; i < vec.size(); i++) os << vec[i] << ";";
                os << "]";

                return os;
            }
    };
}