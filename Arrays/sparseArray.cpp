/*********************************************************************************************************
There is a collection of input strings and a collection of query strings. For each query string,
determine how many times it occurs in the list of input strings.

For example, given input strings=['ab', 'ab', 'abc'] and queries=['ab', 'abc', 'bc'], 
we find 2 instances of 'ab', 1 of 'abc' and 0 of 'bc'. For each query, we add an element to our return array,
result=[2, 1, 0].


Function Description
Complete the function matchingStrings in the editor below. The function must return an array of integers
representing the frequency of occurrence of each query string in strings.

matchingStrings has the following parameters:

strings - an array of strings to search
queries - an array of query strings
Input Format

The first line contains an integer N, the size of strings.
Each of the next N lines contains a string strings[i].
The next line contains q, the size of queries.
Each of the next q lines contains a string queries[i].

Output Format

Return an integer array of the results of all queries in order. 
 *********************************************************************************************************/


#include <bits/stdc++.h>
#include <string>
using namespace std;

// #define STRCMP(X, Y)  strcmp((const char*) X, (const char*) Y)

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
  // your code here.
  vector<int> count(queries.size(), 0);

  for(size_t i=0; i<queries.size(); i++) {
    for(size_t j=0; j<strings.size(); j++) {
      if(0 == queries[i].compare(strings[j]))
        count[i]++;
    }
  }
  return count;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int strings_count;
  cin >> strings_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> strings(strings_count);

  for (int i = 0; i < strings_count; i++) {
    string strings_item;
    getline(cin, strings_item);

    strings[i] = strings_item;
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> queries(queries_count);

  for (int i = 0; i < queries_count; i++) {
    string queries_item;
    getline(cin, queries_item);

    queries[i] = queries_item;
  }

  vector<int> res = matchingStrings(strings, queries);

  for (int i = 0; i < res.size(); i++) {
    fout << res[i];

    if (i != res.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

