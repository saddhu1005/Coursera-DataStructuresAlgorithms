#include <bits/stdc++.h>
using namespace std;
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;
  vector<int> inorder,preorder,postorder;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  vector <int> in_order() {
    //vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    //iterative_inorder(0);
    iterative_inorder(0);
    return inorder;
  }
  void recursive_inorder(int node)
  {
    if(node>=n || node==-1)
      return ;
    recursive_inorder(left[node]);
    inorder.push_back(key[node]);
    recursive_inorder(right[node]);
    
  }
  void iterative_inorder(int node)
  {
    stack<int> s;
    while(!s.empty() || node!=-1)
    {
      while(node!=-1)
      {
        s.push(node);
        node=left[node];
      }
      node=s.top();
      s.pop();
      inorder.push_back(key[node]);
      node=right[node];
    }
  }
  vector <int> pre_order() {
   // vector<int> result;    
    // Finish the implementation
    // You may need to add a new recursive method to do that
    //iterative_preorder(0);
    recursive_preorder(0);
    return preorder;
  }
  void recursive_preorder(int node)
  {
    if(node>=n || node==-1)
      return ;
    preorder.push_back(key[node]);
    recursive_preorder(left[node]);
    recursive_preorder(right[node]);
    
  }
  void iterative_preorder(int node)
  {
    stack<int> s;
    s.push(node);
    while(!s.empty())
    {
      node=s.top();
      s.pop();
      preorder.push_back(key[node]);
      if(right[node]!=-1)
        s.push(right[node]);
      if(left[node]!=-1)
        s.push(left[node]);
    }
  }
  vector <int> post_order() {
    //vector<int> result;
    // Finish the implementation
    // You may need to add a new recursive method to do that
    //iterative_postorder(0);
    recursive_postorder(0);
    return postorder;
  }
  void recursive_postorder(int node)
  {
    if(node>=n || node==-1)
      return ;
    recursive_postorder(left[node]);
    recursive_postorder(right[node]);
    postorder.push_back(key[node]);
    
  }
  void iterative_postorder(int node)
  {
    stack<int> s;
  do{
    while( node!=-1)
    {
      if(right[node]!=-1)
        s.push(right[node]);
      s.push(node);
      node=left[node];
    }
    node=s.top();
    s.pop();
    if(right[node]!=-1 && s.top()==right[node])
    {
      s.pop();
      s.push(node);
      node=right[node];
    }
    else
    {
    postorder.push_back(key[node]);
    node=-1;
    }
  }while(!s.empty());
}
};
void print(vector <int> a) {
  for (size_t i = 0; i < a.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << a[i];
  }
  cout << '\n';
}

int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();

  print(t.in_order());
  print(t.pre_order());
  print(t.post_order());
  return 0;
}
int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}


