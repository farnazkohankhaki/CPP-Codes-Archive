#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

long long w, h, num;
multiset <long long> mySet[2];
set<int> isCut[2];
set<int>::iterator it;


int main()
{
    cin >> w >> h >> num;
    
    mySet[0].insert(w);
    mySet[1].insert(h);
    isCut[0].insert(0);
    isCut[0].insert(w);
    isCut[1].insert(0);
    isCut[1].insert(h);
    
    long long maxW, maxH;
    for (int i = 0; i < num; i++)
    {
        long long side, tmp2;
        char tmp1;
        cin >> tmp1 >> tmp2;
        if (tmp1 == 'V')
            side = 0;
        else
            side = 1;
        
        it = isCut[side].lower_bound(tmp2);
        long long y = *it;
        long long x = *(--it);
        mySet[side].erase(mySet[side].find(y - x));
        mySet[side].insert(y - tmp2);
        mySet[side].insert(tmp2 - x);
        isCut[side].insert(tmp2);

        cout << (*mySet[0].rbegin()) * (*mySet[1].rbegin()) << endl;
    }
    
    return 0;
}