#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int students, int pages)
{
    int cntStu = 1;
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > pages)
            return false;
        if (sum + arr[i] > pages)
        {
            cntStu++;
            sum = arr[i];
            if (cntStu > students)
                return false;
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int findPages(vector<int> &arr, int students)
{
    int n = arr.size();
    int ans = -1;

    if (students > n)
        return ans;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, students, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

/*
🔹 isPossible(arr, students, pages)

Greedily assign books to students.

Keep a running sum of pages.

If adding the next book exceeds pages (the trial max allowed per student), assign it to the next student.

If at any point a book has more pages than pages, or students needed > allowed, return false.

If all books are distributed within the limit, return true.

🔹 findPages(arr, students)

Edge case: if students > books → impossible (-1).

Search space:

low = max(arr) (no student can get less than the largest single book).

high = sum(arr) (one student takes all).

Binary search between low and high:

mid = (low + high)/2.

If isPossible(..., mid) → it’s valid, try minimizing further (ans = mid, high = mid-1).

Else → not possible, increase limit (low = mid+1).

Return ans = minimum maximum pages any student gets.
*/