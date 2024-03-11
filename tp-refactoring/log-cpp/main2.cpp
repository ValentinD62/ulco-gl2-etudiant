#include <fstream>
#include <functional>
#include <iostream>

using logFunc_t = std::function<void(const std::string &)>;

int add3(int n) {
    return n+3;
}

int mul2(int n) {
    return n*2;
}

int inj_dependance(int v0, logFunc_t fonction){
    fonction ("add3 " + std::to_string(v0) + "\n");
    const int v1 = add3(v0);
    fonction ("mul2 " + std::to_string(v1) + "\n");
    const int v2 = add3(v1);
    return v2;
}

void f1(const std::string & str){
    std::cout << str;
}

void f2(const std::string & str, std::ostream fichier){
    fichier << str;
}

int main() {
    std::cout << "this is log-cpp" << std::endl;

    logFunc_t f1 = [](const std::string & str){
        std::cout << str;
    };
    std::string const nomFichier("../log2.txt");
    std::ofstream monFlux(nomFichier.c_str());
    logFunc_t f2 = [& monFlux](const std::string & str){
        monFlux << str;
    };

    const int res = inj_dependance(18, f1);
    std::cout << res << std::endl;
    
    const int resF = inj_dependance(18, f2);
    std::cout << resF << std::endl;
    monFlux.close();
    return 0;
}

