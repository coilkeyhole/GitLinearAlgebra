#include <stdio.h>
#include <limits.h>

int main(void){
	int m,n;	//m*n matrix
	int i,j;	//count
	int anslengs=INT_MAX;

	printf("Type m*n matrix's m&n \n");
	scanf("%d %d",&m,&n);
	printf("%d*%d matrix\n",m,n);
	while(anslengs>n){
		printf("type width besides cofficient matrix\n");
		scanf("%d",&anslengs);
	}
	printf("snalengs=%d\n",anslengs);

	//initialise matrix
	float matrix[m][n];
	for(i=0;i<m;i++){for(j=0;j<n;j++){matrix[i][j]=0.0;}}

	//input matrix
	printf("type matrix\n");
	for(i=0;i<m;i++){for(j=0;j<n;j++){scanf(" %f",&matrix[i][j]);}}

	//print matrix
	printf("\n%d*%dmatrix\n",m,n);
	for(i=0;i<m;i++){for(j=0;j<n;j++){printf("%8.4f ",matrix[i][j]);}printf("\n");}
	printf("\n");
    
	//solve
	//I cant use line changer
	int pivoti=-1,pivotj=-1;	//pivot's i&j
	float pivotval;	//pivot's value
	float decval;	//pivot's declice value
	int k,l;    
	int a,b;


	printf("solve start!\n******************************************\n");

	//search pivot
	for(j=0;j<n-anslengs;j++){
		for(i=0;i<m;i++){
			if(matrix[i][j]!=0.0 && i>pivoti && j>pivotj){
				//pivot=(i,j)
			//pivottanise
				pivoti=i;
				pivotj=j;
				pivotval=matrix[i][j];
				if(pivotval!=1.0){
					//printf("pivot(i,j)=(%d,%d)\npivotval=%8.4f\n",i,j,pivotval);
					printf("pivottanise\nline(%d)=line(%d)/%f",pivoti,pivoti,pivotval);
					for(l=0;l<n;l++){
						matrix[i][l] = matrix[i][l]/pivotval;
					}
			//print matrix
				printf("\n");
				for(a=0;a<m;a++){for(b=0;b<n;b++){printf(" %8.4f",matrix[a][b]);}printf("\n");}
				printf("\n");
				}else{
					//printf("pivot(i,j)=(%d,%d)\n",i,j);
				}

			//hiku line
				for(k=0;k<m;k++){
					if(k!=pivoti){
						decval=matrix[k][pivotj];
						//printf("decval=%f\npivoti=%d\n",decval,pivoti);
						printf("line declice\nline(%d)=line(%d)*(%8.4f)*(-1)+line(%d)\n",k,pivoti,decval,k);
						for(l=0;l<n;l++){
							matrix[k][l] -= matrix[pivoti][l]*decval;
/*
							//print matrix
							printf("\n");
							for(a=0;a<m;a++){for(b=0;b<n;b++){printf(" %8.4f",matrix[a][b]);}printf("\n");}
							printf("\n");
*/
						}
					}
				}

			//print matrix
				//printf("\n");
				for(a=0;a<m;a++){for(b=0;b<n;b++){printf(" %8.4f",matrix[a][b]);}printf("\n");}
				printf("\n");
                
			}
		}
	}

	printf("solve start!\n******************************************\nsolve finish!\n");
    
    //print matrix
	printf("\nsolved matrix\n");
	for(i=0;i<m;i++){for(j=0;j<n;j++){printf(" %8.4f",matrix[i][j]);}printf("\n");}
    
}
