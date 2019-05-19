
#include <iostream>
#include <math.h>
#include <bitset>
#include <string>
namespace itertools{
template <typename T> 
class powerset{

    private:
    T subset_range;
  public:
	powerset (T a):subset_range(a) {}
	
	class iterator {

	  private:
        int counter;
        decltype(subset_range) my_subset_range;
        decltype(subset_range.begin()) iterCurr;
	
	  public:

		iterator(T subset_range)
			:counter(0),my_subset_range(subset_range), iterCurr(subset_range.begin()){};
		
		iterator(T subset_range,bool)
			 :counter(pow(2,subset_range.size())),my_subset_range(subset_range),iterCurr(subset_range.begin()){
             }

        std::string operator*(){
            std::string binaryCounter(dec2BinaryString(counter,my_subset_range.size()));
            std::string result("{");
            int index = binaryCounter.size()-1;
            while (iterCurr!=my_subset_range.end()){
                if (binaryCounter.at(index)=='1')
                   // result=result + std::to_string(*iterCurr)+",";
                   add2String(result,*iterCurr);
                ++iterCurr;
                --index;
            }
            if (result.size()>1)result.erase(result.end()-1);
            result+="}";
            return result;
        }
		// ++i;
		iterator& operator++() {
           counter++;
           iterCurr = my_subset_range.begin();
		return *this;
		}

		bool operator!=(iterator& other){
			return (my_subset_range.begin() != other.my_subset_range.begin()) || 
            (my_subset_range.end() != other.my_subset_range.end())||
            (counter!=other.counter);
		}

      private:
        std::string dec2BinaryString(int counter,int size){
            std::string result ="";
            while (counter!=0){
                int bit = counter%2;
                result = std::to_string(bit) + result;
                counter /=2;
            }
            while (result.size()<size)
                result="0"+result;
            return result;
        }
        template <typename S> void add2String(std::string& str,S something_to_add){
            str = str + std::to_string(*iterCurr)+",";
        }
        void add2String(std::string& str,char char_to_add){
            str = str + (*iterCurr)+",";
        }
	};  // END OF CLASS ITERATOR

	iterator begin() {
		return iterator{subset_range};
	}
	
	iterator end() {
		return iterator{subset_range,false};
	}


};
}