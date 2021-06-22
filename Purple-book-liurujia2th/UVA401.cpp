#include<stdio.h>
#include<string.h>
char res[21];
char mir1[]="AEMHIJOSTUVWXYZ18";
char mir2[]="A3MHILO2TUVWXY518";
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int m = strlen(mir1),i,j,n;
    
    while(scanf("%s",res)!=EOF){
        n = strlen(res);
        bool palindrome = true;
        bool mirror = 1;
        //printf("%s\n",res);
        // bug when i==n/2
        for(i=0;i<=n/2;i++){
            j = 0;  
            if(palindrome) palindrome =res[i]!=res[n-i-1]? 0:1;
            //why bug
            while (j<m && mirror)
            {
                
                if(((mir1[j]==res[i] && mir2[j]==res[n-1-i]) || (mir2[j]==res[i] && mir1[j]==res[n-1-i]))){
                    mirror = 1;
                    break;
                }
                j++;
                if(j==m)mirror=0;
            }
            //if(mirror ) mirror= j>=m?0:1;
            
        }
        if(!palindrome && !mirror) printf("%s -- is not a palindrome.\n\n",res);
        else if(palindrome && !mirror) printf("%s -- is a regular palindrome.\n\n",res);
        else if(!palindrome && mirror) printf("%s -- is a mirrored string.\n\n",res);
        else if(palindrome && mirror) printf("%s -- is a mirrored palindrome.\n\n",res);
   
    
    }
}