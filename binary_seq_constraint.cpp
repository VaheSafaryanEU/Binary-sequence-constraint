#include <iostream>
#include <vector>

int countSequences(int N) {
    std::vector<int> endingWith0(N + 1, 0);
    std::vector<int> endingWith1(N + 1, 0);

    endingWith0[1] = 1;
    endingWith1[1] = 1;

    for (int i = 2; i <= N; ++i) {
        endingWith0[i] = endingWith0[i - 1] + endingWith1[i - 1];
        endingWith1[i] = endingWith0[i - 1];
    }

    return endingWith0[N] + endingWith1[N];
}

int main() {
    int N;
    std::cout << "Enter the length of the sequence: ";
    std::cin >> N;
    
    std::cout << "The number of " << N << "-sized binary sequences without consecutive 1s is: "
              << countSequences(N) << std::endl;
    
    return 0;
}
