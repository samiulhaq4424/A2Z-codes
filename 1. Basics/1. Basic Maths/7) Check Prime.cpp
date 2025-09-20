// https://www.codingninjas.com/studio/problems/check-prime_624934?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


bool isPrime(int n)
{
	if(n==1)
	return false;
	
	for(int i=2; i*i<=n;i++){
		if(n%i==0)
		return false;
	}
	return true;
}
