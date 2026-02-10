#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    int Num_dice=10, Num_trial=10000, dice_dim=6, one_base=1;
    vector<int> sum(Num_dice*dice_dim+1);

    srand(static_cast<unsigned int>(time(0)));

    string outfile = "NSD.csv";
    ofstream ofs(outfile);

    for(int j=0; j < Num_trial; j++){
        int dice=0;
    for(int i=0; i < Num_dice; i++){
        dice += rand() % dice_dim + one_base;
    }
    sum.at(dice)++;
    }

    for(int k=0; k < Num_dice*dice_dim+1; k++){
        ofs << sum.at(k);
        if (k != Num_dice*dice_dim){
            ofs << ",";
        }
        
    }

    ofs << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "time:" << duration << "ms" << std::endl;
}