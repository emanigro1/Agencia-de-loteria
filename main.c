#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<time.h>

struct quini6       //  ESTRUCTURA DEL SORTEO
{
    int sorteo[6];
    char nombresorteo[20];
};
struct boleta       //ESTRUCTURA DE LA BOLETA
{
    int dni;
    int vector[6];
};

void DNI (struct boleta cantidadboletas[],int cantidadpersonas);
void boletasaleatorias (struct boleta cantidadboletas[],int cantidadpersonas);
void boletasmanuales (struct boleta cantidadboletas[],int cantidadpersonas);
void tressorteos (struct quini6 sorteos[]);
void Comparacion (struct boleta cantidadboletas[],struct quini6 sorteos[],int cantidadpersonas);
void MenuContinuar (struct boleta cantidadboletas[],int cantidadpersonas);
void SALEOSALE (struct boleta cantidadboletas[],int cantidadpersonas);

int main()
{
    char op;
    int cantidadpersonas=0;
    srand(time(NULL));
    struct quini6 sorteos[3];
    strcpy(sorteos[0].nombresorteo,"TRADICIONAL");
    strcpy(sorteos[1].nombresorteo,"SEGUNDA VUELTA");
    strcpy(sorteos[2].nombresorteo,"REVANCHA");
    do
    {
        printf ("\n\t\tQUINI6\n");   //PANTALLA BIENVENIDA
        printf ("\t\t======\n");
        printf ("Bienvenido al QUINI6. ");
        printf ("Podra participar de 3 sorteos:\n");
        printf ("\n\t[TRADICIONAL-SEGUNDA VUELTA-REVANCHA]\n\n");
        printf ("OPRIMA:\n\n");
        printf ("1)\tSi desea boletas con numeros aleatorias.\n\n");
        printf ("2)\tSi desea elegir los numeros para cada boleta.\n\n");
        printf ("3)\tSALIR.\n");
        scanf ("%c", &op);
        if (op < '1' || op > '3')
        {
            system("cls");
        }
    }
    while (op < '1' || op > '3');
    system("cls");
    fflush(stdin);
    if (op!='3')
    {
        do
        {
            printf("\nINGRESE CUANTAS BOLETAS DESEA COMPRAR: ");     //BOLETAS A COMPRAR
            scanf("%i",&cantidadpersonas);
            if (cantidadpersonas>10)
            {
                system("cls");
                printf("\nNO PUEDE COMPRAR MAS DE 10 BOLETAS\n");
            }
        }
        while (cantidadpersonas<1 || cantidadpersonas>10 && op );
    }
    struct boleta cantidadboletas[cantidadpersonas];      //CANTIDAD DE BOLETAS COMPRADA
    int x=cantidadpersonas;
    DNI(cantidadboletas,cantidadpersonas);                //PIDE DNI
    switch (op)
    {
    case '1':
        boletasaleatorias (cantidadboletas,x);          // BOLETAS AUTOMATICAS
        tressorteos (sorteos);                          //SORTEOS
        Comparacion (cantidadboletas,sorteos,x);        //COMPARACION DE BOLETAS
        MenuContinuar (cantidadboletas,x);              // MENU SALE O SALE
        break;
    case '2':
        boletasmanuales (cantidadboletas,x);            //ELECCION DE NUMEMEROS
        tressorteos (sorteos);                          // IGUAL QUE CASE 1    {
        Comparacion (cantidadboletas,sorteos,x);
        MenuContinuar (cantidadboletas,x);              //                     }
        break;
    case '3':
        system("cls");
        printf("\n\n\n\n\tHASTA LUEGO!\n\n\n\n\n\n\n\n");           //FINALIZA PROGRAMA
        break;
    }
    return 0;
}

void DNI (struct boleta cantidadboletas[],int cantidadpersonas)
{
    printf("\n\nINGRESE UN DNI PARA CADA BOLETA: \n\n");            //CANTIDAD DE BOLETAS
    for(int i=0; i<cantidadpersonas; i++)
    {
        printf("BOLETA %i: DNI ",i+1);                              //DNI
        do
        {
            scanf("%i",&cantidadboletas[i].dni);
            if (cantidadboletas[i].dni>=50000000 || cantidadboletas[i].dni<1 )
            {
                printf("DNI INCORRECTO, REPITA..\n");
            }

        }
        while(cantidadboletas[i].dni>50000000 || cantidadboletas[i].dni<1 );
    }
    system("cls");
}

void boletasaleatorias (struct boleta cantidadboletas[],int cantidadpersonas)   // BOLETAS ALEATORIAS
{
    int aux,cambio,i,j,k;
    for (i=0; i<cantidadpersonas; i++)
    {
        for ( j=0; j<6; j++)
        {
            do
            {
                aux=0;
                fflush(stdin);
                cantidadboletas[i].vector[j]=rand()%46;
                for (k=0; k<j; k++)
                {
                    if (cantidadboletas[i].vector[j]==cantidadboletas[i].vector[k])    //NO PEROMITE NUMEROS REPETIDOS
                    {
                        aux=1;
                    }
                }
            }
            while(aux==1);
        }
    }
    for ( i=0; i<cantidadpersonas; i++)
    {
        for ( j=0; j<6; j++)
        {
            for ( k=0; k<j; k++)
            {
                if (cantidadboletas[i].vector[j]<cantidadboletas[i].vector[k])      // ORDCENA MENOR A MAYOR
                {
                    cambio=cantidadboletas[i].vector[j];
                    cantidadboletas[i].vector[j]=cantidadboletas[i].vector[k];
                    cantidadboletas[i].vector[k]=cambio;
                }
            }
        }
        printf("\n\tBOLETA: %i  -  DNI: %i  -  Numeros: ",i+1,cantidadboletas[i].dni);  //BOLETAS ALEATORIAS TERMINADAS
        for ( j=0; j<6; j++)
        {
            if (cantidadboletas[i].vector[j]<10)
            {
                printf("0");
            }
            printf("%i ",cantidadboletas[i].vector[j]);
        }
        printf("\n______________________________________________________________________\n");
    }
    printf("\n");
}

void tressorteos (struct quini6 sorteos[])          //SORTEOS
{
    int j,k,aux;
    printf("\n\n\t\tEMPEZO EL SORTEO \n\n");
    printf("%s:        ",sorteos[0].nombresorteo);
    for ( j=0; j<6; j++)
    {
        do
        {
            aux=0;
            sorteos[0].sorteo[j]=rand()%46;
            for (k=0; k<j; k++)
            {
                if (sorteos[0].sorteo[j]==sorteos[0].sorteo[k])           //NO PERMITE REPETIDOS TRADICIONAL
                {
                    aux=1;
                }
            }
        }
        while(aux==1);
        Sleep(2000);
        if (sorteos[0].sorteo[j]<10)
        {
            printf("0");
        }
        printf("%i      ",sorteos[0].sorteo[j]);
    }
    printf("\n");
    printf("%s:     ",sorteos[1].nombresorteo);
    for ( j=0; j<6; j++)
    {
        do
        {
            aux=0;
            sorteos[1].sorteo[j]=rand()%46;
            for (k=0; k<j; k++)
            {
                if (sorteos[1].sorteo[j]==sorteos[1].sorteo[k])        //NO PERMITE REPETIDOS SEG VUELTA
                {
                    aux=1;
                }
            }
        }
        while(aux==1);
        Sleep(2000);
        if (sorteos[1].sorteo[j]<10)
        {
            printf("0");
        }
        printf("%i      ",sorteos[1].sorteo[j]);
    }
    printf("\n");
    printf("%s:           ",sorteos[2].nombresorteo);
    for ( j=0; j<6; j++)
    {
        do
        {
            aux=0;
            sorteos[2].sorteo[j]=rand()%46;
            for (k=0; k<j; k++)
            {
                if (sorteos[2].sorteo[j]==sorteos[2].sorteo[k])            //NO PERMITE REPETIDOS REVANCHA
                {
                    aux=1;
                }
            }
        }
        while(aux==1);
        Sleep(2000);
        if (sorteos[2].sorteo[j]<10)
        {
            printf("0");
        }
        printf("%i      ",sorteos[2].sorteo[j]);
    }
    printf("\n\n");
}

void Comparacion (struct boleta cantidadboletas[],struct quini6 sorteos[],int cantidadpersonas)  //COMPARACION SORTEO BOLETA
{
    int i,k,j,z,contador;
    for (i=0; i<cantidadpersonas; i++)
    {

        printf("\nBOLETA %i   -   DNI: %i    -   NUMEROS ACERTADOS: ",i+1,cantidadboletas[i].dni);
        Sleep(2000);
        for ( z=0; z<3; z++)                                            //COMPARA BOLETAS CON SORTEOS
        {
            printf("\n%s:  ",sorteos[z].nombresorteo);
            contador=0;
            for ( j=0; j<6; j++)
            {
                for ( k=0; k<6; k++)
                {
                    if ( cantidadboletas[i].vector[j] ==  sorteos[z].sorteo[k])
                    {
                        contador++;
                        if (cantidadboletas[i].vector[j]<10)                   //AGREGUE 0 A < 10 PARA EMPAREJAR CIFRAS
                        {
                            printf("0%i",cantidadboletas[i].vector[j]);
                        }
                        else
                        {
                            printf("%i",cantidadboletas[i].vector[j]);
                        }

                    }
                    else
                    {
                        printf("  ");
                    }
                }
            }
            if (z==0)                                                   //BOLETOS GANADORES DE TRADICIONAL
            {
                switch (contador)
                {
                case 4:
                    printf("    - Felicidades!! GANO $300 MIL.!!");
                    break;
                case 5:
                    printf("    - Felicidades!! GANO $2 MILLONES.!!");
                    break;
                case 6:
                    printf("    - Felicidades!! GANO $5 MILLONES.!!");
                    break;
                default:
                    printf("    - SIN PREMIO.");
                    break;
                }
                Sleep(2000);
            }
            if (z==1)                                               //BOLETOS GANADORES DE SEG VUELTA
            {
                switch (contador)
                {
                case 4:
                    printf(" - Felicidades!! GANO $100 MIL.!!");
                    break;
                case 5:
                    printf(" - Felicidades!! GANO $500 MIL.!!");
                    break;
                case 6:
                    printf(" - Felicidades!! GANO $2 MILLONES.!!");
                    break;
                default:
                    printf(" - SIN PREMIO.");
                    break;
                }
                Sleep(2000);
            }
            if (z==2)                                               //BOLETOS GANADORES DE REVANCHA
            {
                switch (contador)
                {
                case 6:
                    printf("       - Felicidades!! 4 MILLONES.!!");
                    break;
                default:
                    printf("       - SIN PREMIO.");
                    break;
                }
                Sleep(2000);
            }
        }
        printf("\n\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void boletasmanuales (struct boleta cantidadboletas[],int cantidadpersonas)   // BOLETAS ELEGIR NUMEROS MANUAL
{
    int i,j,k,aux,cambio;
    printf("\nImprima sus numeros:\t");
    printf("(deben encontrarse entre 0 y 45 y no deben ser repetidos)\n");

    for (i=0; i<cantidadpersonas; i++)
    {
        printf("\nBOLETO: %i  -  DNI: %i \n",i+1,cantidadboletas[i].dni);             //BOLETAS POR DNI
        for (j=0; j<6; j++)
        {
            printf("Numero %i: ",j+1);
            do
            {
                aux=0;
                scanf("%i",&cantidadboletas[i].vector[j]);
                for (k=0; k<j; k++)
                {
                    if (cantidadboletas[i].vector[j]==cantidadboletas[i].vector[k])  //NO PERMITE REPETIDOS
                    {
                        aux=1;
                        printf("Numero repetido, el %i ya esta elegido.Escoja otro.\n",cantidadboletas[i].vector[j]);
                        printf("Numeros %i: ",j);
                    }
                }
                if (cantidadboletas[i].vector[j]>45)
                {
                    aux=1;
                    printf("El numero es invalido. Debe ser menor a 46.\n");  //NO PERMITE MAYORES A 45
                    printf("Numeros %i: ",j);
                }
                else if (cantidadboletas[i].vector[j]<0)
                {
                    aux=1;
                    printf("El numero es invalido. Debe ser positivo.\n");   //NO PERMITE MENOR A 0
                    printf("Numeros %i: ",j);
                }
            }
            while(aux==1);

        }
        system("cls");

    }
    system("cls");
    for (i=0; i<cantidadpersonas; i++)
    {
        for (j=1; j<6; j++)
        {
            for (k=0; k<j; k++)
            {
                if (cantidadboletas[i].vector[j]<cantidadboletas[i].vector[k])       //ORDCENA MENOR A MAYOR
                {
                    cambio=cantidadboletas[i].vector[j];
                    cantidadboletas[i].vector[j]=cantidadboletas[i].vector[k];
                    cantidadboletas[i].vector[k]=cambio;
                }
            }

        }

        printf("\n\tBOLETA: %i  -  DNI: %i  -  Numeros: ",i+1,cantidadboletas[i].dni);
        for (j=0; j<6; j++)
        {
            printf("%i ",cantidadboletas[i].vector[j]);                                 // BOLETAS TERMNADAS
        }
        printf("\n______________________________________________________________________\n");

    }
    printf("\n");

}


void MenuContinuar (struct boleta cantidadboletas[],int cantidadpersonas)    // MENU SALE O SALE
{
    char op;
    printf("\nHa finalizado el sorteo. Desea.. \n\n");
    printf("    1]    Jugar SALE O SALE (sortear con las boletas hasta ganar el tradicional)\n\n");
    printf("        2]    SALIR.\n");
    do
    {
        fflush(stdin);
        scanf("%c",&op);
        if (op<'1' || op>'2')
        {
            printf("Opcion incorrecta.\n");
        }
    }
    while (op<'1' || op>'2');
    switch (op)
    {
    case '1':
        SALEOSALE(cantidadboletas,cantidadpersonas);          //ELEGIR SALE O SALE
        break;

    case '2':
        system ("cls");
        printf("\n\n\n\n\tHASTA LUEGO!\n\n\n\n\n\n\n\n");      // SALIR
        break;
    }
}

void SALEOSALE (struct boleta cantidadboletas[],int cantidadpersonas)           //FUNCION SALE O SALE
{
    int j,i,aux,k,cont,sorteo[6],contador=0;
    system("cls");
    printf("\nBuscando..");
    do
    {
        contador++;
        for ( j=0; j<6; j++)
        {
            do
            {
                aux=0;
                sorteo[j]=rand()%46;
                for (k=0; k<j; k++)
                {
                    if (sorteo[j]==sorteo[k])                       //ENCUENTRAS NUMEROS IGUALES
                    {
                        aux=1;
                    }
                }
            }
            while(aux==1);
        }

        for (i=0; i<cantidadpersonas; i++)
        {
            cont=0;
            for (j=0; j<6; j++)
            {
                for (k=0; k<6; k++)
                {
                    if (cantidadboletas[i].vector[j]==sorteo[k])        //ENCUENTRA BOLETA GANADORA
                    {
                        cont++;
                    }
                }
            }
        }
    }
    while (cont!=6);
    printf("\n\nLa boleta %i fue la ganadora con 6 numeros, en %i intentos:\n\nNumeros:",i,contador);
    for (j=0; j<6; j++)
    {
        printf("    %i    ",sorteo[j]);
    }
    printf("\n\n\n\n\tHASTA LUEGO!\n\n\n\n\n\n\n\n");          //TERMINA PROGRAMA
}
