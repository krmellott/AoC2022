#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <regex>
using namespace std;

int main(){
  ifstream infile;
  infile.open("Input.txt");
  string line;
  string elf1;
  string elf2;
  while (infile.peek() != EOF) {
    getline(infile, line);
    
  }
  infile.close();
  
  return 0;
  
}


vector<string> regex_split(string str, string regex_str) {
    regex regex(regex_str);
    sregex_token_iterator it(str.begin(), str.end(), regex, -1);
    sregex_token_iterator reg_end;
    return vector<string>(it, reg_end);
}