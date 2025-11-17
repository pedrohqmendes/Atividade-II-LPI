#include "produto.hpp"
#include <iostream> 

Produtos::Produtos(string nome_p, double preco_p, int estoque_p) 
    : nome(nome_p), preco(preco_p), estoque(estoque_p) {}

bool Produtos::estoque_suficiente(int quantidade) const {
    return quantidade > 0 && estoque >= quantidade;
}

void Produtos::decrementar_estoque(int quantidade) {
    if (estoque_suficiente(quantidade)) {
        estoque -= quantidade;
    }
}

void Produtos::exibir_informacoes() const {
    cout << "Nome: " << nome << " | Preço: R$ " << preco 
         << " | Estoque: " << estoque << endl;
}

string Produtos::get_nome() const {
    return nome;
}

double Produtos::get_preco() const {
    return preco;
}

int Produtos::get_estoque() const {
    return estoque;
}