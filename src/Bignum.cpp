#include <iostream>
#include <vector>
#include <algorithm>

#define s_max(f,s)(f.size()>s.size() ? f:s)
#define s_min(f,s)(f.size()<s.size() ? f:s)

std::string add(const std::string& f,const std::string& s){
  std::string result;
  int c{ 0 };
  const auto& max = s_max(f,s);
  const auto& min = s_min(f,s);
  const std::size_t mxl{max.size()};
  const std::size_t mnl{min.size()};
  for(int i = 0;i < mxl; ++i){
  const char &fd = i + 1 > mnl? '0':min[mnl-1-i];
  const char &sd = max[mxl-1-i];
  int n = (fd -'0') + (sd - '0') + c;
  result += (n % 10 + '0');
  c = n / 10;
  } 
  result += (c + '0');
  std::reverse(result.begin(),result.end());
  return result;
}

std::string multiply_i(const std::string& f,int num){
  std::string result;
  int c{0};
  std::int32_t i  = f.size() - 1;
  while(i >= 0){
     int n = (f[i]-'0') * num + c;
     result += ( n % 10 +'0');
     c = n / 10;
     --i;
  }
  result += (c + '0'); 
  std::reverse(result.begin(),result.end());
  return result;
}

//multiply_i() , add() are helpers
std::string multiply(const std::string& f,const std::string& s){
 std::vector<std::string> terms;
 const auto& max = s_max(f,s);
 const auto& min = s_min(f,s);
 int j = min.size()-1;
 int i = 0;
 while(j >= 0){
    auto term = multiply_i(max,min[j]-'0');
    int k = 0;
    while(++k<=i) term += '0';
    terms.emplace_back(term);
    ++i;
    --j;
 }
 std::string rock(terms[0]);
 for(int i = 1;i<terms.size();++i){
   rock.erase(rock.begin(),rock.begin()+rock.find_first_not_of("0"));
   rock = add(terms[i],rock);
 }
 rock.erase(rock.begin(),rock.begin()+rock.find_first_not_of("0"));
 return rock;
}

std::string power(const std::string& n,int exp){
 std::string res(n);
 for(int i = 1;i<exp;++i)
   res = multiply(res,n);
 return res;
}

int main(){
 std::cout<<"Multiply in strings : "<<multiply("123456789123456789","123456789123456789");
std::cout<<"\n\nPowers : "<<power("12345678987654433",31);
}
