#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Hecho por @arhcoder
// 14/11/2020

/*
El programa siguiente, sirve para simular la llamada paradoja del cumpleaños, que dice que, bastan sólo 23 personas
en un grupo, para que la probabilidad de que haya 2 con el mísmo cumpleaños, sea mayor al 50%. Es decir, es muy
probable que en un grupo de 23 personas, haya 2 con el mísmo cumpleaños.

Funciona preguntando al usuario, una cantidad de Mapaches con los que quiere simular el escenario. Y a cada uno de
los mapaches del grupo seleccionado, le da un cumpleaños aleatorio con generar(), y comprueba la cantidad de
coincidencias de cumpleaños con comprobar(). Usa además la función calendario(), para transformar números del 1 al
365, en días del año. NOTA: Para fines prácticos, se usaron 365 días para el ejercicio.

Los porcentajes de que haya coincidencias con respecto a los grupos de mapaches, son los siguientes:

    * 23 mapaches: 50.72%
    * 28 mapaches: 65.68%
    * 30 mapaches: 70.63%
    * 35 mapaches: 81.43%
    * 40 mapaches: 89.12%
    * 45 mapaches: 94.08%
    * 50 mapaches: 97.03%
    * 60 mapaches: 99.42%

La ejecucción de este programa, simularía cumpleaños aleatoriamente, y aunque no calcula los porcentajes, funciona
muy bien para entender por qué se le llama "La paradoja del cumpleaños".
*/

int Mapaches[100], cantidad;

char* calendario(int day)
{
    static char fecha[50] = "";
    memset(fecha, 0, 50-1);
    int days = 0, limite = 0, mday = 0;

    if (day >= 1 && day < 32)
    {
        strcat(fecha, "Enero ");
        days = 0;
        limite = 0;
    }
    else if (day >= 32 && day < 60)
    {
        strcat(fecha, "Febrero ");
        days = 28;
        limite = 60 - 1;
    }
    else if (day >= 60 && day < 91)
    {
        strcat(fecha, "Marzo ");
        days = 31;
        limite = 90;
    }
    else if (day >= 91 && day < 121)
    {
        strcat(fecha, "Abril ");
        days = 30;
        limite = 120;
    }
    else if (day >= 121 && day < 152)
    {
        strcat(fecha, "Mayo ");
        days = 31;
        limite = 151;
    }
    else if (day >= 152 && day < 182)
    {
        strcat(fecha, "Junio ");
        days = 30;
        limite = 181;
    }
    else if (day >= 182 && day < 213)
    {
        strcat(fecha, "Julio ");
        days = 31;
        limite = 212;
    }
    else if (day >= 213 && day < 244)
    {
        strcat(fecha, "Agosto ");
        days = 31;
        limite = 243;
    }
    else if (day >= 244 && day < 274)
    {
        strcat(fecha, "Septiembre ");
        days = 30;
        limite = 273;
    }
    else if (day >= 274 && day < 305)
    {
        strcat(fecha, "Octubre ");
        days = 31;
        limite = 304;
    }
    else if (day >= 305 && day < 335)
    {
        strcat(fecha, "Noviembre ");
        days = 30;
        limite = 334;
    }
    else if (day >= 335 && day <= 365)
    {
        strcat(fecha, "Diciembre ");
        days = 31;
        limite = 365;
    }

    mday = fabs(days - (limite - day));
    char sday[3];
    itoa(mday, sday, 10);
    strcat(fecha, sday);
    return fecha;
}

void generar(int cantidad, int Mapaches[])
{
    // Asignar cumpleaños aleatroio a cada mapache.
    srand(time(NULL));
    for(int i = 0; i < cantidad; i++)
    {
        Mapaches[i] = rand() % (365 + 1 - 1);
        printf("\nCumplea%cos del mapache %i:\t%s", 164, i + 1, calendario(Mapaches[i]));
    }
}

void comprobar(int cantidad, int Mapaches[])
{
    int day, coincidencias = 0, flag = 0;

    // Comprueba todas las coincidencias.
    printf("\n\n\nCOINCIDENCIAS:\n_______________________________________\n");
    for(day = 1; day <= 365; day++)
    {
        coincidencias = 0;
        for(int i = 0; i < cantidad; i++)
        {
            if(Mapaches[i] == day)
            {
                coincidencias++;
            }
        }
        if(coincidencias > 1)
        {
            printf("\n%s:\t%i Mapaches cumplea%ceros", calendario(day), coincidencias, 164);
            flag = 1;
        }
    }

    // Muestra en el caso de que no haya coincidencias.
    if(flag == 0)
    {
        printf("\n\nNo hay coincidencias de cumplea%cos", 164);
    }
    printf("\n\nCantidad de mapaches: %i\n_______________________________________\n\n", cantidad);
}

int main()
{
    printf("\n%cCu%cntos mapaches hay en el grupo? ", 168, 160);
    scanf("%i", &cantidad);
    generar(cantidad, Mapaches);
    comprobar(cantidad, Mapaches);
    system("PAUSE");
}