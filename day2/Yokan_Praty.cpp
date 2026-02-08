#include <iostream>
#include <vector>

using namespace std;


pair<long long, long long> merge_tow_piece(vector<long long>& pieces) {
    long long min_tow_piece = (1LL << 60);
    long long min_left_ind = -1;
    for (size_t i = 0; i + 1 < pieces.size(); ++i) {
        if (pieces[i] + pieces[i + 1] < min_tow_piece) {
            min_tow_piece = pieces[i] + pieces[i + 1];
            min_left_ind = i;
        }
    }
    return {min_left_ind, min_tow_piece};
}

vector<long long> update_pieces(vector<long long>& pieces, long long left_ind) {
    vector<long long> new_pieces;
    for (size_t i = 0; i < pieces.size(); ++i) {
        if (i == left_ind) {
            new_pieces.push_back(pieces[i] + pieces[i + 1]);
            ++i;
        } else {
            new_pieces.push_back(pieces[i]);
        }
    }
    return new_pieces;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, L, K;
    if (!(cin >> N >> L)) return 0;
    if (!(cin >> K)) return 0;

    vector<long long> A(N);
    long long previous = 0;
    long long current = 0;
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            if (!(cin >> current)) return 0;
            A[i] = current;
            previous = current;
        }
        else if (i > 0 && i == N - 1) {
            if (!(cin >> current)) return 0;
            A[i] = L - current;
        }
        else {
            if (!(cin >> current)) return 0;
            A[i] = current - previous;
            previous = current;
        }
    }
    for (int i = 0; i < N-K-1; ++i) {
        if (i == N - K - 2) {
            long long score = 0;
            score = merge_tow_piece(A).second;
            cout << score << "\n";
        }
        else{
            A = update_pieces(A, merge_tow_piece(A).first);
        }
    }

    return 0;
}