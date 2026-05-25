#include <bits/stdc++.h>
using namespace std;

#include <stdlib.h> // system関数を使うため

class DictionaryEngine {
private:
    // 二分探索木である map を使用。完全一致は O(log N)、前方一致検索にも対応可能
    map<string, string> dict;

    // 指定文字数（アルファベットのバイト数）で文字列を切り捨てるシンプルな関数
    string truncate(const string& str, size_t max_chars) {
        if (str.length() > max_chars) {
            return str.substr(0, max_chars) + "...";
        }
        return str;
    }

public:
    // 辞書データを読み込む
    bool load(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) return false;

        string line;
        while (getline(ifs, line)) {
            // 1. 最初のカンマ（見出し語の直後）を探す
            size_t first_comma = line.find(',');
            if (first_comma == string::npos) continue;

            // 2. 2番目のカンマ（品詞の直後）を探す
            size_t second_comma = line.find(',', first_comma + 1);
            if (second_comma == string::npos) continue;

            // 3. 各パーツを正確に切り出す
            string key = line.substr(0, first_comma); // 最初のカンマより前
            string pos = line.substr(first_comma + 1, second_comma - first_comma - 1); // カンマの間（品詞）
            string synonyms = line.substr(second_comma + 1); // 2番目のカンマより後ろ

            // 4. 表示形式の整形
            // 縦棒「|」を読みやすいように「, 」に置換
            for (size_t i = 0; i < synonyms.length(); ++i) {
                if (synonyms[i] == '|') {
                    synonyms.replace(i, 1, ", ");
                }
            }

            // 「[品詞] 類義語リスト」の形にまとめる
            string definition = "[" + pos + "] " + synonyms;

            // 100文字で切り捨て
            definition = truncate(definition, 100);

            // 5. データベース（map）に登録
            // 見出し語の前後の空白をトリミング（念のため）
            size_t start = key.find_first_not_of(" ");
            size_t end = key.find_last_not_of(" ");
            if (start != string::npos && end != string::npos) {
                key = key.substr(start, end - start + 1);
            }

            dict[key] = definition;
        }
        return true;
    }

    // 完全一致検索
    void search_exact(const string& query) {
        if (dict.count(query)) {
            cout << ">> " << dict[query] << "\n";
        } else {
            cout << ">> Not found\n";
        }
    }

    // 前方一致検索（サジェスト機能の土台）
    void search_prefix(const string& prefix) {
        auto it = dict.lower_bound(prefix);
        int count = 0;
        bool found = false;
        
        // mapの性質上、アルファベット順に並んでいるので前方一致する間だけループ
        while (it != dict.end() && it->first.substr(0, prefix.length()) == prefix) {
            cout << "  " << it->first << " : " << it->second << "\n";
            it++;
            count++;
            found = true;
            if (count >= 10) { // 画面が埋まるのを防ぐため10件で打ち切り
                cout << "  ... (etc.)\n";
                break;
            }
        }
        if (!found) {
            cout << ">> No words found starting with '" << prefix << "'\n";
        }
    }
};

int main() {
    // Windowsのターミナルを強制的にUTF-8(65001)に切り替える強硬手段
    system("chcp 65001 > NUL");

    DictionaryEngine engine;
    // ファイル名は適宜手元のCSVファイル名（例: words.csv）に書き換えてください
    if (!engine.load("synonyms.csv")) {
        cout << "Error: we failed to find dictionary file\n";
        return 1;
    }

    // コマンドプロンプト風のUI
    cout << "========================================\n";
    cout << " English Thesaurus & Dictionary (CSV)\n";
    cout << " [How to Use] input words and press Enter\n";
    cout << " [Suggest] add '*' in the end (e.g. cust*)\n";
    cout << "========================================\n\n";

    string query;
    while (true) {
        cout << "   >> ";
        if (!getline(cin, query)) break; // Ctrl+C や EOF で安全に終了

        // 入力のクリーニング（前後の空白除去）
        size_t start = query.find_first_not_of(" ");
        size_t end = query.find_last_not_of(" ");
        if (start == string::npos) continue;
        query = query.substr(start, end - start + 1);

        // 仕様：小文字で入力してもマッチするように、入力をすべて小文字化
        for(char &c : query) {
            if(c >= 'A' && c <= 'Z') c += 32;
        }

        // サジェスト機能への分岐
        if (query.back() == '*') {
            query.pop_back(); // '*' を取り除く
            engine.search_prefix(query);
        } else {
            engine.search_exact(query);
        }
        cout << "\n"; // 視認性を高めるための空行
    }

    return 0;
}