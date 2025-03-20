#include <stdio.h>

float calculatePopulationDensity(float area, int population) {
    float populationDensity = population / area;

    return populationDensity;
}

float calculatePibPerCapita(float pib, int population) {
    float pibPerCapita = (pib * 1000000000) / population;

    return pibPerCapita;
}

float calculateSuperPower(
    int population,
    float area,
    float pib,
    int touristAttractions
) {
    float populationDensity = calculatePopulationDensity(area, population);
    float pibPerCapita = calculatePibPerCapita(pib, population);

    return (float) population + area + pib + (float) touristAttractions + populationDensity + pibPerCapita;
}

char compareAttributes(const char *title, int cartaA, int cartaB) {
    if (cartaA > cartaB) {
        printf("%s Carta 01 venceu \n", title);
    } else {
        printf("%s Carta 2 venceu \n", title);
    }
}

char comparePopulationDensityAttribute(const char *title, int cartaA,  int cartaB) {
    if (cartaA < cartaB) {
        printf("%s Carta 01 venceu \n", title);
    } else {
        printf("%s Carta 2 venceu \n", title);
    }
}

int main() {
    char state[2];
    char cardCode[4];
    char city[20];
    int population, touristAttractions;
    float area, pib;

    char state2[2];
    char cardCode2[4];
    char city2[20];
    int population2, touristAttractions2;
    float area2, pib2;

    printf("**** Super Trunfo -- Mestre **** \n\n");

    printf("Carta 01: \n");

    printf("Digite o estado: ");
    scanf("%2s", &state);

    printf("Digite o código da carta: ");
    scanf("%3s", &cardCode);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(city, sizeof(city), stdin);
    city[strcspn(city, "\n")] = '\0';

    printf("Digite a população: ");
    scanf("%d", &population);
    printf("Digite a área (em km²): ");
    scanf("%f", &area);
    printf("Digite o PIB: ");
    scanf("%f", &pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &touristAttractions);

    printf("\nCarta 02: \n");

    printf("Digite o estado: ");
    scanf("%1s", state2);

    printf("Digite o código da carta: ");
    scanf("%3s", cardCode2);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(city2, sizeof(city2), stdin);
    city2[strcspn(city2, "\n")] = '\0';

    printf("Digite a população: ");
    scanf("%d", &population2);
    printf("Digite a área (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB: ");
    scanf("%f", &pib2);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &touristAttractions2);

    printf("\nDados cadastrados: \n\n");

    printf("Carta 01: \n");
    printf("Estado: %s \n", state);
    printf("Código: %s \n", cardCode);
    printf("Nome da Cidade: %s \n", city);
    printf("População: %d \n", population);
    printf("Área: %.2f km² \n", area);
    printf("PIB: %.2f bilhões de reais \n", pib);
    printf("Número de Pontos Turísticos: %d \n", touristAttractions);
    printf("Densidade Populacional: %.2f hab/km² \n", calculatePopulationDensity(area, population));
    printf("PIB per Capita: %.2f reais \n", calculatePibPerCapita(pib, population));
    printf("Super Poder: %f \n", calculateSuperPower(population, area, pib, touristAttractions));
    
    printf("\nCarta 02: \n");
    printf("Estado: %s \n", state2);
    printf("Código: %s \n", cardCode2);
    printf("Nome da Cidade: %s \n", city2);
    printf("População: %d \n", population2);
    printf("Área: %.2f km² \n", area2);
    printf("PIB: %.2f bilhões de reais \n", pib2);
    printf("Número de Pontos Turísticos: %d \n", touristAttractions2);
    printf("Densidade Populacional: %.2f hab/km² \n", calculatePopulationDensity(area2, population2));
    printf("PIB per Capita: %.2f reais \n", calculatePibPerCapita(pib2, population2));
    printf("Super Poder: %f \n", calculateSuperPower(population2, area2, pib2, touristAttractions2));

    /**
     * Comparação das cartas
     */

    printf("\nComparação de Cartas\n");

    compareAttributes("População:", population, population2);
    compareAttributes("Área:", area, area2);
    compareAttributes("PIB:", pib, pib2);
    compareAttributes("Pontos Turísticos:", touristAttractions, touristAttractions2);
    comparePopulationDensityAttribute("Densidade Populacional", calculatePopulationDensity(area, population), calculatePopulationDensity(area2, population2));
    compareAttributes("PIB per Capita:", calculatePibPerCapita(pib, population), calculatePibPerCapita(pib2, population2));
    compareAttributes("Super Poder:", calculateSuperPower(population, area, pib, touristAttractions), calculateSuperPower(population2, area2, pib2, touristAttractions2));


    return 0;
}