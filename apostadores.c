#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C 0
#define K 1

typedef struct Apostador{
    unsigned long long int pontos;
    int escolha;
    

} Apostador;

int mudar(Apostador ap){
    return (ap.escolha + 1) % 2;
}

int continuar(Apostador ap){
    return ap.escolha;
}

int main(){
    int moeda, n;

    scanf("%i", &n);
    fflush(stdin);
    
    

    srand(time(NULL));
    Apostador apostadorC = {0, C};
    Apostador apostadorK = {0, K};
    Apostador apostador1 = {0, rand() % 2};
    Apostador apostador2 = {0, rand() % 2};
    Apostador apostador3 = {0, rand() % 2};
    Apostador apostador4 = {0, rand() % 2};

    printf("Apostador1 \t Apostador2 \t Apostador3 \t Apostador4 \t ApostadorC \t ApostadorK \n");
    for(unsigned long long int contador = 0; contador < n; contador++){
        moeda = rand() % 2;

        //apostador do "se eu errar eu mudo"
        if(apostador1.escolha != moeda){
            apostador1.escolha = mudar(apostador1);
        } else {
            apostador1.escolha = continuar(apostador1);
            apostador1.pontos++;
        }

        //apostador do "se eu errar eu continuo"
        if(apostador2.escolha != moeda){
            apostador2.escolha = continuar(apostador2);
        } else {
            apostador2.escolha = mudar(apostador2);
            apostador2.pontos++;
        }
        
        //apostador do "se eu acertar eu continuo"
        if(apostador3.escolha == moeda){
            apostador3.escolha = continuar(apostador3);
            apostador3.pontos++;
        } else {
            apostador3.escolha = mudar(apostador3);
            
        }

        //apostador do "se eu acertar eu mudo"
        if(apostador4.escolha == moeda){
            apostador4.escolha = continuar(apostador4);
            apostador4.pontos++;
        } else {
            apostador4.escolha = mudar(apostador4);
            
        }

        //apostador do "sempre aposto cara"
        if(apostadorC.escolha == moeda)
            apostadorC.pontos++;
        
        //apostador do "sempre aposto koroa"
        if(apostadorK.escolha == moeda)
            apostadorK.pontos++;

        
        printf("%llu \t\t %llu \t\t %llu \t\t %llu \t\t %llu \t\t %llu\n", apostador1.pontos, apostador2.pontos, apostador3.pontos, apostador4.pontos, apostadorC.pontos, apostadorK.pontos);

    }
    
    
    printf("Resultado: \nApostador1: %llu \nApostador2: %llu \nApostador3: %llu \nApostador4: %llu \nApostadorC: %llu \nApostadorK: %llu\n", apostador1.pontos, apostador2.pontos, apostador3.pontos, apostador4.pontos, apostadorC.pontos, apostadorK.pontos);
    
    getchar();
}

