#pragma once
namespace itertools{
template <typename T> 
class range{
 private:
	T start,finnish;
 public:
	range (T a, T b):start(a), finnish(b) {}
	/*range (const range& other){
		start = other.start;
		finnish = other.finnish;
	}*/
	class iterator {

	  private:
		T _pointer;

	  public:

		iterator(T ptr = nullptr)
			: _pointer(ptr) {
		}

		T& operator*() {
			return _pointer;
		}

		//T* operator->() const {
		//	return &(m_pointer->m_value);
		//}

		// ++i;
		iterator& operator++() {
			_pointer += 1;
			return *this;
		}

		// i++;
		// Usually iterators are passed by value and not by const& as they are small.
		// const iterator operator++(int) {
		// 	iterator tmp= *this;
		// 	*_pointer += 1;
		// 	return tmp;
		// }

		// bool operator==(const iterator& other) const {
		// 	return *_pointer == *(other._pointer);
		// }

		bool operator!=(const iterator& other) const {
			return _pointer != other._pointer;
		}
	};  // END OF CLASS ITERATOR

	iterator begin() const {
		return iterator{start};
	}
	
	iterator end() const {
		return iterator{finnish};
	}

	unsigned int size() const{
		return int(finnish)-int(start);
	}
};
}