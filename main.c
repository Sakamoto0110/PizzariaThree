#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ISRUNNING 1

// COMMENTS TIPS
// FUNCTIONS TYPES:
// INTERNAL -> ONLY USED BY OTHERS FUNCTIONS UNLESS FOR TESTING
// EXTERNAL -> CALLED BY USER
//


typedef struct{
int ingrediente1;
int ingrediente2;
int ingrediente3;
int ingrediente4;
int ingrediente5;
int coca;
int fanta;
int cerveja;
}Estoque;

typedef struct{
char sabor[255];
int cod;
int preco;
int ingrediente1;
int ingrediente2;
int ingrediente3;
int ingrediente4;
int ingrediente5;
}Pizza;

typedef struct{
int cod;
char sabor[255];
int vl;
}Bebida;



typedef struct{
Pizza pizzas[99];
char cpf[255];
char nome[255];
char end[255];
char tel[255];
int valor_total;
}Cliente;



typedef struct{
char dia[3];
char mes[3];
int nPizza;
int nBebida;
Cliente cliente;
Pizza pizzas[99];
Bebida bebidas[99];
int vl_total;

}Registro;



int MAIN_STATE = 2;
int operation = 0;
Bebida nullBebida;
Bebida coca;
Bebida fanta;
Bebida cerveja;


void menuAdmin()
{
    // INTERNAL
    system("cls");
    printf("Menu administrador. \n");
    printf("Digite -1 para deslogar.\n");
    printf("Digite 1 para fazer um pedido.\n");
    printf("Digite 2 para ver pizzas disponiveis.\n");
    printf("Digite 3 para cadastrar um cliente.\n");
    printf("Digite 4 para inserir feedback.\n");
    printf("Digite 5 para ver feedback anterior.\n");
    printf("\n");
    printf("Digite 6 para cadastrar nova pizza.\n");
    printf("Digite 7 para gerar relatorios.\n");
    printf("Digite 8 para conferir estoque.\n");
    int input = 0;
    scanf("%i",&input);
    switch(input){
    case -1:
        MAIN_STATE = 0;
        operation = 0;
        break;
    case 1:
        // Pedir pizza
        operation = 1;
        break;
    case 2:
        // Ver pizzas disponiveis
        operation = 2;
        break;
    case 3:
        // Cadastrar cliente
        operation = 3;
        break;
    case 4:
        // Inserir feedback
        operation = 4;
        break;
    case 5:
        // Ver feedback anterior
        operation = 5;
        break;
    case 6:
        // Cadastrar nova pizza;
        operation = 6;
        break;
    case 7:
        // Gerar relatorios;
        operation = 7;
        break;
    case 8:
        // Conferir estoque
        operation = 8;
        break;
    }
}


void menuUser()
{
    printf("\nMenu usuario\n");
    printf("Digite -1 para deslogar.\n");
    printf("Digite 1 para fazer um pedido.\n");
    printf("Digite 2 para ver pizzas disponiveis.\n");
    printf("Digite 3 para cadastrar um cliente.\n");
    printf("Digite 4 para inserir feedback.\n");
    printf("Digite 5 para ver o feedback\n");
    int input = 0;
    scanf("%i", &input);
    switch(input){
    case -1:
        // logout
        MAIN_STATE = 0;
        operation = 0;
        break;
    case 1:
        // fazer pedido
        operation = 1;
        break;
    case 2:
        // ver pizzas
        operation = 2;
        break;
    case 3:
        // cadastrar cliente
        operation = 3;
        break;
    case 4:
        // inserir feedback
        operation = 4;
        break;
    case 5:
        // ver feedback
        operation = 5;
        break;

    }

}








void cadastroCliente()
{
    // TYPE: EXTERNAL
    char nome[255];
    char  cpf[255];
    char  tel[255];
    char  end[255];
    system("cls");

    printf("Cadastrando cliente: \n");

    printf("Insira o cpf: ");
    fflush(stdin);
    scanf ("%[^\n]%*c", cpf);

    printf("Insira o nome: ");
    fflush(stdin);
    scanf ("%[^\n]%*c", nome);

    printf("Insira o telefone: ");
    fflush(stdin);
    scanf ("%[^\n]%*c", tel);

    printf("Insira o endereco: ");
    fflush(stdin);
    scanf ("%[^\n]%*c", end);

    system("cls");
    printf("Confirma os dados?\n");
    printf("CPF: %s\n",     cpf);
    printf("Nome: %s\n",    nome);
    printf("Telefone: %s\n",tel);
    printf("Endereco: %s\n",end);
    printf("Digite 1 para confirmar e salvar ou digite 2 para anular operacao\n");

    int input = 0;
    fflush(stdin);
    scanf("%i",&input);
    if(input == 1){
        FILE* file = fopen("clientes.txt", "a+");
        fprintf(file, "CPF: %s\n"     , cpf);
        fprintf(file, "Nome: %s\n"    , nome);
        fprintf(file, "Telefone: %s\n", tel);
        fprintf(file, "Endereco: %s\n", end);
        fprintf(file, "\n");
        fclose(file);
        printf("Cliente salvo com sucesso.\n");
        system("pause");

    }else{
        printf("Cliente não salvo.\n");
        system("pause");
    }
    operation = 0;
}

Cliente carregarCliente(char cpf_[])
{
    // INTERNAL
    system("cls");
    int control = 1;
    char nome[255];
    char cpf[255];
    char tel[255];
    char end[255];
    strcpy(nome,"-1");
    strcpy(cpf ,"-1");
    strcpy(tel ,"-1");
    strcpy(end ,"-1");
    Cliente cliente;
    FILE*file = fopen("clientes.txt", "a+");
    while(control != -1){
        char read[255];
        char content[255];
        char datatype[255];
        fgets(read,255,file);
        sscanf(read, "%s %s", datatype, content);
        if(feof(file)){
            control = -1;
        }else  if(strcasecmp(datatype, "CPF:") == 0){
            if(strcasecmp(content,cpf_) == 0){
               strcpy(cpf, content);
            }
        } else if (strcmp(datatype, "Nome:") == 0){
            if(strcasecmp(cpf,cpf_) == 0){
               strcpy(nome, content);
            }
        }else if (strcmp(datatype, "Telefone:") == 0){
            if(strcasecmp(cpf,cpf_) == 0){
                strcpy(tel, content);
            }
        }else if (strcmp(datatype, "Endereco:") == 0){

            if(strcasecmp(cpf,cpf_) == 0){
                strcpy(end, content);
                break;
            }
        }
    }
    strcpy(cliente.nome,nome);
    strcpy(cliente.cpf,cpf);
    strcpy(cliente.tel,tel);
    strcpy(cliente.end,end);
    fclose(file);
    return cliente;
}

void cadastroPizza()
{
    // EXTERNAL
    system("cls");
    int id = 0;
    char sabor[255];
    int preco = 0;
    int qt_ingrediente1 = 0;
    int qt_ingrediente2 = 0;
    int qt_ingrediente3 = 0;
    int qt_ingrediente4 = 0;
    int qt_ingrediente5 = 0;

    system("cls");
    printf("Cadastrando Pizza: \n");

    printf("Insira o codigo da pizza: ");
    fflush(stdin);
    scanf("%i",&id);

    printf("Insira o nome do sabor: ");
    fflush(stdin);
    scanf ("%[^\n]%*c", sabor);

    printf("Insira o preco: ");
    fflush(stdin);
    scanf("%i",&preco);

    printf("Insira a quantidade do ingrediente1: ");
    fflush(stdin);
    scanf("%i",&qt_ingrediente1);

    printf("Insira a quantidade do ingrediente2: ");
    fflush(stdin);
    scanf("%i",&qt_ingrediente2);

    printf("Insira a quantidade do ingrediente3: ");
    fflush(stdin);
    scanf("%i",&qt_ingrediente3);

    printf("Insira a quantidade do ingrediente4: ");
    fflush(stdin);
    scanf("%i",&qt_ingrediente4);

    printf("Insira a quantidade do ingrediente5: ");
    fflush(stdin);
    scanf("%i",&qt_ingrediente5);

    system("cls");
    printf("Confirma os dados?\n");
    printf("Codigo: %i\n",    id);
    printf("Sabor: %s\n",    sabor);
    printf("Preco: %i\n",    preco);
    printf("Quantidade ingrediente1: %i\n",qt_ingrediente1);
    printf("Quantidade ingrediente2: %i\n",qt_ingrediente2);
    printf("Quantidade ingrediente3: %i\n",qt_ingrediente3);
    printf("Quantidade ingrediente4: %i\n",qt_ingrediente4);
    printf("Quantidade ingrediente5: %i\n",qt_ingrediente5);

    printf("Digite 1 para confirmar e salvar ou digite 2 para anular operacao\n");

    int input = 0;
    fflush(stdin);
    scanf("%i",&input);
    if(input == 1){
        FILE* file = fopen("pizzas.txt", "a+");
        fprintf(file, "Codigo: %i\n"      , id);
        fprintf(file, "Sabor: %s\n"       , sabor);
        fprintf(file, "Preco: %i\n"       , preco);
        fprintf(file, "Ingrediente1: %i\n",qt_ingrediente1);
        fprintf(file, "Ingrediente2: %i\n",qt_ingrediente2);
        fprintf(file, "Ingrediente3: %i\n",qt_ingrediente3);
        fprintf(file, "Ingrediente4: %i\n",qt_ingrediente4);
        fprintf(file, "Ingrediente5: %i\n",qt_ingrediente5);
        fprintf(file, "\n");
        fclose(file);
    }
    operation = 0;


}



void mostrarPizzas()
{
    // EXTERNAL
    FILE*file = fopen("pizzas.txt", "a+");
    int codigo = 0;

    int cd_pizza = 0;
    char sabor_pizza[255];
    int preco_pizza = 0;
    int ingredientes1 = 0;
    int ingredientes2 = 0;
    int ingredientes3 = 0;
    int ingredientes4 = 0;
    int ingredientes5 = 0;
    while(codigo!=-1){
        char read[255];
        char datatype[255];
        int i = -1;
        char str[255];
        fgets(read,255,file);
        sscanf(read, "%s %d %s", datatype, &i, str);

        if(feof(file)){
            codigo = -1;
        }else if(strcmp(datatype, "Codigo:") == 0){
            cd_pizza = i;
        }
        else if(i == -1){
             sscanf(read, "%s %s", datatype, str);
             strcpy(sabor_pizza,str);
        }

        else if(strcmp(datatype, "Preco:") == 0){
            preco_pizza = i;
        }

        else if(strcmp(datatype, "Ingrediente1:") == 0){

            ingredientes1 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente2:") == 0){
            ingredientes2 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente3:") == 0){
            ingredientes3 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente4:") == 0){
            ingredientes4 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente5:") == 0){
            ingredientes5 = i>0?i:0;
            printf("\ncodigo pizza:  %i\n", cd_pizza);
            printf("sabor pizza:   %s\n", sabor_pizza);
            printf("preco pizza:   %i\n", preco_pizza);
            printf("ingredientes1: %i\n", ingredientes1);
            printf("ingredientes2: %i\n", ingredientes2);
            printf("ingredientes3: %i\n", ingredientes3);
            printf("ingredientes4: %i\n", ingredientes4);
            printf("ingredientes5: %i\n", ingredientes5);
            printf("----------------\n");



        }

    }
    system("pause");
    operation = 0;



    fclose(file);
}

Pizza carregarPizza(int cd)
{
    // INTERNAL
    FILE*file = fopen("pizzas.txt", "a+");
    int codigo = 0;
    int cd_pizza = 0;
    char sabor_pizza[255];
    int preco_pizza = 0;
    int ingredientes1 = 0;
    int ingredientes2 = 0;
    int ingredientes3 = 0;
    int ingredientes4 = 0;
    int ingredientes5 = 0;
    while(codigo!=-1){
        char read[255];
        char datatype[255];
        int i = -1;
        char str[255];
        fgets(read,255,file);
        sscanf(read, "%s %d %s", datatype, &i, str);

        if(feof(file)){
            codigo = -1;
        }else if(strcmp(datatype, "Codigo:") == 0){

            cd_pizza = i;
        }

        else  if(i == -1){
             sscanf(read, "%s %s", datatype, str);
             strcpy(sabor_pizza,str);
        }

        else if(strcmp(datatype, "Preco:") == 0){

            preco_pizza = i;
        }

        else if(strcmp(datatype, "Ingrediente1:") == 0){

            ingredientes1 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente2:") == 0){
            ingredientes2 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente3:") == 0){
            ingredientes3 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente4:") == 0){
            ingredientes4 = i>0?i:0;
        }
        else if(strcmp(datatype, "Ingrediente5:") == 0){
            ingredientes5 = i>0?i:0;
        }
        if(cd == cd_pizza-1){
            break;
        }


    }
    fclose(file);
    Pizza pizza;
    pizza.cod = -1;
    pizza.preco = 0;
    pizza.ingrediente1 = 0;
    pizza.ingrediente2 = 0;
    pizza.ingrediente3 = 0;
    pizza.ingrediente4 = 0;
    pizza.ingrediente5 = 0;
    strcpy(pizza.sabor, " ");


    if(cd <= cd_pizza){
        strcpy(pizza.sabor, sabor_pizza);
        pizza.cod = cd_pizza;
        pizza.preco = preco_pizza;
        pizza.ingrediente1 = ingredientes1;
        pizza.ingrediente2 = ingredientes2;
        pizza.ingrediente3 = ingredientes3;
        pizza.ingrediente4 = ingredientes4;
        pizza.ingrediente5 = ingredientes5;
    }

    return pizza;


}

int login(char user[], int password)
{
    if( strcasecmp(user, "Admin") == 0 && password == 1234){
        return 2;
    }
    if ( strcasecmp( user, "User" == 0) && password == 1234){

        return 1;
    }
    return 0;
}

void salvarRegistro(Registro reg)
{
    // INTERNAL
    system("cls");
    char fileName[255] = "registro_sede1.txt";
    printf("fileName: %s\n", fileName);
    FILE*file = fopen(fileName, "a+");
    fprintf(file, "Mes: %s\n", reg.mes);
    fprintf(file, "Dia: %s\n", reg.dia);
    fprintf(file, "Cpf: %s\n", reg.cliente.cpf);
    int total = 0;
    for(int c = 0; c < 99; c++){
        Pizza pizza = reg.pizzas[c];
        Bebida bebida = reg.bebidas[c];
        if(pizza.cod != -1){
            fprintf(file,"Pizza: %s %i\n", pizza.sabor, pizza.preco);
            total+= pizza.preco;
        }
        if(bebida.cod != -1){
            fprintf(file, "Bebida: %s %i\n", bebida.sabor, bebida.vl);
            total+=bebida.vl;
        }
    }
    fprintf(file,"Total: %i\n\n", total);
    fclose(file);
}



Estoque carregarEstoque()
{
    // TBD
    Estoque estoque;
    FILE*file = fopen("estoque.txt", "a+");
    int control = 0;
    while(control != -1){
        char read[255];
        char datatype[255];
        int content = 0;
        fgets(read,255,file);
        int v = 0;
        int len = strlen(read);
        sscanf(read, "%s %i", datatype, &content);
        if(feof(file)){
            control = -1;
        }else if(len > 1){
            if( strcasecmp(datatype, "Ingrediente1:") == 0){
                estoque.ingrediente1 = content;
            }else if( strcasecmp(datatype, "Ingrediente2:") == 0){
                estoque.ingrediente2 = content;
            }else if( strcasecmp(datatype, "Ingrediente3:") == 0){
                estoque.ingrediente3 = content;
            }else if( strcasecmp(datatype, "Ingrediente4:") == 0){
                estoque.ingrediente4 = content;
            }else if( strcasecmp(datatype, "Ingrediente5:") == 0){
                estoque.ingrediente5 = content;
            }else if( strcasecmp(datatype, "Coca:") == 0){
                estoque.coca = content;
            }else if( strcasecmp(datatype, "Fanta:") == 0){
                estoque.fanta = content;
            }else if( strcasecmp(datatype, "Cerveja:") == 0){
                estoque.cerveja = content;
            }
        }
    }
    fclose(file);
    return estoque;
}


void salvarEstoque(Estoque estoque){
    FILE*file = fopen("estoque.txt", "w+");
    fprintf(file,"Ingrediente1: %i\n", estoque.ingrediente1);
    fprintf(file,"Ingrediente2: %i\n", estoque.ingrediente2);
    fprintf(file,"Ingrediente3: %i\n", estoque.ingrediente3);
    fprintf(file,"Ingrediente4: %i\n", estoque.ingrediente4);
    fprintf(file,"Ingrediente5: %i\n", estoque.ingrediente5);

    fprintf(file,"Coca: %i\n", estoque.coca);
    fprintf(file,"Fanta: %i\n", estoque.fanta);
    fprintf(file,"Cerveja: %i\n", estoque.cerveja);
    fprintf(file,"\n");
    fclose(file);
}

void verEstoque(Estoque estoque)
{
    system("cls");
    printf("Estoque: \n");
    printf("Ingrediente1: %i\n", estoque.ingrediente1);
    printf("Ingrediente2: %i\n", estoque.ingrediente2);
    printf("Ingrediente3: %i\n", estoque.ingrediente3);
    printf("Ingrediente4: %i\n", estoque.ingrediente4);
    printf("Ingrediente5: %i\n", estoque.ingrediente5);
    printf("Bebidas: \n\n");
    printf("Coca: %i\n", estoque.coca);
    printf("Fanta: %i\n", estoque.fanta);
    printf("Cerveja: %i\n", estoque.cerveja);
    system("pause");
    operation = 0;
}



int verificarEstoque(Pizza pizza, Estoque estoque){
    if(pizza.ingrediente1 > estoque.ingrediente1){
        return 1;
    }
    if(pizza.ingrediente2 > estoque.ingrediente2){
        return 1;
    }
    if(pizza.ingrediente3 > estoque.ingrediente3){
        return 1;
    }
    if(pizza.ingrediente4 > estoque.ingrediente4){
        return 1;
    }
    if(pizza.ingrediente5 > estoque.ingrediente5){
        return 1;
    }
    return 0;
}

int verificarEstoqueDois(int n, Estoque estoque){
    if(n == 1){
        // coca
        if(estoque.coca > 0){
            return 0;
        }else{
            return 1;
        }
    }
    if(n == 2){
        // fanta
        if(estoque.fanta > 0){
            return 0;
        }else{
            return 1;
        }
    }
    if(n == 3){
        // cerveja
        if(estoque.cerveja > 0){
            return 0;
        }else{
            return 1;
        }
    }
    return 0;
}

Estoque subEstoque(Pizza pizza, Estoque old){
    Estoque estoque;

    estoque.ingrediente1 = old.ingrediente1 - pizza.ingrediente1;
    estoque.ingrediente2 = old.ingrediente2 - pizza.ingrediente2;
    estoque.ingrediente3 = old.ingrediente3 - pizza.ingrediente3;
    estoque.ingrediente4 = old.ingrediente4 - pizza.ingrediente4;
    estoque.ingrediente5 = old.ingrediente5 - pizza.ingrediente5;
    estoque.coca = old.coca;
    estoque.fanta = old.fanta;
    estoque.cerveja = old.cerveja;


    return estoque;
}

Estoque subEstoqueDois(Estoque old, int n){
    Estoque estoque;
    estoque.ingrediente1 = old.ingrediente1;
    estoque.ingrediente2 = old.ingrediente2;
    estoque.ingrediente3 = old.ingrediente3;
    estoque.ingrediente4 = old.ingrediente4;
    estoque.ingrediente5 = old.ingrediente5;
    if(n == 1){
        //coca
        estoque.coca = old.coca-1;
        estoque.fanta = old.fanta;
        estoque.cerveja = old.cerveja;
    }
    if(n == 2){
        //fanta
        estoque.coca = old.coca;
        estoque.fanta = old.fanta-1;
        estoque.cerveja = old.cerveja;
    }
    if(n == 3){
        //cerveja
        estoque.coca = old.coca;
        estoque.fanta = old.fanta;
        estoque.cerveja = old.cerveja-1;
    }
    return estoque;
}



void fazerPedido()
{
    // EXTERNAL
    system("cls");
    printf("Por favor insira o CPF do cliente: ");
    char cpf[255];
    scanf("%s",&cpf);
    Cliente cliente = carregarCliente(cpf);
    Registro reg;
    for(int c = 0; c < 99; c++){
        strcpy(reg.bebidas[c].sabor, "");
        reg.bebidas[c].cod = -1;
        reg.pizzas[c].cod = -1;
    }
    if( strcmp(cliente.nome,"-1") == 0){
        printf("Cliente nao cadastrado, gostaria de cadastrar o cliente?\n");
        printf("Digite 1 para cadastrar. Digite 2 para não cadastrar e sair.");
        int input = 0;
        scanf("%i", &input);
        if(input == 1){
            operation = 1;
        }else{
            operation = 0;
        }
    }else{
        printf("Prosseguindo com o pedido, senhor %s.",cliente.nome);
        reg.cliente = cliente;
        char buffer1[3];
        char buffer2[3];
        printf("\nInsira o dia do pedido: ");
        scanf("%s", &buffer1);
        printf("\nInsira o mes do pedido: ");
        scanf("%s", &buffer2);
        strcpy(reg.dia, buffer1);
        strcpy(reg.mes, buffer2);
        reg.nBebida = 0;
        reg.nPizza = 0;
        int input = 0;
        int control = 0;
        int nItem = 0;
        int subTotal = 0;
        while(control != -1){
            Estoque estoque1 = carregarEstoque();
            system("cls");
            printf("Realizando peiddo no nome de: %s\n", cliente.nome);
            printf("Digite -1 para cancelar operacao.\n");
            printf("Digite 0 para realizar o pedido.\n");
            printf("Digite 1 para pedir uma pizza.\n");
            printf("Digite 2 para pedir uma bebida.\n");
            printf("Digite 3 para ver o pedido.\n");
            scanf("%i", &input);
            int input1 = 0;
            switch(input){
            case 1:
                printf("Por favor, digite o codigo da pizza desejada. ( digite -1 para ver a lista de pizzas ) \n");
                scanf("%i", &input1);
                if(reg.nPizza >= 99){
                    printf("Aviso, limite atingido. Por favor finalize esse pedido e inicie um novo.\n");
                }else{
                    if(input1 != -1){
                        Pizza pizza = carregarPizza(input1);
                        if(pizza.cod != -1){
                            if(verificarEstoque(pizza,estoque1)){
                                printf("Estoque indisponivel.\n");
                                system("pause");
                            }else{
                                printf("Pizza selecionada: %s\n", pizza.sabor);
                                printf("Digite 1 para confirmar ou digite 2 para anular.");
                                int input2 = 0;
                                scanf("%i", &input2);
                                if(input2 == 1){
                                    Estoque estoque2 = subEstoque(pizza, estoque1);
                                    salvarEstoque(estoque2);
                                    reg.pizzas[reg.nPizza] = pizza;
                                    reg.nPizza++;
                                }
                            }
                        }

                    }else{
                        mostrarPizzas();
                    }
                }
                break;
            case 2:
                if(reg.nBebida >= 99){
                    printf("Numero de bebidas excedeu o limite, por favor encerre este pedido e tente novamente.");
                }else{
                    printf("Digite o codigo da bebida desejada: \n");
                    printf("1. Coca;\n");
                    printf("2. Fanta;\n");
                    printf("3. Cerveja;\n");
                    Bebida bebida;
                    int n = 0;
                    scanf("%i", &input1);
                    if(input1 == 1 || input1 == 2 || input1 == 3){
                        switch(input1){
                        case 1:
                            n = 1;
                            bebida = coca;
                            break;
                        case 2:
                            n = 2;
                            bebida = fanta;
                            break;
                        case 3:
                            n = 3;
                            bebida = cerveja;
                            break;
                        }
                    }
                    if(verificarEstoqueDois(n,estoque1) == 1){
                        printf("Estoque indisponivel.\n");
                        system("pause");
                    }else{
                        printf("Adicionando um(a) %s ao pedido.\n", bebida.sabor);
                        printf("Digite 1 para confirmar ou digite 2 para anular.\n");
                        scanf("%i", &input1);
                        if(input1 == 1){
                            Estoque estoque2 = subEstoqueDois(estoque1, n);
                            salvarEstoque(estoque2);
                            reg.bebidas[reg.nBebida] = bebida;
                            reg.nBebida++;
                        }
                    }
                }

                break;
            case 3:
                printf("Pedidos solicitados ate o momento ( nao salvo ) \n");
                printf("Pizzas: \n");
                for(int c = 0; c < 99; c++){
                    if( strcmp(reg.pizzas[c].sabor, "") != 0){
                        printf("%i: %s\n", c, reg.pizzas[c].sabor);
                    }
                }
                printf("\n");
                printf("Bebidas: \n");
                for(int c = 0; c < 99; c++){
                    if( strcmp(reg.bebidas[c].sabor, "") != 0){
                        printf("%i: %s\n", c, reg.bebidas[c].sabor);
                    }
                }
                system("pause");

                break;
            case 0:
                for(int c = 0; c < 99; c++){
                    Bebida bebida = reg.bebidas[c];
                    Pizza pizza = reg.pizzas[c];
                    if(bebida.cod != -1){
                        nItem++;
                        int n = bebida.vl;
                        printf("%i.%s %i\n",nItem, bebida.sabor, n );
                        subTotal+=bebida.vl;
                    }
                    if(pizza.cod != -1){
                        nItem++;
                        printf("%i.%s %i\n", nItem,pizza.sabor, pizza.preco);
                        subTotal+=pizza.preco;
                    }
                }
                printf("Subtotal: %i\n", subTotal);
                printf("Digite 1 para confirmar ou digite 2 para anular\n");
                int input2 = 0;
                scanf("%i", &input2);
                if(input2 == 1){
                    salvarRegistro(reg);
                }else{
                    printf("Pedido cancelado.");
                }
                control = -1;
                break;
            case -1:
                printf("Pedido cancelado");
                control = -1;
                break;
            }
        }
    }
    operation = 0;
}




void gerarRelatorio()
{
    int control = 0;

    system("cls");
    printf("Iniciando relatorio completo.\n");
    int totalAnual[3];
    int totalMensal[12][3];
    int totalDiario[12][30][3];
    for(int ss = 0; ss < 3; ss++){
        for(int mm = 0; mm < 12; mm++){
            for(int dd = 0; dd < 30; dd++){
                totalDiario[mm][dd][ss] = 0;
            }
            totalMensal[mm][ss] = 0;
        }
        totalAnual[ss] = 0;
    }
    int len = 0;

    for(int ss = 0; ss < 3; ss++){
        int dd = 0;
        int mm = 0;
        control = 0;
        char fileName[20] = "registro_sede";
        fileName[13] = (char)ss+49;
        strcat(fileName, ".txt");
        FILE*file = fopen(fileName, "r+");
        while(control != -1){
            if(feof(file)){
                control = -1;
            }else{
                char read[255];
                char datatype[255];
                char subtype[255];
                int content = 0;
                fgets(read,255,file);
                len = strlen(read);
                sscanf(read, "%s %s", datatype, subtype);

                if(strcmp(datatype,"Dia:") == 0){
                    sscanf(subtype, "%i", &dd);
                    dd--;
                }
                if(strcmp(datatype,"Mes:") == 0){
                    sscanf(subtype, "%i", &mm);
                    mm--;
                }
                if(strcasecmp(datatype, "Total:") == 0 && len > 1){
                    int c = 0;
                    sscanf(subtype, "%i", &c);
                    totalDiario[mm][dd][ss] += c;
                }
            }
        }
        fclose(file);
        for(int mm = 0; mm < 12; mm++){
            for(int dd = 0; dd < 30; dd++){
                totalMensal[mm][ss] += totalDiario[mm][dd][ss];
            }
            totalAnual[ss]+=totalMensal[mm][ss];
        }
    }

    printf("Relatorio gerado com sucesso.\n");

    control = 0;
    while(control != -1){
        system("cls");
        printf("Digite -1 para sair.\n");
        printf("Digite 1 para ver os ganhos mensais.\n");
        printf("Digite 2 para ver os ganhos anuais\n");
        printf("Digite 3 para ver os ganhos diarios de determinado mes\n");
        printf("Digite 4 para ver todos os ganhos.\n");
        printf("Digite 5 para gerar relatorio extendido.\n");
        printf("Digite 6 para ver o relatorio super extendido.\n");
        int input = 0;
        scanf("%i", &input);
        switch(input){
        case 1:
            for(int c = 0; c < 12; c++){
                printf("Mes %i: %i\n", c+1, totalMensal[c][1]);
            }
            system("pause");
            break;
        case 2:
            printf("Ganho anual: %i\n", totalAnual[0]);
            system("pause");
            break;
        case 3:
            printf("Insira o mes desejado ( 1 - 12 )\n");
            int mes = 0;
            scanf("%i", &mes);
            if(mes >= 1 && mes <= 12){
                printf("Mes: %i\n", mes);
                for(int c = 0; c < 30; c++){
                    printf("Dia %i: %i\n", c+1, totalDiario[mes][c][0]);
                }
            }
            system("pause");
            break;
        case 4:
            for(int mm = 0; mm < 12; mm++){
                printf("Mes: %i\n\n", mm+1);
                for(int dd = 0; dd < 30; dd++){
                    printf("Dia %i: %i\n", dd+1, totalDiario[mm][dd][0]);
                }
                printf("-----------------------------\n\n\n");
            }
            system("pause");
            break;
        case 5:
            printf("Iniciando relatorio extendido.\n");

            int control1 = 0;
            char stack[99][3][255];
            int nPizza[99][3];
            for(int c = 0; c < 99; c++){
                for(int c1 = 0; c1 < 3; c1++){
                    strcpy(stack[c][c1], " ");
                    nPizza[c][c1] = 0;
                }

            }
            for(int s = 0; s < 3; s++){
                for(int c = 0; c < 99; c++){
                    strcpy(stack[c][s], " ");
                    nPizza[c][s] = 0;
                }
                char fileName[20] = "registro_sede";
                char n[2] = " ";
                fileName[13] = (char)s+49;
                strcat(fileName,".txt");
                FILE*file = fopen(fileName, "r+");
                control1 = 0;
                while(control1 != -1){
                    if(feof(file)){
                        control1 = -1;
                    }else{
                        char read[255];
                        char datatype[255];
                        char subtype[255];
                        int content = 0;
                        char sab[255] = " ";
                        fgets(read,255,file);
                        len = strlen(read);
                        sscanf(read, "%s %s", datatype, subtype);
                        if(strcasecmp(datatype,"Pizza:") == 0){
                            char temp[255] = " ";
                            sscanf(subtype, "%s %s", temp, subtype);
                            strcpy(sab,temp);
                            int n = 0;
                            for(int c = 0; c < 99; c++){
                                if(!(strcasecmp(sab, stack[c][s]) == 0)){
                                    n++;
                                }
                            }
                            if(n == 99){
                                int i = 0;
                                for(int c = 0; c < 99; c++){
                                    if(strcasecmp(stack[c][s], " ") == 0 ){
                                        break;
                                    }else{
                                        i++;
                                    }
                                }
                                strcpy(stack[i][s], sab);
                            }
                        }
                    }
                }
                control1 = 0;
                fclose(file);


                file = fopen(fileName,"r+");
                while(control1 != -1){
                    if(feof(file)){
                        control1 = -1;
                    }else{
                        char read[255];
                        char datatype[255];
                        char subtype[255];
                        int content = 0;
                        char sab[255] = " ";
                        fgets(read,255,file);
                        len = strlen(read);
                        sscanf(read, "%s %s", datatype, subtype);
                        if(strcasecmp(datatype,"Pizza:") == 0){
                            char temp[255] = " ";
                            sscanf(subtype, "%s %s", temp, subtype);
                            strcpy(sab,temp);
                            int n = 0;
                            for(int c = 0; c < 99; c++){
                                if( strcmp(stack[c][s], sab) == 0){
                                    nPizza[c][s]++;
                                }
                            }
                        }
                    }
                }
                fclose(file);
            }
            printf("---\n");
            for(int s = 0; s < 3; s++){
                printf("Sede: %i\n", s);
                for(int c = 0; c < 99; c++){
                    if(nPizza[c][s] > 0){
                        printf("%i vendas de %s\n", nPizza[c][s], stack[c][s]);
                    }
                }
                printf("\n");
            }
            int totalMaxPizzas = 0;
            int j = 0;
            for(int s = 0; s < 3; s++){
                int maxV = nPizza[0][s];

                int maxPizzas = 0;
                int i = 0;
                for(int c = 0; c < 99; c++){
                    if(maxV <= nPizza[c][s]){
                        maxV = nPizza[c][s];
                        i = c;
                    }
                    maxPizzas += nPizza[c][s];
                }
                if(maxPizzas >= totalMaxPizzas){
                    totalMaxPizzas = maxPizzas;
                    j = s;
                }
                printf("Sede %i. Pizza mais vendida: %s. Vendas: %i\n", (s+1), stack[i][s], nPizza[i][s]);
            }
            printf("\nSede %i, obteve maior numero de pizzas vendidas, com %i unidades vendidas.\n", (j+1) , totalMaxPizzas);
            system("pause");
            break;
        case 6:
            for(int ss = 0; ss < 3; ss++){
                printf("Sede: %i\n", ss+1);
                for(int mm = 0; mm < 12; mm++){
                    printf("Mes: %i\n", mm+1);
                    for(int dd = 0; dd < 30; dd++){
                        printf("Dia: %i\n", dd+1);
                        printf("Total diario: %i\n", totalDiario[mm][dd][ss]);
                    }
                    printf("Total mensal: %i\n", totalMensal[mm][ss]);
                    printf("-------------------------\n");
                }
                printf("Total anual: %i\n", totalAnual[ss]);
                printf("-----------------------------\n\n\n");
            }
            system("pause");
            break;
        case -1:
            control = -1;
            break;

        }
    }
    operation = 0;


}



void inserirFeedback()
{
    system("cls");
    printf("Aviso: absolutamente nenhuma informacao sera salva durante a coleta sobre o feedback\n");
    printf("Digite -1 para cancelar e anular.\n");
    printf("\n");
    printf("Digite 1 para inserir um elogio.\n");
    printf("Digite 2 para inserir uma critica.\n");
    int input = 0;
    fflush(stdin);
    scanf("%i", &input);
    char str[512] = " ";
    printf("\n\nConte-nos sobre sua experiencia: \n");
    fflush(stdin);
    scanf("%[^\n]%*c", &str);
    switch(input){
    case 1:
        ;
        FILE*elogios = fopen("elogios.txt", "a+");
        fprintf(elogios, str);
        fprintf(elogios, "\n\n");
        fclose(elogios);
        break;
    case 2:
        ;
        FILE*criticas = fopen("criticas.txt", "a+");
        fprintf(criticas, str);
        fprintf(criticas, "\n\n");
        fclose(criticas);
        break;
    }
    system("pause");
    operation = 0;
}

void verFeedback()
{
    system("cls");
    printf("Digite -1 para sair.\n");
    printf("Digite 1 para ver elogios.\n");
    printf("Digite 2 para ver criticas.\n");
    printf("\n\n");
    int input = 0;
    scanf("%i", &input);
    printf("---------\n");
    int  n = 0;
    int control = 0;
    switch(input){
    case 1:
        ;
        FILE*elogios = fopen("elogios.txt", "r+");
        n = 0;
        while(control != -1){
            if(feof(elogios)){
                control = -1;
            }else{
                char read[512] = " ";
                fgets(read,512,elogios);
                int len = strlen(read);
                if(len > 1){
                    n++;
                    printf("%i. %s\n", n, read);
                }
            }
        }

        fclose(elogios);
        break;
    case 2:
        ;
        FILE*criticas = fopen("criticas.txt", "r+");
        n = 0;
        while(control != -1){
            if(feof(criticas)){
                control = -1;
            }else{
                char read[512] = " ";
                fgets(read,512,criticas);
                int len = strlen(read);
                if(len > 1){
                    n++;
                    printf("%i. %s\n", n, read);
                }
            }
        }
        fclose(criticas);
        break;
    case -1:
        operation = 0;
        break;
    }
    system("pause");

}

int main()
{
    // STATIC ITENS
    strcpy(nullBebida.sabor, " ");
    nullBebida.cod = -1;
    nullBebida.vl = -1;

    strcpy(coca.sabor, "Coca");
    coca.cod = 1;
    coca.vl = 5;

    strcpy(fanta.sabor, "Fanta");
    fanta.cod = 2;
    fanta.vl = 4.5f;

    strcpy(cerveja.sabor, "Cerveja");
    cerveja.cod = 3;
    cerveja.vl = 6;
    // ***


    while(ISRUNNING){
        system("cls");
        char preuser[255];
        int prepassword;
        printf("Insira o nome de usuario: ");
        fflush(stdin);
        scanf("%s", &preuser);
        printf("\nInsira a senha: ");
        fflush(stdin);
        scanf("%i", &prepassword);
        MAIN_STATE = login(preuser,prepassword);
        //estoque = carregarEstoque();
        if(!(MAIN_STATE == 1 || MAIN_STATE == 2)){
           printf("Failed to login, please check the username and password.\n");
           system("pause");
        }else{
            if(MAIN_STATE == 2 ){
                // ADMIN OPERATIONS
                printf("\nLogged as AMDIN");
                while(MAIN_STATE == 2){
                    if(operation == 0){
                        menuAdmin();
                    }
                    if(operation == 1){
                        fazerPedido();
                    }
                    if(operation == 2){
                         mostrarPizzas();
                    }
                    if(operation == 3){
                       cadastroCliente();
                    }
                    if(operation == 4){
                        // feedback
                        inserirFeedback();
                    }
                    if(operation == 5){
                        // Ver feedback;
                        verFeedback();
                    }
                    if(operation == 6){
                        cadastroPizza();
                    }
                    if(operation == 7){
                        gerarRelatorio();
                    }
                    if(operation == 8){
                        Estoque estoque = carregarEstoque();
                        verEstoque(estoque);
                    }
                }
            }
            if(MAIN_STATE == 1){
                // USER OPERATIONS
                system("cls");
                printf("Logged as USER");
                while(MAIN_STATE == 1){
                    if(operation == 0){
                        menuUser();
                    }
                    if(operation == 1){
                        // fazer pedido
                        fazerPedido();
                    }
                    if(operation == 2){
                        // ver pizzas
                        mostrarPizzas();
                    }
                    if(operation == 3){
                        // registrar cliente
                        cadastroCliente();
                    }
                    if(operation == 4){
                        // feedback
                        inserirFeedback();
                    }
                    if(operation == 5){
                        // ver feedback;
                        verFeedback();
                    }
                }
            }
        }
    }
}




