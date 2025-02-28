#include <iostream>
#include <vector>;
#include <unordered_map>;
#define MAX 1000
using namespace std;
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

class Solution
{
public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
    {
        // Your code here
        unordered_map<string, int> mm;
        vector<vector<int>> ans;

        for (int i = 0; i < row; i++)
        {
            string s = "";
            vector<int> temp;
            for (int j = 0; j < col; j++)
            {
                s.push_back('0' + M[i][j]);
                temp.push_back(M[i][j]);
            }
            if (!mm[s])
            {
                mm[s]++;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        Solution ob;
        vector<vector<int>> vec = ob.uniqueRow(a, n, m);
        for (int i = 0; i < vec.size(); i++)
        {
            for (int x : vec[i])
            {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;
    }
}

