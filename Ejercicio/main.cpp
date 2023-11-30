#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto fg_white = "\033[47m";
};
struct ConsoleBox {
    void new_text() {/*...*/};
    void set_text (const string &text){cout << text << endl;}
};
ConsoleBox *console_box = new ConsoleBox;
void load_script(const char* filename, bool show_script = false) {
    string script;
    FILE *file = nullptr;
    try {
        file = fopen(filename, "rb");
        if (!file) {
            throw "Error al abrir el archivo";
            return;
        }
        int c;
        char buffer[4001];
        while ((c = fread(buffer, 1, 4000, file)) > 0) {
            buffer[c] = 0;
            script.append(buffer);
        }
        fclose(file);
        file = nullptr;
        if (show_script) {
            cout << ColorConsole::fg_blue << script << ColorConsole::fg_white << endl;
        }
        console_box->new_text();
        console_box->set_text(script);
    } catch (...) {
        cerr << "Error al cargar el archivo" << endl;
        if (file) {
            fclose(file);
        }
    }
}
    void load_script()
    {
        char filename[500];
        printf("Archivo: ");
        scanf("%499s", filename);
        load_script(filename, true);
    }






