int main()
{
    float principal, rate, year, ci;
    printf("Enter principal: ");
    scanf("%f", &principal);
    printf("Enter rate: ");
    scanf("%f", &rate);
    printf("Enter time in years: ");
    scanf("%f", &year);
    ci = principal * ((pow((1 + rate / 100), year) - 1));
    printf("Compound interest is: %f\n", ci);
    return 0;
}
