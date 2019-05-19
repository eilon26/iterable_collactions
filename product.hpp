#include <iostream>

namespace itertools{
template <typename T1,typename T2> 
class product{

    private:
    T1 first;
    T2 second;
  public:
	product (const T1& a, const T2& b):first(a), second(b) {}
	
	class iterator {

	  private:
		decltype(first.begin()) iter1Begin;
		decltype(first.begin())  iter1End;
		decltype(second.begin()) iter2Begin;
		decltype(second.begin())  iter2End;
        const decltype(second.begin()) const_iter2Begin;
	  public:

		iterator(T1& a, T2& b)
			: iter1Begin(a.begin()), iter1End(a.end()) ,iter2Begin(b.begin()),const_iter2Begin(b.begin()), iter2End(b.end()) {}
		
		iterator(T1& a, T2& b,bool)
			: iter1Begin(a.end()), iter1End(a.end()) ,iter2Begin(b.end()),const_iter2Begin(b.begin()), iter2End(b.end()) {}

		std::pair<decltype(*iter1Begin),decltype(*iter2Begin)> operator*() const {
            return std::pair<decltype(*iter1Begin),decltype(*iter2Begin)>(*iter1Begin, *iter2Begin);
		}

		// ++i;
		iterator& operator++() {
            if ((!(++iter2Begin!=iter2End))&&(++iter1Begin!=iter1End)){
                iter2Begin = const_iter2Begin;
            }
		return *this;
		}

		bool operator!=(const iterator& other) const {
			return (iter1Begin != other.iter1Begin) || (iter2Begin!=other.iter2Begin)
            ||(iter1End != other.iter1End) || (iter2End!=other.iter2End)||(const_iter2Begin!=other.const_iter2Begin);
		}
	};  // END OF CLASS ITERATOR

	iterator begin() {
		return iterator{first,second};
	}
	
	iterator end() {
		return iterator{first,second,false};
	}
};
}