#include <stdio.h>
#include <limits.h>

int gcm(int a,int b){

	int c;

	if(a==0||b==0){return -1;}

	if(b>a){c=a;a=b;b=c;}

	//b is littler
	if(b>a){c=a;a=b;b=c;}

	while( (c = a%b) != 0 ){
		a=b;
		b=c;
	}

	return b;

}


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
	printf("anslengs=%d\n",anslengs);

	//initialise matrix
	int overmat[m][n];
	int undermat[m][n];
	for(i=0;i<m;i++){for(j=0;j<n;j++){overmat[i][j]=0;undermat[i][j]=1;}}

	//input matrix
	printf("type matrix\n");
	for(i=0;i<m;i++){for(j=0;j<n;j++){scanf(" %d",&overmat[i][j]);}}

	//print matrix
	printf("\n%d*%dmatrix\n",m,n);
	for(i=0;i<m;i++){for(j=0;j<n;j++){printf("%4d ",overmat[i][j]);}printf("\n");}
	printf("\n");

	//solve
	//I cant use line changer
	int pivoti=-1,pivotj=-1;	//pivot's i&j
	int pivotvalover,pivotvalunder;	//pivot's value
	int decvalover,decvalunder;	//pivot's declice value
	int k,l;
	int a,b;
	int gcmnum;	//gcm num swap
	int overswap,underswap;	//calc for BUNSU


	printf("solve start!\n******************************************\n");

	//search pivot
	for(j=0;j<n-anslengs;j++){
		for(i=0;i<m;i++){
			printf("hello\n");
			if(overmat[i][j]!=0.0 && i>pivoti && j>pivotj){
				//pivot=(i,j)
			//pivottanise
				pivoti=i;
				pivotj=j;
				pivotvalover=overmat[i][j];
				pivotvalunder=undermat[i][j];
				if((pivotvalover/pivotvalunder)!=1.0){
					//printf("pivot(i,j)=(%d,%d)\npivotval=%8.4f\n",i,j,pivotval);
					printf("pivottanise\nline(%d)=line(%d)*%d/%d\n",pivoti+1,pivoti+1,pivotvalunder,pivotvalover);
					for(l=0;l<n;l++){
						overmat[i][l] *= pivotvalunder;
						undermat[i][l] *= pivotvalover;
						if(overmat[i][l]==0){
							undermat[i][l]=1;
						}else{
							gcmnum=gcm(overmat[i][l],undermat[i][l]);
							overmat[i][l] /= gcmnum;
							undermat[i][l] /= gcmnum;
						}
						if(overmat[i][l]==undermat[i][l]){
							overmat[i][l]=1;
							undermat[i][l]=1;
						}
						if(undermat[i][l]<0){
							overmat[i][l]*= -1;
							undermat[i][l] *= -1;
						}

					}
				//print matrix
					printf("\n");
					for(a=0;a<m;a++){
						for(b=0;b<n;b++){
							printf(" %4d",overmat[a][b]);
							if(undermat[a][b]!=1){
								printf("/%4d",undermat[a][b]);
							}else{
								printf("     ");
							}
						}
						printf("\n");
					}
				printf("\n");
				}

			//hiku line
				for(k=0;k<m;k++){
					if(k!=pivoti){
						decvalover=overmat[k][pivotj]*-1;
						decvalunder=undermat[k][pivotj];
						//printf("decval=%f\npivoti=%d\n",decvalover,pivoti);
						printf("line declice\nline(%d)=line(%d)*(%d/%d)*(-1)+line(%d)\n\n",k+1,pivoti+1,decvalover,decvalunder,k+1);
						for(l=0;l<n;l++){
							overswap=overmat[k][l];
							underswap=undermat[k][l];
							overmat[k][l] = overmat[pivoti][l]*decvalover*underswap+undermat[pivoti][l]*decvalunder*overswap;
							undermat[k][l] = undermat[pivoti][l]*decvalunder*underswap;

							if(overmat[k][l]==0){
								undermat[k][l]=1;
							}else{
								gcmnum=gcm(overmat[k][l],undermat[k][l]);
								overmat[k][l] /= gcmnum;
								undermat[k][l] /= gcmnum;
							}
							if(overmat[k][l]==undermat[k][l]){
								overmat[k][l]=1;
								undermat[k][l]=1;
							}
							if(undermat[k][l]<0){
								overmat[k][l]*= -1;
								undermat[k][l] *= -1;
							}

						}
					}
				}

			//print matrix
				//printf("\n");
				for(a=0;a<m;a++){
					for(b=0;b<n;b++){
						printf(" %4d",overmat[a][b]);
						if(undermat[a][b]!=1){
							printf("/%4d",undermat[a][b]);
						}else{
							printf("     ");
						}
					}
					printf("\n");
				}
				printf("\n");
			}
		}
	}

	printf("\n******************************************\nsolve finish!\n");
    
	//print matrix
	printf("\nsolved matrix\n%d * %d matrix\n\n",m,n);
	for(i=0;i<m;i++){
		//printf(" i:%3d  :",i+1);
		for(j=0;j<n;j++){
			printf(" %4d",overmat[i][j]);
			if(undermat[i][j]!=1){
				printf("/%4d |",undermat[i][j]);
			}else{
				printf("      |");
			}
		}
		printf("\n");
	}
	printf("\n");
}

