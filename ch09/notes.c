/* Uses recursion to compute factorial */
int fact(int n)
{
    if (n <= 1)
        return 1;
    else 
        return n * fact(n - 1);
}

/* Uses recursion to compute power */
int power(int x, int n)
{
    if (n == 0)
        return 1;
    else  
        return x * power(x, n - 1);
}