#include "inventario.hpp"
#include <iostream>

using namespace std;

void Inventario::adicionar_produto(const Produtos& produto, const string& categoria) {
    produtos.push_back(produto);
    categorias.insert(categoria);
    contagem_por_categoria[categoria]++;
    valor_total_por_categoria[categoria] += produto.get_preco() * produto.get_estoque();
    categoria_produto[produto.get_nome()] = categoria;
}

Produtos* Inventario::buscar_produto(const string& nome) {
    for (auto& produto : produtos) {
        if (produto.get_nome() == nome) {
            return &produto;
        }
    }
    return nullptr;
}

vector<Produtos> Inventario::listar_produtos_categoria(const string& categoria) {
    vector<Produtos> produtosDaCategoria;
    for (const auto& produto : produtos) {
        if (categoria_produto[produto.get_nome()] == categoria) {
            produtosDaCategoria.push_back(produto);
        }
    }
    return produtosDaCategoria;
}

double Inventario::calcular_valor_total_inventario() {
    double total = 0.0;
    for (const auto& produto : produtos) {
        total += produto.get_preco() * produto.get_estoque();
    }
    return total;
}

void Inventario::registrarVenda(const string& nomeProduto, int quantidade) {
    Produtos* produto = buscar_produto(nomeProduto);
    if (produto && produto->estoque_suficiente(quantidade)) {
        produto->decrementar_estoque(quantidade);
        
        string categoria = categoria_produto[nomeProduto];
        double valorVendido = produto->get_preco() * quantidade;
        valor_total_por_categoria[categoria] -= valorVendido;
        
        historico_vendas.push_back("Venda: " + to_string(quantidade) + " " + nomeProduto);
        
        cout << "Venda registrada: " << quantidade << " unidade(s) de " << nomeProduto << endl;
    } else {
        cout << "Erro: Produto '" << nomeProduto << "' nao encontrado ou estoque insuficiente!" << endl;
    }
}

void Inventario::listar_categorias() const {
    for (const auto& categoria : categorias) {
        cout << "Categoria: " << categoria 
             << " | Quantidade de produtos: " << contagem_por_categoria.at(categoria)
             << " | Valor total em estoque: R$ " << valor_total_por_categoria.at(categoria) << endl;
    }
}

void Inventario::listar_historico() const {
    for (const auto& venda : historico_vendas) {
        cout << venda << endl;
    }
}

void Inventario::listar_produtos() const {
    for (const auto& produto : produtos) {
        produto.exibir_informacoes();
    }
}

bool Inventario::categoriaExiste(const string& categoria) const {
    return categorias.find(categoria) != categorias.end();
}

size_t Inventario::get_quant_categorias() const {
    return categorias.size();
}

size_t Inventario::get_quant_produtos() const {
    return produtos.size();

}

void Inventario::buscar_e_exibir_produto(const string& nome) {
    Produtos* produto = buscar_produto(nome);
    if (produto) {
        cout << "Produto encontrado: ";
        produto->exibir_informacoes();
    } else {
        cout << "Produto nao encontrado: " << nome << endl;
    }
}