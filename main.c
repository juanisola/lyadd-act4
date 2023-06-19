#include <stdio.h>
#include "pico/stdlib.h"
#include "ultrasonico.h"

/*
 * @brief Programa principal
 */
int main(void) {
    // Inicializacion del USB
    stdio_init_all();
    // Elegir un GPIO para trigger, echo y buzzer
    // Inicializacion del ultrasonico
    ultrasonico_init(2, 1);
    // Inicializo buzzer
    gpio_init(25);

    gpio_set_dir(25, true);

    while(1) {
        // Hago una lectura de distancia
        float d = ultrasonico_get_distance_cm(2,1);
        // Muestro por consola
        printf("La distancia es: %.2f\n", d);
        // Verifico distancia
        if(d>10){
            gpio_put(25, false);
        }
        else{
            gpio_put(25, true);
        }
        // Espero
        sleep_ms(10);
    }
}
