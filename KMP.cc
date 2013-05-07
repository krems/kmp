#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

vector<size_t> prefixFunction(const string& source) {
  vector<size_t> pi(source.length());
  pi.push_back(0);
  for(size_t i = 1; i < source.length(); ++i) {
    j = pi[i - 1];
    while (j > 0 && source[j] != source[i]) {
      j = pi[j - 1];
    }
    if (source[j] != source[i]) {
      pi.push_back(0);
      continue;
    }
    pi.push_back(j + 1);
  }
}

int main() {
  string sample("abcdabcab");
  vector<size_t> prefix(prefixFunction(sample));
  cout << sample << endl;
  for (auto it = prefix.cbegin(); it != prefix.cend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
