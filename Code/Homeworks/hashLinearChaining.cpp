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

  void setCount(int n) {
    this->count = n;
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

  bool isNext() {
    if (this->next != nullptr) {
      return true;
    } else {
      return false;
    }
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
    //cout << "Sum of string: " << sum << '\t' << "Hash value: " << sum % TABLE_SIZE << endl;
    return sum % TABLE_SIZE;
  }

  void put(string s) {
    int hashVal = hash(s);
    LLHashNode *newNode = new LLHashNode(s);
    int count;
    if (table[hashVal] == nullptr) {
      newNode->setCount(1);
      table[hashVal] = newNode;
    } else {
      LLHashNode *temp = table[hashVal];
      count = temp->getCount();
      table[hashVal] = newNode;
      newNode->setNext(temp);
      newNode->setCount(count+1);
    }
    cout << s << " has been hashed with value of " << hashVal << endl;
  }

  void displayCounts() {
    LLHashNode *temp;
    for (int i = 0; i < TABLE_SIZE; i++) {
      temp = table[i];
      if(temp != nullptr) {
        cout << i << "\t" << temp->getCount() << endl;
      } else {
        cout << i << '\t' << "0" << endl;
      }

    }
  }

  bool wordExists(string s) {
    int hashVal = hash(s);
    LLHashNode *temp = table[hashVal];
    while (temp != nullptr) {
      //cout << temp->getVal();
      if (temp->getVal() == s) {
        return true;
      } else {
        temp = temp->getNext();
      }
    }
    return false;
  }
};

int main() {
  hashLinearChain h;
  h.put("test");
  h.put("word");
  h.put("yhomas");
  h.put("a");
  cout << h.wordExists("yhomas") << endl;
  h.displayCounts();
}
