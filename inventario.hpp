#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include "produto.hpp"
#include <vector>
#include <set>
#include <map>
#include <list>
#include <string>

using namespace std;

class Inventario {
private:
    vector<Produtos> produtos;
    set<string> categorias;
    map<string, int> contagem_por_categoria;
    map<string, double> valor_total_por_categoria;
    list<string> historico_vendas;
    map<string, string> categoria_produto;

public:
    void adicionar_produto(const Produtos& produto, const string& categoria);
    Produtos* buscar_produto(const string& nome);
    vector<Produtos> listar_produtos_categoria(const string& categoria);
    double calcular_valor_total_inventario();
    void registrarVenda(const string& nomeProduto, int quantidade);
    
    void listar_categorias() const;
    void listar_historico() const;
    void listar_produtos() const;
    
    bool categoriaExiste(const string& categoria) const;
    size_t get_quant_categorias() const;
    size_t get_quant_produtos() const;
    
    void buscar_e_exibir_produto(const string& nome);
};

#endif