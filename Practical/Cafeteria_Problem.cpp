#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    int ppl=20, dice=10, arrive=300;
    srand(static_cast<unsigned int>(time(0)));

    vector<int> time(ppl);
    for (int i=0; i<ppl; i++)           // open the cafe
    {
        int sum=0;
        for(int j=0; j < dice; j++) sum += rand() % 6;   // 0~5*dice which will the duration one visitor will stay
        
        time.at(i) = sum;
    }

    for(int j=0; j < arrive; j++){ 

    for (int i = 0; i < ppl; i++)    // progress one minute 
    {
        if (time.at(i) <= 1)           // get out and come in new visitor
        {
            int sum=0;
            for(int j=0; j < dice; j++) sum += rand() % 6;
            time.at(i) = sum;
        }

        if (time.at(i) > 1)          // past the time
        {
            time.at(i) --;
        } 
    }
    }

    for (int  i = 0; i < ppl; i++)
    {
        cout << time.at(i) << " ";
    }
    
    

auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
cout << "time:" << duration << "ms" << endl;
}