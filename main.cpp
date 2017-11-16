#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//fun��o Conta Letra
/*int funcaoCl(FILE &fp){
    //Pego a bibliota std e usa as fun�oes como padrao.
    using namespace std;
	char ch;
	int contaletra = 0;

	//garante que estar� no come�o do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, ent�o
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		if(((charascii >= 65) && (charascii <= 90)) || ((charascii >= 97) && (charascii <= 122)) ){
            contaletra++;
		}
    }
	return contaletra;
}*/

int funcaoCc(FILE &fp){
    using namespace std;
	char ch;
	int contachar = 0;

	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, ent�o
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		contachar ++;
    }
	return contachar;

}
int funcaoCd(FILE &fp){
    //Pego a bibliota std e usa as fun�oes como padrao.
    using namespace std;
	char ch;
	int contadigito = 0;

	//garante que estar� no come�o do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, ent�o
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		if((charascii >= 48) && (charascii <= 57)){
            contadigito++;
		}
    }
	return contadigito;

}

int funcaoCn(FILE &fp){
    //Pego a bibliota std e usa as fun�oes como padrao.
    using namespace std;
	char ch;
	int contalinha = 1;

	//garante que estar� no come�o do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, ent�o
	while( (ch = fgetc(&fp)) != EOF ){
		int charascii = (int) ch;
		if(charascii == 10){
            contalinha++;
		}
    }
	return contalinha;

}
int funcaoCt(FILE &fp, char letra){
    //Pego a bibliota std e usa as fun�oes como padrao.
    using namespace std;
	char ch;
	int contaespecifico = 0;

	//garante que estar� no come�o do arquivo
	fseek(&fp, 0, SEEK_SET);

    //enquanto o ch (que pega 1 caracter do arquivo do fp) for diferente dO FINAL DO ARQUIVO, ent�o
	while( (ch = fgetc(&fp)) != EOF ){
        if(ch == letra){
            contaespecifico++;
		}
    }
	return contaespecifico;

}

void funcaoCo(FILE &fp, string novo){

    char* tmp[100];
    int result;

    char ch = fgetc(&fp);

    result = fread(&tmp[0], sizeof(char), 100, &fp);
    cout << result << endl;


}
/*int funcaoDo(FILE &fp){

}*/

int main(int argc, char** argv) {
    using namespace std;
	setlocale(LC_ALL, "portuguese");

	FILE *fp; //abre arquivo
	string opcao = argv[1];
	char leitura;

    //se a pessoa digitar um desses comandos, ent�o ele precisa passar 3 par�metros
	if((opcao == "CL") || (opcao == "CC") || (opcao == "CD") || (opcao == "CN")){
		if(argc != 3){
            printf("Voc� precisa passar 3 par�metros");
            exit(1);
		}
    //se a pessoa digitar uma dessas op��es, ent�o ele precisa passar 4 par�metros
	}else if((opcao == "CT") || (opcao == "CO") || (opcao == "DO")){
			if(argc != 4){
                printf("Voc� precisa passar 4 par�metros");
                exit(2);
			}
    //se ele digitar qualquer coisa fora das op��es ent�o � inv�lido
	}else{
		printf("%s", argv[1]);
		exit(3);
	}

	if ((opcao == "CO") || (opcao == "DO")){
        leitura = 'b';
	}else{
        leitura = 't';
	}

    //abre o arquivo e verifica se ele existe.
    if(leitura == 'b'){
        if((fp = fopen(argv[2], "rb")) == NULL){
		printf("Arquivo n�o pode ser aberto\n");
		exit(1);
        }
    }else{
        if((fp = fopen(argv[2], "rt")) == NULL){
		printf("Arquivo n�o pode ser aberto\n");
		exit(1);
        }
    }



    /*printf("%d\n", funcaoCl(*fp));
    printf("%d\n", funcaoCc(*fp));
    printf("%d\n", funcaoCd(*fp));
    printf("%d\n", funcaoCn(*fp));
    printf("%d\n", funcaoCt(*fp, *argv[3]));*/
    funcaoCo(*fp, argv[3]);




    fclose(fp);
    //Caso a pessoa digite qualquer op��o v�lida, ent�o ele vai para a fun�ao chamada.
	/*switch (6){
		case "CL" : funcaoCl(fp); break;
		case "CC" : funcaoCc(fp); break;
		case "CD" : funcaoCd(fp); break;
		case "CN" : funcaoCn(fp); break;
		case "CT" : funcaoCt(fp); break;
		case "CO" : funcaoCo(fp); break;
		case "DO" : funcaoDo(fp); break;
		default : printf("Op��o inv�lida!");
	}*/

	return 0;
}
