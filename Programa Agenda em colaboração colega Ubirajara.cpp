#include <iostream>
#include <string>
using namespace std;

struct Contato {
    string nome;
    int telefone;
    string celular;
    string endereco;
    string data;
    Contato* proximo;
};

void criarContato(Contato** lista) {
    Contato* novoContato = new Contato; 
    cout << "--------------------------------------------------------------" << endl;
    cout << "Digite o nome do contato: ";
    cin.ignore();
    getline(cin, novoContato->nome);
    cout << "Digite o telefone do contato: ";
    cin >> novoContato->telefone;
    cout << "Digite o celular do contato: ";
    cin.ignore();
    getline(cin, novoContato->celular);
    cout << "Digite o endereco do contato: ";
    getline(cin, novoContato->endereco);
    cout << "Digite a data de NASCIMENTO contato: ";
    getline(cin, novoContato->data);
    cout << "--------------------------------------------------------------" << endl;
    novoContato->proximo = NULL;

    if (*lista == NULL) {
        *lista = novoContato;
        return;
    }
    Contato* atual = *lista;
    Contato* anterior = NULL;
    while (atual != NULL && novoContato->nome > atual->nome) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (anterior == NULL) {
        novoContato->proximo = *lista;
        *lista = novoContato;
    } else {
        anterior->proximo = novoContato;
        novoContato->proximo = atual;
    }
}

void mostrarLista(const Contato* lista) {
    cout << "--------------------------------------------------------------" << endl;
    cout << "Lista de contatos:\n" << endl;
    const Contato* atual = lista;
    while (atual != NULL) {
        cout << "Nome: " << atual->nome << endl;
        cout << "Telefone: " << atual->telefone << endl;
        cout << "Celular: " << atual->celular << endl;
        cout << "Endereco: " << atual->endereco << endl;
        cout << "Data: " << atual->data << endl;
        cout << endl;
        atual = atual->proximo;
    }
    cout << "--------------------------------------------------------------" << endl;
}

Contato* buscarPorNome(const Contato* lista, const string& nomeBuscado) {
    const Contato* atual = lista;
    while (atual != NULL) {
        if (atual->nome == nomeBuscado) {
            return const_cast<Contato*>(atual);
        }
        atual = atual->proximo;
    }
    return NULL;
}

Contato* buscarPorTelefone(const Contato* lista, const int& telefoneBuscado) {
    const Contato* atual = lista;
    while (atual != NULL) {
        if (atual->telefone == telefoneBuscado) {
            return const_cast<Contato*>(atual); 
        }
        atual = atual->proximo;
    }
    return NULL;
}

Contato* buscarPorData(const Contato* lista, const string& dataBuscada) {
    const Contato* atual = lista;
    while (atual != NULL) {
        if (atual->data == dataBuscada) {
            return const_cast<Contato*>(atual); // Comando novo para manipular o ponteiro const
        }
        atual = atual->proximo;
    }
    return NULL;
}

void excluir(Contato*& lista, const string& nomeBuscado) {
    Contato* anterior = NULL;
    Contato* atual = lista;
    while (atual != NULL) {
        if (atual->nome == nomeBuscado) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
            } else {
                lista = atual->proximo;
            }
            delete atual;
			cout << "--------------------------------------------------------------" << endl;
            cout << "Contato excluido com sucesso." << endl;
            cout << "--------------------------------------------------------------" << endl;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "Contato nao encontrado." << endl;
    cout << "--------------------------------------------------------------" << endl;
}

int main() {
    Contato* lista = NULL; // A nova especie de "topo"
    int opcao = 0;
    do {
    	system("pause");
    	system("cls");
        cout << "(1) - Salvar novo contato" << endl;
        cout << "(2) - Exibir todos os contatos" << endl;
        cout << "(3) - Buscar contato por nome" << endl;
        cout << "(4) - Buscar contato por telefone" << endl;
        cout << "(5) - Buscar contato por data de nascimento" << endl;
        cout << "(6) - Apagar contato" << endl;
        cout << "(7) - Finalizar o programa" << endl;
        cout << "Digite o numero entre (x) para escolher opcao desejada: ";
        cin >> opcao;
        if (opcao == 1) {
            criarContato(&lista);
            cout << "Contato inserido em ordem alfabetica!" << endl;
        }
		else if (opcao == 2) {
            mostrarLista(lista);
        }
		else if (opcao == 3) {
	        string nomeBuscado;
	        cout << "Digite o nome do contato a ser buscado: ";
	        cin.ignore();
	        getline(cin, nomeBuscado);
	        Contato* contatoEncontrado = buscarPorNome(lista, nomeBuscado);
	        if (contatoEncontrado != NULL) {
	        	cout << "--------------------------------------------------------------" << endl;
	            cout << "Contato encontrado:" << endl;
	            cout << "Nome: " << contatoEncontrado->nome << endl;
	            cout << "Telefone: " << contatoEncontrado->telefone << endl;
	            cout << "Celular: " << contatoEncontrado->celular << endl;
	            cout << "Endereco: " << contatoEncontrado->endereco << endl;
	            cout << "Data de nascimento: " << contatoEncontrado->data << endl;
	            cout << "--------------------------------------------------------------" << endl;
	        } 
			else {
	        	cout << "--------------------------------------------------------------" << endl;
	            cout << "Contato nao encontrado." << endl;
	            cout << "--------------------------------------------------------------" << endl;
	        }
    	}
		else if (opcao == 4) {
	        int telefoneBuscado;
	        cout << "Digite o telefone do contato a ser buscado: ";
	        cin >> telefoneBuscado;
	        Contato* contatoEncontrado = buscarPorTelefone(lista, telefoneBuscado);
	        if (contatoEncontrado != NULL) {
	        	cout << "--------------------------------------------------------------" << endl;
	            cout << "Contato encontrado:" << endl;
	            cout << "Nome: " << contatoEncontrado->nome << endl;
	            cout << "Telefone: " << contatoEncontrado->telefone << endl;
	            cout << "Celular: " << contatoEncontrado->celular << endl;
	            cout << "Endereco: " << contatoEncontrado->endereco << endl;
	            cout << "Data de nascimento: " << contatoEncontrado->data << endl;
	            cout << "--------------------------------------------------------------" << endl;
	        } else {
	        	cout << "--------------------------------------------------------------" << endl;
	            cout << "Contato nao encontrado." << endl;
	            cout << "--------------------------------------------------------------" << endl;
	        }
	    }
		else if (opcao == 5) {
	        string dataBuscada;
	        cout << "Digite a data do contato a ser buscado (dd/mm/aaaa): ";
	        cin >> dataBuscada;
	        Contato* contatoEncontrado = buscarPorData(lista, dataBuscada);
	        if (contatoEncontrado != NULL) {
	        	cout << "--------------------------------------------------------------" << endl;
	            cout << "Contato encontrado:" << endl;
	            cout << "Nome: " << contatoEncontrado->nome << endl;
	            cout << "Telefone: " << contatoEncontrado->telefone << endl;
	            cout << "Celular: " << contatoEncontrado->celular << endl;
	            cout << "Endereco: " << contatoEncontrado->endereco << endl;
	            cout << "Data de nascimento: " << contatoEncontrado->data << endl;
	            cout << "--------------------------------------------------------------" << endl;
	        } else {
	        	cout << "--------------------------------------------------------------" << endl;
	            cout << "Contato nao encontrado." << endl;
	            cout << "--------------------------------------------------------------" << endl;
	        }
	    }
		else if (opcao == 6) {
	        string nomeBuscado;
	        cout << "Digite o nome do contato a ser excluido: ";
	        cin.ignore();
	        getline(cin, nomeBuscado);
	        excluir(lista, nomeBuscado);
	    }
		else if (opcao == 7) {
			cout << "--------------------------------" << endl;
            cout << "Encerrando..." << endl;
            cout << "--------------------------------" << endl;
        }
		else {
			cout << "--------------------------------------------------------------" << endl;
            cout << "Opcao invalida. Tente novamente." << endl;
            cout << "--------------------------------------------------------------" << endl;
        }
    }  while(opcao != 7);
    //Liberando memoria dos contatos
    Contato* atual = lista;
	while (atual != NULL) {
        Contato* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    return 0;
}
