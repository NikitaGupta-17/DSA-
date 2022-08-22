#include <iostream>
#include<algorithm>
using namespace std;

// int main() {
// 	int t,n;
// 	cin>>t;
// 	while(t--){
// 	    cin>>n;
// 	    char str[n],str1[n],str2[n];
// 	    for(int i=0;i<n;i++){
// 	        cin>>str[i];
// 	        str1[i]=str[i];
// 	    }
// 	    sort(str1);
// 	    for(int i=0;i<n;i++){
// 	        for(int j=0;j<n;j++){
// 	            if(str[i]==str[j]){
// 	                str2[i]=j;
// 	            }
// 	        }
// 	    }
// 	    for(int j=0;j<n;j++){
// 	        for(int i=0;i<n;i++){
// 	            if(str2[i]==j){
	                
// 	            }
// 	        }
// 	    }
	    
// 	}
// 	return 0;
//}

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,count=0,temp1;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int min_index;
	    for(int i=0;i<n-1;i++){
	        min_index=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[min_index]){
                    min_index=j;
                }
            }
            if(((arr[i] & arr[min_index]) != 0 ) && min_index!=i && arr[i]!=0 && arr[min_index]!=0){
                temp1=arr[i];
                arr[i]=arr[min_index];
                arr[min_index]=temp1;
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j] && ((arr[i] & arr[j]) != 0 ) && j!=i && arr[i]!=0 && arr[j]!=0){
                    temp1=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp1;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                count=0;
                break;
            }
            count++;
        }
        if(count!=0){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
        cout<<endl;
	}
	return 0;
}
