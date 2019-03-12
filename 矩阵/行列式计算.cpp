
#include<iostream>
using namespace std;
int *C;
int R=0;
void swap(int *l,int *m){
	int a;
	a=*l;
	*l=*m;
	*m=a;
}
void perm(int *l,int mi,int ma){
	static int t=0;
	static int Mi=mi;
	if (ma==mi){
		int temp=1;
		for(int i=Mi;i<=ma;i++){
			temp*=*(C+i*(ma+1)+l[i]);
			cout<<*(C+i*(ma+1)+l[i])<<"*";
		}
		if(t%2==1){
			temp*=-1;
			cout << "(-1)";
		}
		else
			cout << "(1)";
		cout << ";"<<temp;
		cout << endl;
		R+=temp;
	}
		else for(int i=mi;i<=ma;i++){
			swap(l+mi,l+i);
			if(mi!=i)
			t++;
			perm(l,mi+1,ma);
			if(mi!=i)
			t--;
			swap(l+mi,l+i);
		}
}
// int main(){
// 	int l[]={1,2,3,4,5,6};
// 	perm(l,0,5);
	// swap(l+0,l+5);
	// printf("%d %d",l[0],l[5]);

// }
int main(){
	int N;
	cin >> N;
	int a[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> a[i][j];
	int b[N];
	for(int i=0;i<N;i++)
		b[i]=i;
	C=a[0];
	perm(b,0,N-1);
	printf("%d",R);
}
