// Reads an input English-letter string and prints each character on a separate line. // 入力された英字列を読み、各文字を別の行に出力するサンプルプログラム
#include <iostream> // 入出力ストリームを使うためのヘッダ
#include <string> // std::stringを使うためのヘッダ
#include <cctype> // 文字判定関数（isalphaなど）を使うためのヘッダ
using namespace std; // std名前空間を省略して使えるようにする

int main() { // エントリポイント（プログラム開始位置）
    ios::sync_with_stdio(false); // CとC++の入出力同期を無効化して高速化する
    cin.tie(nullptr); // cinとcoutの結びつきを外して入出力を高速化する

    string s; // 入力を格納する文字列変数を宣言
    if (!(cin >> s)) return 0; // 入力がなければ終了（空白で区切られた1単語を読む）

    for (char c : s) { // 文字列sの各文字についてループ
        if (isalpha(static_cast<unsigned char>(c))) { 
            // cctype.hのisalpha関数をを使い、
            // その文字が英字かどうかを判定（符号付き文字対策でunsigned charにキャスト）
            // ctype.h（isalpha など）は引数に EOF か unsigned char の値を期待する
            cout << c << '\n'; // 英字ならその文字を出力し、改行する
        } // ifの終わり
    } // forの終わり

    return 0; // 正常終了を示す戻り値
} // main関数の終わり