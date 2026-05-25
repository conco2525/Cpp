#include <bits/stdc++.h>
using namespace std;


#include <stdlib.h> // system関数を使うため

class DictionaryEngine {
private:
    // 二分探索木である map を使用。完全一致は O(log N)、前方一致検索にも対応可能
    map<string, string> dict;

    // UTF-8の文字数を正確にカウントし、指定文字数で切り捨てる関数
    // （日本語は1文字3バイトのため、単純な .length() ではなくバイト列を判定します）
    string truncate_utf8(const string& str, int max_chars) {
        int chars = 0;
        string result = "";
        for (size_t i = 0; i < str.length(); ) {
            if (chars >= max_chars) {
                result += "...";
                break;
            }
            unsigned char c = str[i];
            int bytes = 1;
            if ((c & 0xE0) == 0xC0) bytes = 2;
            else if ((c & 0xF0) == 0xE0) bytes = 3;
            else if ((c & 0xF8) == 0xF0) bytes = 4;

            if (i + bytes > str.length()) bytes = str.length() - i;
            result += str.substr(i, bytes);
            i += bytes;
            chars++;
        }
        return result;
    }

public:
    // 辞書データを読み込む
    bool load(const string& filename) {
        ifstream ifs(filename);
        if (!ifs) return false;

        string line;
        while (getline(ifs, line)) {
            size_t tab_pos = line.find('\t');
            if (tab_pos != string::npos) {
                string eng_part = line.substr(0, tab_pos);
                string jpn_part = line.substr(tab_pos + 1);
                
                // 仕様：日本語訳をn文字で切り捨て
                jpn_part = truncate_utf8(jpn_part, 125);

                // 仕様への対応：「cotter, cottar」のような表記ゆれを分割し、
                // どちらの単語からでも同じ訳語を引けるようにする
                stringstream ss(eng_part);
                string key;
                while (getline(ss, key, ',')) {
                    // 前後の空白をトリミング
                    size_t start = key.find_first_not_of(" ");
                    size_t end = key.find_last_not_of(" ");
                    if (start != string::npos && end != string::npos) {
                        key = key.substr(start, end - start + 1);
                        dict[key] = jpn_part;
                    }
                }
            }
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
    void search_prefix(const string&prefix) {
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
    if (!engine.load("ejdict-hand-utf8.txt")) {
        cout << "Error:we faild to find dictionary file\n";
        return 1;
    }

    // コマンドプロンプト風のUI（前の結果を消さない）
    cout << "========================================\n";
    cout << " English Dictionary\n";
    cout << " [How to Use] input words and press Enter\n";
    cout << " [Suggest] add '*' in the end (e.g. dicti*)\n";
    cout << "========================================\n\n";

    string query;
    // cin >> query だと "cotton candy" のようなスペースを含む単語が途切れるため getline を使用
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