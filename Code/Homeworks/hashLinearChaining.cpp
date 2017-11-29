#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class LLHashNode {
private:
  string val;
  LLHashNode *next;
  int count;

public:
  LLHashNode(string s) {
    val = s;
    count = 0;
    next = nullptr;
  }

  int getCount() {
    return count;
  }

  string getVal() {
    return val;
  }

  LLHashNode *getNext() {
    return next;
  }

  void setNext(LLHashNode *next) {
    this->next = next;
  }

};

const int TABLE_SIZE = 128;

class hashLinearChain {
private:
  LLHashNode** table;

public:
  hashLinearChain() {
    table = new LLHashNode*[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
      table[i] = nullptr;
    }
  }

  ~hashLinearChain() {
    for (int i = 0; i < TABLE_SIZE; i++) {
      if (table[i] != nullptr) {
        LLHashNode *prevEntry = nullptr;
        LLHashNode *currEntry = table[i];
        while(currEntry != nullptr) {
          prevEntry = currEntry;
          currEntry = currEntry->getNext();
          delete prevEntry;
        }
      }
    }
    delete [] table;
  }

  int hash(string s) {
    int length = s.length();
    int sum = 0;
    for (int i = 0; i < length; i++) {
      sum += (i+1) * s[i];
    }
    cout << "Sum of string: " << sum << '\t' << "Hash value: " << sum % TABLE_SIZE << endl;
    return sum % TABLE_SIZE;
  }

  void put(string s) {
    int hashVal = hash(s);
    if (table[hashVal] == nullptr) {
      table[hash] = new LLHashNode(s);
    } else {

    }

  }
};

int main() {
  hashLinearChain h;
  h.put("test");
  h.put("word");
}
