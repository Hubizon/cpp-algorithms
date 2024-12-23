// Hubert Jastrzębski | Satori B10 (Randka w ciemno) | 2020-12-07
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6612894

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void quickSort(vector<pair<string, long>>&, long, long);
int partition(vector<pair<string, long>>&, long, long);

int main()
{
    long z;
    cin >> z;
    for (; z--;)
    {
        vector<pair<string, long>> vec;
        int n, s;
        cin >> n >> s;
        for (int i = n; i--;)
        {
            string str;
            long a;
            cin >> str >> a;
            vec.push_back(make_pair(str, a));
        }
        quickSort(vec, 0, vec.size() - 1);
        long i = 0, j = n - 1;
        while (i < j && vec[i].second + vec[j].second != s)
        {
            if (vec[i].second + vec[j].second < s)
                i++;
            else
                j--;
        }
        if (i >= j)
            cout << "NIE\n";
        else
            cout << vec[i].first << " " << vec[j].first << "\n";
    }
}

void quickSort(vector<pair<string, long>>& vec, long start, long end)
{
    if (start < end)
    {
        int p = partition(vec, start, end);
        quickSort(vec, start, p);
        quickSort(vec, p + 1, end);
    }
}

int partition(vector<pair<string, long>>& vec, long start, long end)
{
    swap(vec[start], vec[start + rand() % (end - start + 1)]);
    long pivot = vec[start].second;
    long i = start - 1, j = end + 1;
    while (true)
    {
        while (vec[++i].second < pivot);
        while (vec[--j].second > pivot);
        if (i >= j)
            return j;
        swap(vec[i], vec[j]);
    }
}