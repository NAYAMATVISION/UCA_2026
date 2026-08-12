#include <stdio.h>
#include <math.h>

int main()
{
    int population[] = {200, 20, 50};
    int n = 3;
    int k = 5;

    double low = 0;
    double high = 200;

    while (high - low > 0.0001)
    {
        double mid = (low + high) / 2;
        int clinics = 0;

        for (int i = 0; i < n; i++)
        {
            clinics += ceil(population[i] / mid);
        }

        if (clinics <= k)
            high = mid;
        else
            low = mid;
    }

    printf("%.2f\n", high);

    return 0;
}
