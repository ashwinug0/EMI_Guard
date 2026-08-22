#include <stdio.h>
#include <windows.h>

int main() {

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    float income;
    float expenses;
    float emi;
    float carEMI;
    float educationEMI;
    float otherEMI;
    float totalEMI;
    float finalBalance;

    float available;
    float remaining;
    float emiRatio;
    float budgetUsed;
    float stressScore;
   
    FILE *report; 

    printf("\n");
    printf("====================================================\n");
    printf("                  E M I G U A R D\n");
    printf("              BUDGET STRESS ANALYZER\n");
    printf("====================================================\n");

    printf("\nEnter monthly income         : Rs. ");
    scanf("%f", &income);

    printf("Enter monthly expenses       : Rs. ");
    scanf("%f", &expenses);

    printf("your considering EMI         : Rs. ");
    scanf("%f", &emi);
    
    printf("\n--- OTHER MONTHLY COMMITMENTS ---\n");

    printf("Car/Vehicle EMI      : Rs. ");
    scanf("%f", &carEMI);

    printf("Education EMI        : Rs. ");
    scanf("%f", &educationEMI);

    printf("Other EMI/Payment    : Rs. ");
    scanf("%f", &otherEMI);


    /* Budget calculations */

    available = income - expenses;

    remaining = available - emi;

    emiRatio = (emi / income) * 100;

    budgetUsed = ((expenses + emi) / income) * 100;

    totalEMI = emi + carEMI + educationEMI + otherEMI;

    finalBalance = income - expenses - totalEMI;

    /* Educational budget stress model */

    stressScore = budgetUsed;

    if (stressScore > 100)
        stressScore = 100;


    /* Dashboard */

    printf("\n");
    printf("----------------------------------------------------\n");
    printf("                  BUDGET DASHBOARD\n");
    printf("----------------------------------------------------\n");

    printf("\nMonthly Income       : Rs. %.2f", income);
    printf("\nMonthly Expenses     : Rs. %.2f", expenses);
    printf("\nProposed EMI         : Rs. %.2f", emi);

    printf("\n\nAvailable Before EMI : Rs. %.2f", available);
    printf("\nRemaining After EMI  : Rs. %.2f", remaining);

    printf("\n\nEMI / Income         : %.2f%%", emiRatio);
    printf("\nBudget Used          : %.2f%%", budgetUsed);


    /* Stress indicator */

    printf("\n\n----------------------------------------------------\n");
    printf("                  FINANCIAL STRESS\n");
    printf("----------------------------------------------------\n");

    if (remaining < 0) {

        printf("\n[##########] HIGH 🔴\n");
        printf("EMI exceeds your available budget.\n");

    }
    else if (budgetUsed >= 80) {

        printf("\n[########--] HIGH 🟠\n");
        printf("Very little budget remains after expenses and EMI.\n");

    }
    else if (budgetUsed >= 60) {

        printf("\n[######----] MODERATE 🟡\n");
        printf("Your budget has moderate pressure.\n");

    }
    else {

        printf("\n[###-------] LOW 🟢\n");
        printf("Your entered budget has more remaining capacity.\n");
    }


    printf("\n----------------------------------------------------\n");

    printf("\n⚠ This is an educational budgeting tool.\n");
    printf("  It is not financial advice or a loan approval system.\n");

    printf("\n====================================================\n");

    printf("\n----------------------------------------------------\n");
    printf("                STRESS SCORE\n");
    printf("----------------------------------------------------\n");

    printf("\nStress Score : %.0f / 100\n", stressScore);

    printf("[");

    int blocks = (int)stressScore / 10;

    for (int i = 0; i < 10; i++) {

    if (i < blocks)
        printf("#");
    else
        printf("-");
}

    printf("]\n");

    printf("\n\n");
printf("====================================================\n");
printf("                 WHAT-IF SIMULATOR\n");
printf("====================================================\n");

float testEMI;
float testRemaining;
int i;

float emiOptions[] = {5000, 8000, 12000, 15000, 20000};

printf("\n");
printf("EMI          Remaining        Status\n");
printf("---------------------------------------------\n");

for (i = 0; i < 5; i++)
{
    testEMI = emiOptions[i];

    testRemaining = available - testEMI;

    printf("Rs. %6.0f   Rs. %8.0f      ",
           testEMI,
           testRemaining);

    if (testRemaining < 0)
    {
        printf("OVER BUDGET\n");
    }
    else if (testRemaining < available * 0.20)
    {
        printf("HIGH PRESSURE\n");
    }
    else if (testRemaining < available * 0.40)
    {
        printf("MODERATE\n");
    }
    else
    {
        printf("LOW PRESSURE\n");
    }
}

    printf("\n====================================================\n");
printf("               EMI COMMITMENT TRACKER\n");
printf("====================================================\n");

printf("\nProposed EMI       : Rs. %.2f", emi);
printf("\nCar/Vehicle EMI    : Rs. %.2f", carEMI);
printf("\nEducation EMI      : Rs. %.2f", educationEMI);
printf("\nOther Payments     : Rs. %.2f", otherEMI);

printf("\n---------------------------------------------");

printf("\nTOTAL EMI          : Rs. %.2f", totalEMI);
printf("\nFINAL BALANCE      : Rs. %.2f", finalBalance);

printf("\n---------------------------------------------\n");

if (finalBalance < 0)
{
    printf("STATUS: 🔴 OVER BUDGET\n");
}
else if (finalBalance < income * 0.10)
{
    printf("STATUS: 🟠 VERY LIMITED BUFFER\n");
}
else if (finalBalance < income * 0.25)
{
    printf("STATUS: 🟡 MODERATE BUFFER\n");
}
else
{
    printf("STATUS: 🟢 AVAILABLE BUFFER\n");
}

printf("\n====================================================\n");

    report = fopen("emiguard_report.txt", "w");

if (report == NULL)
{
    printf("\nError: Could not create report file.\n");
}
else
{
    fprintf(report, "============================================\n");
    fprintf(report, "              EMIGUARD REPORT\n");
    fprintf(report, "============================================\n\n");

    fprintf(report, "Monthly Income    : Rs. %.2f\n", income);
    fprintf(report, "Monthly Expenses  : Rs. %.2f\n", expenses);
    fprintf(report, "Proposed EMI      : Rs. %.2f\n", emi);

    fprintf(report, "\n--- EMI COMMITMENTS ---\n");

    fprintf(report, "Main EMI           : Rs. %.2f\n", emi);
    fprintf(report, "Vehicle EMI        : Rs. %.2f\n", carEMI);
    fprintf(report, "Education EMI      : Rs. %.2f\n", educationEMI);
    fprintf(report, "Other Payment      : Rs. %.2f\n", otherEMI);

    fprintf(report, "\nTotal EMI          : Rs. %.2f\n", totalEMI);
    fprintf(report, "Final Balance      : Rs. %.2f\n", finalBalance);

    fprintf(report, "\nStress Score       : %.0f / 100\n", stressScore);

    fprintf(report, "\n--------------------------------------------\n");
    fprintf(report, "Educational budgeting tool only.\n");
    fprintf(report, "Not financial advice or loan approval.\n");
    fprintf(report, "============================================\n");

    fclose(report);

    printf("\n");
    printf("✓ Report saved successfully!\n");
    printf("  File: emiguard_report.txt\n");
}

    return 0;

}