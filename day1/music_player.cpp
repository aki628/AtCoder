// day1/music_player.cpp
// 説明: 先頭に整数 N があり、その後に N 個の整数を読み込んで空白区切りで出力する練習用プログラムです。
// 各行に学習用コメントを付けています。

 // 個別ヘッダを明示的に include して使用箇所をコメントしています。
 // どのヘッダがどこで使われているかを明示することで、IDE のエラーを避けやすくします。
 #include <iostream> // cin, cout を使用
 #include <vector>   // std::vector を使用
 #include <cstddef>  // size_t を使用
 // 注意: <bits/stdc++.h> は便利だが非標準なので、明示的なヘッダを推奨します。

using namespace std; // std:: を毎回書かずに済むようにする（学習用に簡潔化）

int main() {
    // 高速入出力の設定（競技プログラミングでよく使う）
    ios::sync_with_stdio(false); // C 標準入出力との同期を解除して高速化
    cin.tie(nullptr);            // 入出力の tying を外してさらに高速化

    // N を long long にしておくと大きな数でも安全（ここでは int でも可）
    long long N;
    // 入力が失敗したら（例えば EOF）プログラムを終了する
    if (!(cin >> N)) return 0;

    // 読み込む値を格納するコンテナ
    // vector は <bits/stdc++.h> により読み込まれる <vector> を利用している
    vector<long long> v;
    // reserve は予めメモリを確保して push_back の再割当を減らすメソッド
    // static_cast でサイズ型に変換しているのは型の警告を避けるため
    v.reserve(N > 0 ? static_cast<size_t>(N) : 0);

    // N 回整数を読み込むループ
    // long long x: 読み込む個々の整数を受け取る変数
    for (long long i = 0; i < N; ++i) {
        long long x;
        // 標準入力から整数を読み込む（cin は <iostream> による）
        cin >> x;
        // 読み取った値を vector に追加する（push_back は <vector> のメソッド）
        v.push_back(x);
    }

    // 読み込んだ整数を空白区切りで出力する
    // i が 0 でなければ前に空白を入れることで末尾に余分な空白を入れない
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ' '; // cout は <iostream> による
        cout << v[i];       // vector から値を取り出して出力
    }
    cout << '\n'; // 最後に改行を出力

    return 0; // 正常終了
}