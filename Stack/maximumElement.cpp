#include <stack>
#include <iostream>
using namespace std;

#if 0
int maxFromStack(stack<int> &s) {
  stack<int>  temp = s;   // make a copy of s;
  int maxVal=temp.top();  // initialise maxVal as top of the stack.

  while(!temp.empty()) {
    temp.pop(); // remove top as top is already in maxVal.
    if(!temp.empty() && maxVal < temp.top())
      maxVal = temp.top();
  }
  return maxVal;
}
#endif

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int N;
  stack<int>  s;
  int maxStack[100000] = {0};
  int topm=-1;
  cin >> N;

  for(int i=0; i<N; i++) {
    int a;
    cin >> a;
    switch(a) {
      case 1: {
                int b;    cin >> b;
                if(topm==-1 || maxStack[topm]<=b)
                  maxStack[++topm] = b;
                s.push(b);
                break;
              }
      case 2: {
                if(maxStack[topm]==s.top())
                  topm--;
                s.pop();
                break;
              }
      case 3: {
                cout << maxStack[topm] << endl;
                break; 
              }
    }
  }
  return 0;
}
