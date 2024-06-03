#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {

  vector<char> intersect;
  ifstream infile;
  infile.open("Input.txt");
  string line;
  array<string, 3> group = {};
  group.fill("");
  int count = 0;

  while (infile.peek() != EOF) {
    getline(infile, line);
    if (count == 2) {
      group[count] = line;
      unordered_set<char> set1(group[0].begin(), group[0].end());
      unordered_set<char> set2(group[1].begin(), group[1].end());
      unordered_set<char> set3(group[2].begin(), group[2].end());
      for (char c : set1) {
        if ((set2.count(c) >= 1) && (set3.count(c) >= 1)) {
          intersect.push_back(c);
        }
      }
      count = 0;
    } else {
      group[count] = line;
      count++;
    }
  }
  infile.close();
  int total = 0;
  int newC = 0;
  for (char c : intersect) {
    /*
      a = 97
      z = 122
      A = 65
      Z = 90
    */
    if ((int(c) >= 97) && (int(c) <= 122)) {
      newC = int(c) - 96;
    } else {
      newC = int(c) - 65 + 26;
    }
    total += newC;
  }
  cout << total;
  return total;
}