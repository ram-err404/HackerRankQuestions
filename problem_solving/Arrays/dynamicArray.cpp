/***************************************************************************************************************
 
Create a list, , of  empty sequences, where each sequence is indexed from  to . The elements within each of the  sequences also use -indexing.
Create an integer, , and initialize it to .
The  types of queries that can be performed on your list of sequences () are described below:
Query: 1 x y
Find the sequence, , at index  in .
Append integer  to sequence .
Query: 2 x y
Find the sequence, , at index  in .
Find the value of element  in  (where  is the size of ) and assign it to .
Print the new value of  on a new line
Task
Given , , and  queries, execute each query.

Note:  is the bitwise XOR operation, which corresponds to the ^ operator in most languages. Learn more about it on Wikipedia.

Input Format

The first line contains two space-separated integers,  (the number of sequences) and  (the number of queries), respectively.
Each of the  subsequent lines contains a query in the format defined above.

Constraints

It is guaranteed that query type  will never query an empty sequence or index.
Output Format

For each type  query, print the updated value of  on a new line.

Sample Input

2 5
1 0 5
1 1 7
1 0 3
2 1 0
2 1 1
Sample Output

7
3
Explanation

Initial Values:
N=2
lastAnswer=0
s0 = [ ]
s1 = [ ]

Query 0: Append  to sequence .
lastAnswer=0
s0 = [5]
s1 = [ ]

Query 1: Append  to sequence .
s0 = [5]
s1 = [7]

Query 2: Append  to sequence .
lastAnswer=0
s0 = [5, 3]
s1 = [7]

Query 3: Assign the value at index  of sequence  to , print .
lastAnswer=7
s0 = [5, 3]
s1 = [7]

7

Query 4: Assign the value at index  of sequence  to , print .
lastAnswer=3
s0 = [5, 3]
s1 = [7]

3

*******************************************************************************************************/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
  // Write your code here.
  vector<vector<int>> seq(n, vector<int>());
  vector<int> res;
  int lastAnswer=0;
  for(size_t i=0; i<queries.size(); i++) {
    int x = queries[i][1];
    int y = queries[i][2];
    if(queries[i][0] == 1) {
      seq[(x^lastAnswer)%n].push_back(y);
    } else {
      lastAnswer=seq[(x^lastAnswer)%n][y%seq[(x^lastAnswer)%n].size()];
      res.push_back(lastAnswer);
    }
  }
  return res;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int q = stoi(first_multiple_input[1]);

  vector<vector<int>> queries(q);

  for (int i = 0; i < q; i++) {
    queries[i].resize(3);

    string queries_row_temp_temp;
    getline(cin, queries_row_temp_temp);

    vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

    for (int j = 0; j < 3; j++) {
      int queries_row_item = stoi(queries_row_temp[j]);

      queries[i][j] = queries_row_item;
    }
  }

  vector<int> result = dynamicArray(n, queries);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

