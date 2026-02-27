#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    
    int ppl=10, dice=6, arrive=4449, N=3000, meal=20;        // initial condition
    
    srand(static_cast<unsigned int>(time(0)));
    string outfile = "Cafe.csv";    // output
    ofstream ofs(outfile);



    for(int k=0; k < N; k++){             // N days

    vector<int> time(ppl);
    for (int i=0; i<ppl; i++)           // open the cafe
    {
        int sum=meal;
        for(int j=0; j < dice; j++) sum += rand() % 6;   // 0~5*dice which will the duration one visitor will stay for
        
        time.at(i) = sum;
    }

    for(int j=0; j < arrive; j++){ 

    for (int i = 0; i < ppl; i++)    // progress one minute 
    {
        if (time.at(i) <= 1)           // get out and come in new visitor
        {
            int sum=meal;
            for(int j=0; j < dice; j++) sum += rand() % 6;
            time.at(i) = sum;
        }

        if (time.at(i) > 1)          // progress the time
        {
            time.at(i) --;
        } 
    }
    }

            // out put

    int wait=400, s=0;
    for (int  i = 0; i < ppl; i++)
    {
    //    cout << time.at(i) << " ";
        wait = min(wait, time.at(i));
        s += time.at(i);
    }
    // cout << wait << " ";
    ofs << wait;
    if (k != N) ofs << ",";
        

}

ofs << endl;

cout << 5 * dice / 2 + meal;

auto end = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
cout << "time:" << duration << "ms" << endl;    // order: ppl * (dice + arrive) * N
// 6 * 10^7 /s
}