#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float input_temperature, converted_temperature;
    int input_scale, target_scale;

    while (1) {
        printf("Enter the temperature value (or type -999 to exit): ");
        scanf("%f", &input_temperature);

        if (input_temperature == -999) {
            break;
        }

        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &input_scale);

        if (input_scale < 1 || input_scale > 3) {
            printf("Invalid input scale. Please enter 1, 2, or 3.\n");
            continue; 
        }

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &target_scale);

        // Validate target scale input
        if (target_scale < 1 || target_scale > 3) {
            printf("Invalid target scale. Please enter 1, 2, or 3.\n");
            continue; 
        }

        // Handle Kelvin-specific validation
        if (input_scale == 3 && input_temperature < 0) {
            printf("Invalid input: Temperature in Kelvin cannot be negative.\n");
            continue; 
        }

        if (input_scale == 1) { 
            if (target_scale == 2) {
                converted_temperature = celsius_to_fahrenheit(input_temperature);
                printf("Converted temperature: %.2f°F\n", converted_temperature);
            } else if (target_scale == 3) {
                converted_temperature = celsius_to_kelvin(input_temperature);
                printf("Converted temperature: %.2fK\n", converted_temperature);
            } else {
                converted_temperature = input_temperature; 
                printf("Converted temperature: %.2f°C\n", converted_temperature);
            }
        } else if (input_scale == 2) { 
            if (target_scale == 1) {
                converted_temperature = fahrenheit_to_celsius(input_temperature);
                printf("Converted temperature: %.2f°C\n", converted_temperature);
            } else if (target_scale == 3) {
                converted_temperature = celsius_to_kelvin(fahrenheit_to_celsius(input_temperature));
                printf("Converted temperature: %.2fK\n", converted_temperature);
            } else {
                converted_temperature = input_temperature; 
                printf("Converted temperature: %.2f°F\n", converted_temperature);
            }
        } else if (input_scale == 3) { 
            if (target_scale == 1) {
                converted_temperature = kelvin_to_celsius(input_temperature);
                printf("Converted temperature: %.2f°C\n", converted_temperature);
            } else if (target_scale == 2) {
                converted_temperature = celsius_to_fahrenheit(kelvin_to_celsius(input_temperature));
                printf("Converted temperature: %.2f°F\n", converted_temperature);
            } else {
                converted_temperature = input_temperature; 
                printf("Converted temperature: %.2fK\n", converted_temperature);
            }
        }

        float celsius_for_categorization;
        if (target_scale == 1) {
            celsius_for_categorization = converted_temperature;
        } else if (target_scale == 2) {
            celsius_for_categorization = fahrenheit_to_celsius(converted_temperature); 
        } else {
            celsius_for_categorization = kelvin_to_celsius(converted_temperature); 
        }

        categorize_temperature(celsius_for_categorization);
    }

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat.\n");
    } else if (celsius >= 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}
