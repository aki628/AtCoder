 // day1/music_player.cpp
 // 説明: N 個の操作を読み取り、音楽の再生状態と音量を更新して最終判定を出力する簡易シミュレータです。
 //
 // 使用している標準ヘッダとそのこのファイル内での用途（明示）
 // - <iostream>
 //     用途: 標準入力 (std::cin) で操作コードを読み取り、標準出力 (std::cout) に結果を出力します。
 //     具体箇所: 入力の読み取り（if (!(std::cin >> N)) など）、最終判定やループ内出力（std::cout << ...）。
 // - <list>
 //     用途: std::list<long long> 型のコンテナを使って「履歴」を保持します（hist_music_on, hist_sound_volume）。
 //     具体箇所: hist_music_on.push_back(...) / hist_sound_volume.push_back(...)、および begin()/end() による走査。
 //
 // 補足:
 // - このファイルでは双方向連結リスト (std::list) を履歴保持に使っています。
 //   std::list は先頭/末尾での挿入・削除が O(1) で行える点が特徴ですが、ランダムアクセスはできません。
 // - 入出力は <iostream> の std::cin / std::cout を使っています。競技プログラミング向けに
 //   ios::sync_with_stdio(false) と cin.tie(nullptr) を設定して高速化しています。
 //
 #include <iostream> // std::cin, std::cout を使用
 #include <list>     // std::list を使用（履歴保持）
 
 // 注意: 学習用に簡潔化のため using namespace std; を使っています。実務では名前衝突を避けるため
 // 個別に std:: を付けるか、限定的な using 宣言を推奨します。
 using namespace std;
 
 // auto に関する補足:
 // - auto は初期化子（右辺）の型をコンパイラが推論して変数の型を決めます。
 //   例: auto it = container.begin(); なら it の型は container.begin() の戻り型（iterator など）になります。
 // - top-level の const/volatile は除去される点に注意。参照で受けたい場合は auto& / const auto& を使います。
 // - イテレータの型は長くなることがあるため、auto を使うと可読性が向上します。
 // - ただし、型が曖昧になりやすい場合や意図を明確にしたい場合は明示的な型や decltype を使ってください。
 //   例: decltype(container.begin()) it = container.begin();
 

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

    list<long long> hist_music_on; // 操作を格納するリスト（この実装では使用しないが例示のために宣言）
    list<long long> hist_sound_volume; // 音量履歴を格納するリスト（この実装では使用しないが例示のために宣言）

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
        hist_music_on.push_back(music_on ? 1 : 0); // 状態をリストに記録（例示用）
        hist_sound_volume.push_back(sound_volume); // 音量をリストに記録
    }

     // イテレータに関する詳しい説明：
     // - イテレータはコンテナの要素を順に参照するための「ポインタ様オブジェクト」です。
     // - デリファレンス演算子 `*it` によってイテレータが指す要素を取り出します（例: long long v = *it;）。
     // - 増分演算子 `++it` で次要素へ進めます（std::list のイテレータは双方向なので --it も可能）。
     // - イテレータのカテゴリにより性能や使える操作が異なります（例: random-access iterator は O(1) で += が可能、
     //   bidirectional iterator（std::list）は ++/-- のみ O(1)）。std::list の iterator は双方向イテレータに該当します。
     // - 無効化について：コンテナ操作（erase 等）で一部のイテレータが無効化される場合があります。
     //   std::list では erase(it) はその要素のイテレータを無効化しますが、他の要素のイテレータは通常有効です。
     //
     // auto に関する補足（イテレータ文脈）:
     // - `auto it = hist.begin();` は `hist.begin()` の戻り型（std::list<long long>::iterator など）を推論して it の型にします。
     // - 要素を直接書き換えたい場合は参照で受けることもできます：
     //     auto &val = *it;   // コンテナ要素を参照として受け取る（変更可能）
     //     const auto &val = *it; // 読み取り専用でコピーを避ける
     //
     auto it_music_on = hist_music_on.begin();
     auto it_sound_volume = hist_sound_volume.begin();
     for (; it_music_on != hist_music_on.end() && it_sound_volume != hist_sound_volume.end(); ++it_music_on, ++it_sound_volume) {
        long long music_state = *it_music_on;
        long long volume_level = *it_sound_volume;
        if (music_state == 1 && volume_level > 2) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0; // 正常終了
}