// 入力された英字列を読み、各文字を別々の行に出力するサンプルプログラム
#include <iostream> // std::cin, std::cout, ios::sync_with_stdio, cin.tie などを提供（入出力とIO最適化に使用）
#include <string> // std::string を提供（変数 s の型として使用）
#include <cctype> // isalpha 等の文字判定関数を提供（現在の実装では直接使用していないが、安全に使う場合に必要）
using namespace std; // std:: を省略して cin, cout, string などを使えるようにする

int main() { // プログラムのエントリポイント
    ios::sync_with_stdio(false); // C の入出力と C++ の入出力の同期を無効化して高速化する（<iostream> による機能）
    cin.tie(nullptr); // std::cin と std::cout の結びつきを外す（入力前の自動フラッシュを止めて高速化する）

    string s; // 入力を格納する文字列（std::string を使用）
    if (!(cin >> s)) return 0; // 標準入力から空白区切りで1ワードを読み取り、読み取れなければ終了する

    int count_ij = 0; // 'i' または 'j' の出現回数を数えるカウンタを初期化
    for (char c : s) { // 文字列 s の各文字について順に処理する（std::string の反復処理）
        if (c == 'i' or c == 'j') { // その文字が小文字の 'i' または 'j' であるかを直接比較して判定
            // 補足: 文字分類関数を使う場合は <cctype> の isalpha を使うが、
            // isalpha に渡す際は `static_cast<unsigned char>(c)` のようにキャストしてから渡すのが安全。
            // 例: if (isalpha(static_cast<unsigned char>(c)) && (c == 'i' || c == 'j')) { ... }
            // これは符号付き char が負の値を取る実装で未定義動作を避けるため。
            count_ij++; // 判定が真ならカウンタを増やす
        } // if 終了
    } // for 終了

    return count_ij; // 出現回数を終了コードとして返す（注意: 終了コードは通常 0 が成功扱い）
} // main 関数の終わり