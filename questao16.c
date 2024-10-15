/*
 Suponha que as seguintes declarações tenham sido realizadas:
float aloha[10], coisas[10][5], *pf, value = 2.2;
int i=3;
Identifique quais dos seguintes comandos é válido ou inválido:
aloha[2] = value;
scanf("%f", &aloha);
aloha = "value";
printf("%f", aloha);
coisas[4][4] = aloha[3];
coisas[5] = aloha;
pf = value;
pf = aloha;

Vamos analisar cada comando e determinar se é válido ou inválido:
aloha[2] = value;
Válido. Atribui o valor de value (2.2) ao terceiro elemento do array aloha.
scanf("%f", &aloha);
Inválido. O scanf espera o endereço de um float, mas &aloha é o endereço do array inteiro. Deveria ser scanf("%f", &aloha[0]); para ler o primeiro elemento.
aloha = "value";
Inválido. Não se pode atribuir uma string a um array de float. Além disso, arrays não podem receber atribuições diretas.
printf("%f", aloha);
Inválido. O printf espera um float, mas aloha é o nome do array, que decai para um ponteiro para o primeiro elemento. Deveria ser printf("%f", aloha[0]); para imprimir o primeiro elemento.
5. coisas[4][4] = aloha[3];
Válido. Atribui o valor do quarto elemento de aloha ao elemento na posição [4][4] de coisas.
coisas[5] = aloha;
Inválido. Não se pode atribuir um array unidimensional a uma linha de um array bidimensional.
pf = value;
Inválido. Não se pode atribuir um float diretamente a um ponteiro para float. Deveria ser pf = &value; para atribuir o endereço de value a pf.
pf = aloha;
Válido. Atribui o endereço do primeiro elemento de aloha a pf.
*/

