// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <deque>
#include <stdlib.h>
#include <string>
#include <set>

using namespace std;

bool isNailed(int nail, const vector<int>& A, const vector<int>& B, const vector<int>& C)
{
    const int N=A.size();
    const int M=C.size();

    vector<int> nails(2*M+1,0);
    for(int i=0; i<nail;i++)
        nails[C[i]]=1;

    std::partial_sum(nails.begin(), nails.end(), nails.begin());

    bool nailed=true;
    /* Iterate searching for a difference of nails between tables, there shall always be at least one more nail
       for all the table to return True, if there is no enough nails, return false.
       The expression checks how many new nails are present between the last table end and the current table, if there is no new nail
       means that the selected index has no enough nails.*/
    for(int i=0; (i<N) && nailed;i++)
        nailed = (nails[B[i]]-nails[A[i]-1])>0;

    return nailed;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int minNails=1;
    int maxNails=C.size();

    int result=-1;
    while(minNails <= maxNails)
    {
        int mid=(minNails+maxNails)/2;
        if(isNailed(mid,A,B,C))
        {
            maxNails=mid-1;
            result=mid;
        }
        else
            minNails=mid+1;
    }
    return result;
}