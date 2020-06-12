#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
  // Create an empty stack. The stack holds indexes  
  // of hist[] array. The bars stored in stack are  
  // always in increasing order of their heights. 
  stack<int> s; 

  int max_area = 0; // Initialize max area 
  int tp;  // To store top of stack 
  int area_with_top; // To store area with top bar 
  // as the smallest bar 

  // Run through all bars of given histogram 
  int i = 0;
  int n = h.size();
  while (i < n) { 
    // If this bar is higher than the bar on top  
    // stack, push it to stack 
    if (s.empty() || h[s.top()] <= h[i]) 
      s.push(i++); 

    // If this bar is lower than top of stack,  
    // then calculate area of rectangle with stack  
    // top as the smallest (or minimum height) bar.  
    // 'i' is 'right index' for the top and element  
    // before top in stack is 'left index' 
    else { 
      tp = s.top();  // store the top index 
      s.pop();  // pop the top 
      // Calculate the area with hist[tp] stack  
      // as smallest bar 
      area_with_top = h[tp] * (s.empty() ? i : i - s.top() - 1); 
      // update max area, if needed 
      if (max_area < area_with_top) 
        max_area = area_with_top; 
    } 
  } 
  // Now pop the remaining bars from stack and calculate 
  // area with every popped bar as the smallest bar 
  while (s.empty() == false) { 
    tp = s.top(); 
    s.pop(); 
    area_with_top = h[tp] * (s.empty() ? i : i - s.top() - 1); 

    if (max_area < area_with_top) 
      max_area = area_with_top; 
  } 
  return max_area;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string h_temp_temp;
  getline(cin, h_temp_temp);

  vector<string> h_temp = split_string(h_temp_temp);

  vector<int> h(n);

  for (int i = 0; i < n; i++) {
    int h_item = stoi(h_temp[i]);

    h[i] = h_item;
  }

  long result = largestRectangle(h);

  fout << result << "\n";

  fout.close();

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
      return x == y and x == ' ';
      });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
