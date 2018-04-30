void extgcd(int a, int b, int &i, int &j, int &d)
{
    if (b == 0)
    {
        d = a; i = 1; j = 0;
    }
    else
    {
        gcd(b, a % b, j, i, d);
        j -= (a / b) * i;
    }
}
