#include <unordered_map>
#include <vector>
#include <algorithm>    // std::sort
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector < int > ingots = vector < int > (n);
	for(int i = 0 ; i < n ; i++) {
		cin >> ingots[i];
	}
	sort(ingots.begin(),ingots.end());

	int best_len = 1;
	int val;
    unordered_map < int , unordered_map < int, int > > seq_info;
    for(int i=0 ; i<n ; i++) 
    {
        for(int j=0 ; j<i ; j++) 
        {
            int inter = ingots[i] - ingots[j];
            if(inter==0)
            {
                continue;
            }
            if(seq_info.count(i)==0)
            {
            	seq_info.emplace(i, unordered_map < int, int > () );
            }
            val = 2;
            if(!seq_info.count(j) == 0 && !seq_info[j].count(inter) == 0) 
            {
            	val = seq_info[j][inter] + 1;
            }
            seq_info[i].emplace( inter , val );
            if(val > best_len)
            {
                best_len = val;
            }
        }
    }
    cout << best_len<< endl;
}
