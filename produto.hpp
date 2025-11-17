#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

using namespace std;

class Produtos {
private:
    string nome;
    double preco;
    int estoque;

public:
    Produtos(string nome_p, double preco_p, int estoque_p);
    bool estoque_suficiente(int quantidade) const;
    void decrementar_estoque(int quantidade);
    void exibir_informacoes() const;

    string get_nome() const;
    double get_preco() const;
    int get_estoque() const;
};

#endif