package clases;

import java.util.Scanner;

public class Cumpleaños {

    public static void main(String[] args) {
        
        int cantidad = 50;
        int cumple = 0;
        float probabilidad = 0;
        int i;
        int i2;
        int day;
        boolean coincidencias = false;
        Scanner scanner = new Scanner(System.in);
        
        // Pregunta por la cantidad de mapaches del grupo.
        System.out.println("¿Cuántos mapaches hay en el grupo?");
        cantidad = scanner.nextInt();
        int[] Mapaches = new int[cantidad];
        
        // Asignar cumpleaños aleatroio a cada gato.
        System.out.println("_______________________________________\n");
        for(i = 0; i <= Mapaches.length - 1; i++)
        {
            cumple = (int) Math.floor(Math.random()* 365 + 1);
            Mapaches[i] = cumple;
            System.out.println("Cumpleaños del Mapache "+((int)i+1)+": "+Mapaches[i]);
        }
        System.out.println("_______________________________________\n");
        
        // Comprueba todas las coincidencias.
        System.out.println("COINCIDENCIAS:");
        for(day = 1; day <= 365; day++)
        {
            int n = 0;
            for(i = 0; i <= Mapaches.length - 1; i++)
            {
                if(Mapaches[i] == day)
                {
                    n++;
                }
            }
            
            if(n > 1)
            {
                System.out.println("Día "+day+": "+n+" mapaches cumpleañeros.");
                coincidencias = true;
            }
        }
        
        // Muestra en el caso de que no haya coincidencias.
        if(!coincidencias)
        {
            System.out.println("No hay coincidencias de cumpleaños.");
        }
        System.out.println("_______________________________________\n");
    }
}