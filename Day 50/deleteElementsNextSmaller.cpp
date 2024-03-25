//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> deleteElement(int arr[], int n, int k);

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        vector<int> v;

        v = deleteElement(arr, n, k);
        vector<int>::iterator it;
        for (it = v.begin(); it != v.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<int> deleteElement(int arr[], int n, int k)
{
    vector<int> ans;
    stack<int> st;

    int i = 0;
    while (i < n)
    {
        while (!st.empty() and k > 0)
        {
            if (st.top() < arr[i])
            {
                st.pop();
                k--;
            }
            else
            {
                break;
            }
        }

        st.push(arr[i]);
        i++;
    }

    while (!st.empty())
    {
        ans.insert(ans.begin(), st.top());
        st.pop();
    }

    return ans;
}
