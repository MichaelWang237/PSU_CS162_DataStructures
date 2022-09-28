#include "Node.h"
#include <cstdlib>

Node::Node() {
  left = NULL;
  right = NULL;
  data = NULL;
  parent = NULL; 
}

Node* Node::getLeft() {
  return left; 
}

Node* Node::getRight() {
  return right; 
}

int Node::getData() {
  return data; 
}

Node* Node::getParent() {
  return parent; 
}

void Node::setLeft(Node* newLeft) {
  left = newLeft; 
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setData(int newData) {
  data = newData; 
}

void Node::setParent(Node* newParent) {
  parent = newParent; 
}


