//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct Meeting
    {
        int start;
        int end;

        Meeting(int start, int end)
        {
            this->start = start;
            this->end = end;
        }

        static bool compare(const Meeting &a, const Meeting &b)
        {
            return a.end < b.end; // for increasing order
        }
    };

    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<Meeting> meetings;

        for (int i = 0; i < n; i++)
        {
            meetings.push_back(Meeting(start[i], end[i]));
        }

        sort(meetings.begin(), meetings.end(), Meeting::compare);

        int totalMeetings = 1;
        int lastEndtime = meetings[0].end;

        for (int i = 1; i < n; i++)
        {
            if (meetings[i].start > lastEndtime)
            {
                totalMeetings++;
                lastEndtime = meetings[i].end;
            }
        }

        return totalMeetings;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends