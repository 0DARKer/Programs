# include <stdio.h>
#include<vector>
#include<iostream>
# define MaxVnNum 100
# define MaxVtNum 100
# define MaxRuleNum 100
# define MaxstateNum 100
using namespace std;
char Vn[MaxVnNum];
char Vt[MaxVtNum];
struct rule {
	char left_char;
	char right_fst;
	char right_sec;
};
rule grammar[MaxRuleNum];
vector<char> fa[MaxstateNum][MaxVtNum];
void  print_fa(const vector<char> fa[MaxstateNum][MaxVtNum]){
	printf("%8c",' ');
	bool ck1[MaxstateNum]={0};
	bool ck2[MaxVtNum]={0};
	for(int i=0;i<MaxstateNum;i++)
	for(int j=0;j<MaxVtNum;j++)
	if(fa[i][j].size())ck1[i]=1,ck2[j]=1,printf("%-7c",j);
	printf("\n");
	for(int i=0;i<MaxstateNum;i++)
			if(ck1[i]){
				printf("%c ",i);
				for(int j=0;j<MaxVtNum;j++)
					if(ck2[j])
						if(fa[i][j].size())
							for(const char &k:fa[i][j])
								printf("%7c",k);
						else printf("%7c",' ');
				printf("\n");
			}
}
int main() {
	printf("Please input the Vn set <end up with'#'>\n");
	int i,j,k,n,p,q,z;
	for(i=0; i<MaxVnNum; i++) 
	{
		cin>>Vn[i];
		if(Vn[i]=='#')
			break;
	}
	printf("please input the Vt set <end up with'#'>\n");             
	for(j=0; j<MaxVtNum; j++) 
	{
		cin>>Vt[j];
		if(Vt[j]=='#')
			break;
	}
	printf("Please input the Regular Grammar:\n");
	for(k=0; k<MaxRuleNum; k++) 
	{
		cin>>grammar[k].left_char>>grammar[k].right_fst>>grammar[k].right_sec;
		if(grammar[k].left_char =='#')
		break;
	}
//	for(p=1;p<=j;p++)
//		fa[0][p].push_back(grammar[p].right_fst);
//	for(q=1;q<=i;q++)
//		fa[q][0].push_back(grammar[q].left_char);
//	for(q=1;q<=i;q++)
//		for(p=1;p<=j;p++)
//		{
//			for(n=0;n<=k;n++)
//			fa[q+1][p+1].push_back(grammar[k].right_sec);
//		}
	for(int i=0;grammar[i].left_char!='#';i++){
		fa[grammar[i].left_char][grammar[i].right_fst].push_back(grammar[i].right_sec);
	} 
	printf("The state transforming matrix of the FA is:\n");
	print_fa(fa);

printf("The fa is ...");
return 0;
}

	// for(z=0;z<MaxstateNum;z++)
	// 	for(p=0;p<MaxVtNum;p++)
	// 		if(fa[z][p].size())printf("%c ",)
	// for(z=0; z<MaxstateNum; z++)
	// 	for(p=0; p<MaxVtNum; p++)
	// 		// for(int n=0;n<fa[k][p].size();n++)
 //                // if(fa[z][p].size())printf("%c\n",fa[z][p][n]);
	// 		for(char & i:fa[z][p])
	// 			{
	// 				printf("%c ",i);
	// 			}