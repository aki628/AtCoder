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

vector<long long> create_pieces_length(vector<long long>& lengths) {
    vector<long long> vec(lengths.size());
    for (size_t i = 0; i < lengths.size(); ++i) {
        if (i == 0) {
            vec[i] = lengths[i];
            continue;
        }
        else {
            vec[i] = lengths[i] - lengths[i - 1];
        }
    }
    return vec;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, L, K;
    if (!(cin >> N >> L)) return 0;
    if (!(cin >> K)) return 0;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            if (!(cin >> A[i])) return 0;
        }
        else if (i > 0 && i == N - 1) {
            long long last;
            if (!(cin >> last)) return 0;
            A[i] = L - last;
        }
        else {
            if (!(cin >> A[i])) return 0;
        }
    }
    for (int i = 0; i < N-K; ++i) {
        if (i == N - K - 1) {
            cout << merge_tow_piece(A).second << "\n";
        }
        A = update_pieces(A, merge_tow_piece(A).first);
    }

    return 0;
}