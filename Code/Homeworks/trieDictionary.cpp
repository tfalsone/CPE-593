/*
Thomas Falsone
CPE 593
11/30/17
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int ALPH_SIZE = 26;

class trieDict {
private:
  class Node {
  public:
    Node* next[ALPH_SIZE];
    bool isWord;
    Node() : isWord(false) {}
  } *root;

public:
  trieDict() {
    newNode(root);
  }

  void newNode(Node*& n) {
    n = new Node();
    //n->isWord = false;
    //cout << "Initializing node" << endl;
    for (int i = 0; i < ALPH_SIZE; i++) {
      n->next[i] = nullptr;
    }
  }

  void insert(string s) {
    Node *p = root;
    Node *follow = p;
    int length = s.length();
    char c; int key;

    for (int i = 0; i < length; i++) {
      c = s[i];
      key = tolower(c) - 'a';
      //cout << "Inserting " << c << " with key of " << key << endl;

      follow = p->next[key];
      if (follow == nullptr) {
        newNode(follow);
        p->next[key] = follow;
      }
      p = p->next[key];
    }

    p->isWord = true;
  }

  bool contains(string s) {
    Node *p = root;
    int length = s.length();
    char c; int key;

    for (int i = 0; i < length; i++) {
      c = s[i];
      key = tolower(c) - 'a';
      p = p->next[key];
      if (p == nullptr) {
        return false;
      }
    }

    return p->isWord;
  }

  bool startsWith(string s) {
    Node *p = root;
    int length = s.length();
    char c; int key;

    for (int i = 0; i < length; i++) {
      c = s[i];
      key = tolower(c) - 'a';
      p = p->next[key];
      if (p == nullptr) {
        return false;
      }
    }

    return true;
  }


};

int main() {
  trieDict t;
  ifstream readFile;
  readFile.open("dict.txt");
  string s;

  if (readFile.is_open()) {
    while (readFile >> s) {
      t.insert(s);
    }
  }
  readFile.close();

  readFile.open("hw5.txt");
  if (readFile.is_open()) {
    while (readFile >> s) {
      if (t.contains(s)) { cout << "true" << endl; }
      else { cout << "false" << endl; }
    }
  }
  readFile.close();

  t.insert("test");
  cout << t.contains("test") << endl;
}
