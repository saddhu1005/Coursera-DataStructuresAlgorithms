#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};
vector<ll> inorder;
void IsBinarySearchTree_rec(const vector<Node>& tree,ll root) {
  // Implement correct algorithm here
  
  if(root==-1)
    return ;
  
    IsBinarySearchTree_rec(tree,tree[root].left);
  
    inorder.push_back(tree[root].key);
  
   IsBinarySearchTree_rec(tree,tree[root].right);

  
}
void IsBinarySearchTree_itr(const vector<Node>& tree,ll node) {
  // Implement correct algorithm here
  if(tree.size()==0)
    return ;
  
  stack<ll> s;
 
  while(!s.empty() && node!=-1)
  {
    
    while(node!=-1)
    { 
      s.push(node);
      node=tree[node].left;
    }
    node=s.top();
    s.pop();
    inorder.push_back(tree[node].key);
    node=tree[node].right;
  }
}
bool IsBinarySearchTree_itr2(const vector<Node>& tree,ll node) {
  // Implement correct algorithm here
  if(tree.size()==0)
    return true;
  
  stack<ll> s;
  ll root;
  while(!s.empty() || node!=-1)
  {
    
    while(node!=-1)
    { 
      s.push(node);
      root=tree[node].left;
      if(root!=-1 && tree[root].key>=tree[node].key)
        {//cout<<"found the bitches\n";

          return false;
        }
      node=tree[node].left;
    }
    node=s.top();
    s.pop();
    //inorder.push_back(tree[node].key);
    node=tree[node].right;
  }
  return true;
}
bool IsBinarySearchTree(const vector<Node>& tree){
  if(tree.size()==0)
    return true;
  IsBinarySearchTree_rec(tree,0);
  ll i;

  for(i=1;i<inorder.size();++i)
  { 
    if(inorder[i-1]>=inorder[i])
      return false;

  }

  return IsBinarySearchTree_itr2(tree,0);
  }



int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
