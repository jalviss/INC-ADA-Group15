#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	int n;
	scanf("%d", &n);
	
	char oriString[n + 1];
	scanf("%s", oriString); 
	
	int q;
	scanf("%d", &q);
	
	for(int i = 0; i < q; i++){
		char target[n + 1];
		scanf("%s", target);
		
		int flag = 1;
        int oriIndex = 0;
        char temp[n + 1];
        temp[0] = '\0';
        int index = 0;
        
        for(int j = 0; j < n; j++){
        	int temp_len = strlen(temp);
            temp[temp_len] = target[j];
            temp[temp_len + 1] = '\0';

            if (oriString[n - oriIndex - 1] == target[j]) {
                if (strncmp(oriString + n - j - 1, temp, temp_len + 1) == 0) {
                    oriIndex = j + 1;
                    temp[0] = '\0';
                }
            }

            if (temp[0] != '\0' && j == n - 1) {
                flag = 0;
            }
        }

        if (flag == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
	}

	return 0;
}

