#include <iostream>
#include "inventario.hpp"

using namespace std;

int main() {
    Inventario inventario;
    
    cout << "=== SISTEMA DE INVENTARIO ===" << endl;
    
    // Cadastro de Produtos
    cout << "\nCADASTRO DE PRODUTOS:" << endl;
    cout << "---------------------" << endl;
    
    inventario.adicionar_produto(Produtos("Nokia Tijolao", 4999.99, 15), "Eletronicos");
    inventario.adicionar_produto(Produtos("Samsung Galaxy", 3499.99, 12), "Eletronicos");
    inventario.adicionar_produto(Produtos("Camiseta Nike", 129.90, 30), "Vestuario");
    inventario.adicionar_produto(Produtos("Tenis Abididas", 399.90, 20), "Calcados");
    inventario.adicionar_produto(Produtos("Notebook Dell", 3299.99, 8), "Eletronicos");
    inventario.adicionar_produto(Produtos("Calca Jeans", 189.90, 25), "Vestuario");
    inventario.adicionar_produto(Produtos("Fone Bluetooth", 299.90, 18), "Eletronicos");
    inventario.adicionar_produto(Produtos("Pacote Big big", 16.99, 10), "Bagana");
    inventario.adicionar_produto(Produtos("Pacote Pirulito", 10.25, 5), "Bagana");
    
    cout << "Quantidade de produtos cadastrados: " << inventario.get_quant_produtos() << endl;
    
    // Situação inicial
    cout << "\nINVENTARIO INICIAL:" << endl;
    cout << "-------------------" << endl;
    inventario.listar_produtos();
    cout << "Valor total inicial: R$ " << inventario.calcular_valor_total_inventario() << endl;
    
    // Processamento Automático de Vendas
    cout << "\nPROCESSAMENTO DE VENDAS:" << endl;
    cout << "-----------------------" << endl;
    
    inventario.registrarVenda("Nokia Tijolao", 2);
    inventario.registrarVenda("Camiseta Nike", 5);
    inventario.registrarVenda("Tenis Abididas", 3);
    inventario.registrarVenda("Fone Bluetooth", 4);
    inventario.registrarVenda("Samsung Galaxy", 1);
    inventario.registrarVenda("Notebook Dell", 2);
    inventario.registrarVenda("Calca Jeans", 3);
    inventario.registrarVenda("Camiseta Nike", 2);
    inventario.registrarVenda("Pacote Big big", 1);
    inventario.registrarVenda("Tenis Abididas", 2);
    inventario.registrarVenda("Fone Bluetooth", 3);
    
    // Tentativa de venda com estoque insuficiente
    inventario.registrarVenda("iPhone 15", 20);
    
    // Relatórios Finais
    cout << "\nRELATORIOS FINAIS:" << endl;
    cout << "------------------" << endl;
    
    cout << "\nCATEGORIAS:" << endl;
    inventario.listar_categorias();
    
    cout << "\nESTOQUE ATUALIZADO:" << endl;
    inventario.listar_produtos();
    
    cout << "\nINFORMACOES FINANCEIRAS:" << endl;
    cout << "Valor total em estoque: R$ " << inventario.calcular_valor_total_inventario() << endl;
    cout << "Quantidade de produtos: " << inventario.get_quant_produtos() << endl;
    cout << "Quantidade de categorias: " << inventario.get_quant_categorias() << endl;
    
    cout << "\nHISTORICO DE VENDAS:" << endl;
    inventario.listar_historico();
    
    cout << "\n=== SISTEMA CONCLUIDO ===" << endl;
    
    return 0;
}