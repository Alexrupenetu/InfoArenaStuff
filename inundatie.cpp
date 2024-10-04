#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

ifstream fin("inundatie.in");
ofstream fout("inundatie.out");

#define MAX_SIZE 100005

int M,N,cnt, blocuri[MAX_SIZE], Q, q;
long long sume_part[MAX_SIZE];

void citire(int &N, int &M, int &cnt, int blocuri[MAX_SIZE])
{
	fin>>N>>M;
	cnt = N*M;
	
	for(int i=1; i<=cnt; i++)
			fin>>blocuri[i];
		
	
	sort(blocuri+1, blocuri+cnt+1); //sortam crescator vectorul de blocuri
	
	for(int i=1; i<=cnt; i++)
	sume_part[i] = sume_part[i-1]+blocuri[i]; //calculam sumele partiale 
	
}

int cautare_binara(int x)
{
    int st=1,dr=cnt;
    while(st<=dr)
    {
        int mij=(st+dr)/2;
        if(blocuri[mij]<x) st=mij+1;
        else dr=mij-1;
    }
    return dr; //returnam pozitia ultimului termen <q-1
    //urm termen dr+1 ar fi primul termen >=q-1
}


int main()
{
	citire(N, M, cnt, blocuri);

	int poz;
	long long flood=0;
	fin>>Q;
	for(int i=1; i<=Q; i++)
		{
			fin>>q; 
		
			flood = 0;

			poz = cautare_binara(q-1);
			
			flood = (cnt-poz)*(q-1) + sume_part[poz];
			
			if(q!=0)
				fout<<flood<<endl;
			else
				fout<<0<<endl;	
		}
	
	return 0;
}
