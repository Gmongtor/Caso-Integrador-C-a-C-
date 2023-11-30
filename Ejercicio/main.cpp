#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
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
    if (filename == nullptr || strlen(filename) == 0 || strlen(filename) > 499) {
        cerr << "Nombre de archivo inválido o demasiado largo." << endl;
        return;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error al abrir el archivo");
        return;
    }

    string script;
    char buffer[4001];
    while (fread(buffer, 1, sizeof(buffer) - 1, file) > 0) {
        buffer[sizeof(buffer) - 1] = '\0';
        script.append(buffer);
    }

    if (ferror(file)) {
        perror("Error al leer el archivo");
        fclose(file);
        return;
    }

    fclose(file);

    if (show_script) {
        cout << script << endl;
    }

    console_box->new_text();
    console_box->set_text(script);
}
    void load_script()
    {
        char filename[500];
        printf("Archivo: ");
        scanf("%499s", filename);
        load_script(filename, true);
    }
int main() {
    load_script();
    return 0;
}





