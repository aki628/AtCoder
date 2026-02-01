 // day1/music_player.cpp
 // 説明: N 個の操作を読み取り、音楽の再生状態と音量を更新して最終判定を出力する簡易シミュレータです。
 // 以下にこのファイルで使っている標準ヘッダとその利用箇所を明示します。
 //
 // 使用ヘッダと用途（このファイル内での利用箇所）
 // - <iostream> : 標準入力 std::cin と標準出力 std::cout を使用（入力の読み取り・結果出力）
 // ※ このファイルでは他の標準コンテナ（std::vector 等）やアルゴリズムは使用していません。
 #
 #include <iostream> // std::cin, std::cout を使用

using namespace std; // std:: を毎回書かずに済むようにする（学習用に簡潔化）

int main() {
    // 高速入出力の設定（競技プログラミングでよく使う）
    ios::sync_with_stdio(false); // C 標準入出力との同期を解除して高速化
    cin.tie(nullptr);            // 入出力の tying を外してさらに高速化

    // N を long long にしておくと大きな数でも安全（ここでは int でも可）
    long long N;
    // 入力が失敗したら（例えば EOF）プログラムを終了する
    if (!(cin >> N)) return 0;

    bool music_on = false; // 音楽の再生状態を表すフラグ（初期値は停止状態）
    long long sound_volume = 0; // 音量レベルを表す変数（初期値は0）

    // N 回整数を読み込むループ
    // long long x: 読み込む個々の整数を受け取る変数
    for (long long i = 0; i < N; ++i) {
        long long x;
        // 標準入力から整数を読み込む（cin は <iostream> による）
        if (!(cin >> x)) break; // 入力不足やエラー時はループを抜ける
        // 入力値に応じて状態を更新する（この実装では配列に格納せず直接処理する）
        if (x == 3) {
            music_on = !music_on; // トグル動作で音楽の再生/停止を切り替え
        } else if (x == 1) {
            sound_volume++; // 音楽が再生中なら音量を1上げる
        } else if (x == 2 && sound_volume > 0) {
            sound_volume--; // 音楽が再生中で音量が0より大きければ1下げる
        }
    }

    if (music_on && sound_volume > 2) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
    return 0; // 正常終了
}