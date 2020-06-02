/**********************************************************************************************************
Starting with a 1-indexed array of zeros and a list of operations, for each operation
add a value to each of the array element between two given indices, inclusive. Once all
operations have been performed, return the maximum value in your array.

For example, the length of your array of zeros n=10. Your list of queries is as follows:

    a b k
    1 5 3
    4 8 7
    6 9 1
Add the values of  between the indices  and  inclusive:

index->	 1 2 3  4  5 6 7 8 9 10
	[0,0,0, 0, 0,0,0,0,0, 0]
	[3,3,3, 3, 3,0,0,0,0, 0]
	[3,3,3,10,10,7,7,7,0, 0]
	[3,3,3,10,10,8,8,8,1, 0]
The largest value is 10 after all operations are performed.

Function Description

Complete the function arrayManipulation in the editor below. It must return an integer,
the maximum value in the resulting array.

arrayManipulation has the following parameters:
--> n         - the number of elements in your array
--> queries   - a two dimensional array of queries where each queries[i] contains 
                three integers, a, b, and k.

Input Format

The first line contains two space-separated integers M and N, the size of the array and 
the number of operations. Each of the next M lines contains three space-separated integers 
a, b and k, the left index, right index and summand. 


Output Format

Return the integer maximum value in the finished array.
 **********************************************************************************************************/



#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
  vector<int> res(n, 0);
  long max=0;
  long x=0;
  for(size_t i=0; i<queries.size(); i++) {
    int start = queries[i][0]-1;
    int end = queries[i][1];
    res[start] += queries[i][2];
    res[end] -= queries[i][2];

  }
  for(size_t i=0; i<n; i++) {
    x += res[i];
    if(x > max)
      max = x;
  }
  return max;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nm_temp;
  getline(cin, nm_temp);

  vector<string> nm = split_string(nm_temp);

  int n = stoi(nm[0]);

  int m = stoi(nm[1]);

  vector<vector<int>> queries(m);
  for (int i = 0; i < m; i++) {
    queries[i].resize(3);

    for (int j = 0; j < 3; j++) {
      cin >> queries[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  long result = arrayManipulation(n, queries);

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

