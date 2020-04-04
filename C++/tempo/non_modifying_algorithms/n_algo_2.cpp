#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
 
int main(){
 
  std::cout << std::endl;
 
  std::string str{"abcdabAAAaefaBqeaBCQEaadsfdewAAQAaafbd"};
  std::cout << "count: " << std::count(str.begin(), str.end(), 'a') << std::endl;
  std::cout << "count_if: " << std::count_if(str.begin(), str.end(), [](char a){ return std::isupper(a);}) << std::endl;
 
  std::cout << std::endl;
 
}