#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

void Frequency(string seq, int start, int end, vector<atomic<int>>& counter) {
    for(int i = start; i < end; i++) {
        char nucleotide = seq[i];
        if(nucleotide == 'A')
            ++counter[0];
        else if(nucleotide == 'T')
            ++counter[1];
        else if(nucleotide == 'C')
            ++counter[2];
        else if(nucleotide == 'G')
            ++counter[3];

    }
}

int main() {
    string sequence;
    cin >> sequence;
    int number = 4;
    int seqLength = sequence.length() / number;
    int seqRemainder = sequence.length() % number;
    vector <thread> threads;
    vector<atomic<int>> counter(4);

    int start = 0;
    for(int i = 0; i < number; i++) {
        int end = start + seqLength;
        if (i == number - 1)
            end += seqRemainder;
        threads.emplace_back(Frequency, ref(sequence), start, end, ref(counter));
        start = end;
    }

    for(auto& thread : threads) {
        thread.join();
    }

    cout << "A: " << counter[0] << endl;
    cout << "T: " << counter[1] << endl;
    cout << "C: " << counter[2] << endl;
    cout << "G: " << counter[3] << endl;

    return 0;
}