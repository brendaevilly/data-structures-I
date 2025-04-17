#include <stdio.h>
#include <stdlib.h>

	int numeroAusente(int *nums, int numsSize);

	int main(){
		int numsSize, *nums;
        printf("\nIntervalo: "); scanf("%d", &numsSize);
		nums = (int *)calloc(numsSize, sizeof(int));

		if(nums == NULL){
			printf("Falha na alocacao de memoria!\n");
			return 1;
		}
		
		for(int i=0; i<numsSize; i++){
            printf("\nInsira o numero: ");
			scanf("%d", &nums[i]);

			for(int j=0; j<i; j++){
				if(nums[j] == nums[i] || nums[i] > numsSize || nums[i] < 0){
					printf("\nEsse valor ja foi inserido no vetor ou nao esta dentro do intervalo. Tente novamente.\n");
					nums[i] = 0;
					i--;
					break;
				}
			}
		}

		printf("\nNumero ausente: %d\n", numeroAusente(nums, numsSize));

		free(nums);

		return 0;
	}

	int numeroAusente(int *nums, int numsSize){
		int encontrado = 0;

		for(int i=0; i<=numsSize; i++){
			for(int j=0; j<numsSize; j++){
                encontrado = 0;
				if(*(nums+j) == i){
                    encontrado = 1;
                    break;
                }
			}

            if(!encontrado){
                return i;
            }
		}
	}
