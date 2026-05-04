#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using ll = long long;

struct Home
{
    int homeID;

    Home(int ID) { homeID = ID; };
};

struct Bird
{
    int birdID;
    Home *homePtr;

    Bird(int ID, Home *ptr)
    {
        birdID = ID;
        homePtr = ptr;
    }
};

int main()
{

    int N, Q;
    cin >> N >> Q;

    vector<Home> homeVec;
    vector<Bird> birdVec;
    homeVec.reserve(N); // 再確保によるアドレスずれを防ぐ
    for (int i = 0; i < N; i++)
        homeVec.emplace_back(i);
    for (int i = 0; i < N; i++)
        birdVec.emplace_back(i, &homeVec[i]);

    vector<int> labelToPos(N); // labelToPos[label] = homeVec の index
    for (int i = 0; i < N; i++)
        labelToPos[i] = i;

    // for (int i = 0; i < N; i++)
    // {
    //     cout << homeVec[i].homeID << endl;
    // }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << birdVec[i].birdID << " " << birdVec[i].homePtr->homeID << endl;
    // }

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            birdVec[a].homePtr = &homeVec[labelToPos[b]];
        }

        else if (type == 2)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            int pa = labelToPos[a], pb = labelToPos[b];
            swap(homeVec[pa].homeID, homeVec[pb].homeID);
            swap(labelToPos[a], labelToPos[b]);
        }

        else
        {
            int a;
            cin >> a;
            a--;

            cout << birdVec[a].homePtr->homeID + 1 << endl;
        }

        // for (int i = 0; i < N; i++)
        // {
        //     cout << birdVec[i].homePtr->homeID << " ";
        // }
        // cout << endl;
    }

    return 0;
}