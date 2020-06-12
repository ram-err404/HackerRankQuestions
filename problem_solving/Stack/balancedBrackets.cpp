#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string str) {
  int i=1;
  stack<char> s;
  s.push(str[0]);
  while(str[i]) {
    if(!s.empty()) {
      char bracket=s.top();
      if( str[i]=='}' && bracket=='{' ||
          str[i]==']' && bracket=='[' ||
          str[i]==')' && bracket=='(' ) {
        s.pop();
        i++;  continue;
      }
    }
    s.push(str[i]);
    i++;
  }
  if(s.empty())
    return "YES";
  else
    return "NO";
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string s;
    getline(cin, s);

    string result = isBalanced(s);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}

