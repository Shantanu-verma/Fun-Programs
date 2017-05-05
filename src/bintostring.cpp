#include <iostream>
#include <math.h>
#include <bitset>
#include <array>

// For Changing CharBits
#define BITS 8

char chfun(const std::string& test){
	int s = 0;
	for (int i = test.length()-1,j=0; i >= 0; --i)
		s += (test[i]-'0')*pow(2,j++);
	return s;
}
std::string convert(const std::string& input){
	std::string answer;
	for(int i = 0 ; i < input.length() ; i += 8)
		answer += chfun(input.substr(i,BITS));
	return answer;
}
int main(){
	// Write Your Name Chars
	std::array<std::bitset<BITS>,8> t{'S','H','A','N','T','A','N','U'};
	std::string tobin;
	// Use bitset to binary string
	for(const auto& i: t) tobin += i.to_string();
	std::cout<<" SHANTANU in Binary ( Using Bitset ) : "<<tobin;
	std::cout<<"\n Reverse To string By Manual Conversion : "<<convert(tobin);
	std::cin.get();
}
