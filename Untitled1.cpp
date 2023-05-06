#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int determenant(int**m,int n);
int main() 
{
    char path1[255],path2[255];
    cout<<"Enter path:";
	cin.getline(path1,255);
	FILE *f=fopen(path1,"r");
	if(f==NULL)
	{
		cout<<"File not open";
		return 0;
	}
    int n;
    fscanf(f,"%d",&n);
    int **m=new int*[n];
    for (int i=0;i<n;i++)
    m[i]=new int [n];
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
    fscanf(f,"%d",&m[i][j]);
    fclose(f);
    cout<<"Enter path:";
    cin.getline(path2,255);
    FILE *f2=fopen(path2,"w");
    if(f2==NULL)
	{
		cout<<"File not open";
		return 0;
	}
    fprintf(f2,"%d",determenant(m,n));
    fclose(f2);
    for (int i=0;i<n;i++)
    delete [] m[i];
    delete m;
    return 0;
}
int determenant(int**m,int n)
{
	if(n==1)
	{
		return m[0][0];
	}
	else if(n==2)
	{
		return (m[0][0]*m[1][1]-m[0][1]*m[1][0]);
	}
	else if (n>=3)
	{
	int **t=new int*[n-1];
	for (int i=0;i<n;i++)
    t[i]=new int [n-1];
    int det=0,a,b;
    for (int i=0;i<n;i++)
    {
    a=0;
	for (int j=1;j<n;j++)
    {
    b=0;
	for (int k=0;k<n;k++)
	{
    	if(k!=i)
    	{
		t[a][b]=m[j][k];
		b++;
	    }
    }
	a++;
	}
	det+=pow(-1,i+2)*m[0][i]*determenant(t,n-1);
	}
	return det;
	}         
}
