

namespace itertools{
template <typename T1,typename T2> 
class chain{
  private:
    T1 first;
    T2 second;
  public:
	chain (const T1& a, const T2& b):first(a), second(b) {}
	
	class iterator {

	  private:
		decltype(first.begin()) iter1Begin;
		decltype(first.begin())  iter1End;
		decltype(second.begin()) iter2Begin;
		decltype(second.begin())  iter2End;

	  public:

		iterator(T1& a, T2& b)
			: iter1Begin(a.begin()), iter1End(a.end()) ,iter2Begin(b.begin()), iter2End(b.end()) {}
		
		iterator(decltype(first.begin())  start1,decltype(first.begin())  end1, decltype(second.begin())  start2,decltype(second.begin())  end2)
		:iter1Begin(start1), iter1End(end1) ,iter2Begin(start2), iter2End(end2)	{}

		auto& operator*() {
			if (iter1Begin !=iter1End) return *iter1Begin;
           		else return *iter2Begin;
		}

		// ++i;
		iterator& operator++() {
            if (iter1Begin !=iter1End)  ++iter1Begin;
            else ++iter2Begin;
		return *this;
		}

		bool operator!=(const iterator& other) const {
			return (iter1Begin != other.iter1Begin) || (iter2Begin!=other.iter2Begin)
			||(iter1End != other.iter1End) || (iter2End!=other.iter2End);
		}
	};  // END OF CLASS ITERATOR

	iterator begin()const {
		return iterator{first,second};
	}
	
	iterator end() const{
		return iterator{first.end(),first.end(),second.end(),second.end()};
	}
	unsigned int size() const{
		return first.size()+second.size();
	}
};
}