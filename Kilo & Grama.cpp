#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <iomanip> 

using namespace std;


/* ========= STRUCTS ========= */
typedef struct datas
{
	int dia, mes, ano;
	int hora, min, seg;
}DATA;

struct Cliente
{
	int idCliente;
	char nome[50];
	char cpf[11];
	char telefone[8];
	char endereco[50];
	DATA data;
	bool ativo; 
};
Cliente pessoa[3];

struct Produto
{
	int idProduto;
	char descricao[50]; 
	int idFornecedor;
	int precoCusto;
	int precoVenda;
	int estoque;
	DATA data;
	bool ativo; 
};
Produto coisa[3];

/*struct Fornecedor{
	long int idFornecedor;
	5 
	string nome;
	float cpf;
	float telefone;
	string empresa;	
};
struct Funcionario{
	long int idFuncionario;
	string nome;
	float cpf;
	float telefone;
	float endereco;	
};
struct venda{
	long int idNota;
	long int idNota;
	long int idNota;
	long int idNota;
	string data;
	long int ValorTotal;
	
};*/

/* ========= STRUCTS ========= */












/* ========= DATA  ========= */

 DATA gerar_data()
 {
	DATA D;
	time_t mytime;
	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);
	D.dia = tm.tm_mday;
	D.mes = tm.tm_mon + 1;
	D.ano = tm.tm_year + 1900;
	D.hora = tm.tm_hour;
	D.min = tm.tm_min;
	D.seg = tm.tm_sec;
	return D;	
 }

 void imprimir_data(DATA D)
  {
	if (D.dia < 10)
		cout << "0" << D.dia << "/";
	else
		cout << D.dia << "/";
	if (D.mes < 10)
		cout << "0" << D.mes << "/";
	else
		cout << D.mes << "/";
	if (D.ano < 10)
		cout << "0" << D.ano << " ";
	else
		cout << D.ano << " ";
	if (D.hora < 10)
		cout << "0" << D.hora << ":";
	else
		cout << D.hora << ":";
	if (D.min < 10)
		cout << "0" << D.min << ":";
	else
		cout << D.min << ":";
	if (D.seg < 10)
		cout << "0" << D.seg;
	else
		cout << D.seg;
 }

 /* ========= DATA  ========= */


/*  =========== MODULO DE ATUALIZAÇÃO =========== */                               

 
 void ClienteAtualizacoes ()
  {
 		Cliente c;
	 	int id;
        bool achou=false;
        int op;
        
	  FILE *arq = fopen("clientes.dat", "rb+");
	   if (arq == NULL) 
	   {
		cout << "\n Nenhum cliente cadastrado ou erro ao abrir arquivo.\n";
		return;
       }              
	   
	   cout << "================= \n";
	   cout << "-IDs Cadastrados- \n";
	   cout << "================= \n";
	   while (fread(&c, sizeof(Cliente), 1, arq) == 1)
	    {
         cout << "ID - " << c.idCliente << " - " << c.nome << "\n"; 	   
		
		}
 	   
	  cout << "Digite o ID desejado: \n";
	  cin >> id;
	  system("cls");
	  
	  rewind(arq);
	
	  
	  while (fread(&c, sizeof(Cliente), 1, arq) == 1)
	  {
	   if (c.idCliente == id )
	    {
	    achou=true;
	    break;		 
		}
	  }	
	  if (achou)
	  {
		fseek (arq, -(long)sizeof(Cliente), SEEK_CUR);
    	  
		cout <<"Nome: " << c.nome << endl ; 
	 	cout <<"ID:" <<  c.idCliente << endl;
		cout <<"CPF: " << c.cpf << endl ;
		cout <<"Telefone"<< c.telefone<< endl;
		imprimir_data(c.data);
		cout << "\n \n";
		
	   cout << "Escolha o campo que deseja alterar" << endl;
	   cout << "1- Nome" << endl;
	   cout << "2- ID" << endl;
	   cout << "3- CPF" << endl;
	   cout << "4- Telefone" << "\n\n";
	   cin >> op;
	    
		switch (op)
		{
		 case 1:
		 {
 	 	 cout<< "Novo Nome: ";
		 cin >> c.nome;
		 break;
	     }
	
	    case 2:
		 {
 	 	 cout<< "Novo ID: ";
		 cin >> c.idCliente;
		 break;
	     }
	     
	     case 3:
		 {
 	 	 cout<< "Novo CPF: ";
		 cin >> c.cpf;
		 break;
	     }
	     
	     case 4:
		 {
 	 	 cout<< "Novo Telefone: ";
		 cin >> c.telefone;
		 break;
	     }
	
	    } 
	    
		 }
		
   fwrite (&c, sizeof(Cliente), 1, arq);
   cout << "Cliente atualizado! \n";
   
   fclose (arq);		
 }

 void ProdutosAtualizacoes ()
 {
  	Produto c;
	 int id;
        bool achou=false;
        int op;
        
	  FILE *arq = fopen("produtos.dat", "rb+");
	   if (arq == NULL) 
	   {
		cout << "\n Nenhum cliente cadastrado ou erro ao abrir arquivo.\n";
		return;
       }              
	   
	   cout << "================= \n";
	   cout << "-IDs Cadastrados- \n";
	   cout << "================= \n";
	   while (fread(&c, sizeof(Produto), 1, arq) == 1)
	    {
         cout << "ID - " << c.idProduto << " - " << c.descricao << "\n"; 	   
		
		}
 	   
	  cout << "Digite o ID desejado: \n";
	  cin >> id;
	  system("cls");
	  
	  rewind(arq);
	
	  
	  while (fread(&c, sizeof(Produto), 1, arq) == 1)
	  {
	   if (c.idProduto == id )
	    {
	    achou=true;
	    break;		 
		}
	  }	
	  if (achou)
	  {
		fseek (arq, -(long)sizeof(Produto), SEEK_CUR);
    	  
		cout <<"Descricao: " << c.descricao << endl ; 
	 	cout <<"ID Produto:" <<  c.idProduto << endl;
		cout <<"ID Funcionario: " << c.idFornecedor << endl ;
		cout <<"Custo"<< c.precoCusto<< endl;
		cout <<"Venda"<< c.precoVenda<< endl;
		cout <<"Estoque"<< c.estoque<< endl;


		imprimir_data(c.data);
		cout << "\n \n";
		
	   cout << "Escolha o campo que deseja alterar" << endl;
	   cout << "1- Descricao" << endl;
	   cout << "2- ID Produto" << endl;
	   cout << "3- ID Funcionario" << endl;
	   cout << "4- Custo" << endl;
	   cout << "5- Venda" << endl;
	   cout << "6- Estoque" << "\n\n";
	   cin >> op;
	    
		switch (op)
		{
		 case 1:
		 {
 	 	 cout<< "Nova Descricao: ";
		 cin >> c.descricao;
		 break;
	     }
	
	    case 2:
		 {
 	 	 cout<< "Novo ID Produto: ";
		 cin >> c.idProduto;
		 break;
	     }
	     
	     case 3:
		 {
 	 	 cout<< "Novo ID Fornecedor: ";
		 cin >> c.idFornecedor;
		 break;
	     }
	     
	     case 4:
		 {
 	 	 cout<< "Novo Custo: ";
		 cin >> c.precoCusto;
		 break;
	     }
	     
	      case 5:
		 {
 	 	 cout<< "Novo Venda: ";
		 cin >> c.precoVenda;
		 break;
	     }
	     
	      case 6:
		 {
 	 	 cout<< "Novo Estoque: ";
		 cin >> c.estoque;
		 break;
	     }
	     
	    
	
	    } 
	    
		 }
		
   fwrite (&c, sizeof(Produto), 1, arq);
   cout << "Produto atualizado! \n";
   
   fclose (arq);		
 
 }











 void menuAtualizacoes ()

 {
 	int op;
 	
    cout << "================= \n"; 	
	cout << " Atualizar Campo > \n";
	cout << "================= \n \n"; 	
	cout << "Escolha qual setor deseja alterar \n";
	cout << " 1 - Clientes \n";	
	cout << " 2 - Funcionarios \n";
	cout << " 3 - Produtos \n";
	cout << " 4 - Fornecedores \n";
	cout << " 5 - Notas \n \n";
	cout << " > ";
	cin >> op;
	
	system("cls");
	switch (op)
	{
	 
	 case 1:
	 {
	  ClienteAtualizacoes ();
	  break;
	 }
	
     case 3:
	 {
	  ProdutosAtualizacoes ();
	  break;
	 } 	
	
	 }
			
	
	
	}
 




/*  =========== MODULO DE ATUALIZAÇÃO =========== */    




/* =========== RELATORIOS / LISTAGEM =========== */

 void ListarClientes() {
	FILE *arq = fopen("clientes.dat", "rb");
	if (arq == NULL) {
		cout << "\nNenhum cliente cadastrado ou erro ao abrir arquivo.\n";
		return;
	}
	Cliente p;
	cout << "\n================================ LISTA DE CLIENTES ================================\n";
	cout << left << setw(8) << "ID" 
		 << setw(20) << "Nome" 
		 << setw(14) << "CPF" 
		 << setw(12) << "Telefone" 
		 << "Data Cadastro" << endl;
	cout << "-----------------------------------------------------------------------------------\n";

	while (fread(&p, sizeof(Cliente), 1, arq) == 1) {
		if (p.ativo) {
			cout << left << setw(8) << p.idCliente 
				 << setw(20) << p.nome 
				 << setw(14) << p.cpf 
				 << setw(12) << p.telefone;
			imprimir_data(p.data);
			cout << endl;
		}
	}
	fclose(arq);
 }

 void ListarProdutos() 
   {
	FILE *arq = fopen("produtos.dat", "rb");
	if (arq == NULL) {
		cout << "\nNenhum produto cadastrado ou erro ao abrir arquivo.\n";
		return;
   }
	Produto p;
	cout << "\n================================ LISTA DE PRODUTOS ================================\n";
	cout << left << setw(8) << "ID" 
		 << setw(22) << "Descricao" 
		 << setw(10) << "Estoque" 
		 << setw(12) << "Preco Venda" 
		 << "Data Cadastro" << endl;
	cout << "-----------------------------------------------------------------------------------\n";

	while (fread(&p, sizeof(Produto), 1, arq) == 1) 
	{
		if (p.ativo) {
			cout << left << setw(8) << p.idProduto 
				 << setw(22) << p.descricao 
				 << setw(10) << p.estoque 
				 << "R$ " << setw(9) << p.precoVenda;
			imprimir_data(p.data);
			cout << endl;
		}
	}
	fclose(arq);
 }

/* =========== RELATORIOS / LISTAGEM =========== */


bool BuscaCliente (int id, Cliente &pessoa);
bool BuscaProduto (int id, Produto &coisa);

/* =========== CADASTROS =========== */
bool BuscaCliente (int id, Cliente &pessoa);
bool BuscaProduto (int id, Produto &coisa);

 void CadastrarCliente() {
	system("cls");
	for(int i=0; i < 3; i++) {
		cout << "Cliente " << i+1 << endl;
		cout << "ID Cliente: ";
		cin >> pessoa[i].idCliente;

	
		Cliente temp;
		if (BuscaCliente(pessoa[i].idCliente, temp)) 
		{
			cout << "Erro: ID ja cadastrado! Tente novamente.\n";
			i--; 
			continue;
		}

		cout << "Nome: ";
		cin.ignore();
		cin.getline(pessoa[i].nome, 50);
		cout << "CPF: ";
		cin >> pessoa[i].cpf;
		cout << "Telefone: ";
		cin >> pessoa[i].telefone;
		cout << "Endereço: ";
		cin.ignore();
		cin.getline(pessoa[i].endereco, 50);
		
		
		pessoa[i].data = gerar_data();
		pessoa[i].ativo = true;
		system("cls");
	}

	FILE *arq = fopen ("clientes.dat", "ab");
	if (arq == NULL) {
		cout << "Erro ao abrir arquivo! \n";
		return;	
	}

	for(int i=0; i < 3; i++) {
		fwrite (&pessoa[i], sizeof(Cliente), 1, arq);
	}
	fclose (arq);
	cout << "Clientes Cadastrados com Sucesso! \n";
}
/* -----------------------------------------------------*/
 
 void CadastrarProduto() {
	system("cls");
	FILE *arq = fopen ("produtos.dat", "ab");
	if (arq == NULL) {
		cout << "Erro ao abrir o arquivo! \n";
		return;
	}

	for(int i=0; i < 3; i++) {
		cout << "Produto " << i+1 << endl;
		cout << "ID Produto: ";
		cin >> coisa[i].idProduto;
		Produto temp;
		if (BuscaProduto(coisa[i].idProduto, temp)) {
			cout << "Erro: ID ja cadastrado! Tente novamente.\n";
			i--; 
			continue;
		}

		cout << "Descrição do Produto: ";
		cin.ignore();
		cin.getline(coisa[i].descricao, 50);  
		cout << "ID Fornecedor: ";
		cin >> coisa[i].idFornecedor;
		cout << "Custo: ";
		cin >> coisa[i].precoCusto;
		cout << "Preço de Venda: ";
		cin >> coisa[i].precoVenda;
		cout << "Quantia em Estoque: ";
		cin >> coisa[i].estoque;
		coisa[i].data = gerar_data();
		coisa[i].ativo = true;

		fwrite (&coisa[i], sizeof(Produto), 1, arq);
		system("cls");
	}

	fclose (arq);
	cout << "Produtos Cadastrados com Sucesso! \n";
}
/* =========== CADASTROS =========== */


/* =========== BUSCA ID =========== */



void MenuBuscaID ()
{
	int op, id;

	cout << "=============== \n"; 	
	cout << " BUSQUE UM <ID> \n";
	cout << "=============== \n \n"; 	
	cout << "Escolha qual setor deseja buscar: \n";
	cout << " 1 - Clientes \n";	
	cout << " 2 - Funcionarios \n";
	cout << " 3 - Produtos \n";
	cout << " 4 - Fornecedores \n";
	cout << " 5 - Notas \n \n";
	cout << " > ";
	cin >> op;

	switch (op)
	{
		case 1:
		{
			cout << "Digite o ID do Cliente: ";
			cin >> id;
			Cliente c;
			if (BuscaCliente(id, c)) {
				cout << "\n--- CLIENTE ENCONTRADO ---\n";
				cout << "ID: " << c.idCliente << "\nNome: " << c.nome << "\nCPF: " << c.cpf 
					 << "\nTelefone: " << c.telefone << "\nEndereco: " << c.endereco << "\nData Cadastro: ";
				imprimir_data(c.data);
				cout << endl;
			} else {
				cout << "\nCliente nao encontrado ou inativo.\n";
			}
			break;
		}

		case 2:
		{
			cout << "\nSetor de Funcionarios em desenvolvimento...\n";
			break;
		} 	
		
		case 3:
		{
			cout << "Digite o ID do Produto: ";
			cin >> id;
			Produto p;
			if (BuscaProduto(id, p)) {
				cout << "\n--- PRODUTO ENCONTRADO ---\n";
				cout << "ID: " << p.idProduto << "\nDescricao: " << p.descricao 
					 << "\nPreco Venda: R$ " << p.precoVenda << "\nEstoque: " << p.estoque << "\nData Cadastro: ";
				imprimir_data(p.data);
				cout << endl;
			} else {
				cout << "\nProduto nao encontrado ou inativo.\n";
			}
			break;
		}
	}
}    



 bool BuscaCliente (int id, Cliente &pessoa)
 {
	FILE *arq = fopen("clientes.dat", "rb");
	if (arq == NULL) return false;

	while (fread(&pessoa, sizeof(Cliente), 1, arq) == 1) {
		if (pessoa.idCliente == id && pessoa.ativo) {
			fclose(arq);
			return true;
		}
	}

	fclose(arq);
	return false;
 } 
/* -----------------------------------------------------*/
bool BuscaProduto (int id, Produto &coisa)
 {
	FILE *arq = fopen("produtos.dat", "rb");
	if (arq == NULL) return false;

	while (fread(&coisa, sizeof(Produto), 1, arq) == 1) {
		if (coisa.idProduto == id && coisa.ativo) {
			fclose(arq);
			return true;
		}
	}

	fclose(arq);
	return false; 
 }

 /* =========== BUSCA ID =========== */




void menuprincipal(){
	int op1, op2;
	cout << "Sistema de Gerenciamento Empresarial" << endl;
	cout << "1 - Menu de Cadastro" << endl;
	cout << "2 - Busca por ID" << endl;
	cout << "3 - Listagem Geral de Registros Ativos" << endl;
	cout << "4 - Atualizações" << endl;
	cin >> op1;

	switch(op1)
	{
		case 1:
		{
			cout << "Menu de Cadastros" << endl;
			cout << "1 - Cliente"<< endl;
			cout << "2 - Produto"<< endl;
			/*cout << "3"<< endl;
			cout << "4"<< endl;
			cout << "5"<< endl;*/
			cin >> op2;

			switch(op2)
			{
				case 1:
				{ 
					CadastrarCliente();
					break;
				}
				case 2:
				{
					CadastrarProduto();
					break;
				}
			}
			break;
		}   
		case 2:
		{
			MenuBuscaID();
			break;
		}
		case 3:
		{
		ListarClientes();
	    cout << endl;
	    ListarProdutos();
	break;
		}
	
	  case 4:
	  {
	  menuAtualizacoes ();
	    break;
	  }
	
	}
}

int main(int argc, char** argv) {
	setlocale(LC_ALL,"Portuguese");
	
	menuprincipal();	
	
	return 0;
}
