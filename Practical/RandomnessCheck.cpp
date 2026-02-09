#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    int Num_dice=1, Num_trial=1000000;
    vector<int> sum(Num_dice*60 +1);

    srand(static_cast<unsigned int>(time(0)));

    string outfile = "Randomcheck.csv";
    ofstream ofs(outfile);

    for(int j=0; j < Num_trial; j++){
        int dice=0;
    for(int i=0; i < Num_dice; i++){
        dice += rand() % 60;
    }
    sum.at(dice)++;
    }

    for(int k=0; k < Num_dice*60+1; k++){
        ofs << sum.at(k);
        if (k != Num_dice*60){
            ofs << ",";
        }
        
    }

    ofs << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "time:" << duration << "ms" << std::endl;
}